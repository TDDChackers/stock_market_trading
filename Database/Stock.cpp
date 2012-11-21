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

using namespace std;
Stock::Stock(const string& name,const string& path)
:_name(name),_path(path)
{
    if (! _path.empty())
    {
        import_database(_path);
    }
    
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
time_t Stock::time_parser(const std::string time_string,int hour,int min)
{
    if (0 > hour || hour >23 ||
        0 > min  || min  >59)
    {
    //Kasta fel
    }
    std::stringstream ss(time_string);
    std::string  y,m,d;
    getline(ss,y,'-');
    getline(ss,m,'-');
    getline(ss,d,'-');
    
    time_t rawtime;
    struct tm * timeinfo;
    
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    int year = atoi(y.c_str()); // fullösning, akta https://www.msb.se/RibData/Filer/pdf/20259.pdf

    if (year > 1900)
        year -=1900;
    if (0 <= year <50) {
        year += 100;
    }
    
    timeinfo->tm_year = year;
    timeinfo->tm_mon = atoi(m.c_str())-1; // fullösning, akta https://www.msb.se/RibData/Filer/pdf/20259.pdf
    timeinfo->tm_mday = atoi(d.c_str());
    timeinfo->tm_hour = hour;
    timeinfo->tm_min  = min;
    timeinfo->tm_sec  = 0;
    
    return mktime(timeinfo);
}
