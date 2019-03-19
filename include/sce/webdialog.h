#pragma once

#include <stdint.h>
#include <string.h>

#include <sce/commondialog.h>
#include <sce/types/webdialog.h>

int32_t sceWebBrowserDialogInitialize(void);
int32_t sceWebBrowserDialogOpen(const SceWebBrowserDialogParam *param);
int32_t sceWebBrowserDialogOpenForPredeterminedContent(const SceWebBrowserDialogParam *param, SceWebBrowserDialogPredeterminedContentParam *param2);
SceCommonDialogStatus sceWebBrowserDialogUpdateStatus(void);
SceCommonDialogStatus sceWebBrowserDialogGetStatus(void);
int32_t sceWebBrowserDialogGetResult(SceWebBrowserDialogResult *result);
int32_t sceWebBrowserDialogTerminate(void);
int32_t sceWebBrowserDialogClose(void);
int32_t sceWebBrowserDialogResetCookie(const SceWebBrowserDialogResetCookieParam *param);
int32_t sceWebBrowserDialogSetCookie(const SceWebBrowserDialogSetCookieParam *param);

static inline void sceWebBrowserDialogParamInitialize(SceWebBrowserDialogParam *param) {
  memset(param, 0x0, sizeof(SceWebBrowserDialogParam));
  _sceCommonDialogBaseParamInit(&param->baseParam);
  param->size = sizeof(SceWebBrowserDialogParam);
}
