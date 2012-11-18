/*
 * Evaluation.cc

 *
 *  Created on: Nov 15, 2012
 *      Author: axel
 */
#include "Evaluation.h"
#include "Decision.h"
#include "Model.h"
#include <iostream>
using namespace std;

Evaluation::Evaluation(string stock_input, vector<string> models_input,
						int interval_start_input, int interval_end_input,
						string frequency_input, double confidence_input,
						Database* database_input, Trader* trader_input)
: stock(stock_input), model_names(models_input), interval_start(interval_start_input),
  interval_end(interval_end_input),frequency(frequency_input),
  confidence(confidence_input), database(database_input), trader(trader_input),
  decision(nullptr)
{
	for(int i = 0; i + models_input.begin() != models_input.end(); i++)
	{
		if(models_input[i] == "MACD")
		{
			Model* temp = new MACD(stock_input, models_input[i], interval_start_input,
								interval_end_input, frequency_input, database_input);
			models.push_back(temp);
		}
		if(models_input[i] == "Williamson")
		{
			Model* temp = new Williamson(stock_input, models_input[i], interval_start_input,
								interval_end_input, frequency_input, database_input);
			models.push_back(temp);
		}

	}
}

Evaluation::~Evaluation()
{
	for(int i = 0; i + models.begin() != models.end(); i++)
	{
		delete models.at(i);
		models.at(i) = nullptr;
	}
	delete decision;
}


Decision* Evaluation::make_decision()
{
	cout << stock <<" säger hej\n";
	for(int i = 0; i + models.begin() != models.end(); i++)
	{
		models.at(i)->make_decision();
	}
	decision = new Decision(stock, 3.14, 2);
	return decision;
}

vector<int> Evaluation::get_model_data()
{
	vector<int> data_vector;
	for(int i = 0; i + models.begin() != models.end(); i++)
	{
		data_vector.push_back(models.at(i)->get_model_data());
	}
	return data_vector;
}
