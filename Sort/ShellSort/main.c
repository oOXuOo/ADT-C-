#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void shell_sort(void*,size_t,size_t,int(*)(const void*,const void*));

int cmp(const void* a,const void* b)
{
	return *(int*)a > *(int*)b;
}

int main(int argc, char **argv)
{
	int i,num[100],count=0;
	do
		scanf("%d",&num[count++]);
	while(getchar()!='\n');
	
	shell_sort(num,count,sizeof(int),cmp);
	
	for(i=0;i<count;i++)
		printf("%d ",num[i]);
	
	putchar('\n');
	return 0;
}

void shell_sort(void* start,size_t length,size_t ele_size,int(* cmp)(const void*,const void*))
{
	char * cache = (char*)malloc(ele_size);
	int gap;
	for(gap = length/2;gap>0;gap/=2)
		{
		int i,j;
		for(i=0;i<length;i++)
			{
			char *p = (char*)start + i*ele_size;
			memcpy((void*)cache,(void*)p,ele_size);
			for(j=i-gap;j>=0;j-=gap)
				if((*cmp)(cache,(char*)start + j*ele_size))
					{
					void* src = (char*)start + j*ele_size;
					void* dst = (char*)start + (j+gap)*ele_size;
					memmove(dst,src,ele_size);
					memcpy(src,cache,ele_size);
					}
			}
		}
	free(cache);
}