//
//  Test2.cpp
//  Database_ver2
//
//  Created by Victor Birath on 2012-12-09.
//  Copyright (c) 2012 database. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <ctime>
#include "Database.h"
#include "Stock.h"
#include "Time_Parser.h"
#include "Stock_Error.h"
using namespace Time_Parser;

int main()
{
    Database* _Database = new Database();
    
    time_t from = Time_Parser::time_parser("2012-10-14");
    
    time_t from_later = Time_Parser::time_parser("2000-09-10");
    time_t to = Time_Parser::time_parser("2012-10-20");
    
    
    std::string _id = "GOOG";
    try {
        _Database->import_web(_id,from, to);
        std::cout << "First import done!" << std::endl;
        _Database->import_web(_id,from_later, to);
        std::cout << "Second import done!" << std::endl;

    } catch (const Stock_Error& err)
    {
        std::cout << err.what() << std::endl;
    }
    time_t test_time = Time_Parser::time_parser("2012-09-20");
        std::cout << "test: " << _Database->get(_id, test_time)[OPEN] << std::endl;

   
    
    
    
    delete _Database;
    
    _Database = new Database();
    
    //std::string* ids = _Database->get_potential_ids();
    
//    for(; (*ids) != "" ; ids++)
//    {
//        std::string id = (*ids);
//        
//    _Database->import_web(id,from, to);
//    
//    std::cout << "ID:" << id << std::endl;
//    time_t timestamp = time_parser("2011-10-21");
//    std::cout << "is timestamp?\"2011-10-21\"" << _Database->is_timestamp(id, timestamp) << std::endl;
//   
//    std::vector<double> data_vec =  _Database->get(id, timestamp);
//    
//    std::cout << "_Database->get(id, \"2011-10-21\")" << data_vec[3] << std::endl;
//    //std::cout << "get_latest_close_price: " <<  _Database->get_latest_close_price(id) << std::endl;
//   }
    std::cout << "THE END!! " << std::endl;

    delete _Database;
    return 0;
}
