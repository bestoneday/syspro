#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
int main(int argc,char *argv[])
{
	FILE *fds,*fdt;
	char answer='n';
	ssize_t	size=-1;
	char buf[1024];
	struct timeval tv;
	long starttime,endtime;
	gettimeofday(&tv,NULL);
	starttime=tv_usec;
	if(argc!=3)
		{
			printf("Usage:%s SOURCE TARGET.\n",argc[0];
)
			return 1;
		}
	fds=fopen(argv[1],"rb");
	if(fds==NULL)
		{
			printf("Usage:%s source doesn't exist.\n",argc[0]);
			return 1;

		}
	fdt=fopen(argv[2],"wb+");
	if(fdt==NULL)
	{}

	fds=fopen()
}
