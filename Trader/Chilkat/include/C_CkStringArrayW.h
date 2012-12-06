#ifndef _CkStringArray_W_H
#define _CkStringArray_W_H
#include "Chilkat_C.h"

HCkStringArrayW CkStringArrayW_Create(void);
void CkStringArrayW_Dispose(HCkStringArrayW handle);
long CkStringArrayW_getCount(HCkStringArrayW cHandle);
BOOL CkStringArrayW_getCrlf(HCkStringArrayW cHandle);
void CkStringArrayW_putCrlf(HCkStringArrayW cHandle, BOOL newVal);
void CkStringArrayW_getDebugLogFilePath(HCkStringArrayW cHandle, HCkStringW retval);
void CkStringArrayW_putDebugLogFilePath(HCkStringArrayW cHandle, const wchar_t *newVal);
void CkStringArrayW_getLastErrorHtml(HCkStringArrayW cHandle, HCkStringW retval);
void CkStringArrayW_getLastErrorText(HCkStringArrayW cHandle, HCkStringW retval);
void CkStringArrayW_getLastErrorXml(HCkStringArrayW cHandle, HCkStringW retval);
BOOL CkStringArrayW_getTrim(HCkStringArrayW cHandle);
void CkStringArrayW_putTrim(HCkStringArrayW cHandle, BOOL newVal);
BOOL CkStringArrayW_getUnique(HCkStringArrayW cHandle);
void CkStringArrayW_putUnique(HCkStringArrayW cHandle, BOOL newVal);
BOOL CkStringArrayW_getVerboseLogging(HCkStringArrayW cHandle);
void CkStringArrayW_putVerboseLogging(HCkStringArrayW cHandle, BOOL newVal);
void CkStringArrayW_Append(HCkStringArrayW cHandle, const wchar_t *str);
BOOL CkStringArrayW_AppendSerialized(HCkStringArrayW cHandle, const wchar_t *encodedStr);
void CkStringArrayW_Clear(HCkStringArrayW cHandle);
BOOL CkStringArrayW_Contains(HCkStringArrayW cHandle, const wchar_t *str);
long CkStringArrayW_Find(HCkStringArrayW cHandle, const wchar_t *str, long firstIndex);
int CkStringArrayW_FindFirstMatch(HCkStringArrayW cHandle, const wchar_t *str, int firstIndex);
BOOL CkStringArrayW_GetString(HCkStringArrayW cHandle, long index, HCkStringW outStr);
int CkStringArrayW_GetStringLen(HCkStringArrayW cHandle, int index);
void CkStringArrayW_InsertAt(HCkStringArrayW cHandle, long index, const wchar_t *str);
BOOL CkStringArrayW_LastString(HCkStringArrayW cHandle, HCkStringW outStr);
BOOL CkStringArrayW_LoadFromFile(HCkStringArrayW cHandle, const wchar_t *filename);
void CkStringArrayW_LoadFromText(HCkStringArrayW cHandle, const wchar_t *str);
BOOL CkStringArrayW_Pop(HCkStringArrayW cHandle, HCkStringW outStr);
void CkStringArrayW_Prepend(HCkStringArrayW cHandle, const wchar_t *str);
void CkStringArrayW_Remove(HCkStringArrayW cHandle, const wchar_t *str);
BOOL CkStringArrayW_RemoveAt(HCkStringArrayW cHandle, long index);
BOOL CkStringArrayW_SaveLastError(HCkStringArrayW cHandle, const wchar_t *filename);
BOOL CkStringArrayW_SaveNthToFile(HCkStringArrayW cHandle, int index, const wchar_t *filename);
BOOL CkStringArrayW_SaveToFile(HCkStringArrayW cHandle, const wchar_t *filename);
BOOL CkStringArrayW_SaveToText(HCkStringArrayW cHandle, HCkStringW outStr);
BOOL CkStringArrayW_Serialize(HCkStringArrayW cHandle, HCkStringW outStr);
void CkStringArrayW_Sort(HCkStringArrayW cHandle, BOOL ascending);
void CkStringArrayW_SplitAndAppend(HCkStringArrayW cHandle, const wchar_t *str, const wchar_t *boundary);
void CkStringArrayW_Subtract(HCkStringArrayW cHandle, HCkStringArrayW sa);
void CkStringArrayW_Union(HCkStringArrayW cHandle, HCkStringArrayW sa);
const wchar_t *CkStringArrayW__debugLogFilePath(HCkStringArrayW cHandle);
const wchar_t *CkStringArrayW__getString(HCkStringArrayW cHandle, long index);
const wchar_t *CkStringArrayW__lastErrorHtml(HCkStringArrayW cHandle);
const wchar_t *CkStringArrayW__lastErrorText(HCkStringArrayW cHandle);
const wchar_t *CkStringArrayW__lastErrorXml(HCkStringArrayW cHandle);
const wchar_t *CkStringArrayW__lastString(HCkStringArrayW cHandle);
const wchar_t *CkStringArrayW__pop(HCkStringArrayW cHandle);
const wchar_t *CkStringArrayW__saveToText(HCkStringArrayW cHandle);
const wchar_t *CkStringArrayW__serialize(HCkStringArrayW cHandle);
const wchar_t *CkStringArrayW__strAt(HCkStringArrayW cHandle, long index);
#endif
