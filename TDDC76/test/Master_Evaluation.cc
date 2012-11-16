/*
 * Master_Evaluation.cc
 *
 *  Created on: Nov 15, 2012
 *      Author: axel
 */
#include "Master_Evaluation.h"
#include "Evaluation.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;


void Master_Evaluation::initialize(Database* database_input, Trader* trader_input)
  {
	database = database_input;
	trader = trader_input;
  }


void Master_Evaluation::set_parameters(vector<string>& stock_input,
										vector<string>& models_input,
										int interval_start_input, int interval_end_input,
										string frequency_input, double confidence_input)

{
	stocks = stock_input;
	models = models_input;
	interval_start = interval_start_input;
	interval_end = interval_end_input;
	frequency = frequency_input;
	confidence = confidence_input;

	//Cleans previous Evaluation tree.
	/*for(vector<Evaluation*>::iterator i = evaluations.begin(); i != evaluations.end(); i++)
	{
		delete evaluations.at(i);
		evaluations.at(i) = nullptr;
	}
	evaluations.clear();
*/
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

void Master_Evaluation::make_decision()
{
	for(int i = 0; i + evaluations.begin() != evaluations.end(); i++)
	{
		evaluations[i]->make_decision();
	}
}

