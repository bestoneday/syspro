#include <sys/utsname.h>
#include <stdio.h>
void main()
{
	struct utsname sysinfo;
	uname(&sysinfo);

	printf("Sysname:%s\n",sysinfo.sysname);
	printf("Nodenam:%s\n",sysinfo.nodename);
	printf("Release:%s\n",sysinfo.release);
	printf("Version:%s\n",sysinfo.version);
	printf("Machine:%s\n",sysinfo.machine);
}
