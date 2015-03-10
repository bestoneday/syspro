#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc,char *argv[])
{
	int fdt=-1;
	int fds=-1;
	ssize_t size=-1;
	char buf[1024];
	struct timeval tv;
	long starttime,endtime;
	gettimeofday(&tv,NULL);
	starttime=tv.tv_usec;
	if(argc!=3)
		{
			puts("usage wrong");
			return 1;
		}
	fds=open(argv[1],O_RDONLY|O_EXCL);
	if(fds==-1)
		{
			puts("source open wrong");
			return 2;
		}
	fdt=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,00666);

	if(fdt==-1)
		{
			puts("source open wrong");
			return 3;
		}
	
	while(size)
		{
			size=read(fds,buf,1024);
			if(size!=-1)
				{
					if(size>0)
						write(fdt,buf,size);	
				}
			else
				{puts("copy wrong");
				 return 4;
				}
		}
	close(fds);
	close(fdt);
	gettimeofday(&tv,NULL);
	endtime=tv.tv_usec;
	printf("running time:%ld us\n",endtime-starttime);
	return 0;

}
