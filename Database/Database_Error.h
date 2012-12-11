//
//  Database_Error.h
//  Database_ver2
//
//  Created by Victor Birath on 2012-12-11.
//  Copyright (c) 2012 database. All rights reserved.
//

#ifndef __Database_ver2__Database_Error__
#define __Database_ver2__Database_Error__

#include <iostream>
#include <stdexcept>

class Database_Error : public std::runtime_error
{
public:
    explicit Database_Error(const std::string& what_arg)
    : std::runtime_error(what_arg) {};
    
};
#endif /* defined(__Database_ver2__Database_Error__) */
