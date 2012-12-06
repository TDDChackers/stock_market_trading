//
//  Connector.h
//  Kommunikation_Test
//
//  Created by Victor Bergelin on 2012-11-05.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Kommunikation_Test_Connector_h
#define Kommunikation_Test_Connector_h

#include <vector>

class Connector
{
public:
    const char * Get_time_stamp();
    const char * To_base64(const char * convert);
    const char * From_base64(const char * convert);
    const char * To_uft8(const char * convert);
    const char * Get_system_info();
//    std::vector<double> 
    void Get_stock_data(std::string stock_name, unsigned long int timestamp);
    void Get_stock_data_socket(std::string stock_name, unsigned long int timestamp);
    void Clock_Network(int iterations);
    
protected:
    void                Send_message(int importance, std::string title, std::string message);
    const std::string   BASE_URL;
    const std::string   API_VERSION;
    std::string         Session_key;
    int Get_stock_nr(std::string stock_string);
};
#endif
