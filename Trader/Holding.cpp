//
//  Holding.cpp
//  Portfolio
//
//  Created by Victor Birath on 2012-12-01.
//  Copyright (c) 2012 database. All rights reserved.
//

#include "Holding.h"
#include "Holding_Error.h"

Holding::Holding(const unsigned int number_of_pcs, const double price_per_pcs)
{
    entry(number_of_pcs, price_per_pcs);
}

void Holding::entry(const unsigned int number_of_new_pcs, const double price_per_pcs)
{
    _mean_buying_price = (_number_of_pcs*_mean_buying_price +
                          number_of_new_pcs * price_per_pcs) /
                            (number_of_new_pcs+_number_of_pcs);
    _number_of_pcs += number_of_new_pcs;
}

double Holding::subtract(const unsigned int number_of_sold_pcs, const double price_per_pcs)
{
    if(number_of_sold_pcs > _number_of_pcs)
    {
        throw Holding_Error("Trying to sell more pcs than you own!");
    }
    double profit = (price_per_pcs -_mean_buying_price) * number_of_sold_pcs;
    _profit += profit;
    
    _number_of_pcs -= number_of_sold_pcs;
    return profit;
}

double  Holding::get_total_profit() const
{
    return _profit;
}

double Holding::get_mean_buying_price() const
{
    return _mean_buying_price;
}

unsigned int Holding::get_number_of_shares() const
{
    return _number_of_pcs;
}
