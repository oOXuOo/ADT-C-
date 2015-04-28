// ADT 单链表
#include <stdbool.h>

#ifndef SLIST_H
#define SLIST_H


// 定义元素类型
#define ElemType char // 注意这通常须是个直接类型如char int struct等

// 定义普通节点
struct slist_node{
	ElemType data;  			// 数据域
	struct slist_node *next; // 指针域
};

// 定义链表（头）
struct slist{
	int count;  			// 统计含有的元素个数
	struct slist_node *head;		// 指向第一个元素
	struct slist_node *tail;		// 指向最后一个元素
};

// 定义操作接口
/*整体操作*/
struct slist*	SList_Create		(void);			// 创建一个单链表，返回指针
void			SList_Destroy	(struct slist*); // 销毁一个已存在的链表
void			SList_Clear		(struct slist*); // 置空一个链表
void			SList_Traverse	(struct slist*, void(*visit)(ElemType)); // 遍历链表
/*状态查询*/
bool			SList_Empty(struct slist*);		// 查看链表是否为空
int				SList_Length(struct slist*);		// 获取链表长度（含有元素个数）
/*元素操作*/
ElemType		SList_Element_Get	(struct slist*, int);
void			SList_Element_Insert	(struct slist*, int, ElemType);
void			SList_Element_Delete	(struct slist*, int);
int				SList_Element_Locate	(struct slist*, ElemType, bool(*compare)(ElemType, ElemType));
ElemType*		SList_Element_Prior	(struct slist*, ElemType);
ElemType*		SList_Element_Next	(struct slist*, ElemType);


#endif