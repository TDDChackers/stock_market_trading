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

Model::Model(string stock_input, string model_input, int interval_start_input,
		int interval_end_input, string frequency_input, Database* database_input)
: stock(stock_input), model(model_input), interval_start(interval_start_input),
  interval_end(interval_end_input), frequency(frequency_input), database(database_input) {}

void Model::make_decision()
{
	cout << model << " säger hej!\n";
}


