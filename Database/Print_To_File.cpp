//
//  Print_To_File.cpp
//  Database_ver2
//
//  Created by Victor Birath on 2012-12-02.
//  Copyright (c) 2012 database. All rights reserved.
//

//#include "Print_To_File.h"
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <fstream>
#include <vector>
#include <stdexcept>
#include "Time_Parser.h"
#include <iomanip>

using namespace Time_Parser;
void Print_To_File(std::ofstream& file,unsigned long timestamp, std::vector<double> data)
{
    unsigned int i;

    if (file.is_open())
    {
        //file.seekp(std::ios_base::end);
        file << year(timestamp) << "-" << month(timestamp)<< "-" << date(timestamp);
        file << std::setprecision(10);
        for (i = 1;  i < data.size(); i++)
        {
            file << "," << data[i];
        }
        file <<'\n';
    }
    else throw std::runtime_error("Can not print data");
    
}

std::string make_file(std::string path, std::string stock_id)
{
    path +="/Database";
    if ( mkdir((path).c_str(),0777) != 0)
    {
        throw std::runtime_error("Can not make file: " + path);
    }
    std::string filename = path+"/"+stock_id+".txt";
    std::ofstream ofs(filename.c_str());
    if (ofs)
    {
        ofs << "Date,Open,High,Low,Close,Volume,Adj Close" << std::endl;
        return (filename);
        
    }
    else
        throw std::runtime_error("Can not use file: " + path);
}
