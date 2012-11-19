/*
 * Master_Evaluation.h
 *
 *  Created on: Nov 15, 2012
 *      Author: axel
 */

#ifndef MASTER_EVALUATION_H_
#define MASTER_EVALUATION_H_

#include "Database.h"
#include "Trader.h"
#include "Decision.h"
#include "Evaluation.h"
//#include "Portfolio.h"
#include <vector>
#include <string>

class Master_Evaluation
{
public:
	~Master_Evaluation();
	void initialize(Database*, Trader*);
	std::vector<Decision*> make_decision();
	void set_parameters(std::vector<std::string>&, std::vector<std::string>&,
						time_t, time_t,
						std::string frequency, double confidence);

	void show_decisions();
	std::vector<std::vector<double>> get_model_data();

private:
	std::vector<Evaluation*> evaluations;
	std::vector<Decision*> decisions;
	Database* database;
	Trader* trader;
	//Portfolio* portfolio;
	std::vector<std::string> stocks;
	std::vector<std::string> models;
	time_t interval_start;
	time_t interval_end;
	std::string frequency;
	int confidence;
};

#endif /* MASTER_EVALUATION_H_ */
