#pragma once

#include <stdint.h>
#include <string.h>

#include <sce/types/errordialog.h>
#include <sce/types/userservice.h>

int32_t sceErrorDialogInitialize(void);
int32_t sceErrorDialogTerminate(void);
int32_t sceErrorDialogOpen(const SceErrorDialogParam *param);
int32_t sceErrorDialogClose(void);
SceErrorDialogStatus sceErrorDialogUpdateStatus(void);
SceErrorDialogStatus sceErrorDialogGetStatus(void);

static inline void sceErrorDialogParamInitialize(SceErrorDialogParam *param) {
  memset(param, 0x0, sizeof(SceErrorDialogParam));
  param->size = sizeof(SceErrorDialogParam);
  param->userId = SCE_USER_SERVICE_USER_ID_EVERYONE;
}
