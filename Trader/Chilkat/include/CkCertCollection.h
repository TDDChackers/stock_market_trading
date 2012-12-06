// CkCertCollection.h: interface for the CkCertCollection class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CKCERTCOLLECTION_H__C76FB184_136E_442A_ACFF_773BD284D60E__INCLUDED_)
#define AFX_CKCERTCOLLECTION_H__C76FB184_136E_442A_ACFF_773BD284D60E__INCLUDED_


class CkCert;
class CkString;
#include "CkMultiByteBase.h"
#include "CkString.h"

/*
    IMPORTANT: Objects returned by methods as non-const pointers must be deleted
    by the calling application. 

  */

#ifndef __sun__
#pragma pack (push, 8)
#endif
 

// Holds one or more certificates.
// CLASS: CkCertCollection
class CkCertCollection  : public CkMultiByteBase
{
    private:
	// Don't allow assignment or copying these objects.
	CkCertCollection(const CkCertCollection &) { } 
	CkCertCollection &operator=(const CkCertCollection &) { return *this; }
	CkCertCollection(void *impl);

    public:
	CkCertCollection();
	virtual ~CkCertCollection();

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	// BEGIN PUBLIC INTERFACE


	bool LoadPkcs7File(const char *filename);
	bool LoadPkcs7Data(const unsigned char *data, unsigned long dataLen);

	CkCert *GetCert(int index);

	int get_NumCerts(void) const;


	// CK_INSERT_POINT

	// END PUBLIC INTERFACE



};
#ifndef __sun__
#pragma pack (pop)
#endif


#endif // !defined(AFX_CKCERTCOLLECTION_H__C76FB184_136E_442A_ACFF_773BD284D60E__INCLUDED_)

