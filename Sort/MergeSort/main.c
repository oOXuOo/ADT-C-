#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void merge_sort(void*,size_t,size_t,int(*)(const void*,const void*));

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
	
	merge_sort(num,count,sizeof(int),cmp);
	
	for(i=0;i<count;i++)
		printf("%d ",num[i]);
	
	putchar('\n');
	return 0;
}

void merge(void* start,size_t length,size_t ele_size,int(* cmp)(const void*,const void*))
{
	char *cpy = malloc(length*ele_size);
	memcpy(cpy,start,length*ele_size);
	char *p = cpy;
	char *q = cpy+length/2*ele_size;
	int i=0;
	while(p<(cpy+length/2*ele_size)&&q<(cpy+length*ele_size))
		{
		if((*cmp)(p,q))
			{
			memcpy((start+(i++)*ele_size),p,ele_size);
			p+=ele_size;
			}
		else
			{
			memcpy((start+(i++)*ele_size),q,ele_size);
			q+=ele_size;	
			}
		}
	while(p<cpy+length/2*ele_size) {memcpy((start+(i++)*ele_size),p,ele_size);p+=ele_size;}
	while(q<cpy+length*ele_size) {memcpy((start+(i++)*ele_size),q,ele_size);q+=ele_size;}
	free(cpy);
}
void merge_sort(void* start,size_t length,size_t ele_size,int(* cmp)(const void*,const void*))
{
	if(length>1 )
		{
		merge_sort((void*)start,length/2,ele_size,cmp);
		merge_sort(start+length/2*ele_size,length-length/2,ele_size,cmp);
		merge(start,length,ele_size,cmp);
		}
}