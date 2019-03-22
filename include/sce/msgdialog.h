#pragma once

#include <stdint.h>
#include <string.h>

#include <sce/commondialog.h>
#include <sce/types/msgdialog.h>

static inline void sceMsgDialogParamInitialize(SceMsgDialogParam *param) {
  memset(param, 0x0, sizeof(SceMsgDialogParam));
  _sceCommonDialogBaseParamInit(&param->baseParam);
  param->size = sizeof(SceMsgDialogParam);
}

int32_t sceMsgDialogInitialize(void);
int32_t sceMsgDialogOpen(const SceMsgDialogParam *param);
SceCommonDialogStatus sceMsgDialogUpdateStatus(void);
SceCommonDialogStatus sceMsgDialogGetStatus(void);
int32_t sceMsgDialogGetResult(SceMsgDialogResult *result);
int32_t sceMsgDialogTerminate(void);
int32_t sceMsgDialogClose(void);
int32_t sceMsgDialogProgressBarInc(SceMsgDialogProgressBarTarget target, int32_t delta);
int32_t sceMsgDialogProgressBarSetValue(SceMsgDialogProgressBarTarget target, uint32_t rate);
int32_t sceMsgDialogProgressBarSetMsg(SceMsgDialogProgressBarTarget target, const char *barMsg);
