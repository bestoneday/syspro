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
	starttime=tv.tv_usec;
	
	if(argc!=3) puts("wrong usage.");
	if(!(fds=fopen(argv[1],"rb"))) puts("source open wrong");
	if(!(fdt=fopen(argv[2],"wb+"))) puts("target wrong");
	
	while(size)
		{
			size=fread(buf,sizeof(char),1024,fds);
			if(size==-1) puts("copy wrong");
			else if(size>0) fwrite(buf,sizeof(char),size,fdt);
			
		}
	fclose(fdt);
	fclose(fds);
	gettimeofday(&tv,NULL);
	endtime=tv.tv_usec;
	printf("done,cost %ld us\n",endtime-starttime);
	return 0;
}

