#pragma once

#include <stddef.h>
#include <stdint.h>

#include <sce/types/userservice.h>

/* Legacy */
#define SCE_SAVE_DATA_MEMORY_MAXSIZE (1 * 1024 * 1024)
#define SCE_SAVE_DATA_MEMORY_MAXSIZE2 (8 * 1024 * 1024)
#define SCE_SAVE_DATA_MEMORY_UNLOCK_LIMITATION_MAXSIZE (32 * 1024 * 1024)
#define SCE_SAVE_DATA_MEMORY_OPTION_UNLOCK_LIMITATION (0x00000001 << 2)
/* End Legacy */

#define SCE_SAVE_DATA_TITLE_ID_DATA_SIZE (10)
#define SCE_SAVE_DATA_DIRNAME_DATA_MAXSIZE (32)
#define SCE_SAVE_DATA_FINGERPRINT_DATA_SIZE (65)
#define SCE_SAVE_DATA_MOUNT_POINT_DATA_MAXSIZE (16)
#define SCE_SAVE_DATA_DIRNAME_MAX_COUNT (1024)

#define SCE_SAVE_DATA_TITLE_MAXSIZE (128)
#define SCE_SAVE_DATA_SUBTITLE_MAXSIZE (128)
#define SCE_SAVE_DATA_DETAIL_MAXSIZE (1024)

typedef uint32_t SceSaveDataMountMode;
#define SCE_SAVE_DATA_MOUNT_MODE_RDONLY (0x00000001)
#define SCE_SAVE_DATA_MOUNT_MODE_RDWR (0x00000002)
#define SCE_SAVE_DATA_MOUNT_MODE_CREATE (0x00000004)
#define SCE_SAVE_DATA_MOUNT_MODE_DESTRUCT_OFF (0x00000008)
#define SCE_SAVE_DATA_MOUNT_MODE_COPY_ICON (0x00000010)
#define SCE_SAVE_DATA_MOUNT_MODE_CREATE2 (0x00000020)

typedef uint32_t SceSaveDataMountStatus;
#define SCE_SAVE_DATA_MOUNT_STATUS_CREATED (0x00000001)

typedef uint32_t SceSaveDataParamType;
#define SCE_SAVE_DATA_PARAM_TYPE_ALL (0)
#define SCE_SAVE_DATA_PARAM_TYPE_TITLE (1)
#define SCE_SAVE_DATA_PARAM_TYPE_SUB_TITLE (2)
#define SCE_SAVE_DATA_PARAM_TYPE_DETAIL (3)
#define SCE_SAVE_DATA_PARAM_TYPE_USER_PARAM (4)
#define SCE_SAVE_DATA_PARAM_TYPE_MTIME (5)

typedef uint32_t SceSaveDataSortKey;
#define SCE_SAVE_DATA_SORT_KEY_DIRNAME (0)
#define SCE_SAVE_DATA_SORT_KEY_USER_PARAM (1)
#define SCE_SAVE_DATA_SORT_KEY_BLOCKS (2)
#define SCE_SAVE_DATA_SORT_KEY_MTIME (3)
#define SCE_SAVE_DATA_SORT_KEY_FREE_BLOCKS (5)

typedef uint32_t SceSaveDataSortOrder;
#define SCE_SAVE_DATA_SORT_ORDER_ASCENT (0)
#define SCE_SAVE_DATA_SORT_ORDER_DESCENT (1)

#define SCE_SAVE_DATA_ICON_WIDTH (228)
#define SCE_SAVE_DATA_ICON_HEIGHT (128)
#define SCE_SAVE_DATA_ICON_FILE_MAXSIZE (SCE_SAVE_DATA_ICON_WIDTH * SCE_SAVE_DATA_ICON_HEIGHT * 4)

typedef uint64_t SceSaveDataBlocks;
#define SCE_SAVE_DATA_BLOCK_SIZE (32768)
#define SCE_SAVE_DATA_BLOCKS_MIN2 (96)
#define SCE_SAVE_DATA_BLOCKS_MAX (32768)

typedef uint32_t SceSaveDataSaveDataMemoryOption;
#define SCE_SAVE_DATA_MEMORY_OPTION_NONE (0x00000000)
#define SCE_SAVE_DATA_MEMORY_OPTION_SET_PARAM (0x00000001 << 0)
#define SCE_SAVE_DATA_MEMORY_OPTION_DOUBLE_BUFFER (0x00000001 << 1)

#define SCE_SAVE_DATA_DIRNAME_SAVE_DATA_MEMORY "sce_sdmemory"
#define SCE_SAVE_DATA_FILENAME_SAVE_DATA_MEMORY "memory.dat"

typedef uint32_t SceSaveDataEventType;
#define SCE_SAVE_DATA_EVENT_TYPE_INVALID (0)
#define SCE_SAVE_DATA_EVENT_TYPE_UMOUNT_BACKUP_END (1)
#define SCE_SAVE_DATA_EVENT_TYPE_BACKUP_END (2)
#define SCE_SAVE_DATA_EVENT_TYPE_SAVE_DATA_MEMORY_SYNC_END (3)

typedef struct SceSaveDataTitleId {
  char data[SCE_SAVE_DATA_TITLE_ID_DATA_SIZE];
  char padding[6];
} SceSaveDataTitleId;

typedef struct SceSaveDataDirName {
  char data[SCE_SAVE_DATA_DIRNAME_DATA_MAXSIZE];
} SceSaveDataDirName;

typedef struct SceSaveDataMountPoint {
  char data[SCE_SAVE_DATA_MOUNT_POINT_DATA_MAXSIZE];
} SceSaveDataMountPoint;

typedef struct SceSaveDataFingerprint {
  char data[SCE_SAVE_DATA_FINGERPRINT_DATA_SIZE];
  char padding[15];
} SceSaveDataFingerprint;

typedef struct _SceSaveDataInitParams3 SceSaveDataInitParams3;

typedef struct SceSaveDataMount2 {
  SceUserServiceUserId userId;
  int : 32;
  const SceSaveDataDirName *dirName;
  SceSaveDataBlocks blocks;
  SceSaveDataMountMode mountMode;
  uint8_t reserved[32];
  int : 32;
} SceSaveDataMount2;

typedef struct SceSaveDataTransferringMount {
  SceUserServiceUserId userId;
  const SceSaveDataTitleId *titleId;
  const SceSaveDataDirName *dirName;
  const SceSaveDataFingerprint *fingerprint;
  uint8_t reserved[32];
} SceSaveDataTransferringMount;

typedef struct SceSaveDataMountResult {
  SceSaveDataMountPoint mountPoint;
  SceSaveDataBlocks requiredBlocks;
  uint32_t unused;
  SceSaveDataMountStatus mountStatus;
  uint8_t reserved[28];
  int : 32;
} SceSaveDataMountResult;

typedef struct SceSaveDataMountInfo {
  SceSaveDataBlocks blocks;
  SceSaveDataBlocks freeBlocks;
  uint8_t reserved[32];
} SceSaveDataMountInfo;

typedef struct SceSaveDataIcon {
  void *buf;
  size_t bufSize;
  size_t dataSize;
  uint8_t reserved[32];
} SceSaveDataIcon;

typedef struct SceSaveDataParam {
  char title[SCE_SAVE_DATA_TITLE_MAXSIZE];
  char subTitle[SCE_SAVE_DATA_SUBTITLE_MAXSIZE];
  char detail[SCE_SAVE_DATA_DETAIL_MAXSIZE];
  uint32_t userParam;
  int : 32;
  time_t mtime;
  uint8_t reserved[32];
} SceSaveDataParam;

typedef struct SceSaveDataDelete {
  SceUserServiceUserId userId;
  int : 32;
  const SceSaveDataTitleId *titleId;
  const SceSaveDataDirName *dirName;
  uint32_t unused;
  uint8_t reserved[32];
  int : 32;
} SceSaveDataDelete;

typedef struct SceSaveDataSearchInfo {
  SceSaveDataBlocks blocks;
  SceSaveDataBlocks freeBlocks;
  uint8_t reserved[32];
} SceSaveDataSearchInfo;

typedef struct SceSaveDataDirNameSearchCond {
  SceUserServiceUserId userId;
  int : 32;
  const SceSaveDataTitleId *titleId;
  const SceSaveDataDirName *dirName;
  SceSaveDataSortKey key;
  SceSaveDataSortOrder order;
  uint8_t reserved[32];
} SceSaveDataDirNameSearchCond;

typedef struct SceSaveDataDirNameSearchResult {
  uint32_t hitNum;
  int : 32;
  SceSaveDataDirName *dirNames;
  uint32_t dirNamesNum;
  uint32_t setNum;
  SceSaveDataParam *params;
  SceSaveDataSearchInfo *infos;
  uint8_t reserved[12];
  int : 32;
} SceSaveDataDirNameSearchResult;

typedef struct SceSaveDataMemorySync {
  SceUserServiceUserId userId;
  uint8_t reserved[36];
} SceSaveDataMemorySync;

typedef struct SceSaveDataRestoreBackupData {
  SceUserServiceUserId userId;
  int : 32;
  const SceSaveDataTitleId *titleId;
  const SceSaveDataDirName *dirName;
  const SceSaveDataFingerprint *fingerprint;
  uint32_t unused;
  uint8_t reserved[32];
  int : 32;
} SceSaveDataRestoreBackupData;

typedef struct SceSaveDataCheckBackupData {
  SceUserServiceUserId userId;
  int : 32;
  const SceSaveDataTitleId *titleId;
  const SceSaveDataDirName *dirName;
  SceSaveDataParam *param;
  SceSaveDataIcon *icon;
  uint8_t reserved[32];
} SceSaveDataCheckBackupData;

typedef struct SceSaveDataBackup {
  SceUserServiceUserId userId;
  int : 32;
  const SceSaveDataTitleId *titleId;
  const SceSaveDataDirName *dirName;
  const SceSaveDataFingerprint *fingerprint;
  uint8_t reserved[32];
} SceSaveDataBackup;

typedef struct SceSaveDataMemoryData {
  void *buf;
  size_t bufSize;
  off_t offset;
  uint8_t reserved[40];
} SceSaveDataMemoryData;

typedef struct SceSaveDataMemorySetup2 {
  SceSaveDataSaveDataMemoryOption option;
  SceUserServiceUserId userId;
  size_t memorySize;
  size_t iconMemorySize;
  const SceSaveDataParam *initParam;
  const SceSaveDataIcon *initIcon;
  uint8_t reserved[24];
} SceSaveDataMemorySetup2;

typedef struct SceSaveDataMemorySetupResult {
  size_t existedMemorySize;
  uint8_t reserved[16];
} SceSaveDataMemorySetupResult;

typedef struct SceSaveDataMemoryGet2 {
  SceUserServiceUserId userId;
  uint8_t padding[4];
  SceSaveDataMemoryData *data;
  SceSaveDataParam *param;
  SceSaveDataIcon *icon;
  uint8_t reserved[32];
} SceSaveDataMemoryGet2;

typedef struct SceSaveDataMemorySet2 {
  SceUserServiceUserId userId;
  uint8_t padding[4];
  const SceSaveDataMemoryData *data;
  const SceSaveDataParam *param;
  const SceSaveDataIcon *icon;
  uint8_t reserved[32];
} SceSaveDataMemorySet2;

typedef struct _SceSaveDataEventParam SceSaveDataEventParam;

typedef struct SceSaveDataEvent {
  SceSaveDataEventType type;
  int32_t errorCode;
  SceUserServiceUserId userId;
  uint8_t padding[4];
  SceSaveDataTitleId titleId;
  SceSaveDataDirName dirName;
  uint8_t reserved[40];
} SceSaveDataEvent;
