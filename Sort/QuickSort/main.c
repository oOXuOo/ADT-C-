#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void quick_sort(void*,size_t,size_t,int(*)(const void*,const void*));

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
	
	quick_sort(num,count,sizeof(int),cmp);
	
	for(i=0;i<count;i++)
		printf("%d ",num[i]);
	
	putchar('\n');
	return 0;
}

void* partition(void* start,size_t length,size_t ele_size,int(* cmp)(const void*,const void*))
{
	char *big = (char*)start + ele_size*(length-1);
	char *small = start;
	char *cache = malloc(ele_size);
	memcpy(cache,start,ele_size);
	while(small<big)
		{
		while((*cmp)(cache,big)&&small<big) big-=ele_size;
		memcpy(small,big,ele_size);
		while((*cmp)(small,cache)&&small<big) small+=ele_size;
		memcpy(big,small,ele_size);
		}
	memcpy(small,cache,ele_size);
	free(cache);
	return (void*)small;
}
void quick_sort(void* start,size_t length,size_t ele_size,int(* cmp)(const void*,const void*))
{
	if(length>1 )
		{
		void* mid = partition(start,length,ele_size,cmp);
		quick_sort((void*)start,((char*)mid-(char*)start)/ele_size,ele_size,cmp);
		quick_sort((void*)((char*)mid+ele_size),length-1-((char*)mid-(char*)start)/ele_size,ele_size,cmp);
		}
}