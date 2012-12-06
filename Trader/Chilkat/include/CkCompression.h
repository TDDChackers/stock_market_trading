// CkCompression.h: interface for the CkCompression class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _CKCOMPRESSION_H
#define _CKCOMPRESSION_H



#include "CkString.h"
class CkByteData;
#include "CkMultiByteBase.h"

/*
    IMPORTANT: Objects returned by methods as non-const pointers must be deleted
    by the calling application. 

*/
#ifndef __sun__
#pragma pack (push, 8)
#endif
 

// CLASS: CkCompression
class CkCompression  : public CkMultiByteBase
{
    public:
	CkCompression();
	virtual ~CkCompression();

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	// BEGIN PUBLIC INTERFACE
	void get_Algorithm(CkString &outStr);
	void put_Algorithm(const char *alg);

	bool CompressFile(const char *inFile, const char *outFile);
	bool DecompressFile(const char *inFile, const char *outFile);



	bool DecompressStringENC(const char *str, CkString &outStr);
	bool DecompressString(const CkByteData &bData, CkString &outStr);
	bool DecompressBytesENC(const char *str, CkByteData &outData);
	bool DecompressBytes(const CkByteData &bData, CkByteData &outData);

	bool CompressStringENC(const char *str, CkString &outStr);
	bool CompressBytesENC(const CkByteData &bData, CkString &outStr);
	bool CompressString(const char *str, CkByteData &outData);
	bool CompressBytes(const CkByteData &bData, CkByteData &outData);

	const char *compressStringENC(const char *str);
	const char *compressBytesENC(const CkByteData &bData);

	const char *decompressString(const CkByteData &bData);
	const char *decompressStringENC(const char *str);



	bool BeginDecompressStringENC(const char *str, CkString &outStr);
	bool BeginDecompressString(const CkByteData &bData, CkString &outStr);
	bool BeginDecompressBytesENC(const char *str, CkByteData &outData);
	bool BeginDecompressBytes(const CkByteData &bData, CkByteData &outData);

	bool BeginCompressStringENC(const char *str, CkString &outStr);
	bool BeginCompressBytesENC(const CkByteData &bData, CkString &outStr);
	bool BeginCompressString(const char *str, CkByteData &outData);
	bool BeginCompressBytes(const CkByteData &bData, CkByteData &outData);

	const char *beginCompressStringENC(const char *str);
	const char *beginCompressBytesENC(const CkByteData &bData);

	const char *beginDecompressString(const CkByteData &bData);
	const char *beginDecompressStringENC(const char *str);




	bool MoreDecompressStringENC(const char *str, CkString &outStr);
	bool MoreDecompressString(const CkByteData &bData, CkString &outStr);
	bool MoreDecompressBytesENC(const char *str, CkByteData &outData);
	bool MoreDecompressBytes(const CkByteData &bData, CkByteData &outData);

	bool MoreCompressStringENC(const char *str, CkString &outStr);
	bool MoreCompressBytesENC(const CkByteData &bData, CkString &outStr);
	bool MoreCompressString(const char *str, CkByteData &outData);
	bool MoreCompressBytes(const CkByteData &bData, CkByteData &outData);

	const char *moreCompressStringENC(const char *str);
	const char *moreCompressBytesENC(const CkByteData &bData);

	const char *moreDecompressString(const CkByteData &bData);
	const char *moreDecompressStringENC(const char *str);




	bool EndDecompressStringENC(CkString &outStr);
	bool EndDecompressString(CkString &outStr);
	bool EndDecompressBytesENC(CkByteData &outData);
	bool EndDecompressBytes(CkByteData &outData);

	bool EndCompressStringENC(CkString &outStr);
	bool EndCompressBytesENC(CkString &outStr);
	bool EndCompressString(CkByteData &outData);
	bool EndCompressBytes(CkByteData &outData);

	const char *endCompressStringENC(void);
	const char *endCompressBytesENC(void);

	const char *endDecompressString(void);
	const char *endDecompressStringENC(void);


	// CHARSET_BEGIN
	void get_Charset(CkString &str);
	const char *charset(void);
	void put_Charset(const char *newVal);
	// CHARSET_END
	// ENCODINGMODE_BEGIN
	void get_EncodingMode(CkString &str);
	const char *encodingMode(void);
	void put_EncodingMode(const char *newVal);
	// ENCODINGMODE_END
	// UNLOCKCOMPONENT_BEGIN
	bool UnlockComponent(const char *unlockCode);
	// UNLOCKCOMPONENT_END

	const char *algorithm(void);
	// VERSION_BEGIN
	void get_Version(CkString &str);
	const char *version(void);
	// VERSION_END

	// COMPRESSION_INSERT_POINT

	// END PUBLIC INTERFACE


    // Everything below is for internal use only.
    private:
	// Don't allow assignment or copying these objects.
	CkCompression(const CkCompression &);
	CkCompression &operator=(const CkCompression &);
	CkCompression(void *impl);



};
#ifndef __sun__
#pragma pack (pop)
#endif


#endif
