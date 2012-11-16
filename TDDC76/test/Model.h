/*
 * Model.h
 *
 *  Created on: Nov 15, 2012
 *      Author: axel
 */

#ifndef MODEL_H_
#define MODEL_H_
#include "Database.h"
#include <string>


class Model
{
public:
	Model(std::string, std::string, int, int, std::string, Database*);

	void make_decision();
	//int get_model_data();
private:
	//int evaluate();
	std::string stock;
	std::string model;
	int interval_start;
	int interval_end;
	std::string frequency;
	Database* database;
};



#endif /* MODEL_H_ */
