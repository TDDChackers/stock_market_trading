/*
 * Decision.h
 *
 *  Created on: Nov 16, 2012
 *      Author: axel
 */

#ifndef DECISION_H_
#define DECISION_H_

#include <string>

class Decision
{
public:
	Decision(std::string, double, int);
	std::string get_stock();
	double get_price();
	int get_volume();
	void set_pending_order(bool);
	bool get_pending_order();

private:
	std::string stock;
	double price;
	int volume;
	bool pending_order;

};


#endif /* DECISION_H_ */
