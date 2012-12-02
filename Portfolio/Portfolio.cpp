//
//  Portfolio.cpp
//  Portfolio
//
//  Created by Victor Birath on 2012-12-01.
//  Copyright (c) 2012 database. All rights reserved.
//

#include "Portfolio.h"
#include "Portfolio_Error.h"
#include <map>

void Portfolio::entry(const std::string stock_id, const int number_of_pcs, const double price_per_pcs)
{
    if (number_of_pcs < 0 || price_per_pcs < 0)
    {
        throw Portfolio_Error("Entry argument error!");
    }
    
    if (! (bool)_Portfolio.count(stock_id))
    {
        _Portfolio[stock_id] = new Holding(number_of_pcs,price_per_pcs);
    }
    else _Portfolio[stock_id]->entry(number_of_pcs, price_per_pcs);
    

    
}

double Portfolio::subtract(const std::string stock_id, const int number_of_pcs, const double price_per_pcs)
{
    if (! (bool)_Portfolio.count(stock_id))
    {
        throw Portfolio_Error(stock_id + " doesn't exist in portfolio");
        return -1;
    }
    else return _Portfolio[stock_id]->subtract(number_of_pcs, price_per_pcs);
}

double Portfolio::get_profit(const std::string stock_id) const
{
    if (! (bool)_Portfolio.count(stock_id))
    {
        throw Portfolio_Error(stock_id + " doesn't exist in portfolio");
        return -1;
    }
    else
    {
        const Holding* _Holding = (*_Portfolio.find(stock_id)).second;
        return _Holding->get_total_profit();
    }
}

unsigned int Portfolio::get_number_of_shares(const std::string stock_id) const
{
    if (! (bool)_Portfolio.count(stock_id))
    {
        throw Portfolio_Error(stock_id + " doesn't exist in portfolio");
        return -1;
    }
    else
    {
    const Holding* _Holding = (*_Portfolio.find(stock_id)).second;
    return _Holding->get_number_of_shares();
    }
}

double Portfolio::get_mean_buying_price(const std::string stock_id) const
{
    if (! (bool)_Portfolio.count(stock_id))
    {
        throw Portfolio_Error(stock_id + " doesn't exist in portfolio");
        return -1;
    }
    else
    {
        const Holding* _Holding = (*_Portfolio.find(stock_id)).second;
        return _Holding->get_mean_buying_price();
    }
}
/*
double Portfolio::get_balance() const
{
    return _balance;
}
*/