#ifndef _CkSFtpFile_W_H
#define _CkSFtpFile_W_H
#include "Chilkat_C.h"

HCkSFtpFileW CkSFtpFileW_Create(void);
void CkSFtpFileW_Dispose(HCkSFtpFileW handle);
void CkSFtpFileW_getCreateTime(HCkSFtpFileW cHandle, SYSTEMTIME *retval);
void CkSFtpFileW_getDebugLogFilePath(HCkSFtpFileW cHandle, HCkStringW retval);
void CkSFtpFileW_putDebugLogFilePath(HCkSFtpFileW cHandle, const wchar_t *newVal);
void CkSFtpFileW_getFileType(HCkSFtpFileW cHandle, HCkStringW retval);
void CkSFtpFileW_getFilename(HCkSFtpFileW cHandle, HCkStringW retval);
int CkSFtpFileW_getGid(HCkSFtpFileW cHandle);
void CkSFtpFileW_getGroup(HCkSFtpFileW cHandle, HCkStringW retval);
BOOL CkSFtpFileW_getIsAppendOnly(HCkSFtpFileW cHandle);
BOOL CkSFtpFileW_getIsArchive(HCkSFtpFileW cHandle);
BOOL CkSFtpFileW_getIsCaseInsensitive(HCkSFtpFileW cHandle);
BOOL CkSFtpFileW_getIsCompressed(HCkSFtpFileW cHandle);
BOOL CkSFtpFileW_getIsDirectory(HCkSFtpFileW cHandle);
BOOL CkSFtpFileW_getIsEncrypted(HCkSFtpFileW cHandle);
BOOL CkSFtpFileW_getIsHidden(HCkSFtpFileW cHandle);
BOOL CkSFtpFileW_getIsImmutable(HCkSFtpFileW cHandle);
BOOL CkSFtpFileW_getIsReadOnly(HCkSFtpFileW cHandle);
BOOL CkSFtpFileW_getIsRegular(HCkSFtpFileW cHandle);
BOOL CkSFtpFileW_getIsSparse(HCkSFtpFileW cHandle);
BOOL CkSFtpFileW_getIsSymLink(HCkSFtpFileW cHandle);
BOOL CkSFtpFileW_getIsSync(HCkSFtpFileW cHandle);
BOOL CkSFtpFileW_getIsSystem(HCkSFtpFileW cHandle);
void CkSFtpFileW_getLastAccessTime(HCkSFtpFileW cHandle, SYSTEMTIME *retval);
void CkSFtpFileW_getLastErrorHtml(HCkSFtpFileW cHandle, HCkStringW retval);
void CkSFtpFileW_getLastErrorText(HCkSFtpFileW cHandle, HCkStringW retval);
void CkSFtpFileW_getLastErrorXml(HCkSFtpFileW cHandle, HCkStringW retval);
void CkSFtpFileW_getLastModifiedTime(HCkSFtpFileW cHandle, SYSTEMTIME *retval);
void CkSFtpFileW_getOwner(HCkSFtpFileW cHandle, HCkStringW retval);
int CkSFtpFileW_getPermissions(HCkSFtpFileW cHandle);
int CkSFtpFileW_getSize32(HCkSFtpFileW cHandle);
void CkSFtpFileW_getSizeStr(HCkSFtpFileW cHandle, HCkStringW retval);
int CkSFtpFileW_getUid(HCkSFtpFileW cHandle);
BOOL CkSFtpFileW_getVerboseLogging(HCkSFtpFileW cHandle);
void CkSFtpFileW_putVerboseLogging(HCkSFtpFileW cHandle, BOOL newVal);
HCkDateTimeW CkSFtpFileW_GetCreateDt(HCkSFtpFileW cHandle);
HCkDateTimeW CkSFtpFileW_GetLastAccessDt(HCkSFtpFileW cHandle);
HCkDateTimeW CkSFtpFileW_GetLastModifiedDt(HCkSFtpFileW cHandle);
BOOL CkSFtpFileW_SaveLastError(HCkSFtpFileW cHandle, const wchar_t *filename);
const wchar_t *CkSFtpFileW__debugLogFilePath(HCkSFtpFileW cHandle);
const wchar_t *CkSFtpFileW__fileType(HCkSFtpFileW cHandle);
const wchar_t *CkSFtpFileW__filename(HCkSFtpFileW cHandle);
const wchar_t *CkSFtpFileW__group(HCkSFtpFileW cHandle);
const wchar_t *CkSFtpFileW__lastErrorHtml(HCkSFtpFileW cHandle);
const wchar_t *CkSFtpFileW__lastErrorText(HCkSFtpFileW cHandle);
const wchar_t *CkSFtpFileW__lastErrorXml(HCkSFtpFileW cHandle);
const wchar_t *CkSFtpFileW__owner(HCkSFtpFileW cHandle);
const wchar_t *CkSFtpFileW__sizeStr(HCkSFtpFileW cHandle);
#endif
