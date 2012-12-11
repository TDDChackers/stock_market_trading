//
//  Time_Parser.h
//  Database_ver2
//
//  Created by Victor Birath on 2012-12-02.
//  Copyright (c) 2012 database. All rights reserved.
//

#ifndef __database__Print_To_File__
#define __database__Print_To_File__

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

namespace Time_Parser
{
    time_t time_parser(const std::string time_string,int hour = 0,int min = 0);
    std::string year(time_t timestamp);
    std::string month(time_t timestamp);
    std::string date(time_t timestamp);
    int int_year(time_t timestamp);
    int int_month(time_t timestamp);
    int int_date(time_t timestamp);
    void increase_day(time_t& t);
}
    std::string to_string(int);
    int to_int(std::string);



#endif /* defined(__database__Print_To_File__) */
