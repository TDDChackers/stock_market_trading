//
//  Stock.cpp
//  database
//
//  Created by Victor Birath on 2012-11-04.
//  Copyright (c) 2012 Victor Birath. All rights reserved.
//

#include "Stock.h"
#include <ctime>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "Stock_Error.h"
#include "Time_Parser.h"
#include <cstdlib>
#include <CkHttp.h>
#include <CkString.h>
#include "Print_To_File.h"

using namespace Time_Parser;
using namespace std;
Stock::Stock(const string& name,const string& path)
:_name(name),_path(path)
{
    _history = new std::map<time_t, std::vector<double> >;
    if (! _path.empty())
    {
        import_database(_path);
    }
    
}

Stock::~Stock()
{
       std::cout << "deleting Stock" << std::endl;
    std::ofstream file;
#warning Denna variabel ska sättas genom GUI.
    std::string path = _name+".txt";
    file.open((path.c_str()));
        for (std::map<time_t, std::vector<double> >::iterator it = _history->begin();
             it != _history->end();
             it++)
        {
            try
            {
                Print_To_File(file, (*it).first, (*it).second);
            }
            catch (const runtime_error& err)
            {
                #warning Här ska det vara popup
                cout << err.what() << endl;
            }
        
        }
    delete _history;
}

void Stock::insert(const string& data)
{
    stringstream ss(data);
    string timestamp;
    string stock_data;
    getline(ss, timestamp,',');
    getline(ss, stock_data,'\n');
    time_t id = time_parser(timestamp);
    if (! (bool)_history->count(id))
    {
        
        _history->operator[](id) = data_parser(stock_data);
    }
    if ( id > _timestamp_latest_close_price)
    {
        _latest_close_price = _history->at(id)[CLOSE];
        _timestamp_latest_close_price = id;
        
    }
    std::cout << "_history[id]" << _history->at(id)[CLOSE] << std::endl;
}

void Stock::import_database(const std::string& path)
{
    ifstream ifs(path.c_str());
    if (!ifs.good())
    {
        throw Stock_Error("Can not read " + path + " to " + _name);
    }
    string stock_info;
    getline(ifs,stock_info,'\n');
    while (ifs.good()&& !ifs.eof())
    {
        insert(stock_info);
        getline(ifs,stock_info,'\n');
    }
    ifs.close();
    cout << "Map size is: " << _history->size() << endl;
}

bool  Stock::is_exists(const time_t & timestamp)
{
    return (bool)_history->count(timestamp);
}

std::vector<double> Stock::get_data(const time_t& timestamp)
{
    if (is_exists(timestamp))
    {
        return _history->at(timestamp);
    }
    else
    {
        std::cout << "Efterfrågad aktie finns inte i databasen" << std::endl;
        throw logic_error("Efterfrågad aktie finns inte i databasen");
    }
    
}

vector<double> Stock::data_parser(const string& sData)
{
    stringstream ss(sData);
    vector<double> data(VOLUME,-1);
    for (int i = OPEN; i <= VOLUME; i++)
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

void Stock::import_web_data(time_t from, time_t to)
{
    const char* http_charptr = 0;
     std::cout << "from = " << from << ",To = " << to << std::endl;
    
    int from_mday, from_mon,from_year;
    
    from_mday = int_date(from);
    from_mon  = int_month(from);
    from_year = int_year(from);
    
    int to_mday, to_mon,to_year;
    to_mday = int_date(to);
    to_mon  = int_month(to);
    to_year = int_year(to);
    
    
    if (from == to) {
        std::cout << "From == to!!" << std::endl;
    }
    std::string http_string = make_http_str(_name,from_mday,from_mon,from_year,to_mday,to_mon,to_year);
    
    std::cout << "Downloading: " << http_string << std::endl;
    
    CkHttp http;
    
    bool sucess = 0;
    sucess =   http.UnlockComponent("Anything for 30-day trial");
    
    if (! sucess)
    {
        printf("%s\n",http.lastErrorText());
    }
    
    char* data =0;
    data = (char*) malloc (5000);
    data = (char*)http.quickGetStr(http_string.c_str());
    std::cout << "Html get complete: " << std::endl;
    if (data[0] == '<')
    {
        throw Stock_Error("Downloading data error");
    }
    std::cout << "Html print complete: " << std::endl;
    
    
    for (;data[0] != '\n';data++)
    {
        ;
        
    }
    data++;// skip headder

    for (; data[0] != 0;data++)
    {
        std::string data_line = "";
        for (;data[0] != '\n';data++)
        {
            data_line.push_back(data[0]);
        }
        insert(data_line);
        std::cout << data_line << std::endl;
    }
}

std::string Stock::make_http_str(std::string ID,int _from_mady,int _from_month,int _from_year,int _to_mady,int _to_month,int _to_year)
{
    std::cout << _from_mady <<  _from_month <<  _from_year<< _to_mady<< _to_month<< _to_year <<  std::endl;
    std::string sFrom_Day = to_string(_from_mady);
    std::string sFrom_Month = to_string(_from_month-1);
    std::string sFrom_Year = to_string(_from_year);
    
    std::string sTo_Day = to_string(_to_mady);
    std::string sTo_Month = to_string(_to_month-1);
    std::string sTo_Year = to_string(_to_year);
    
    std::string str = "http://ichart.yahoo.com/table.csv?s=";
    str.append(ID);
    str.append("&a=");
    str.append(sFrom_Month);
    str.append("&b=");
    str.append(sFrom_Day);
    str.append("&c=");
    str.append(sFrom_Year);
    
    str.append("&d=");
    str.append(sTo_Month);
    str.append("&e=");
    str.append(sTo_Day);
    str.append("&f=");
    str.append(sTo_Year);
    
    str.append("&ignore=.csv&g=d");
    
    return str;
}

