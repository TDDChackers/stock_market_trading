#ifndef _CkMultiByteBase_H
#define _CkMultiByteBase_H
#pragma once

#ifndef __sun__
#pragma pack (push, 8)
#endif

#include "CkObject.h"

class CkString;

class CkMultiByteBase : public CkObject
{
    private:
	    
	// Disallow assignment or copying this object.
	CkMultiByteBase(const CkMultiByteBase &) { }
	CkMultiByteBase &operator=(const CkMultiByteBase &) { return *this; }

    protected:
	void *m_impl;	
	void *m_base;

	bool m_utf8;	// If true, all input "const char *" parameters are utf-8, otherwise they are ANSI strings.
	    
	unsigned int m_resultIdx;
	CkString *m_pResultString[10];

	unsigned int nextIdx(void);
    
    public:
	    
	CkMultiByteBase(void);
	virtual ~CkMultiByteBase(void);
    
	// BEGIN PUBLIC INTERFACE

	bool get_Utf8(void) const;
	void put_Utf8(bool b);

    	bool get_VerboseLogging(void);
	void put_VerboseLogging(bool b);

	bool SaveLastError(const char *filename);

	void LastErrorXml(CkString &str);
	void LastErrorHtml(CkString &str);
	void LastErrorText(CkString &str);

	const char *lastErrorText(void);
	const char *lastErrorXml(void);
	const char *lastErrorHtml(void);

	void get_DebugLogFilePath(CkString &str);
	void put_DebugLogFilePath(const char *newVal);

	const char *debugLogFilePath(void);

	// END PUBLIC INTERFACE

	void *getImpl(void) const;

	// The following method(s) should not be called by an application.
	// They for internal use only.
	void setLastErrorProgrammingLanguage(int v);

};


#endif
	
