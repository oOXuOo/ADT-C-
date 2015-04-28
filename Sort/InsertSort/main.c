#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void insert_sort(void*,size_t,size_t,int(*)(const void*,const void*));

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
	
	insert_sort(num,count,sizeof(int),cmp);
	
	for(i=0;i<count;i++)
		printf("%d ",num[i]);
	
	putchar('\n');
	return 0;
}

void insert_sort(void* start,size_t length,size_t ele_size,int(* cmp)(const void*,const void*))
{
	char * cache = (char*)malloc(ele_size);
	int i,j;
	for(i=0;i<length;i++)
		{
		char *p = (char*)start + i*ele_size;
		memcpy((void*)cache,(void*)p,ele_size);
		for(j=0;j<i;j++)
			if((*cmp)(cache,(char*)start + j*ele_size))
				{
				void* src = (char*)start + j*ele_size;
				void* dst = src+ele_size;
				memmove(dst,src,(i-j)*ele_size);
				memcpy(src,cache,ele_size);
				break;
				}
		}
	free(cache);
}