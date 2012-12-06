//
//  Holding.h
//  Portfolio
//
//  Created by Victor Birath on 2012-12-01.
//  Copyright (c) 2012 database. All rights reserved.
//

#ifndef __Portfolio__Holding__
#define __Portfolio__Holding__

#include <iostream>

class Holding {
    
public:
    Holding()  = delete;
    Holding(const unsigned int number_of_pcs, const double price_per_pcs);
    void            entry(const unsigned int number_of_pcs, const double price_per_pcs);
    double          subtract(const unsigned int number_of_pcs, const double price_per_pcs);
    double          get_total_profit() const;
    double          get_mean_buying_price() const;
    unsigned int    get_number_of_shares() const;
    
    
private:
    unsigned int    _number_of_pcs = 0;
    double          _mean_buying_price = 0;
    double          _profit = 0;
    
    
    
};

#endif /* defined(__Portfolio__Holding__) */
