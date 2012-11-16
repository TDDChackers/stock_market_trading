/*
 * Evaluation.cc

 *
 *  Created on: Nov 15, 2012
 *      Author: axel
 */
#include "Evaluation.h"
#include <iostream>
using namespace std;

Evaluation::Evaluation(string stock_input, vector<string> models_input, int interval_start_input, int interval_end_input,
						string frequency_input, double confidence_input, Database* database_input, Trader* trader_input)
: stock(stock_input), model_names(models_input), interval_start(interval_start_input), interval_end(interval_end_input),
  frequency(frequency_input), confidence(confidence_input), database(database_input), trader(trader_input)
{
	for(int i = 0; i + models_input.begin() != models_input.end(); i++)
	{
		Model* temp = new Model(stock_input, models_input[i], interval_start_input,
				interval_end_input, frequency_input, database_input);
		models.push_back(temp);
	}
}

void Evaluation::make_decision()
{
	cout << stock <<" säger hej\n";
	for(int i = 0; i + models.begin() != models.end(); i++)
	{
		models.at(i)->make_decision();
	}
}



std::string stock;
std::vector<std::string> models;
int interval_start;
int interval_end;
std::string frequency;
double confidence;
Database* database;
Trader* trader;
