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
#include "Decision.h"
#include <string>
#include <vector>

class Evaluation
{
public:
	Evaluation(std::string, std::vector<std::string>, time_t, time_t, std::string, double,
			Database*, Trader*);
	~Evaluation();
	Decision* make_decision();
	std::vector<double> get_model_data();

private:
std::vector<Model*> models;
std::string stock;
std::vector<std::string> model_names;
time_t interval_start;
time_t interval_end;
std::string frequency;
double confidence;
Database* database;
Trader* trader;
Decision* decision;
//Portfolio* portfolio;

};



#endif /* EVALUATION_H_ */
