/*
 * Decision.cc
 *
 *  Created on: Nov 16, 2012
 *      Author: axel
 */

#include "Decision.h"
#include <string>

using namespace std;

string Decision::get_stock()
{
	return stock;
}

double Decision::get_price()
{
	return price;
}

int Decision::get_volume()
{
	return volume;
}

bool Decision::get_pending_order()
{
	return pending_order;
}

void Decision::set_pending_order(bool order_state)
{
	pending_order = order_state;
}
