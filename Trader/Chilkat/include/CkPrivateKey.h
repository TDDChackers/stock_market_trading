// CkPrivateKey.h: interface for the CkPrivateKey class.
//
//////////////////////////////////////////////////////////////////////
#ifndef _CKPRIVATEKEY_H
#define _CKPRIVATEKEY_H



class CkString;

#include "CkMultiByteBase.h"
#include "CkString.h"
#include "CkByteData.h"

#ifndef __sun__
#pragma pack (push, 8)
#endif
 

// CLASS: CkPrivateKey
class CkPrivateKey : public CkMultiByteBase 
{
    private:
	// Don't allow assignment or copying these objects.
	CkPrivateKey(const CkPrivateKey &) { } 
	CkPrivateKey &operator=(const CkPrivateKey &) { return *this; }

    public:
	CkPrivateKey();
	CkPrivateKey(void *impl);
	virtual ~CkPrivateKey();

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	// BEGIN PUBLIC INTERFACE

	// Load from file:
	bool LoadRsaDerFile(const char *filename);
	bool LoadPkcs8File(const char *filename);
	bool LoadPemFile(const char *filename);
	bool LoadXmlFile(const char *filename);

	// Load from memory.
	bool LoadPem(const char *str);
	bool LoadRsaDer(CkByteData &data);
	bool LoadPkcs8(CkByteData &data);
	bool LoadXml(const char *xml);

#ifdef WIN32
	bool LoadPvk(CkByteData &data, const char *password);
	bool LoadPvkFile(const char *filename, const char *password);
#endif

	// Save to file:
	bool SaveRsaDerFile(const char *filename);
	bool SavePkcs8File(const char *filename);
	bool SaveRsaPemFile(const char *filename);
	bool SavePkcs8PemFile(const char *filename);
	bool SaveXmlFile(const char *filename);

	// Get to memory
	bool GetRsaDer(CkByteData &outData);
	bool GetPkcs8(CkByteData &outData);
	bool GetRsaPem(CkString &outStr);
	bool GetPkcs8Pem(CkString &outStr);
	bool GetXml(CkString &outStr);


	const char *getRsaPem(void);
	const char *getPkcs8Pem(void);
	const char *getXml(void);
	// LOADENCRYPTEDPEM_BEGIN
	bool LoadEncryptedPem(const char *pemStr, const char *password);
	// LOADENCRYPTEDPEM_END
	// LOADENCRYPTEDPEMFILE_BEGIN
	bool LoadEncryptedPemFile(const char *filename, const char *password);
	// LOADENCRYPTEDPEMFILE_END
	// LOADPKCS8ENCRYPTED_BEGIN
	bool LoadPkcs8Encrypted(CkByteData &data, const char *password);
	// LOADPKCS8ENCRYPTED_END
	// LOADPKCS8ENCRYPTEDFILE_BEGIN
	bool LoadPkcs8EncryptedFile(const char *filename, const char *password);
	// LOADPKCS8ENCRYPTEDFILE_END
	// GETPKCS8ENCRYPTED_BEGIN
	bool GetPkcs8Encrypted(const char *password, CkByteData &outBytes);
	// GETPKCS8ENCRYPTED_END
	// GETPKCS8ENCRYPTEDPEM_BEGIN
	bool GetPkcs8EncryptedPem(const char *password, CkString &outStr);
	const char *getPkcs8EncryptedPem(const char *password);
	// GETPKCS8ENCRYPTEDPEM_END
	// SAVEPKCS8ENCRYPTEDFILE_BEGIN
	bool SavePkcs8EncryptedFile(const char *password, const char *filename);
	// SAVEPKCS8ENCRYPTEDFILE_END
	// SAVEPKCS8ENCRYPTEDPEMFILE_BEGIN
	bool SavePkcs8EncryptedPemFile(const char *password, const char *filename);
	// SAVEPKCS8ENCRYPTEDPEMFILE_END

	// PRIVATEKEY_INSERT_POINT

	// END PUBLIC INTERFACE


};
#ifndef __sun__
#pragma pack (pop)
#endif


#endif
