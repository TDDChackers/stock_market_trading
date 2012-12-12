//
//  Stock.h
//  database
//
//  Created by Victor Birath on 2012-11-04.
//  Copyright (c) 2012 Victor Birath. All rights reserved.
//
//  Stock is a class which delivers historical data for
//  a stock. Stock can download data  
//
//

#ifndef __database__Stock__
#define __database__Stock__

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <ctime>


enum stock_data_index
{
    DATE = 0, // för framtida användning
    OPEN = 1,
    HIGH = 2,
    LOW =  3,
    CLOSE= 4,
    VOLUME=5
};

class Stock {
    
public:
    ~Stock();
    Stock() = delete;
    Stock(const std::string& name,const std::string& path = "");
    void    insert(const std::string& data);
    void    import_database(const std::string& path);
    bool    is_exists(const time_t& t_);
    double  get_latest_close_price() const;
    void import_web_data(time_t from, time_t to);

    std::string make_http_str(std::string ID,int _from_mady,int _from_month,int _from_year,int _to_mady,int _to_month,int _to_year);
    
    std::vector<double>         get_data(const time_t& timestamp);
    static std::vector<double>  data_parser(const std::string& data);
    
private:
    std::string     _name;
    std::string     _path;
    double          _latest_close_price = -1;
    time_t          _timestamp_latest_close_price = -1;
    time_t          _timestamp_oldest_close_price = 10000000000000000;
    
    std::map<time_t, std::vector<double> >* _history;
    
    void correct_timestamps(time_t& from, time_t& to);
    
};
#endif /* defined(__database__Stock__) */
