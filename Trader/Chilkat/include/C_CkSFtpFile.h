#ifndef _CkSFtpFile_H
#define _CkSFtpFile_H
#include "Chilkat_C.h"

HCkSFtpFile CkSFtpFile_Create(void);
void CkSFtpFile_Dispose(HCkSFtpFile handle);
void CkSFtpFile_getCreateTime(HCkSFtpFile cHandle, SYSTEMTIME *retval);
void CkSFtpFile_getDebugLogFilePath(HCkSFtpFile cHandle, HCkString retval);
void CkSFtpFile_putDebugLogFilePath(HCkSFtpFile cHandle, const char *newVal);
void CkSFtpFile_getFileType(HCkSFtpFile cHandle, HCkString retval);
void CkSFtpFile_getFilename(HCkSFtpFile cHandle, HCkString retval);
int CkSFtpFile_getGid(HCkSFtpFile cHandle);
void CkSFtpFile_getGroup(HCkSFtpFile cHandle, HCkString retval);
BOOL CkSFtpFile_getIsAppendOnly(HCkSFtpFile cHandle);
BOOL CkSFtpFile_getIsArchive(HCkSFtpFile cHandle);
BOOL CkSFtpFile_getIsCaseInsensitive(HCkSFtpFile cHandle);
BOOL CkSFtpFile_getIsCompressed(HCkSFtpFile cHandle);
BOOL CkSFtpFile_getIsDirectory(HCkSFtpFile cHandle);
BOOL CkSFtpFile_getIsEncrypted(HCkSFtpFile cHandle);
BOOL CkSFtpFile_getIsHidden(HCkSFtpFile cHandle);
BOOL CkSFtpFile_getIsImmutable(HCkSFtpFile cHandle);
BOOL CkSFtpFile_getIsReadOnly(HCkSFtpFile cHandle);
BOOL CkSFtpFile_getIsRegular(HCkSFtpFile cHandle);
BOOL CkSFtpFile_getIsSparse(HCkSFtpFile cHandle);
BOOL CkSFtpFile_getIsSymLink(HCkSFtpFile cHandle);
BOOL CkSFtpFile_getIsSync(HCkSFtpFile cHandle);
BOOL CkSFtpFile_getIsSystem(HCkSFtpFile cHandle);
void CkSFtpFile_getLastAccessTime(HCkSFtpFile cHandle, SYSTEMTIME *retval);
void CkSFtpFile_getLastErrorHtml(HCkSFtpFile cHandle, HCkString retval);
void CkSFtpFile_getLastErrorText(HCkSFtpFile cHandle, HCkString retval);
void CkSFtpFile_getLastErrorXml(HCkSFtpFile cHandle, HCkString retval);
void CkSFtpFile_getLastModifiedTime(HCkSFtpFile cHandle, SYSTEMTIME *retval);
void CkSFtpFile_getOwner(HCkSFtpFile cHandle, HCkString retval);
int CkSFtpFile_getPermissions(HCkSFtpFile cHandle);
int CkSFtpFile_getSize32(HCkSFtpFile cHandle);
void CkSFtpFile_getSizeStr(HCkSFtpFile cHandle, HCkString retval);
int CkSFtpFile_getUid(HCkSFtpFile cHandle);
BOOL CkSFtpFile_getUtf8(HCkSFtpFile cHandle);
void CkSFtpFile_putUtf8(HCkSFtpFile cHandle, BOOL newVal);
BOOL CkSFtpFile_getVerboseLogging(HCkSFtpFile cHandle);
void CkSFtpFile_putVerboseLogging(HCkSFtpFile cHandle, BOOL newVal);
HCkDateTime CkSFtpFile_GetCreateDt(HCkSFtpFile cHandle);
HCkDateTime CkSFtpFile_GetLastAccessDt(HCkSFtpFile cHandle);
HCkDateTime CkSFtpFile_GetLastModifiedDt(HCkSFtpFile cHandle);
BOOL CkSFtpFile_SaveLastError(HCkSFtpFile cHandle, const char *filename);
const char *CkSFtpFile_debugLogFilePath(HCkSFtpFile cHandle);
const char *CkSFtpFile_fileType(HCkSFtpFile cHandle);
const char *CkSFtpFile_filename(HCkSFtpFile cHandle);
const char *CkSFtpFile_group(HCkSFtpFile cHandle);
const char *CkSFtpFile_lastErrorHtml(HCkSFtpFile cHandle);
const char *CkSFtpFile_lastErrorText(HCkSFtpFile cHandle);
const char *CkSFtpFile_lastErrorXml(HCkSFtpFile cHandle);
const char *CkSFtpFile_owner(HCkSFtpFile cHandle);
const char *CkSFtpFile_sizeStr(HCkSFtpFile cHandle);
#endif
