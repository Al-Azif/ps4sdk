#define _KERNEL

#include <sys/cdefs.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/kernel.h>
#include <sys/libkern.h>

#include <sys/kthread.h>
#include <sys/filedesc.h>
#include <sys/ucred.h>

#include <sys/syscall.h>
#include <sys/sysent.h>
#include <bsm/audit_kevents.h>

#include <ps4/kern.h>

int ps4KernSyscallCopyInAndPatch(int number, sy_call_t *call, size_t size, int argumentCount)//, uint32_t thrcnt)
{
	void *m;
	if(ps4KernMemoryAllocate(&m, size) != 0)
		return -1;
	ps4KernMemoryCopy((void *)call, m, size);
	return ps4KernSyscallPatch(number, (sy_call_t *)m, argumentCount);
}

int ps4KernSyscallPatch(int number, sy_call_t *call, int argumentCount)//, uint32_t thrcnt)
{
	if(!ps4KernIsKernelAddress((void *)call))
		return -1; // do not hook kernel code to userland Oo
	if(number > SYS_MAXSYSCALL)
		return -2;
	return ps4KernSyscallPatchUnsafe(number, call, argumentCount);
}

int ps4KernSyscallPatchUnsafe(int number, sy_call_t *call, int argumentCount)
{
    struct sysent *sy = ps4KernDlSym("sysent");
	if(sy == NULL)
		return -1;

    sy = &sy[number];
	memset(sy, 0, sizeof(*sy));
    sy->sy_narg = argumentCount;
    sy->sy_call = (sy_call_t *)call;
	//sy->sy_auevent = AUE_NULL;
	sy->sy_thrcnt = SY_THR_STATIC; //SY_THR_ABSENT

	return 0;
}
