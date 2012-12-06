#ifndef _CkStringArray_H
#define _CkStringArray_H
#include "Chilkat_C.h"

HCkStringArray CkStringArray_Create(void);
void CkStringArray_Dispose(HCkStringArray handle);
long CkStringArray_getCount(HCkStringArray cHandle);
BOOL CkStringArray_getCrlf(HCkStringArray cHandle);
void CkStringArray_putCrlf(HCkStringArray cHandle, BOOL newVal);
void CkStringArray_getDebugLogFilePath(HCkStringArray cHandle, HCkString retval);
void CkStringArray_putDebugLogFilePath(HCkStringArray cHandle, const char *newVal);
void CkStringArray_getLastErrorHtml(HCkStringArray cHandle, HCkString retval);
void CkStringArray_getLastErrorText(HCkStringArray cHandle, HCkString retval);
void CkStringArray_getLastErrorXml(HCkStringArray cHandle, HCkString retval);
BOOL CkStringArray_getTrim(HCkStringArray cHandle);
void CkStringArray_putTrim(HCkStringArray cHandle, BOOL newVal);
BOOL CkStringArray_getUnique(HCkStringArray cHandle);
void CkStringArray_putUnique(HCkStringArray cHandle, BOOL newVal);
BOOL CkStringArray_getUtf8(HCkStringArray cHandle);
void CkStringArray_putUtf8(HCkStringArray cHandle, BOOL newVal);
BOOL CkStringArray_getVerboseLogging(HCkStringArray cHandle);
void CkStringArray_putVerboseLogging(HCkStringArray cHandle, BOOL newVal);
void CkStringArray_Append(HCkStringArray cHandle, const char *str);
BOOL CkStringArray_AppendSerialized(HCkStringArray cHandle, const char *encodedStr);
void CkStringArray_Clear(HCkStringArray cHandle);
BOOL CkStringArray_Contains(HCkStringArray cHandle, const char *str);
long CkStringArray_Find(HCkStringArray cHandle, const char *str, long firstIndex);
int CkStringArray_FindFirstMatch(HCkStringArray cHandle, const char *str, int firstIndex);
BOOL CkStringArray_GetString(HCkStringArray cHandle, long index, HCkString outStr);
int CkStringArray_GetStringLen(HCkStringArray cHandle, int index);
void CkStringArray_InsertAt(HCkStringArray cHandle, long index, const char *str);
BOOL CkStringArray_LastString(HCkStringArray cHandle, HCkString outStr);
BOOL CkStringArray_LoadFromFile(HCkStringArray cHandle, const char *filename);
void CkStringArray_LoadFromText(HCkStringArray cHandle, const char *str);
BOOL CkStringArray_Pop(HCkStringArray cHandle, HCkString outStr);
void CkStringArray_Prepend(HCkStringArray cHandle, const char *str);
void CkStringArray_Remove(HCkStringArray cHandle, const char *str);
BOOL CkStringArray_RemoveAt(HCkStringArray cHandle, long index);
BOOL CkStringArray_SaveLastError(HCkStringArray cHandle, const char *filename);
BOOL CkStringArray_SaveNthToFile(HCkStringArray cHandle, int index, const char *filename);
BOOL CkStringArray_SaveToFile(HCkStringArray cHandle, const char *filename);
BOOL CkStringArray_SaveToText(HCkStringArray cHandle, HCkString outStr);
BOOL CkStringArray_Serialize(HCkStringArray cHandle, HCkString outStr);
void CkStringArray_Sort(HCkStringArray cHandle, BOOL ascending);
void CkStringArray_SplitAndAppend(HCkStringArray cHandle, const char *str, const char *boundary);
void CkStringArray_Subtract(HCkStringArray cHandle, HCkStringArray sa);
void CkStringArray_Union(HCkStringArray cHandle, HCkStringArray sa);
const char *CkStringArray_debugLogFilePath(HCkStringArray cHandle);
const char *CkStringArray_getString(HCkStringArray cHandle, long index);
const char *CkStringArray_lastErrorHtml(HCkStringArray cHandle);
const char *CkStringArray_lastErrorText(HCkStringArray cHandle);
const char *CkStringArray_lastErrorXml(HCkStringArray cHandle);
const char *CkStringArray_lastString(HCkStringArray cHandle);
const char *CkStringArray_pop(HCkStringArray cHandle);
const char *CkStringArray_saveToText(HCkStringArray cHandle);
const char *CkStringArray_serialize(HCkStringArray cHandle);
const char *CkStringArray_strAt(HCkStringArray cHandle, long index);
#endif
