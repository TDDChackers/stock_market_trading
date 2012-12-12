//
//  Database.cpp
//  database
//
//  Created by Victor Birath on 2012-11-04.
//  Copyright (c) 2012 Victor Birath. All rights reserved.
//

#include "Database.h"
#include "Database_Error.h"
#include "Time_Parser.h"
#include "Stock.h"
#include "Stock_Error.h"
#include <map>
#include <string>
#include <fstream>
#include <stdexcept>


using namespace std;
Database::Database()
{
    std::string* ids = POTENTIAL_IDS;
    for(; (*ids) != "" ; ids++)
    {
        std::string id = (*ids);
        try
        {
            std::string path = id+".txt";
            import_file(path);
            
        }
        catch (const Database_Error& err)
        {;}
    }
}
Database::~Database()
{
    std::cout << "delete Database" << std::endl;
    std::map<std::string, Stock*>::iterator it;
    
    for (it = _Stocks.begin();
         it != _Stocks.end();
         it++)
    {
        std::cout << "delete a stock" << std::endl;
        std::cout << "delete " << (*it).first << std::endl;
        delete (*it).second;
    }
    std::cout << "End of delete Database" << std::endl;
}

void Database::update(std::string& id,std::string& data)
{
    //Kolla om aktien finns
    std::map<std::string, Stock*>::iterator it;
    it = _Stocks.find(id);
    if(it == _Stocks.end())
    {
        throw Database_Error("Trying to update non-existing share");
    }
    (*it).second->insert(data);
    
}

void Database::import_file(std::string& path)
{
    //läs sidhuvud.
    ifstream ifs(path.c_str());
    
    if(! ifs.good())
    {
        throw Database_Error("Path "+ path + " is not valid");
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
        try {
            string data;
            while (ifs >> data)
            {
                _stock->insert(data);
            }
        } catch (const exception& err)
        {
            delete _Stocks[stock_id];
#warning här ska det vara popup
            cout << "Data kunde inte lagaras för " + stock_id << ", därför raderas denna" << endl;
            throw Database_Error(err.what());
        }
        
    }
}

void Database::import_web(std::string& stock_id,time_t& from,time_t& to)
{
    if (! is_id(stock_id))
    {
        std::cout << "new Stock(stock_id)"<<stock_id << std::endl;
        _Stocks[stock_id] = new Stock(stock_id);
    }
    try
    {
        _Stocks[stock_id]->import_web_data(from, to);
    }
    catch (const Stock_Error& err)
    {
        throw Database_Error(err.what());
    }
    
}

bool Database::is_id(const string& id)
{
    bool c = (bool)_Stocks.count(id);
    return c;
}

bool Database::is_timestamp(const std::string& stock,time_t& t)
{
    if (is_id(stock))
    {
        return (bool)_Stocks[stock]->is_exists(t);
    }
    return false;
}

std::vector<double> Database::get(std::string& id, time_t& timestamp)
{
    return _Stocks[id]->get_data(timestamp);
}

std::vector<std::string> Database::get_ids()
{
    
    std::map<std::string, Stock*>::const_iterator it;
    
    std::vector<std::string> ids;
    
    for (it = _Stocks.begin(); it != _Stocks.end(); it++)
    {
        ids.push_back((*it).first);
    }
    return ids;
}

std::string* Database::get_potential_ids()
{
    return POTENTIAL_IDS;
}

double Database::get_latest_close_price(const std::string& stock_id)
{
    return _Stocks[stock_id]->get_latest_close_price();
}
