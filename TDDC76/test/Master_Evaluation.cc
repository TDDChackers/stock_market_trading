/*
 * Master_Evaluation.cc
 *
 *  Created on: Nov 15, 2012
 *      Author: axel
 */
#include "Master_Evaluation.h"
#include "Evaluation.h"
#include "Decision.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;


Master_Evaluation::~Master_Evaluation()
{
	//Deletes Evaluation objects
	for(int i = 0; i + evaluations.begin() != evaluations.end(); i++)
		{
			delete evaluations.at(i);
			evaluations.at(i) = nullptr;
		}
	//Deletes Decision objects
	for(int i = 0; i + decisions.begin() != decisions.end(); i++)
		{
			delete decisions.at(i);
			decisions.at(i) = nullptr;
		}
	cout << "Master_Evaluation deleted.\n";
}

void Master_Evaluation::initialize(Database* database_input, Trader* trader_input)
  {
	database = database_input;
	trader = trader_input;
  }


void Master_Evaluation::set_parameters(vector<string>& stock_input,
										vector<string>& models_input,
										time_t interval_start_input, time_t interval_end_input,
										string frequency_input, double confidence_input)

{
	stocks = stock_input;
	models = models_input;
	interval_start = interval_start_input;
	interval_end = interval_end_input;
	frequency = frequency_input;
	confidence = confidence_input;

	//Cleans previous Evaluation tree.
	for(int i = 0; i + evaluations.begin() != evaluations.end(); i++)
	{
		delete evaluations.at(i);
		evaluations.at(i) = nullptr;
	}
	evaluations.clear();
	//Creates new Evaluation tree.
	//int i = 0;
	for (int i = 0; i + stock_input.begin() != stock_input.end(); i++)
	{
		Evaluation* temp = new Evaluation(stock_input.at(i), models_input, interval_start_input,
				interval_end_input, frequency_input, confidence_input,
				database, trader);
		evaluations.push_back(temp);
	}
}

vector<Decision*> Master_Evaluation::make_decision()
{
	for(int i = 0; i + evaluations.begin() != evaluations.end(); i++)
	{
		Decision* temp = evaluations[i]->make_decision();
		decisions.push_back(temp);
	}
	return decisions;
}

//Dummy-funktion för testning
void Master_Evaluation::show_decisions()
{
	for(int i= 0; decisions.begin() + i != decisions.end(); i++)
	{
		cout << "Beslut " << stocks[i] << " handlades för " << decisions.at(i)->get_price() << endl;
	}
}

vector<vector<double>> Master_Evaluation::get_model_data()
{
	vector<vector<double>> data_vector;
	for(int i = 0; i + evaluations.begin() != evaluations.end(); i++)
		{
			data_vector.push_back(evaluations.at(i)->get_model_data());
		}
	return data_vector;
}




