// CkXmp.h: interface for the CkXmp class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _CKXMP_H
#define _CKXMP_H



#include "CkMultiByteBase.h"
#include "CkString.h"

#if !defined(WIN32) && !defined(WINCE)
#include "SystemTime.h"
#endif

class CkXml;
class CkStringArray;
class CkByteData;

/*
    IMPORTANT: Objects returned by methods as non-const pointers must be deleted
    by the calling application. 

  */

#ifndef __sun__
#pragma pack (push, 8)
#endif
 

// CLASS: CkXmp
class CkXmp : public CkMultiByteBase
{
    private:
	// If false, use rdf:parseType="Resource" for structures instead of 
	// inner description nodes.  The default value is true.
	bool m_structInnerDescrip;
	
	CkString m_errorInfo;
	
	CkXml **m_xml;
	
	// Don't allow assignment or copying these objects.
	CkXmp(const CkXmp &) { } 
	CkXmp &operator=(const CkXmp &) { return *this; }

    public:
    	
	CkXmp();
	virtual ~CkXmp();

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	// BEGIN PUBLIC INTERFACE


	bool UnlockComponent(const char *unlockCode);
	
	void get_Version(CkString &outStr);
	
	long get_NumEmbedded(void);

	bool LoadAppFile(const char *filename);
	bool SaveAppFile(const char *filename);
	
	bool LoadFromBuffer(CkByteData &byteData, const char *ext);
	bool SaveToBuffer(CkByteData &byteData);
	
	CkXml *GetEmbedded(int index);
	
	bool GetSimpleStr(CkXml &xml, const char *propName, CkString &outStr);
	int GetSimpleInt(CkXml &xml, const char *propName);
	bool GetSimpleDate(CkXml &xml, const char *propName, SYSTEMTIME &outSysTime);
	
	bool AddSimpleStr(CkXml &xml, const char *propName, const char *propVal);
	bool AddSimpleInt(CkXml &xml, const char *propName, int propVal);
	bool AddSimpleDate(CkXml &xml, const char *propName, SYSTEMTIME &sysTime);
	
	void AddNsMapping(const char *ns, const char *uri);
	void RemoveNsMapping(const char *ns);
	
	void NewXmp(CkXml &xmlOut);
	
	bool StringToDate(const char *str, SYSTEMTIME &outSysTime);
	bool DateToString(SYSTEMTIME &sysTime, CkString &outStr);
	
	bool RemoveSimple(CkXml &xml, const char *propName);
	bool Append(CkXml &xml);
	
	void RemoveAllEmbedded(void);
	void RemoveEmbedded(int index);

	bool get_StructInnerDescrip(void);
	void put_StructInnerDescrip(bool val);

	bool GetArray(CkXml &xml, const char *propName, CkStringArray &sa);
	bool RemoveArray(CkXml &xml, const char *propName);
	bool AddArray(CkXml &xml, const char *arrType, const char *propName, CkStringArray &values);

	bool GetStructValue(CkXml &xml, const char *structName, const char *propName, CkString &outStr);
	bool GetStructPropNames(CkXml &xml, const char *structName, CkStringArray &sa);
	
	bool RemoveStruct(CkXml &xml, const char *structName);
	bool RemoveStructProp(CkXml &xml, const char *structName, const char *propName);
	bool AddStructProp(CkXml &xml, const char *structName, const char *propName, const char *propVal);

	const char *getSimpleStr(CkXml &xml, const char *propName);
	const char *getStructValue(CkXml &xml, const char *structName, const char *propName);

	// Same as getSimpleStr/getStructValue:
	const char *simpleStr(CkXml &xml, const char *propName);
	const char *structValue(CkXml &xml, const char *structName, const char *propName);

	const char *version(void);
	// SYSTEMTIME is defined in <windows.h>
	// For more information, Google "SYSTEMTIME"
	const char *dateToString(SYSTEMTIME &sysTime);
	// GETPROPERTY_BEGIN
	CkXml *GetProperty(CkXml &xml, const char *propName);
	// GETPROPERTY_END

	// XMP_INSERT_POINT

	// END PUBLIC INTERFACE



};

#ifndef __sun__
#pragma pack (pop)
#endif


#endif


