//
//  Database.h
//  database
//
//  Created by Victor Birath on 2012-11-04.
//  Copyright (c) 2012 Victor Birath. All rights reserved.
//

#ifndef __database__Database__
#define __database__Database__

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Stock.h"



class Database
{
    
public:
    Database();
    Database(Database&) = delete;
    ~Database();
    void update(std::string& stock_id,std::string& data);
    void import_file(std::string& path);
    void import_web(std::string& stock_id,time_t& from,time_t& to);
    bool is_id(const std::string& id);
    
    bool is_timestamp(const std::string& stock_id, time_t& t_);
    double get_latest_close_price(const std::string& stock_id);
    std::string* get_potential_ids();
    std::vector<std::string> get_ids();
    std::vector<double> get(std::string& id, time_t& timestamp);
    
private:
    std::map<std::string, Stock*> _Stocks;
    std::string POTENTIAL_IDS[7] = {"HPQ","CAT","INTC","IBM","GM","GOOG",""};

};

#endif /* defined(__database__Database__) */
