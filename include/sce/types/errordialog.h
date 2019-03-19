#pragma once

#include <stdint.h>

#include <sce/types/userservice.h>

typedef enum SceErrorDialogStatus {
  SCE_ERROR_DIALOG_STATUS_NONE = 0,
  SCE_ERROR_DIALOG_STATUS_INITIALIZED = 1,
  SCE_ERROR_DIALOG_STATUS_RUNNING = 2,
  SCE_ERROR_DIALOG_STATUS_FINISHED = 3
} SceErrorDialogStatus;

typedef struct SceErrorDialogParam {
  int32_t size;
  int32_t errorCode;
  SceUserServiceUserId userId;
  int32_t reserved;
} SceErrorDialogParam;
