#pragma once

#include <stddef.h>
#include <stdint.h>

#include <sce/types/commondialog.h>
#include <sce/types/userservice.h>

#define SCE_WEB_BROWSER_DIALOG_URL_SIZE (2048)
#define SCE_WEB_BROWSER_DIALOG_URL_SIZE_EXTENDED (8192)
#define SCE_WEB_BROWSER_DIALOG_DOMAIN_SIZE (256)
#define SCE_WEB_BROWSER_DIALOG_DOMAIN_COUNT (20)

#define SCE_WEB_BROWSER_DIALOG_MODE_INVALID (0)
#define SCE_WEB_BROWSER_DIALOG_MODE_DEFAULT (1)
#define SCE_WEB_BROWSER_DIALOG_MODE_CUSTOM (2)

#define SCE_WEB_BROWSER_DIALOG_CALLBACK_PARAM_TYPE_NONE (0)
#define SCE_WEB_BROWSER_DIALOG_CALLBACK_PARAM_TYPE_URL (1)

#define SCE_WEB_BROWSER_DIALOG_CUSTOM_PARTS_NONE (0)
#define SCE_WEB_BROWSER_DIALOG_CUSTOM_PARTS_TITLE (1 << 0)
#define SCE_WEB_BROWSER_DIALOG_CUSTOM_PARTS_ADDRESS (1 << 1)
#define SCE_WEB_BROWSER_DIALOG_CUSTOM_PARTS_FOOTER (1 << 2)
#define SCE_WEB_BROWSER_DIALOG_CUSTOM_PARTS_BACKGROUND (1 << 3)
#define SCE_WEB_BROWSER_DIALOG_CUSTOM_PARTS_WAIT_DIALOG (1 << 4)

#define SCE_WEB_BROWSER_DIALOG_CUSTOM_CONTROL_NONE (0)
#define SCE_WEB_BROWSER_DIALOG_CUSTOM_CONTROL_EXIT (1 << 0)
#define SCE_WEB_BROWSER_DIALOG_CUSTOM_CONTROL_RELOAD (1 << 1)
#define SCE_WEB_BROWSER_DIALOG_CUSTOM_CONTROL_BACK (1 << 2)
#define SCE_WEB_BROWSER_DIALOG_CUSTOM_CONTROL_FORWARD (1 << 3)
#define SCE_WEB_BROWSER_DIALOG_CUSTOM_CONTROL_ZOOM (1 << 4)
#define SCE_WEB_BROWSER_DIALOG_CUSTOM_CONTROL_EXIT_UNTIL_COMPLETE (1 << 5)

#define SCE_WEB_BROWSER_DIALOG_IME_OPTION_DEFAULT 0x00000000
#define SCE_WEB_BROWSER_DIALOG_IME_OPTION_NO_AUTO_CAPITALIZATION 0x00000002
#define SCE_WEB_BROWSER_DIALOG_IME_OPTION_NO_LEARNING 0x00000020
#define SCE_WEB_BROWSER_DIALOG_IME_OPTION_DISABLE_COPY_PASTE 0x00000080
#define SCE_WEB_BROWSER_DIALOG_IME_OPTION_DISABLE_AUTO_SPACE 0x00000200

#define SCE_WEB_BROWSER_DIALOG_WEBVIEW_OPTION_NONE (0)
#define SCE_WEB_BROWSER_DIALOG_WEBVIEW_OPTION_BACKGROUND_TRANSPARENCY (1 << 0)
#define SCE_WEB_BROWSER_DIALOG_WEBVIEW_OPTION_CURSOR_NONE (1 << 1)

#define SCE_WEB_BROWSER_DIALOG_ANIMATION_DEFAULT (0)
#define SCE_WEB_BROWSER_DIALOG_ANIMATION_DISABLE (1)

#define SCE_WEB_BROWSER_DIALOG_COOKIE_COUNT (10)
#define SCE_WEB_BROWSER_DIALOG_COOKIE_URL_SIZE (2048)
#define SCE_WEB_BROWSER_DIALOG_COOKIE_DATA_SIZE (4096)

typedef struct SceWebBrowserDialogCallbackInitParam {
  size_t size;
  int32_t type;
  int : 32;
  const char* data;
  char reserved[32];
} SceWebBrowserDialogCallbackInitParam;

typedef struct SceWebBrowserDialogCallbackResultParam {
  size_t size;
  int32_t type;
  char data[SCE_WEB_BROWSER_DIALOG_URL_SIZE];
  uint8_t reserved0[4];
  char* buffer;
  uint32_t bufferSize;
  char reserved[20];
} SceWebBrowserDialogCallbackResultParam;

typedef struct SceWebBrowserDialogImeParam {
  size_t size;
  uint32_t option;
  char reserved[256];
  int : 32;
} SceWebBrowserDialogImeParam;

typedef struct SceWebBrowserDialogWebViewParam {
  size_t size;
  uint32_t option;
  char reserved[256];
  int : 32;
} SceWebBrowserDialogWebViewParam;

typedef struct SceWebBrowserDialogPredeterminedContentParam {
  size_t size;
  const char* domain[SCE_WEB_BROWSER_DIALOG_DOMAIN_COUNT];
  char reserved[256];
} SceWebBrowserDialogPredeterminedContentParam;

typedef struct SceWebBrowserDialogParam {
  SceCommonDialogBaseParam baseParam;
  size_t size;
  int32_t mode;
  SceUserServiceUserId userId;
  const char* url;
  SceWebBrowserDialogCallbackInitParam* callbackInitParam;
  uint16_t width;
  uint16_t height;
  uint16_t positionX;
  uint16_t positionY;
  uint32_t parts;
  uint16_t headerWidth;
  uint16_t headerPositionX;
  uint16_t headerPositionY;
  short : 16;
  uint32_t control;
  SceWebBrowserDialogImeParam* imeParam;
  SceWebBrowserDialogWebViewParam* webviewParam;
  uint32_t animation;
  char reserved[202];
  short : 16;
} SceWebBrowserDialogParam;

typedef struct SceWebBrowserDialogResult {
  int32_t result;
  int : 32;
  SceWebBrowserDialogCallbackResultParam* callbackResultParam;
  char reserved[240];
} SceWebBrowserDialogResult;

typedef struct SceWebBrowserDialogResetCookieParam {
  size_t size;
  char reserved[256];
} SceWebBrowserDialogResetCookieParam;

typedef struct SceWebBrowserDialogSetCookieParam {
  size_t size;
  const char* url;
  const char* cookie;
  char reserved[256];
} SceWebBrowserDialogSetCookieParam;
