#pragma once

#include <stddef.h>
#include <stdint.h>

#include <sce/types/userservice.h>
// #include for sceKernelCpumask

int32_t sceUserServiceInitialize(const SceUserServiceInitializeParams *initParams);
// int32_t sceUserServiceInitialize2(int threadPriority, SceKernelCpumask cpuAffinityMask);
int32_t sceUserServiceTerminate();
int32_t sceUserServiceGetLoginUserIdList(SceUserServiceLoginUserIdList *userIdList);
int32_t sceUserServiceGetEvent(SceUserServiceEvent *event);
int32_t sceUserServiceGetInitialUser(SceUserServiceUserId *userId);
int32_t sceUserServiceGetUserName(const SceUserServiceUserId userId, char *userName, const size_t size);
int32_t sceUserServiceGetUserColor(const SceUserServiceUserId userId, SceUserServiceUserColor *color);
