//
//  Login.h
//  Kommunikation_Test
//
//  Created by Victor Bergelin on 2012-11-05.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Kommunikation_Test_Login_h
#define Kommunikation_Test_Login_h

#include "Connector.h"

class Login : protected Connector
{
public:
    Login(std::string user, std::string pwd);

    std::string     get_username();
    void            Logout();
    void            Touch();
    
private:
    void            Try_Login();
    const char *    username;
    const char *    password;
    const char *    Create_login_format_string();
    const char *    Create_JSON_string(const char * encoded_string);
    const char *    Create_RSA_Encode(const char * login_string);
    std::string     Create_HTTP_Request(const char * json_string);
};
#endif
