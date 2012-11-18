/*
 * Decision.cc
 *
 *  Created on: Nov 16, 2012
 *      Author: axel
 */

#include "Decision.h"
#include <string>

using namespace std;

Decision::Decision(string stock_input, double price_input, int volume_input)
: stock(stock_input), price(price_input), volume(volume_input), pending_order(true) {}

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
