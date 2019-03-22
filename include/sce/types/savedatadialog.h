#pragma once

#include <stddef.h>
#include <stdint.h>

#include <sce/types/commondialog.h>
#include <sce/types/savedata.h>
#include <sce/types/userservice.h>

#define SCE_SAVE_DATA_DIALOG_USER_MSG_MAXSIZE (256)

typedef int32_t SceSaveDataDialogMode;
#define SCE_SAVE_DATA_DIALOG_MODE_INVALID (0)
#define SCE_SAVE_DATA_DIALOG_MODE_LIST (1)
#define SCE_SAVE_DATA_DIALOG_MODE_USER_MSG (2)
#define SCE_SAVE_DATA_DIALOG_MODE_SYSTEM_MSG (3)
#define SCE_SAVE_DATA_DIALOG_MODE_ERROR_CODE (4)
#define SCE_SAVE_DATA_DIALOG_MODE_PROGRESS_BAR (5)

typedef int32_t SceSaveDataDialogType;
#define SCE_SAVE_DATA_DIALOG_TYPE_INVALID (0)
#define SCE_SAVE_DATA_DIALOG_TYPE_SAVE (1)
#define SCE_SAVE_DATA_DIALOG_TYPE_LOAD (2)
#define SCE_SAVE_DATA_DIALOG_TYPE_DELETE (3)

typedef int32_t SceSaveDataDialogFocusPos;
#define SCE_SAVE_DATA_DIALOG_FOCUS_POS_LISTHEAD (0)
#define SCE_SAVE_DATA_DIALOG_FOCUS_POS_LISTTAIL (1)
#define SCE_SAVE_DATA_DIALOG_FOCUS_POS_DATAHEAD (2)
#define SCE_SAVE_DATA_DIALOG_FOCUS_POS_DATATAIL (3)
#define SCE_SAVE_DATA_DIALOG_FOCUS_POS_DATALATEST (4)
#define SCE_SAVE_DATA_DIALOG_FOCUS_POS_DATAOLDEST (5)
#define SCE_SAVE_DATA_DIALOG_FOCUS_POS_DIRNAME (6)

typedef int32_t SceSaveDataDialogSystemMessageType;
#define SCE_SAVE_DATA_DIALOG_SYSMSG_TYPE_INVALID (0)
#define SCE_SAVE_DATA_DIALOG_SYSMSG_TYPE_NODATA (1)
#define SCE_SAVE_DATA_DIALOG_SYSMSG_TYPE_CONFIRM (2)
#define SCE_SAVE_DATA_DIALOG_SYSMSG_TYPE_OVERWRITE (3)
#define SCE_SAVE_DATA_DIALOG_SYSMSG_TYPE_NOSPACE (4)
#define SCE_SAVE_DATA_DIALOG_SYSMSG_TYPE_PROGRESS (5)
#define SCE_SAVE_DATA_DIALOG_SYSMSG_TYPE_FILE_CORRUPTED (6)
#define SCE_SAVE_DATA_DIALOG_SYSMSG_TYPE_FINISHED (7)
#define SCE_SAVE_DATA_DIALOG_SYSMSG_TYPE_NOSPACE_CONTINUABLE (8)
#define SCE_SAVE_DATA_DIALOG_SYSMSG_TYPE_CORRUPTED_AND_DELETE (10)
#define SCE_SAVE_DATA_DIALOG_SYSMSG_TYPE_CORRUPTED_AND_CREATE (11)
#define SCE_SAVE_DATA_DIALOG_SYSMSG_TYPE_CORRUPTED_AND_RESTORE (13)
#define SCE_SAVE_DATA_DIALOG_SYSMSG_TYPE_TOTAL_SIZE_EXCEEDED (14)

typedef int32_t SceSaveDataDialogButtonType;
#define SCE_SAVE_DATA_DIALOG_BUTTON_TYPE_OK (0)
#define SCE_SAVE_DATA_DIALOG_BUTTON_TYPE_YESNO (1)
#define SCE_SAVE_DATA_DIALOG_BUTTON_TYPE_NONE (2)
#define SCE_SAVE_DATA_DIALOG_BUTTON_TYPE_OKCANCEL (3)

typedef int32_t SceSaveDataDialogButtonId;
#define SCE_SAVE_DATA_DIALOG_BUTTON_ID_INVALID (0)
#define SCE_SAVE_DATA_DIALOG_BUTTON_ID_OK (1)
#define SCE_SAVE_DATA_DIALOG_BUTTON_ID_YES (1)
#define SCE_SAVE_DATA_DIALOG_BUTTON_ID_NO (2)

typedef int32_t SceSaveDataDialogOptionBack;
#define SCE_SAVE_DATA_DIALOG_OPTION_BACK_ENABLE (0)
#define SCE_SAVE_DATA_DIALOG_OPTION_BACK_DISABLE (1)

typedef int32_t SceSaveDataDialogProgressBarType;
#define SCE_SAVE_DATA_DIALOG_PROGRESSBAR_TYPE_PERCENTAGE (0)

typedef int32_t SceSaveDataDialogProgressBarTarget;
#define SCE_SAVE_DATA_DIALOG_PROGRESSBAR_TARGET_BAR_DEFAULT (0)

typedef int32_t SceSaveDataDialogItemStyle;
#define SCE_SAVE_DATA_DIALOG_ITEM_STYLE_TITLE_DATESIZE_SUBTITLE (0)
#define SCE_SAVE_DATA_DIALOG_ITEM_STYLE_TITLE_SUBTITLE_DATESIZE (1)
#define SCE_SAVE_DATA_DIALOG_ITEM_STYLE_TITLE_DATESIZE (2)

typedef int32_t SceSaveDataDialogAnimation;
#define SCE_SAVE_DATA_DIALOG_ANIMATION_ON (0)
#define SCE_SAVE_DATA_DIALOG_ANIMATION_OFF (1)

typedef int32_t SceSaveDataDialogUserMessageType;
#define SCE_SAVE_DATA_DIALOG_USERMSG_TYPE_NORMAL (0)
#define SCE_SAVE_DATA_DIALOG_USERMSG_TYPE_ERROR (1)

typedef int32_t SceSaveDataDialogProgressSystemMessageType;
#define SCE_SAVE_DATA_DIALOG_PRGRESS_SYSMSG_TYPE_INVALID (0)
#define SCE_SAVE_DATA_DIALOG_PRGRESS_SYSMSG_TYPE_PROGRESS (1)
#define SCE_SAVE_DATA_DIALOG_PRGRESS_SYSMSG_TYPE_RESTORE (2)

typedef struct SceSaveDataDialogAnimationParam {
  SceSaveDataDialogAnimation userOK;
  SceSaveDataDialogAnimation userCancel;
  uint8_t reserved[32];
} SceSaveDataDialogAnimationParam;

typedef struct SceSaveDataDialogNewItem {
  const char *title;
  void *iconBuf;
  size_t iconSize;
  uint8_t reserved[32];
} SceSaveDataDialogNewItem;

typedef struct SceSaveDataDialogItems {
  SceUserServiceUserId userId;
  int32_t : 32;
  const SceSaveDataTitleId *titleId;
  const SceSaveDataDirName *dirName;
  uint32_t dirNameNum;
  int32_t : 32;
  const SceSaveDataDialogNewItem *newItem;
  SceSaveDataDialogFocusPos focusPos;
  int32_t : 32;
  const SceSaveDataDirName *focusPosDirName;
  SceSaveDataDialogItemStyle itemStyle;
  uint8_t reserved[36];
} SceSaveDataDialogItems;

typedef struct SceSaveDataDialogUserMessageParam {
  SceSaveDataDialogButtonType buttonType;
  SceSaveDataDialogUserMessageType msgType;
  const char *msg;
  uint8_t reserved[32];
} SceSaveDataDialogUserMessageParam;

typedef struct SceSaveDataDialogSystemMessageParam {
  SceSaveDataDialogSystemMessageType sysMsgType;
  int32_t : 32;
  uint64_t value;
  uint8_t reserved[32];
} SceSaveDataDialogSystemMessageParam;

typedef struct SceSaveDataDialogErrorCodeParam {
  int32_t errorCode;
  uint8_t reserved[32];
} SceSaveDataDialogErrorCodeParam;

typedef struct SceSaveDataDialogProgressBarParam {
  SceSaveDataDialogProgressBarType barType;
  int32_t : 32;
  const char *msg;
  SceSaveDataDialogProgressSystemMessageType sysMsgType;
  uint8_t reserved[28];
} SceSaveDataDialogProgressBarParam;

typedef struct SceSaveDataDialogOptionParam {
  SceSaveDataDialogOptionBack back;
  uint8_t reserved[32];
} SceSaveDataDialogOptionParam;

typedef struct SceSaveDataDialogParam {
  SceCommonDialogBaseParam baseParam;
  int32_t size;
  SceSaveDataDialogMode mode;
  SceSaveDataDialogType dispType;
  int32_t : 32;
  SceSaveDataDialogAnimationParam *animParam;
  SceSaveDataDialogItems *items;
  SceSaveDataDialogUserMessageParam *userMsgParam;
  SceSaveDataDialogSystemMessageParam *sysMsgParam;
  SceSaveDataDialogErrorCodeParam *errorCodeParam;
  SceSaveDataDialogProgressBarParam *progBarParam;
  void *userData;
  SceSaveDataDialogOptionParam *optionParam;
  uint8_t reserved[24];
} SceSaveDataDialogParam;

typedef struct SceSaveDataDialogCloseParam {
  SceSaveDataDialogAnimation anim;
  uint8_t reserved[32];
} SceSaveDataDialogCloseParam;

typedef struct SceSaveDataDialogResult {
  SceSaveDataDialogMode mode;
  int32_t result;
  SceSaveDataDialogButtonId buttonId;
  int32_t : 32;
  SceSaveDataDirName *dirName;
  SceSaveDataParam *param;
  void *userData;
  uint8_t reserved[32];
} SceSaveDataDialogResult;
