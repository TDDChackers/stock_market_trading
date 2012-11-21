





//
//  Database.cpp
//  database
//
//  Created by Victor Birath on 2012-11-04.
//  Copyright (c) 2012 Victor Birath. All rights reserved.
//

#include "Database.h"
#include <map>
#include <string>
#include <fstream>
using namespace std;

void Database::update(std::string id,std::string data)
{
    //Kolla om aktien finns
    std::map<std::string, Stock*>::iterator it;
    it = _Stocks.find(id);
    if(it == _Stocks.end())
    {
        //Kasta fel.
    }
    (*it).second->insert(data);
        
}
void Database::import_file(std::string path)
{
    //läs sidhuvud.
    ifstream ifs(path.c_str());
    
    if(! ifs.good())
    {
        //Kasta fel!
    }
    string stock_id;
    ifs >> stock_id;
    Stock* _stock;
    
    if (! is_id(stock_id))
    {
        _Stocks[stock_id] = new Stock(stock_id,path);
        
    }
    else
    { 
        _stock = _Stocks[stock_id];
        
        string data;
        while (ifs >> data)
        {
            _stock->insert(data);
        }
    }
}
void import_web(const std::string stock_id,const time_t from,const time_t to,const float freq)
{
    //Vänta med denna.
}

bool Database::is_id(string id)
{
    bool c = (bool)_Stocks.count(id);
    return c;
}

bool Database::is_timestamp(std::string stock_,time_t t_)
{
    if (is_id(stock_))
    {
        return (bool)_Stocks[stock_]->is_exists(t_);
    }
    return false;
}

std::vector<double> Database::get(std::string id, time_t timestamp)
{
    return _Stocks[id]->get_data(timestamp);
}