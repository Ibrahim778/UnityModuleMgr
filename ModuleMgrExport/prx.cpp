#include <kernel.h>
#include <stdio.h>

#define PRX_EXPORT extern "C" __declspec (dllexport)

PRX_EXPORT int esceKernelLoadModule(const char *moduleFileName, int flags)
{	
	return sceKernelLoadModule(moduleFileName, 0, NULL);
}

PRX_EXPORT int esceKernelStartModule(int id, int flags)
{
	int res = 0;
	int module_start = 0;
	res = sceKernelStartModule(id, 0, NULL, flags, NULL, &module_start);
	return res;
}

PRX_EXPORT int esceKernelLoadStartModule(char *moduleFileName, int flags)
{
	int res = 0;
	int module_start = 0;

	sceKernelLoadStartModule(moduleFileName, 0, NULL, flags, 0, &module_start);

	return res;
}

PRX_EXPORT int esceKernelStopModule(int uid, int flags)
{
	int module_stop = 0;
	int res = 0;
	res = sceKernelStopModule(uid, 0, NULL, flags, 0, &module_stop);
	if (res < 0) return res;
	return module_stop;
}

PRX_EXPORT int esceKernelUnloadModule(int uid, int flags)
{
	return sceKernelUnloadModule(uid, flags, 0);
}

PRX_EXPORT int esceKernelStopUnloadModule(int uid, int flags)
{
	int module_stop = 0;
	int res = 0;
	sceKernelStopUnloadModule(uid, 0, NULL, flags, 0, &module_stop);
	if (res < 0) return res;
	return module_stop;
}