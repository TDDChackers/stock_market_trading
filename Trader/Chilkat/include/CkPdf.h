// CkPdf.h: interface for the CkPdf class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _CkPdf_H
#define _CkPdf_H



#include "CkString.h"
class CkByteData;
#include "CkObject.h"

#ifndef __sun__
#pragma pack (push, 8)
#endif
 
class CkPdfObject;
class CkCert;

// CLASS: CkPdf
class CkPdf  : public CkObject
{
    private:
	void *m_impl;
	bool m_utf8;	// If true, all input "const char *" parameters are utf-8, otherwise they are ANSI strings.

	// Don't allow assignment or copying these objects.
	CkPdf(const CkPdf &);
	CkPdf &operator=(const CkPdf &);

	unsigned long nextIdx(void);
	unsigned long m_resultIdx;
	CkString m_resultString[10];

    public:
	void *getImpl(void) const;

	CkPdf(void *impl);

	CkPdf();
	virtual ~CkPdf();

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	// BEGIN PUBLIC INTERFACE
	bool get_Utf8(void) const;
	void put_Utf8(bool b);

	// Error log retrieval and saving (these methods are common to all Chilkat VC++ classes.)
	bool SaveLastError(const char *filename);

	void LastErrorXml(CkString &str);
	void LastErrorHtml(CkString &str);
	void LastErrorText(CkString &str);

	const char *lastErrorText(void);
	const char *lastErrorXml(void);
	const char *lastErrorHtml(void);
	

	// UNLOCKCOMPONENT_BEGIN
	bool UnlockComponent(const char *unlockCode);
	// UNLOCKCOMPONENT_END


	// OPENFILE_BEGIN
	bool OpenFile(const char *path);
	// OPENFILE_END
	// NUMINDIRECTOBJECTS_BEGIN
	int get_NumIndirectObjects(void);
	// NUMINDIRECTOBJECTS_END
	// GETOBJNUM_BEGIN
	int ObjNum(int index);
	// GETOBJNUM_END
	// GETOBJECTBYINDEX_BEGIN
	CkPdfObject *ObjByIndex(int index);
	// GETOBJECTBYINDEX_END
	// DEBUGLOGFILEPATH_BEGIN
	void get_DebugLogFilePath(CkString &str);
	const char *debugLogFilePath(void);
	void put_DebugLogFilePath(const char *newVal);
	// DEBUGLOGFILEPATH_END
	// GETTRAILEROBJECT_BEGIN
	CkPdfObject *TrailerObject(const char *key);
	// GETTRAILEROBJECT_END
	// GETOBJECTBYREF_BEGIN
	CkPdfObject *ObjByRef(int objNum, int genNum);
	// GETOBJECTBYREF_END
	// OBJBYREFSTR_BEGIN
	CkPdfObject *ObjByRefStr(const char *refstr);
	// OBJBYREFSTR_END
	// STRUCTUREREPORT_BEGIN
	bool StructureReport(CkString &outStr);
	const char *structureReport(void);
	// STRUCTUREREPORT_END
	// NUMSIGNATURES_BEGIN
	int get_NumSignatures(void);
	// NUMSIGNATURES_END
	// VERIFYSIGNATURES_BEGIN
	bool VerifySignatures(void);
	// VERIFYSIGNATURES_END
	// NUMSIGNERCERTS_BEGIN
	int get_NumSignerCerts(void);
	// NUMSIGNERCERTS_END
	// GETSIGNERCERT_BEGIN
	CkCert *GetSignerCert(int index);
	// GETSIGNERCERT_END
	// GETSIGNATURESIGNINGTIME_BEGIN
	bool GetSignatureSigningTime(int index, SYSTEMTIME &outSysTime);
	// GETSIGNATURESIGNINGTIME_END
	// HASSIGNATURESIGNINGTIME_BEGIN
	bool HasSignatureSigningTime(int index);
	// HASSIGNATURESIGNINGTIME_END
	// GETSIGNINGREASON_BEGIN
	bool GetSigningReason(int index, CkString &outStr);
	const char *getSigningReason(int index);
	// GETSIGNINGREASON_END
	// GETSIGNERNAME_BEGIN
	bool GetSignerName(int index, CkString &outStr);
	const char *getSignerName(int index);
	// GETSIGNERNAME_END
	// ADDNEWINDIRECTOBJECT_BEGIN
	int AddNewIndirectObject(CkPdfObject &pdfObj);
	// ADDNEWINDIRECTOBJECT_END
	// WRITETOFILE_BEGIN
	bool WriteToFile(const char *path);
	// WRITETOFILE_END
	// OBJBYPATH_BEGIN
	CkPdfObject *ObjByPath(const char *objPath);
	// OBJBYPATH_END

	// PDF_INSERT_POINT

	// END PUBLIC INTERFACE


	// The following method(s) should not be called by an application.
	// They for internal use only.
	void setLastErrorProgrammingLanguage(int v);

};
#ifndef __sun__
#pragma pack (pop)
#endif



#endif


