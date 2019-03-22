#pragma once

#include <stddef.h>

#include <sce/types/savedata.h>

int32_t sceSaveDataInitialize3(const SceSaveDataInitParams3 *initParam);
int32_t sceSaveDataTerminate();
int32_t sceSaveDataMount2(const SceSaveDataMount2 *mount, SceSaveDataMountResult *mountResult);
int32_t sceSaveDataTransferringMount(const SceSaveDataTransferringMount *mount, SceSaveDataMountResult *mountResult);
int32_t sceSaveDataUmount(const SceSaveDataMountPoint *mountPoint);
int32_t sceSaveDataUmountWithBackup(const SceSaveDataMountPoint *mountPoint);
int32_t sceSaveDataGetMountInfo(const SceSaveDataMountPoint *mountPoint, SceSaveDataMountInfo *info);
int32_t sceSaveDataDelete(const SceSaveDataDelete *del);
int32_t sceSaveDataDirNameSearch(const SceSaveDataDirNameSearchCond *cond, SceSaveDataDirNameSearchResult *result);
int32_t sceSaveDataSetParam(const SceSaveDataMountPoint *mountPoint, const SceSaveDataParamType paramType, const void *paramBuf, const size_t paramBufSize);
int32_t sceSaveDataGetParam(const SceSaveDataMountPoint *mountPoint, const SceSaveDataParamType paramType, void *paramBuf, const size_t paramBufSize, size_t *gotSize);
int32_t sceSaveDataSaveIcon(const SceSaveDataMountPoint *mountPoint, const SceSaveDataIcon *param);
int32_t sceSaveDataLoadIcon(const SceSaveDataMountPoint *mountPoint, SceSaveDataIcon *param);
int32_t sceSaveDataSyncSaveDataMemory(const SceSaveDataMemorySync *syncParam);
int32_t sceSaveDataSetupSaveDataMemory2(const SceSaveDataMemorySetup2 *setupParam, SceSaveDataMemorySetupResult *result);
int32_t sceSaveDataGetSaveDataMemory2(SceSaveDataMemoryGet2 *getParam);
int32_t sceSaveDataSetSaveDataMemory2(const SceSaveDataMemorySet2 *setParam);
int32_t sceSaveDataRestoreBackupData(const SceSaveDataRestoreBackupData *restore);
int32_t sceSaveDataCheckBackupData(const SceSaveDataCheckBackupData *check);
int32_t sceSaveDataBackup(const SceSaveDataBackup *backup);
int32_t sceSaveDataGetProgress(float *progress);
int32_t sceSaveDataClearProgress(void);
int32_t sceSaveDataGetEventResult(const SceSaveDataEventParam *param, SceSaveDataEvent *event);
