// ADT 单链表 接口实现

#include "SList.h"
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

/*整体操作*/
struct slist* SList_Create(void){
	slist* psl = (slist*)malloc(sizeof(slist));
	psl->count = 0;
	psl->head = NULL;
	psl->tail = NULL;
	// 尾插法
	char c;
	wprintf(L"请输入字符元素，中间无分割，回车结束\n");
	while ((c = getchar())!='\n')
		{
		slist_node* tmp = (slist_node*)malloc(sizeof(slist_node));
		tmp->data = c;
		tmp->next = Null;
		psl->count++;
		psl->tail->next = tmp;
		psl->tail = tmp;
		if(!psl->head) psl->head = tmp;
		}
	return psl;
}

void SList_Destroy(struct slist* psl){
	SList_Clear(psl);
	free(psl);
}

void SList_Clear(struct slist* psl){
	while(psl->head)
		{
		struct slist_node* tmp = psl->head;
		psl->head = tmp->next;
		free(tmp);
		}
	psl->count = 0;
	psl->tail = psl->head;
}

void SList_Traverse(struct slist* psl, void(*visit)(ElemType)){
	struct slist_node* tmp = psl->head;
	while(tmp)
		{
		(*visit)(tmp->data);
		tmp = tmp->next;
		}
}



/*状态查询*/
bool SList_Empty(struct slist* psl){
	return psl->head;
}

int SList_Length(struct slist* psl){
	return psl->count;
}



/*元素操作*/
ElemType* SList_Element_Get(struct slist* psl, int index){
	if(index > psl->count)
		return NULL; 
	struct slist_node* tmp = psl->head;
	for( int i=1;i<index;i++)
		tmp = tmp->next;
	return &tmp->data;
}

void SList_Element_Insert(struct slist* psl, int index, ElemType e){
	if(index > psl->count)
		return; 
	struct slist_node* tmp = psl->head;
	for( int i=1;i<index-1;i++)
		tmp = tmp->next;
	struct slist_node* pe = (struct slist_node*)malloc(sizeof(struct slist_node));
	pe->data = e;
	pe->next = tmp->next;
	tmp->next = pe;
	psl->count++;
}

void SList_Element_Delete(struct slist* psl, int index){
	if(index > psl->count)
		return; 
	struct slist_node* tmp = psl->head;
	for( int i=1;i<index-1;i++)
		tmp = tmp->next;
	struct slist_node* pdel = tmp->next;
	tmp->next = tmp->next->next;
	free(pdel);
}

int SList_Element_Locate(struct slist* psl, ElemType e, bool(*compare)(ElemType, ElemType)){
	struct slist_node* tmp = psl->head;
	int index = 1;
	while(tmp)
		{
		if((*compare)(tmp->data,e)) return index;
		tmp = tmp->next;
		index++;
		}
	return 0;
}

ElemType* SList_Element_Prior(struct slist*, ElemType){
	struct slist_node* pri = NULL,tmp = psl->head;
	while(tmp)
		{
		if(tmp->data==e) return pri?(&pri->data):NULL;
		pri = tmp;
		tmp = tmp->next;
		}
	return NULL;
}

ElemType* SList_Element_Next(struct slist* psl, ElemType e){
	struct slist_node* tmp = psl->head;
	while(tmp)
		{
		if(tmp->data==e) return tmp->next?(&tmp->next->data):NULL;
		tmp = tmp->next;
		}
	return NULL;
}