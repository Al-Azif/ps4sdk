#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include <sce/types/commondialog.h>

int32_t sceCommonDialogInitialize();
bool sceCommonDialogIsUsed();

static inline void _sceCommonDialogSetMagicNumber(uint32_t* magic, const SceCommonDialogBaseParam* param) {
  *magic = (uint32_t)(SCE_COMMON_DIALOG_MAGIC_NUMBER + (uint64_t)param);
}

static inline void _sceCommonDialogBaseParamInit(SceCommonDialogBaseParam* param) {
  memset(param, 0x0, sizeof(SceCommonDialogBaseParam));
  param->size = (uint32_t)sizeof(SceCommonDialogBaseParam);
  _sceCommonDialogSetMagicNumber(&(param->magic), param);
}
