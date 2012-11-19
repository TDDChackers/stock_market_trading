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
#include <iostream>


class Model
{
public:
	//Model(std::string, std::string, int, int, std::string, Database*);
	Model(std::string, std::string, time_t, time_t, std::string, Database*);
	virtual int make_decision() = 0;
	virtual double get_model_data();
	virtual ~Model()
	{
		std::cout << "Model has been deleted.\n";
	};
protected:
	virtual double evaluate() = 0;
	std::string stock;
	std::string model;
	time_t interval_start;
	time_t interval_end;
	std::string frequency;
	Database* database;

};

class Williamson : public Model
{
public:
	Williamson(std::string, std::string, time_t, time_t, std::string, Database*);
	virtual int make_decision() override;
	virtual ~Williamson()
	{
		std::cout << "Williamson has been deleted.\n";
	};
private:
	virtual double evaluate() override;
};

class MACD : public Model
{
public:
	MACD(std::string, std::string, time_t, time_t, std::string, Database*);
	virtual int make_decision() override;
	virtual ~MACD()
	{
		std::cout << "MACD has been deleted.\n";
	};
private:
	virtual double evaluate() override;
};



#endif /* MODEL_H_ */
