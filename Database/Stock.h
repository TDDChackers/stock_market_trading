//
//  Stock.h
//  database
//
//  Created by Victor Birath on 2012-11-04.
//  Copyright (c) 2012 Victor Birath. All rights reserved.
//

#ifndef __database__Stock__
#define __database__Stock__

#include <iostream>
#include <string>
#include <map>
#include <vector>

enum stock_data_index
{
    DATE = 0,
    OPEN = 1,
    HIGH = 2,
    LOW = 3,
    CLOSE= 4,
    VOLUME=5,
    ADJ_CLOSE = 6
};

class Stock {
    
    
public:
//    Stock() = delete;
    Stock(const std::string& name,const std::string& path = "");
    void insert(const std::string data);
    void import_database(const std::string path);
    std::vector<double> get_data(const time_t timestamp);
    static time_t time_parser(const std::string time_string,int hour = 0,int min = 0);
    static std::vector<double> data_parser(const std::string data);
    bool is_exists(time_t);
    
private:
    std::string _name;
    std::string _path;
    std::map<time_t, std::vector<double> > _history;
    
    
    
    
    

};
//end_namespace?
#endif /* defined(__database__Stock__) */
