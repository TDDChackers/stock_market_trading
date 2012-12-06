
//
//  Login.cc
//  Kommunikation_Test
//
//  Created by Victor Bergelin on 2012-11-05.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <time.h>
#include <time.h>
#include <sstream>
#include <string.h>
#include <string>
#include <stdio.h>

#include <CkHttpRequest.h>
#include <CkHttp.h>
#include <CkHttpResponse.h>
#include <CkCrypt2.h>
#include <CkRsa.h>

#include "Login.h"
#include "Login_error.h"
#include "Connector.h"

const bool _DEBUG = 1;
using namespace std;

Login::Login(string user, string pwd)
{
    username = user.c_str();
    password = pwd.c_str();
    
    try 
    {
        Try_Login();
    } 
    catch (const Login_error& err) 
    {
        cout << "Problem with Login: " << err.what() << endl;
    }
}

string Login::get_username()
{
    string string_to_return(username);
    return string_to_return;
}

void Login::Try_Login()
{    
    //--------------------------------TIME-----------------
    
    time_t rawtime;
    time (&rawtime);
    
    stringstream ss;
    ss << rawtime;
    string timestamp = ss.str() + "000";
    const char * time_c_str = timestamp.c_str();
    
    //--------------------------------PRINT----------------
    
    cout << "\n\n--------------------------------\nUsername: " << username 
    << "\nPassword: " << password << "\nTime: " << timestamp <<  "\n--------------------------------\n\n" << endl;
    
    //--------------------------------BASE64---------------
    //                         Username
    
    CkCrypt2 crypt;
    
    bool success_crypt;
    
    success_crypt = crypt.UnlockComponent("Anything for 30-day trial");
    if (success_crypt != true)
    {
        printf("RSA component unlock failed\n\n");
        return;
    }
    
    //  Indicate that no encryption should be performed,
    //  only encoding/decoding.
    crypt.put_CryptAlgorithm("none");
    crypt.put_EncodingMode("Base64");
    
    //  Other possible EncodingMode settings are:
    //  "quoted-printable", "hex", "uu", "base32", and "url"
    
    CkString strBase64;
    
    crypt.EncodeString(username, "utf-8", "base64", strBase64);
    
    const char * UserPrintStr = strBase64.getEnc("utf-8");    
    
    printf("Username: %s\n\n",UserPrintStr);
    
    
    //                         Password
    
    CkCrypt2 crypt_pwd;
    
    bool success_crypt_pwd;
    
    success_crypt_pwd = crypt_pwd.UnlockComponent("Anything for 30-day trial");
    if (success_crypt_pwd != true)
    {
        printf("RSA component unlock failed\n\n");
        return;
    }
    
    //  Indicate that no encryption should be performed,
    //  only encoding/decoding.
    crypt_pwd.put_CryptAlgorithm("none");
    crypt_pwd.put_EncodingMode("Base64");
    
    //  Other possible EncodingMode settings are:
    //  "quoted-printable", "hex", "uu", "base32", and "url"
    
    CkString strBase64_pwd;
    
    crypt_pwd.EncodeString(password, "utf-8", "base64", strBase64_pwd);
    
    const char * printStr_pwd = strBase64_pwd.getEnc("utf-8");    
    
    printf("Password: %s\n\n",printStr_pwd);
    
    
    //                         Time stamp
    
    CkCrypt2 crypt_time;
    
    bool success_crypt_time;
    
    success_crypt_time = crypt_time.UnlockComponent("Anything for 30-day trial");
    if (success_crypt_time != true)
    {
        printf("RSA component unlock failed\n\n");
        return;
    }
    
    //  Indicate that no encryption should be performed,
    //  only encoding/decoding.
    crypt_time.put_CryptAlgorithm("none");
    crypt_time.put_EncodingMode("Base64");
    
    //  Other possible EncodingMode settings are:
    //  "quoted-printable", "hex", "uu", "base32", and "url"
    
    CkString strBase64_time;
    
    crypt_time.EncodeString(time_c_str, "utf-8", "base64", strBase64_time);
    
    const char * printStr_time = strBase64_time.getEnc("utf-8");    
    
    printf("Time Stamp: %s\n\n",printStr_time);
    
    
    //--------------------------------Concatinate----------
    
    char concat_str[200];
    strcpy (concat_str, UserPrintStr);
    strcat (concat_str, ":");
    strcat (concat_str, printStr_pwd);
    strcat (concat_str, ":");
    strcat (concat_str, printStr_time);
    
    cout << "Concatinated formated string: " << concat_str << "\n" << endl;
    
    
    //--------------------------------BASE64---------------
    //                         concatinated
    CkCrypt2 crypt_conc;
    
    bool success_conc;
    
    success_conc = crypt_conc.UnlockComponent("Anything for 30-day trial");
    if (success_conc != true)
    {
        printf("RSA component unlock failed\n\n");
        return;
    }
    
    //  Indicate that no encryption should be performed,
    //  only encoding/decoding.
    crypt_conc.put_CryptAlgorithm("none");
    crypt_conc.put_EncodingMode("Base64");
    
    //  Other possible EncodingMode settings are:
    //  "quoted-printable", "hex", "uu", "base32", and "url"
    
    CkString strBase64_conc;
    
    crypt_conc.EncodeString(concat_str, "utf-8", "base64", strBase64_conc);
    
    const char * UserPrintStr_conc = strBase64_conc.getEnc("utf-8");    
    
    printf("Base64 formated concatinated string: %s\n\n",UserPrintStr_conc);    
    
    //--------------------------------Rsa------------------
    
    CkRsa rsa;
    
    bool success;
    success = rsa.UnlockComponent("Anything for 30-day trial");
    if (success != true) {
        printf("RSA component unlock failed\n\n");
        return;
    }
    
    //  RSA public key in XML format:    
    const char * publicKey;
    publicKey = "<RSAKeyValue><Modulus>5td/64fAicX2r8sN6RP3mfHf2bcwvTzmHrLcjJbU85gLROL+IXclrjWsluqyt5xtc/TCwMTfC/NcRVIAvfZdt+OPdDoO0rJYIY3hOGBwLQJeLRfruM8dhVD+/Kpu8yKzKOcRdne2hBb/mpkVtIl5avJPFZ6AQbICpOC8kEfI1DHrfgT18fBswt85deILBTxVUIXsXdG1ljFAQ/lJd/62J74vayQJq6l2DT663QB8nLEILUKEt/hQAJGU3VT4APSfT+5bkClfRb9+kNT7RXT/pNCctbBTKujr3tmkrdUZiQiJZdl/O7LhI99nCe6uyJ+la9jNPOuK5z6v72cXenmKZw==</Modulus><Exponent>AQAB</Exponent></RSAKeyValue>";
    
    bool success_key;
    
    success_key = rsa.ImportPublicKey(publicKey);
    if (success != true) {
        printf("RSA PublicKey failed.\n\n");
        return;
    }

    //  Use the utf-8 character encoding.  When encrypting, the
    //  plain text is first converted to utf-8 bytes and then
    //  RSA encrypted.
    rsa.put_Charset("utf-8");
    
    //  Encrypt a string and return the encrypted data base64-encoded:
    rsa.put_EncodingMode("base64");
    
    bool usePrivateKey;
    usePrivateKey = false;
    const char * encryptedStr;
    encryptedStr = rsa.encryptStringENC(UserPrintStr_conc,usePrivateKey);
    printf("Encrypted (RSA) string : %s\n\n",encryptedStr);
    
    //------------url-format------------------
    
    CkString ckstring;
    
    ckstring = encryptedStr;
    
    ckstring.urlEncode("utf8");
    
    const char * url_to_post = ckstring.getEnc("utf8");
    
    cout << "url_to_post: " << url_to_post << "\n" << endl;
    
    
    //------------Http-TEST------------------
    
    CkHttpRequest req;
    CkHttp http;
    
    // Save session log:
    http.put_SessionLogFilename("httpSessionLog.txt");
    
    bool success_http;
    
    //  Any string unlocks the component for the 1st 30-days.
    success_http = http.UnlockComponent("Anything for 30-day trial");
    if (success_http != true) {
        printf("%s\n",http.lastErrorText());
    }
    
    //  Build an HTTP POST Request:    
    req.UsePost();
    
    req.put_ContentType("application/x-www-form-urlencoded");
    
    req.AddParam("service","NEXTAPI");
    req.AddParam("auth", url_to_post);
    
    const char * path = "/next/1/login";
    
    cout << "path: " << path << "\n" << endl;
    
    req.put_Path(path);
    
    //  Send the HTTP POST and get the response.  Note: This is a blocking call.
    //  The method does not return until the full HTTP response is received.
    const char * domain;
    long port;
    bool ssl;

    domain = "https://api.test.nordnet.se";
    port = 443;
    ssl = true;
    CkHttpResponse *resp = 0;
    resp = http.SynchronousRequest(domain,port,ssl,req);
    
    if (resp == 0 ) 
    {
        printf("Error: \n%s\n",http.lastErrorText());
    }
    else {
        //  Display the HTML page returned.
        printf("Svar: \n%s\n",resp->bodyStr());
    }
    
    //------------Svar från Nordnet----------------
    //resp_test.
    
    // Få ut Session_key med en parser
    
    
    delete resp;    
}

void Login::Logout()
{
    CkHttpRequest req_test;
    CkHttp http_test;
    
    bool success_test;
    
    //  Any string unlocks the component for the 1st 30-days.
    success_test = http_test.UnlockComponent("Anything for 30-day trial");
    if (success_test != true) {
        printf("%s\n",http_test.lastErrorText());
    }
    
    stringstream ss_test;
    ss_test << "/next/1/login/" << Session_key;
    const char * path_test = ss_test.str().c_str();
    cout << "path: " << path_test << "\n" << endl;
    
    //  Build an HTTP POST Request:    
    req_test.put_HttpVerb("DELETE");
    req_test.put_ContentType("application/x-www-form-urlencoded");
    req_test.put_Path(path_test);
    http_test.put_SessionLogFilename("httpSessionLog.txt");
    
    //  Send the HTTP POST and get the response.  Note: This is a blocking call.
    //  The method does not return until the full HTTP response is received.
    const char * domain;
    long port;
    bool ssl;
    
    domain = "https://api.test.nordnet.se";
    port = 443;
    ssl = true;
    CkHttpResponse *resp_test = 0;
    resp_test = http_test.SynchronousRequest(domain,port,ssl,req_test);
    
    if (resp_test == 0 ) 
    {
        printf("Error: \n%s\n",http_test.lastErrorText());
    }
    else {
        //  Display the HTML page returned.
        printf("Svar: \n%s\n",resp_test->bodyStr());
    }
    
    delete resp_test;
}

void Login::Touch()
{
    CkHttpRequest req_test;
    CkHttp http_test;
    
    bool success_test;
    
    //  Any string unlocks the component for the 1st 30-days.
    success_test = http_test.UnlockComponent("Anything for 30-day trial");
    if (success_test != true) {
        printf("%s\n",http_test.lastErrorText());
    }
    
    stringstream ss_test;
    ss_test << "/next/1/login/" << Session_key;
    const char * path_test = ss_test.str().c_str();
    cout << "path: " << path_test << "\n" << endl;
    
    //  Build an HTTP POST Request:    
    req_test.put_HttpVerb("PUT");
    req_test.put_ContentType("application/x-www-form-urlencoded");
    req_test.put_Path(path_test);
    http_test.put_SessionLogFilename("httpSessionLog.txt");
    
    //  Send the HTTP POST and get the response.  Note: This is a blocking call.
    //  The method does not return until the full HTTP response is received.
    const char * domain;
    long port;
    bool ssl;
    
    domain = "https://api.test.nordnet.se";
    port = 443;
    ssl = true;
    CkHttpResponse *resp_test = 0;
    resp_test = http_test.SynchronousRequest(domain,port,ssl,req_test);
    
    if (resp_test == 0 ) 
    {
        printf("Error: \n%s\n",http_test.lastErrorText());
    }
    else {
        //  Display the HTML page returned.
        printf("Svar: \n%s\n",resp_test->bodyStr());
    }
    
    delete resp_test;
}

/*
const char * Login::Create_login_format_string()
{
    stringstream ss;

    const char * timestamp = Get_time_stamp();
    
    const char * timestamp_convert;
    const char * username_convert;
    const char * password_convert;

    timestamp_convert = "MTM1MzI1MTgwNzAwMA==";
    cout << "timestamp: " << To_base64_time() << endl;

    cout << "timestamp_convert: " << timestamp_convert << "\n" << endl;
    cout << "username: " << username << "\n" << endl;
    cout << "password: " << password << "\n" << endl;
    
    
    username_convert = "VmljdG9yQmVyZ2VsaW4=";
    password_convert = "QUJDMTIz"; 
    
//    timestamp_convert = To_base64_time();
    
    cout << "\nPre stringstream print: " << username_convert << ":" << password_convert
    << ":" << timestamp_convert << endl;
    
    ss << username_convert << ":" << password_convert << ":" << timestamp_convert; 
    
    const char * string = ss.str().c_str();

    if (_DEBUG) 
    {
        cout << "Converted string: \"";
        cout << string << "\n" << endl;   
    }
    
    return string;
}

const char * Login::Create_RSA_Encode(const char * login_string2)
{
    if(_DEBUG)
    {
        cout << "Innan RSA, login_string: " << login_string2 << endl;
    }
    
    CkRsa rsa;

    cout << "Error: " << rsa.lastErrorText() << endl;
    
    if(_DEBUG)
    {
        cout << "Efter RSA, login_string: " << login_string2 << endl;
    }
    
    bool success;
    success = rsa.UnlockComponent("Anything for 30-day trial");
    if (success != true) 
    {
        printf("RSA component unlock failed\n");
        return "RSA Problem";
    }
    
    if(_DEBUG)
    {
        cout << login_string2 << endl;
    }
    
    if(0)
    {
        const char * url2 = "FFdRyiv0KDrU1ZAlk%2BobxM%2B8jBcPyiVMl79%2FtlYxXsUqqBODUW1j77xzJURQ0Cb3xU0MuKFkWUCqdZHclod5KS5HjZ5ZwnRy8XqMCCzXabhRkwU6tsGd21WaZBAV7kPnQag3U2WoAjHjDpbmHhUN9OnCTC%2FKfiSSBmru0dE4DTs%3D";
        return url2; 
    }
    
    const char * PUBLIC_KEY = "<?xml version=\"1.0\"?><RSAParameters xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><Exponent>AQAB</Exponent><Modulus>5td/64fAicX2r8sN6RP3mfHf2bcwvTzmHrLcjJbU85gLROL+IXclrjWsluqyt5xtc/TCwMTfC/NcRVIAvfZdt+OPdDoO0rJYIY3hOGBwLQJeLRfruM8dhVD+/Kpu8yKzKOcRdne2hBb/mpkVtIl5avJPFZ6AQbICpOC8kEfI1DHrfgT18fBswt85deILBTxVUIXsXdG1ljFAQ/lJd/62J74vayQJq6l2DT663QB8nLEILUKEt/hQAJGU3VT4APSfT+5bkClfRb9+kNT7RXT/pNCctbBTKujr3tmkrdUZiQiJZdl/O7LhI99nCe6uyJ+la9jNPOuK5z6v72cXenmKZw==</Modulus></RSAParameters>";

    
    CkRsa rsa2;
    rsa2.UnlockComponent("Anything for 30-day trial");
    
    //  Encrypted output is always binary.  In this case, we want
    //  to encode the encrypted bytes in a printable string.
    //  Our choices are "hex", "base64", "url", "quoted-printable".
    rsa2.put_EncodingMode("base64");
    
    //  We'll encrypt with the public key and decrypt with the private
    //  key.  It's also possible to do the reverse.
    rsa2.ImportPublicKey(PUBLIC_KEY);
    
    bool usePrivateKey;
    usePrivateKey = false;
    
    const char * encryptedStr;
    
    
    encryptedStr = rsa2.encryptStringENC(login_string2,usePrivateKey);

    if (_DEBUG) 
    {
        cout << "RSA-encrypted string (base64): " << login_string2 << " -> " << encryptedStr << "\n" << endl;
    }


    CkCrypt2 crypt;
    
    bool success2;

    success2 = crypt.UnlockComponent("Anything for 30-day trial");
    if (success2 != true) 
    {
        cout << "\nRSA FAILED" << endl;
        return "fail fail fail";
    }
    
    
    
    crypt.put_CryptAlgorithm("none");
    crypt.put_EncodingMode("url");
    
    const char * url;
    url = crypt.encryptStringENC(encryptedStr);
    if (_DEBUG) 
    {
        cout << "Encrypted string (base64 and url): " << url << "\n" << endl;
    }

    
    if(0)
    {
        const char * url2 = "FFdRyiv0KDrU1ZAlk%2BobxM%2B8jBcPyiVMl79%2FtlYxXsUqqBODUW1j77xzJURQ0Cb3xU0MuKFkWUCqdZHclod5KS5HjZ5ZwnRy8XqMCCzXabhRkwU6tsGd21WaZBAV7kPnQag3U2WoAjHjDpbmHhUN9OnCTC%2FKfiSSBmru0dE4DTs%3D";
        return url2; 
    }
  
     return url;

}


const char * Login::Create_JSON_string(const char * encoded_string)
{
    stringstream ss;
    ss << "{\"cmd\":\"login\", \"args\":{ \"session_key\":\"" 
    << encoded_string << "\", \"service\":\"NEXTAPI\" }}";
    
    const char * string = ss.str().c_str();
    
    return string;
}

string Login::Create_HTTP_Request(const char * json_string)
{
    CkHttpRequest req;
    CkHttp http;
    
    bool success;
    
    success = http.UnlockComponent("Anything for 30-day trial");
    if (success != true) 
    {
        throw Login_error("Problem med CHILKAT");
    }
    
    http.put_AcceptCharset("");
    http.put_UserAgent("");
    http.put_AcceptLanguage("");
    
    http.put_AllowGzip(false);
    
    // ***
    //  If a Cookie needs to be added, it may be added by calling
    //  AddQuickHeader:
    //    http.AddQuickHeader("Cookie","JSESSIONID=1234");
    
    //  To use SSL/TLS, simply use "https://" in the URL.
    
    if (0) 
    {
        // Strängen som den ska se ut; Men med gammal tidsstämpel...
        json_string = "qqTYTnxkB8UQTpwR%2Fe4OhAusJ1EmfLcBiPcYRxngMdoub3SLEyf9hrEBwtoIZAeXcyuWwSeHuOhOkHmFsU%2FiAwiceJqQgresW9ENg7XSzxSJrjrCTe4OewfYxgH9Zzooqh9zJ7Z3BAS96RSbhMHBKyVfbwwdLT4VbgnV6EvsJN4%3D";
    }
    
    CkHttpResponse * resp = 0;
    
    // Testsystemet: "https://api.test.nordnet.se/next/1/login"
    resp = http.PostJson("https://api.nordnet.se/next/1/login",json_string);
    
    if (resp == 0 ) 
    {
        if (_DEBUG) 
        {
            cout << "_DEBUG: Felrapport från Nordnet API: " << string(http.lastErrorText()) << endl;
           // return "Fail";
        }
        else
        {
            string error = "Login fail:\n" + string(http.lastErrorText());
            throw Login_error(error); //http.lastErrorText());
        }
    }    
     
    stringstream ss;
    // ***
    ss << resp->bodyStr();
    
    string respons;
    
    respons = ss.str();
    
    if(_DEBUG)
    {
        cout << "Svar från Nordnet:\n" << respons << endl;   
    }
    
	return respons;
}

*/