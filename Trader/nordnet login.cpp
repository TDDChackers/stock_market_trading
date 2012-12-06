//
//  till nordnet.cpp
//  Kommunikation_Start
//
//  Created by Victor Bergelin on 2012-12-05.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

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
    
    
    //---------------------Http--------------------
    
    CkHttpRequest req_test;
    CkHttp http_test;
    
    http_test.put_SessionLogFilename("httpSessionLog.txt");
    
    bool success_test;
    
    //  Any string unlocks the component for the 1st 30-days.
    success_test = http_test.UnlockComponent("Anything for 30-day trial");
    if (success_test != true) {
        printf("%s\n",http_test.lastErrorText());
    }
    
    //  Build an HTTP POST Request:
    req_test.UsePost();
    req_test.put_ContentType("application/x-www-form-urlencoded");
    
    req_test.AddParam("service","NEXTAPI");
    req_test.AddParam("auth", url_to_post);
    
    const char * path_test = "/next/1/login";
    
    cout << "path: " << path_test << "\n" << endl;
    
    req_test.put_Path(path_test);
    
    //  Send the HTTP POST and get the response.  Note: This is a blocking call.
    //  The method does not return until the full HTTP response is received.
    
    const char * domain;
    long port;
    bool ssl;
    
    domain = "https://api.test.nordnet.se";
    port = 443;
    ssl = true;
    CkHttpResponse *resp = 0;
    resp = http_test.SynchronousRequest(domain,port,ssl,req_test);
    
    if (resp == 0 ) 
    {
        printf("Error: \n%s\n",http_test.lastErrorText());
    }
    else {
        //  Display the HTML page returned.
        printf("Svar: \n%s\n",resp_test->bodyStr());
    }
    
    delete resp_test;
}