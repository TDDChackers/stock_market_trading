//
//  Portfolio.h
//  Portfolio
//
//  Created by Victor Birath on 2012-12-01.
//  Copyright (c) 2012 database. All rights reserved.
//

#ifndef __Portfolio__Portfolio__
#define __Portfolio__Portfolio__

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "Holding.h"

class Portfolio {
    
public:
    void entry(const std::string _stock_id, const int number_of_pcs, const double price_per_pcs);
    double subtract(const std::string _stock_id, const int number_of_pcs, const double price_per_pcs);
    double get_profit(const std::string stock_id) const;
    unsigned int get_number_of_shares(const std::string stock_id) const;
    double get_mean_buying_price(const std::string stock_id) const;
    std::vector<std::string> get_ids() const;
    double get_balance() const;

private:
    std::map<const std::string,Holding*> _Portfolio;
    
    double  _balance = 0;
};
    
#endif /* defined(__Portfolio__Portfolio__) */
