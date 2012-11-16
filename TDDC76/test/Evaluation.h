/*
 * Evaluation.h
 *
 *  Created on: Nov 15, 2012
 *      Author: axel
 */

#ifndef EVALUATION_H_
#define EVALUATION_H_

#include "Model.h"
//#include "Portfolio.h"
#include "Database.h"
#include "Trader.h"
//#include "Decision.h"
#include <string>
#include <vector>

class Evaluation
{
public:
	Evaluation(std::string, std::vector<std::string>, int, int, std::string, double,
			Database*, Trader*);
	void make_decision();
	int get_model_data();

private:
std::vector<Model*> models;
std::string stock;
std::vector<std::string> model_names;
int interval_start;
int interval_end;
std::string frequency;
double confidence;
Database* database;
Trader* trader;
//Portfolio* portfolio;

};



#endif /* EVALUATION_H_ */
