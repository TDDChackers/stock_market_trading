/*
 * Model.cc
 *
 *  Created on: Nov 15, 2012
 *      Author: axel
 */
#include "Model.h"
#include "Database.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

double Model::get_model_data()
{
	return evaluate();
}

Model::Model(string stock_input, string model_input, time_t interval_start_input,
		time_t interval_end_input, string frequency_input, Database* database_input)
: stock(stock_input), model(model_input), interval_start(interval_start_input),
  interval_end(interval_end_input), frequency(frequency_input), database(database_input)
{
	cout << "Model parameters has been set.\n";
}

Williamson::Williamson(string stock_input, string model_input, time_t interval_start_input,
		time_t interval_end_input, string frequency_input, Database* database_input)
: Model(stock_input, model_input,interval_start_input, interval_end_input,
		frequency_input,database_input)
{
	cout << model_input << " has been created.\n";
}


// Skall returnera -1,0,1
int Williamson::make_decision()
{
	return 1;
}


double Williamson::evaluate()
{
	vector<double> stock_data;
	stock_data = database->get(stock,interval_end);
	return stock_data[CLOSE];
}

//------------------------------------------------------------------------------------------------
MACD::MACD(string stock_input, string model_input, time_t interval_start_input,
		time_t interval_end_input, string frequency_input, Database* database_input)
: Model(stock_input, model_input,interval_start_input, interval_end_input,
		frequency_input,database_input)
{
	cout << model_input << " has been created.\n";
}


// Skall returnera -1,0,1
int MACD::make_decision()
{
	return 2;
}

double MACD::evaluate()
{
	vector<double> stock_data;
	stock_data = database->get(stock,interval_end);
	return stock_data[OPEN];
}
