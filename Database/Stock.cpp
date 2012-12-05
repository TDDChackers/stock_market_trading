//
//  Stock.cpp
//  database
//
//  Created by Victor Birath on 2012-11-04.
//  Copyright (c) 2012 Victor Birath. All rights reserved.
//

#include "Stock.h"
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "Stock_Error.h"
#include "Time_Parser.h"
//#include "Print_To_File.h"

using namespace Time_Parser;
using namespace std;
Stock::Stock(const string& name,const string& path)
:_name(name),_path(path)
{
    if (! _path.empty())
    {
        import_database(_path);
    }
    
}
Stock::~Stock()
{
//    std::ofstream ofs = make_file("/Users/victorbirath/Desktop/stock_market_trading-master/Database", _name);
//    for (std::map<time_t, std::vector<double> >::iterator it = _history.begin();
//         it != _history.end(); it++)
//    {
//        Print_To_File(ofs, (*it).second);
//    }
}
void Stock::insert(string data)
{
    stringstream ss(data);
    string timestamp;
    string stock_data;
    getline(ss, timestamp,',');
    getline(ss, stock_data,'\n');
    time_t id = time_parser(timestamp);
    if (_history.count(id))
        throw Stock_Error("Trying to update al ready existing timestamp ");
    else _history[id] = data_parser(stock_data);
    _latest_close_price = _history[id][CLOSE];
}

void Stock::import_database(const std::string path)
{
    ifstream ifs(path.c_str());
    if (!ifs.good())
    {
        throw Stock_Error("Can not read " + path + " to " + _name);
    }
    string stock_info;
    getline(ifs,stock_info,'\n');//Skip header
    getline(ifs,stock_info,'\n');//Skip header
    getline(ifs,stock_info,'\n');
    while (ifs.good()&& !ifs.eof())
    {
        
        
        insert(stock_info);
        getline(ifs,stock_info,'\n');
    }
    ifs.close();
    cout << "Map size is: " << _history.size() << endl;
}

bool Stock::is_exists(time_t t_)
{
    return (bool)_history.count(t_);
}

std::vector<double> Stock::get_data(const time_t timestamp)
{
    unsigned long x = _history.count(timestamp);
    if (x) {
        return _history[timestamp];
    }
    else
    {
        throw logic_error("Efterfrågad aktie finns inte i databasen");
    }
    
}
vector<double> Stock::data_parser(const string sData)
{
    stringstream ss(sData);
    vector<double> data(ADJ_CLOSE + 1,-1);
    for (int i = OPEN; i <= ADJ_CLOSE; i++)
    {   string value;
        getline(ss,value,',');
        double dValue =  atof(value.c_str());
        data[i] =dValue;
    }
    return data;
}
double Stock::get_latest_close_price() const
{
    return _latest_close_price;
}
