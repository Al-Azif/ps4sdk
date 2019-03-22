#pragma once

#include <stdint.h>
#include <string.h>

#include <sce/commondialog.h>
#include <sce/types/savedatadialog.h>

static inline void sceSaveDataDialogParamInitialize(SceSaveDataDialogParam *param) {
  memset(param, 0x0, sizeof(SceSaveDataDialogParam));
  _sceCommonDialogBaseParamInit(&param->baseParam);
  param->size = sizeof(SceSaveDataDialogParam);
}

int32_t sceSaveDataDialogInitialize();
int32_t sceSaveDataDialogTerminate(void);
SceCommonDialogStatus sceSaveDataDialogUpdateStatus(void);
SceCommonDialogStatus sceSaveDataDialogGetStatus(void);
int32_t sceSaveDataDialogGetResult(SceSaveDataDialogResult *result);
int32_t sceSaveDataDialogOpen(const SceSaveDataDialogParam *param);
int32_t sceSaveDataDialogClose(const SceSaveDataDialogCloseParam *closeParam);
int32_t sceSaveDataDialogProgressBarInc(SceSaveDataDialogProgressBarTarget target, uint32_t delta);
int32_t sceSaveDataDialogProgressBarSetValue(SceSaveDataDialogProgressBarTarget target, uint32_t rate);
int32_t sceSaveDataDialogIsReadyToDisplay();
