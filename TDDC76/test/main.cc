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
#include <iostream>

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
	test.show_decisions();
	vector<vector<int> > apa = test.get_model_data();

	for(int i = 0; i + apa.begin() != apa.end(); i++)
	{
		for(int k = 0; k + (apa.at(i)).begin() != (apa.at(i)).end(); k++)
			{
				cout << "Aktie " << stock[i] << ", Modell " << model[k] << " returnerade " << (apa.at(i)).at(k) << endl;
			}
	}
	delete database_ptr;
	delete trader_ptr;
}
