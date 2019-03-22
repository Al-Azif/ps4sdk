#pragma once

#include <stddef.h>
#include <stdint.h>

#include <sce/types/commondialog.h>
#include <sce/types/userservice.h>

#define SCE_MSG_DIALOG_USER_MSG_SIZE (8192)

typedef int32_t SceMsgDialogMode;
#define SCE_MSG_DIALOG_MODE_INVALID (0)
#define SCE_MSG_DIALOG_MODE_USER_MSG (1)
#define SCE_MSG_DIALOG_MODE_PROGRESS_BAR (2)
#define SCE_MSG_DIALOG_MODE_SYSTEM_MSG (3)

typedef int32_t SceMsgDialogSystemMessageType;
#define SCE_MSG_DIALOG_SYSMSG_TYPE_TRC_EMPTY_STORE (0)
#define SCE_MSG_DIALOG_SYSMSG_TYPE_TRC_PSN_CHAT_RESTRICTION (1)
#define SCE_MSG_DIALOG_SYSMSG_TYPE_TRC_PSN_UGC_RESTRICTION (2)
#define SCE_MSG_DIALOG_SYSMSG_TYPE_CAMERA_NOT_CONNECTED (4)
#define SCE_MSG_DIALOG_SYSMSG_TYPE_WARNING_PROFILE_PICTURE_AND_NAME_NOT_SHARED (5)

typedef int32_t SceMsgDialogButtonType;
#define SCE_MSG_DIALOG_BUTTON_TYPE_OK (0)
#define SCE_MSG_DIALOG_BUTTON_TYPE_YESNO (1)
#define SCE_MSG_DIALOG_BUTTON_TYPE_NONE (2)
#define SCE_MSG_DIALOG_BUTTON_TYPE_OK_CANCEL (3)
#define SCE_MSG_DIALOG_BUTTON_TYPE_CANCEL (4)
#define SCE_MSG_DIALOG_BUTTON_TYPE_WAIT (5)
#define SCE_MSG_DIALOG_BUTTON_TYPE_WAIT_CANCEL (6)
#define SCE_MSG_DIALOG_BUTTON_TYPE_YESNO_FOCUS_NO (7)
#define SCE_MSG_DIALOG_BUTTON_TYPE_OK_CANCEL_FOCUS_CANCEL (8)
#define SCE_MSG_DIALOG_BUTTON_TYPE_2BUTTONS (9)

typedef int32_t SceMsgDialogButtonId;
#define SCE_MSG_DIALOG_BUTTON_ID_INVALID (0)
#define SCE_MSG_DIALOG_BUTTON_ID_OK (1)
#define SCE_MSG_DIALOG_BUTTON_ID_YES (1)
#define SCE_MSG_DIALOG_BUTTON_ID_NO (2)
#define SCE_MSG_DIALOG_BUTTON_ID_BUTTON1 (1)
#define SCE_MSG_DIALOG_BUTTON_ID_BUTTON2 (2)

typedef int32_t SceMsgDialogProgressBarType;
#define SCE_MSG_DIALOG_PROGRESSBAR_TYPE_PERCENTAGE (0)
#define SCE_MSG_DIALOG_PROGRESSBAR_TYPE_PERCENTAGE_CANCEL (1)

typedef int32_t SceMsgDialogProgressBarTarget;
#define SCE_MSG_DIALOG_PROGRESSBAR_TARGET_BAR_DEFAULT (0)

#define SCE_MSG_DIALOG_BUTTON_MSG_SIZE (64)

typedef struct SceMsgDialogButtonsParam {
  const char *msg1;
  const char *msg2;
  char reserved[32];
} SceMsgDialogButtonsParam;

typedef struct SceMsgDialogUserMessageParam {
  SceMsgDialogButtonType buttonType;
  int : 32;
  const char *msg;
  SceMsgDialogButtonsParam *buttonsParam;
  char reserved[24];
} SceMsgDialogUserMessageParam;

typedef struct SceMsgDialogSystemMessageParam {
  SceMsgDialogSystemMessageType sysMsgType;
  char reserved[32];
} SceMsgDialogSystemMessageParam;

typedef struct SceMsgDialogProgressBarParam {
  SceMsgDialogProgressBarType barType;
  int : 32;
  const char *msg;
  char reserved[64];
} SceMsgDialogProgressBarParam;

typedef struct SceMsgDialogParam {
  SceCommonDialogBaseParam baseParam;
  size_t size;
  SceMsgDialogMode mode;
  int : 32;
  SceMsgDialogUserMessageParam *userMsgParam;
  SceMsgDialogProgressBarParam *progBarParam;
  SceMsgDialogSystemMessageParam *sysMsgParam;
  SceUserServiceUserId userId;
  char reserved[40];
  int : 32;
} SceMsgDialogParam;

typedef struct SceMsgDialogResult {
  SceMsgDialogMode mode;
  int32_t result;
  SceMsgDialogButtonId buttonId;
  char reserved[32];
} SceMsgDialogResult;
