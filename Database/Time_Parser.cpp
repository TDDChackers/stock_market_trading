//
//  Time_Parser.cpp
//  Database_ver2
//
//  Created by Victor Birath on 2012-12-02.
//  Copyright (c) 2012 database. All rights reserved.
//

#include "Time_Parser.h"
#include <sstream>
#include <string>

namespace Time_Parser
{
    time_t time_parser(const std::string time_string,int hour,int min)
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
            year -=2000;
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
    
    std::string year(time_t timestamp)
    {
        struct tm * timeinfo;
        timeinfo = gmtime(&timestamp);
        return to_string(1900 +timeinfo->tm_year);
        
    }
    std::string month(time_t timestamp)
    {
        struct tm * timeinfo;
        timeinfo = gmtime(&timestamp);
        unsigned int iMonth = timeinfo->tm_mon;
        if (iMonth<10) {
            return ("0"+to_string(iMonth));
        }
        return to_string(iMonth);
    }
    std::string date(time_t timestamp)
    {
        struct tm * timeinfo;
        timeinfo = gmtime(&timestamp);
        unsigned int iDate = timeinfo->tm_mday;
        if (iDate<10) {
            return ("0"+to_string(iDate));
        }
        return to_string(iDate);
    }
    
    void increase_day(time_t& t)
    {
        t += 86400;
    }
}

std::string to_string(int i)
{
    std::stringstream ss;
    ss << i;
    return  ss.str();
}


