#ifndef _CkSFtpDir_W_H
#define _CkSFtpDir_W_H
#include "Chilkat_C.h"

HCkSFtpDirW CkSFtpDirW_Create(void);
void CkSFtpDirW_Dispose(HCkSFtpDirW handle);
void CkSFtpDirW_getDebugLogFilePath(HCkSFtpDirW cHandle, HCkStringW retval);
void CkSFtpDirW_putDebugLogFilePath(HCkSFtpDirW cHandle, const wchar_t *newVal);
void CkSFtpDirW_getLastErrorHtml(HCkSFtpDirW cHandle, HCkStringW retval);
void CkSFtpDirW_getLastErrorText(HCkSFtpDirW cHandle, HCkStringW retval);
void CkSFtpDirW_getLastErrorXml(HCkSFtpDirW cHandle, HCkStringW retval);
int CkSFtpDirW_getNumFilesAndDirs(HCkSFtpDirW cHandle);
void CkSFtpDirW_getOriginalPath(HCkSFtpDirW cHandle, HCkStringW retval);
BOOL CkSFtpDirW_getVerboseLogging(HCkSFtpDirW cHandle);
void CkSFtpDirW_putVerboseLogging(HCkSFtpDirW cHandle, BOOL newVal);
HCkSFtpFileW CkSFtpDirW_GetFileObject(HCkSFtpDirW cHandle, int index);
BOOL CkSFtpDirW_GetFilename(HCkSFtpDirW cHandle, int index, HCkStringW outStr);
BOOL CkSFtpDirW_SaveLastError(HCkSFtpDirW cHandle, const wchar_t *filename);
const wchar_t *CkSFtpDirW__debugLogFilePath(HCkSFtpDirW cHandle);
const wchar_t *CkSFtpDirW__getFilename(HCkSFtpDirW cHandle, int index);
const wchar_t *CkSFtpDirW__lastErrorHtml(HCkSFtpDirW cHandle);
const wchar_t *CkSFtpDirW__lastErrorText(HCkSFtpDirW cHandle);
const wchar_t *CkSFtpDirW__lastErrorXml(HCkSFtpDirW cHandle);
const wchar_t *CkSFtpDirW__originalPath(HCkSFtpDirW cHandle);
#endif
