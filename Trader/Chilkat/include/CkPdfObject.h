// CkPdfObject.h: interface for the CkPdfObject class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _CkPdfObject_H
#define _CkPdfObject_H



#include "CkString.h"
class CkByteData;
#include "CkObject.h"

#ifndef __sun__
#pragma pack (push, 8)
#endif
 

// CLASS: CkPdfObject
class CkPdfObject  : public CkObject
{
    private:
	void *m_impl;
	bool m_utf8;	// If true, all input "const char *" parameters are utf-8, otherwise they are ANSI strings.

	// Don't allow assignment or copying these objects.
	CkPdfObject(const CkPdfObject &);
	CkPdfObject &operator=(const CkPdfObject &);

	unsigned long nextIdx(void);
	unsigned long m_resultIdx;
	CkString m_resultString[10];

    public:
	void *getImpl(void) const;

	CkPdfObject(void *impl);

	CkPdfObject();
	virtual ~CkPdfObject();

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
	

	bool DictObjectRef(const char *key, CkString &outStr);
	const char *dictObjectRef(const char *key);
	CkPdfObject *DictObject(const char *key);
	CkPdfObject *IndirectObject(void);
	int get_ObjectType(void);
	void get_ObjectTypeStr(CkString &str);
	const char *objectTypeStr(void);
	bool DictString(const char *key, CkString &outStr);
	const char *dictString(const char *key);
	bool DictBool(const char *key);
	int DictInt(const char *key);
	int get_NumDictKeys(void);
	bool DictKey(int index, CkString &outStr);
	const char *dictKey(int index);
	bool StructureReport(CkString &outStr);
	const char *structureReport(void);
	// BOOLVALUE_BEGIN
	bool get_BoolValue(void);
	void put_BoolValue(bool newVal);
	// BOOLVALUE_END
	// INTVALUE_BEGIN
	int get_IntValue(void);
	void put_IntValue(int newVal);
	// INTVALUE_END
	// STRVALUE_BEGIN
	void get_StrValue(CkString &str);
	const char *strValue(void);
	void put_StrValue(const char *newVal);
	// STRVALUE_END
	// NAMEVALUE_BEGIN
	void get_NameValue(CkString &str);
	const char *nameValue(void);
	void put_NameValue(const char *newVal);
	// NAMEVALUE_END
	// INITASDICT_BEGIN
	bool InitAsDict(void);
	// INITASDICT_END
	// INITASSTREAM_BEGIN
	bool InitAsStream(void);
	// INITASSTREAM_END
	// INITASARRAY_BEGIN
	bool InitAsArray(void);
	// INITASARRAY_END
	// ARRAYSIZE_BEGIN
	int get_ArraySize(void);
	// ARRAYSIZE_END
	// ARRAYOBJECT_BEGIN
	CkPdfObject *ArrayObject(int index);
	// ARRAYOBJECT_END
	// ARRAYBOOL_BEGIN
	bool ArrayBool(int index);
	// ARRAYBOOL_END
	// ARRAYINT_BEGIN
	int ArrayInt(int index);
	// ARRAYINT_END
	// ARRAYOBJECTREF_BEGIN
	bool ArrayObjectRef(int index, CkString &outStr);
	const char *arrayObjectRef(int index);
	// ARRAYOBJECTREF_END
	// ARRAYSTRING_BEGIN
	bool ArrayString(int index, CkString &outStr);
	const char *arrayString(int index);
	// ARRAYSTRING_END
	// TOSTRING_BEGIN
	bool ToString(CkString &outStr);
	const char *toString(void);
	// TOSTRING_END
	// TOBYTES_BEGIN
	bool ToBytes(CkByteData &outBytes);
	// TOBYTES_END
	// INITASNAME_BEGIN
	bool InitAsName(const char *name);
	// INITASNAME_END
	// INITASSTRING_BEGIN
	bool InitAsString(const char *str);
	// INITASSTRING_END
	// INITASREFERENCE_BEGIN
	bool InitAsReference(int objNum, int genNum);
	// INITASREFERENCE_END
	// INITASINT_BEGIN
	bool InitAsInt(int val);
	// INITASINT_END
	// ADDDICTNAME_BEGIN
	bool AddDictName(const char *key, const char *value);
	// ADDDICTNAME_END
	// ADDDICTSTRING_BEGIN
	bool AddDictString(const char *key, const char *value);
	// ADDDICTSTRING_END
	// APPENDNAME_BEGIN
	bool AppendName(const char *value);
	// APPENDNAME_END
	// APPENDSTRING_BEGIN
	bool AppendString(const char *value);
	// APPENDSTRING_END
	// APPENDREF_BEGIN
	bool AppendRef(int objNum, int genNum);
	// APPENDREF_END
	// APPENDINT_BEGIN
	bool AppendInt(int value);
	// APPENDINT_END
	// APPENDBOOL_BEGIN
	bool AppendBool(bool value);
	// APPENDBOOL_END
	// ADDDICTREF_BEGIN
	bool AddDictRef(const char *key, int objNum, int genNum);
	// ADDDICTREF_END
	// ADDDICTINT_BEGIN
	bool AddDictInt(const char *key, int value);
	// ADDDICTINT_END
	// ADDDICTBOOL_BEGIN
	bool AddDictBool(const char *key, bool value);
	// ADDDICTBOOL_END
	// INITFROMRAW_BEGIN
	bool InitFromRaw(const char *rawPdfObjectText);
	// INITFROMRAW_END

	// PDFOBJECT_INSERT_POINT

	// END PUBLIC INTERFACE


	// The following method(s) should not be called by an application.
	// They for internal use only.
	void setLastErrorProgrammingLanguage(int v);

};
#ifndef __sun__
#pragma pack (pop)
#endif



#endif


