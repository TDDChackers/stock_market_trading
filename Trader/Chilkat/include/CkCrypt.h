// CkCrypt.h: interface for the CkCrypt class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _CKCRYPT_H
#define _CKCRYPT_H



#ifdef WIN32
class CkCSP;
#endif

class CkCert;
class CkCertStore;
#include "CkString.h"
class CkByteData;
#include "CkMultiByteBase.h"

#ifndef __sun__
#pragma pack (push, 8)
#endif
 

// CLASS: CkCrypt
class CkCrypt  : public CkMultiByteBase
{
    private:
	// Don't allow assignment or copying these objects.
	CkCrypt(const CkCrypt &) { } 
	CkCrypt &operator=(const CkCrypt &) { return *this; }
	CkCrypt(void *impl);

    public:

	CkCrypt();
	virtual ~CkCrypt();

	// BEGIN PUBLIC INTERFACE


#if defined(WIN32) && !defined(__MINGW32__)
	bool SetCSP(const CkCSP *csp);
	bool SetCSP(const CkCSP &csp) { return SetCSP(&csp); }
#endif
	void SetAlgorithmRSA();
	void SetAlgorithmTwofish();
	void SetAlgorithmBlowfish();
	void SetAlgorithmRijndael();

#if defined(WIN32) && !defined(__MINGW32__)
	bool AddSearchCertStore(const CkCertStore *certStore);
#endif

	void SetEncryptCertificate(const CkCert *cert);
	void SetSigningCertificate(const CkCert *cert);

	bool UnlockComponent(const char *unlockCode);
	bool IsUnlocked(void) const;

	void get_LastCertSubject(CkString &str);
	void get_LastAlgorithm(CkString &str);

	void get_SigningCertSubject(CkString &str);
	void put_SigningCertSubject(const char *str);

	void get_EncryptCertSubject(CkString &str);
	void put_EncryptCertSubject(const char *str);

	//bool get_UseStandardSearchCertStores(void);
	//void put_UseStandardSearchCertStores(bool newVal);

	// Key length is implied by the length of the secret key.
	void get_SecretKey(CkByteData &data);
	void put_SecretKey(const unsigned char *data, unsigned long dataLen);

	// Generate a secret key according to a particular method.
	void PassPhraseToSecretKey(const char *newVal);

	void get_Version(CkString &str);

	long get_KeyLength(void);
	void put_KeyLength(long newVal);

	bool CreateSignature(const unsigned char *data, unsigned long dataLen, CkByteData &outSigData);
	bool VerifySignature(const unsigned char *data, unsigned long dataLen, 
	    const unsigned char *sig, unsigned long sigLen);

	bool Encrypt(const unsigned char *data, unsigned long dataLen, CkByteData &outData);
	bool Decrypt(const unsigned char *data, unsigned long dataLen, CkByteData &outData);

	void Base64Encode(const unsigned char *data, unsigned long dataLen, CkString &outStr);
	bool Base64Decode(const char *str, CkByteData &outData);

	void QuotedPrintableEncode(const unsigned char *data, unsigned long dataLen, CkString &outStr);
	bool QuotedPrintableDecode(const char *str, CkByteData &outData);
	
	void HexEncode(const unsigned char *data, unsigned long dataLen, CkString &outStr);
	void HexDecode(const char *str, CkByteData &outData);

	void CalcDigestMD5(const unsigned char *data, unsigned long dataLen, CkByteData &outData);
	bool CalcSha1Hash(const unsigned char *data, unsigned long dataLen, CkByteData &outData);
	bool CalcMd2Hash(const unsigned char *data, unsigned long dataLen, CkByteData &outData);

	bool get_HasIV(void);
	void put_HasIV(bool b);

	void get_IV(CkByteData &db);
	void put_IV(const unsigned char *ivData);

	void GenerateRandomIV(void);

	bool ZipAndEncrypt(const unsigned char *data, unsigned long dataLen, CkByteData &outData);
	bool DecryptAndUnzip(const unsigned char *data, unsigned long dataLen, CkByteData &outData);


	// CRYPT_INSERT_POINT

	// END PUBLIC INTERFACE

};
#ifndef __sun__
#pragma pack (pop)
#endif



#endif


