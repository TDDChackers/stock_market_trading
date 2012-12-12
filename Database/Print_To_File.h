//
//  Print_To_File.h
//  Database_ver2
//
//  Created by Victor Birath on 2012-12-02.
//  Copyright (c) 2012 database. All rights reserved.
//

#ifndef __Database_ver2__Print_To_File__
#define __Database_ver2__Print_To_File__

#include <iostream>
#include <vector>

void Print_To_File(std::ofstream& file,unsigned long, std::vector<double>);
std::string make_file(std::string path, std::string stock_id);

#endif /* defined(__Database_ver2__Print_To_File__) */
