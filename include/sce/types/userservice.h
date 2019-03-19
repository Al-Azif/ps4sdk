#pragma once

#include <stdint.h>

typedef int32_t SceUserServiceUserId;

#define SCE_USER_SERVICE_MAX_LOGIN_USERS (4)
#define SCE_USER_SERVICE_MAX_USER_NAME_LENGTH (16)
#define SCE_USER_SERVICE_USER_ID_INVALID (-1)
#define SCE_USER_SERVICE_USER_ID_SYSTEM (0xFF)
#define SCE_USER_SERVICE_USER_ID_EVERYONE (0xFE)

typedef struct SceUserServiceInitializeParams {
  int32_t priority;
} SceUserServiceInitializeParams;

typedef enum SceUserServiceEventType {
  SCE_USER_SERVICE_EVENT_TYPE_LOGIN = 0,
  SCE_USER_SERVICE_EVENT_TYPE_LOGOUT
} SceUserServiceEventType;

typedef struct SceUserServiceEvent {
  SceUserServiceEventType eventType;
  SceUserServiceUserId userId;
} SceUserServiceEvent;

typedef struct SceUserServiceLoginUserIdList {
  SceUserServiceUserId userId[SCE_USER_SERVICE_MAX_LOGIN_USERS];
} SceUserServiceLoginUserIdList;

typedef enum SceUserServiceUserColor {
  SCE_USER_SERVICE_USER_COLOR_BLUE = 0,
  SCE_USER_SERVICE_USER_COLOR_RED,
  SCE_USER_SERVICE_USER_COLOR_GREEN,
  SCE_USER_SERVICE_USER_COLOR_PINK
} SceUserServiceUserColor;
