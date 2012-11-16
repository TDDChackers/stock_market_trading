/*
 * main.cc
 *
 *  Created on: Nov 15, 2012
 *      Author: axel
 */
#include "Master_Evaluation.h"
#include "Database.h"
#include "Trader.h"
#include <vector>
#include <string>

using namespace std;

int main ()
{
	Master_Evaluation test;
	Database* database_ptr = new Database;
	Trader* trader_ptr = new Trader;
	vector<string> stock;
	stock.push_back("Ericsson");
	stock.push_back("SEB");
	vector<string> model;
	model.push_back("MACD");
	model.push_back("Williamson");
	int interval_start = 1;
	int interval_end = 2;
	string frequency = "Minute";
	double confidence = 0.8;


	test.initialize(database_ptr, trader_ptr);
	test.set_parameters(stock, model, interval_start, interval_end, frequency, confidence);
	test.make_decision();

	delete database_ptr;
	delete trader_ptr;
}
