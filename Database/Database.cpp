





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
#include "Time_Parser.h"
//#include "Print_To_File.h"
using namespace std;

Database::~Database()
{
    std::map<std::string, Stock*>::iterator it;
    for ( it = _Stocks.begin();
         it != _Stocks.end(); it++)
    {
        delete (*it).second;
    }
}
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
    #warning import_web fungerar inte, det ska den inte heller!!
    //denna kod finns för att parametrarna ska annvändas. Den fungerar inte
    const std::string _stock_id = stock_id;
    time_t _from = from;
    _from = to;
    
    
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

double Database::get_latest_close_price(std::string stock_id)
{
    return _Stocks[stock_id]->get_latest_close_price();
}
