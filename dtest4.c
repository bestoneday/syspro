#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
int main()
{
	void *pHandle;
	void (*pFunc)();
	int *p;
	pHandle=dlopen("./dtest1.so",RTLD_NOW);
	if(!pHandle)
		{
			puts("Can't find dtest1.so\n");
			exit(1);
		}
	pFunc= (void(*)())dlsym(pHandle,"print");
	if(pFunc)
		pFunc();
	else
		puts("Can't find function print\n");
	p=(int *)dlsym(pHandle,"p");
	if(p)
		printf("p=%d",*p);
	else
		printf("Can't find int p");
	dlclose(pHandle);
	return 0;
}
