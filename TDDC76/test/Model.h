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
	//Model(std::string, std::string, int, int, std::string, Database*);
	Model(std::string, std::string, int, int, std::string, Database*);
	virtual int make_decision() = 0;
	virtual int get_model_data();
	virtual ~Model() {};
protected:
	virtual int evaluate() = 0;
	std::string stock;
	std::string model;
	int interval_start;
	int interval_end;
	std::string frequency;
	Database* database;
};

class Williamson : public Model
{
public:
	Williamson(std::string, std::string, int, int, std::string, Database*);
	virtual int make_decision() override;
	virtual ~Williamson() = default;
private:
	virtual int evaluate() override;
};

class MACD : public Model
{
public:
	MACD(std::string, std::string, int, int, std::string, Database*);
	virtual int make_decision() override;
	virtual ~MACD() = default;
private:
	virtual int evaluate() override;
};



#endif /* MODEL_H_ */
