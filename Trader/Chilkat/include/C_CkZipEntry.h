#ifndef _CkZipEntry_H
#define _CkZipEntry_H
#include "Chilkat_C.h"

HCkZipEntry CkZipEntry_Create(void);
void CkZipEntry_Dispose(HCkZipEntry handle);
void CkZipEntry_getComment(HCkZipEntry cHandle, HCkString retval);
void CkZipEntry_putComment(HCkZipEntry cHandle, const char *newVal);
unsigned long CkZipEntry_getCompressedLength(HCkZipEntry cHandle);
long CkZipEntry_getCompressionLevel(HCkZipEntry cHandle);
void CkZipEntry_putCompressionLevel(HCkZipEntry cHandle, long newVal);
long CkZipEntry_getCompressionMethod(HCkZipEntry cHandle);
void CkZipEntry_putCompressionMethod(HCkZipEntry cHandle, long newVal);
int CkZipEntry_getCrc(HCkZipEntry cHandle);
long CkZipEntry_getEntryID(HCkZipEntry cHandle);
long CkZipEntry_getEntryType(HCkZipEntry cHandle);
void CkZipEntry_getFileDateTime(HCkZipEntry cHandle, SYSTEMTIME *retval);
void CkZipEntry_putFileDateTime(HCkZipEntry cHandle, SYSTEMTIME *newVal);
void CkZipEntry_getFileName(HCkZipEntry cHandle, HCkString retval);
void CkZipEntry_putFileName(HCkZipEntry cHandle, const char *newVal);
BOOL CkZipEntry_getIsDirectory(HCkZipEntry cHandle);
void CkZipEntry_getLastErrorHtml(HCkZipEntry cHandle, HCkString retval);
void CkZipEntry_getLastErrorText(HCkZipEntry cHandle, HCkString retval);
void CkZipEntry_getLastErrorXml(HCkZipEntry cHandle, HCkString retval);
unsigned long CkZipEntry_getUncompressedLength(HCkZipEntry cHandle);
BOOL CkZipEntry_getUtf8(HCkZipEntry cHandle);
void CkZipEntry_putUtf8(HCkZipEntry cHandle, BOOL newVal);
BOOL CkZipEntry_AppendData(HCkZipEntry cHandle, HCkByteData bdata);
BOOL CkZipEntry_AppendStringAnsi(HCkZipEntry cHandle, HCkString sdata);
BOOL CkZipEntry_Copy(HCkZipEntry cHandle, HCkByteData outData);
BOOL CkZipEntry_CopyToBase64(HCkZipEntry cHandle, HCkString outStr);
BOOL CkZipEntry_CopyToHex(HCkZipEntry cHandle, HCkString outStr);
BOOL CkZipEntry_Extract(HCkZipEntry cHandle, const char *dirPath);
BOOL CkZipEntry_ExtractInto(HCkZipEntry cHandle, const char *dirPath);
HCkDateTime CkZipEntry_GetDt(HCkZipEntry cHandle);
BOOL CkZipEntry_Inflate(HCkZipEntry cHandle, HCkByteData outData);
BOOL CkZipEntry_InflateToString(HCkZipEntry cHandle, BOOL addCR, HCkString outStr);
BOOL CkZipEntry_InflateToString2(HCkZipEntry cHandle, HCkString outStr);
HCkZipEntry CkZipEntry_NextEntry(HCkZipEntry cHandle);
BOOL CkZipEntry_ReplaceData(HCkZipEntry cHandle, HCkByteData bdata);
BOOL CkZipEntry_ReplaceStringAnsi(HCkZipEntry cHandle, HCkString sdata);
BOOL CkZipEntry_SaveLastError(HCkZipEntry cHandle, const char *filename);
void CkZipEntry_SetDt(HCkZipEntry cHandle, HCkDateTime dt);
const char *CkZipEntry_comment(HCkZipEntry cHandle);
const char *CkZipEntry_copyToBase64(HCkZipEntry cHandle);
const char *CkZipEntry_copyToHex(HCkZipEntry cHandle);
const char *CkZipEntry_fileName(HCkZipEntry cHandle);
const char *CkZipEntry_inflateToString(HCkZipEntry cHandle, BOOL addCR);
const char *CkZipEntry_inflateToString2(HCkZipEntry cHandle);
const char *CkZipEntry_lastErrorHtml(HCkZipEntry cHandle);
const char *CkZipEntry_lastErrorText(HCkZipEntry cHandle);
const char *CkZipEntry_lastErrorXml(HCkZipEntry cHandle);
#endif
