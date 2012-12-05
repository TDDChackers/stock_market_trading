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

void Print_To_File(std::ofstream& ofs, std::vector<double> data)
{
    
    unsigned int i;
    if (ofs.good())
    {
        for (i = 0;  i < data.size(); i++)
        {
            ofs << data[i] << ",";
        }
        ofs << data[i]<<std::endl;
    }else std::cout << "Filen fakkar!" <<std::endl;

}

std::ofstream make_file(std::string path, std::string stock_id)
{
    path +="/Database";
    if ( mkdir((path).c_str(),0777) != 0)
    {
        std::cout<<"Mappen finns redan" << std::endl;
    }
    
    std::ofstream ofs(path+"/"+stock_id+".txt");
    if (ofs)
    {
        ofs << stock_id << std::endl;
        ofs << "Date,Open,High,Low,Close,Volume,Adj Close" << std::endl;
        return ofs;

    }
    
}