#pragma once

#include <stddef.h>
#include <stdint.h>

#define SCE_COMMON_DIALOG_MAGIC_NUMBER 0xC0D1A109

typedef enum SceCommonDialogStatus {
  SCE_COMMON_DIALOG_STATUS_NONE = 0,
  SCE_COMMON_DIALOG_STATUS_INITIALIZED = 1,
  SCE_COMMON_DIALOG_STATUS_RUNNING = 2,
  SCE_COMMON_DIALOG_STATUS_FINISHED = 3
} SceCommonDialogStatus;

typedef enum SceCommonDialogResult {
  SCE_COMMON_DIALOG_RESULT_OK = 0,
  SCE_COMMON_DIALOG_RESULT_USER_CANCELED = 1,
} SceCommonDialogResult;

typedef struct SceCommonDialogBaseParam {
  size_t size;
  uint8_t reserved[36];
  uint32_t magic;
} SceCommonDialogBaseParam;
