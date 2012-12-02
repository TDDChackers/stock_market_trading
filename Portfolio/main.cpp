//
//  main.cpp
//  Portfolio
//
//  Created by Victor Birath on 2012-12-01.
//  Copyright (c) 2012 database. All rights reserved.
//

#include <iostream>
#include "Portfolio.h"

int main()
{

    Portfolio* My_Portfolio = new Portfolio();
    std::string stock_id = "Eric-b.ST";
    
    std::cout << "Buy 100 shares: " << stock_id << std::endl;
   
    My_Portfolio->entry(stock_id, 100, 10);
    
    std::cout << "Number of shares: ";
    std::cout << My_Portfolio->get_number_of_shares(stock_id) << std::endl;
    std::cout << "Mean Buying price: ";
    std::cout << My_Portfolio->get_mean_buying_price(stock_id) << std::endl;
    
    std::cout << "\nSell 50 shares 20 SEKpp!\n";
    std::cout << "Profit: ";
    std::cout << My_Portfolio->subtract(stock_id, 50, 20) << std::endl;
    
    std::cout << "\nSell 50 shares 10 SEKpp!\n";
    std::cout << "Profit: ";
    std::cout << My_Portfolio->subtract(stock_id, 50, 10) << std::endl;
    
    std::cout << "Total profit: ";
    std::cout << My_Portfolio->get_profit(stock_id) << std::endl;
    

    
    
    
    return 0;
}

