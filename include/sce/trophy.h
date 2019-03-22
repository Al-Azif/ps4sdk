#pragma once

#include <stddef.h>
#include <stdint.h>

#include <sce/types/userservice.h>
#include <sce/types/trophy.h>

int sceNpTrophyCreateHandle(SceNpTrophyHandle *handle);
int sceNpTrophyDestroyHandle(SceNpTrophyHandle handle);
int sceNpTrophyAbortHandle(SceNpTrophyHandle handle);
int sceNpTrophyCreateContext(SceNpTrophyContext *context, SceUserServiceUserId userId, SceNpServiceLabel serviceLabel, uint64_t options);
int sceNpTrophyDestroyContext(SceNpTrophyContext context);
int sceNpTrophyRegisterContext(SceNpTrophyContext context, SceNpTrophyHandle handle, uint64_t options);
int sceNpTrophyUnlockTrophy(SceNpTrophyContext context, SceNpTrophyHandle handle, SceNpTrophyId trophyId, SceNpTrophyId *platinumId);
int sceNpTrophyGetTrophyUnlockState(SceNpTrophyContext context, SceNpTrophyHandle handle, SceNpTrophyFlagArray *flags, uint32_t *count);
int sceNpTrophyGetGameInfo(SceNpTrophyContext context, SceNpTrophyHandle handle, SceNpTrophyGameDetails *details, SceNpTrophyGameData *data);
int sceNpTrophyGetGroupInfo(SceNpTrophyContext context, SceNpTrophyHandle handle, SceNpTrophyGroupId groupId, SceNpTrophyGroupDetails *details, SceNpTrophyGroupData *data);
int sceNpTrophyGetTrophyInfo(SceNpTrophyContext context, SceNpTrophyHandle handle, SceNpTrophyId trophyId, SceNpTrophyDetails *details, SceNpTrophyData *data);
int sceNpTrophyGetGameIcon(SceNpTrophyContext context, SceNpTrophyHandle handle, void *buffer, size_t *size);
int sceNpTrophyGetGroupIcon(SceNpTrophyContext context, SceNpTrophyHandle handle, SceNpTrophyGroupId groupId, void *buffer, size_t *size);
int sceNpTrophyGetTrophyIcon(SceNpTrophyContext context, SceNpTrophyHandle handle, SceNpTrophyId trophyId, void *buffer, size_t *size);
int sceNpTrophyShowTrophyList(SceNpTrophyContext context, SceNpTrophyHandle handle);
int sceNpTrophyCaptureScreenshot(SceNpTrophyHandle handle, const SceNpTrophyScreenshotTarget *targets, uint32_t numTargets);
