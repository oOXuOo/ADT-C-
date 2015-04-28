#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "bitree.h"


// 先序建立  
bitree* bitree_preorder_create()
{
	bitree * T = NULL;
	char data = getchar();
	if(data!='#')
		{
		T = (bitree*)malloc(sizeof(bitree));
		T->data = data;
		T->lchild = bitree_preorder_create();
		T->rchild = bitree_preorder_create();
		}
	return T;
}

// 中序无法建立  
// 后序建立（略）

// 层级建立  
bitree* bitree_levelorder_create()
{
	// 处理根节点
	char data = getchar();
	if(data=='#'||data=='@')
		return NULL;
	struct queue* Q = queue_create();
	bitree* T = (bitree*)malloc(sizeof(struct bitree_node));
	T->data = data; T->lchild=T->rchild=NULL; enqueue(Q,T);
	// 建立二叉树
	while((data=getchar())!='#')
		{
		// 出队一个节点
		bitree* e = (bitree*)dequeue(Q);
		// 处理左孩子
		if(data!='@')
			{
			e->lchild = (bitree*)malloc(sizeof(struct bitree_node));
			e->lchild->data=data;
			e->lchild->rchild = e->lchild->lchild = NULL;
			enqueue(Q,e->lchild);
			}
		// 处理右孩子
		data = getchar();
		if(data == '#') break;
		else if(data != '@')
			{
			e->rchild = (bitree*)malloc(sizeof(struct bitree_node));
			e->rchild->data=data;
			e->rchild->lchild = e->rchild->rchild = NULL;
			enqueue(Q,e->rchild);
			}
		}
	queue_delete(Q);
	return T;
}





//  先序遍历
void bitree_preorder_traverse(bitree *p,void(*visit)(char))
{
	if(p != NULL)  
		{
		(*visit)(p->data);  
		bitree_preorder_traverse(p->lchild,visit);  
		bitree_preorder_traverse(p->rchild,visit);  
		}  
}
//  中序遍历
void bitree_inorder_traverse(bitree *p,void(*visit)(char))
{
	if(p != NULL)  
		{ 
		bitree_inorder_traverse(p->lchild,visit);  
		visit(p->data); 
		bitree_inorder_traverse(p->rchild,visit);  
		}
}
//  后序遍历
void bitree_postorder_traverse(bitree *p,void(*visit)(char))
{
	if(p != NULL)  
		{ 
		bitree_postorder_traverse(p->lchild,visit); 
		bitree_postorder_traverse(p->rchild,visit);   
		(*visit)(p->data); 
		}
}
//  层级遍历
void bitree_levelorder_traverse(bitree *p,void(*visit)(char))
{
	struct queue* Q = queue_create();
	enqueue(Q,p);
	while(!queue_is_empty(Q))
		{
		bitree* T = (bitree*)dequeue(Q);
		visit(T->data);
		if(T->lchild) enqueue(Q,T->lchild);
		if(T->rchild) enqueue(Q,T->rchild);
		}
	queue_delete(Q);
}


// 基于先序和中序 重建二叉树
bitree* bitree_rebuild_prein(char* preod, char* inod, int m, int n, int p, int q)
{
	int mid = p;
	bitree *T = (bitree*)malloc(sizeof(bitree));
	T->data = preod[m];
	while(inod[mid]!=preod[m]) mid++;
	if(mid==p) T->lchild = NULL;
	else T->lchild = bitree_rebuild_prein(preod,inod,m+1,m+mid-p,p,mid-1);
	if(mid==q) T->rchild = NULL;
	else T->rchild = bitree_rebuild_prein(preod,inod,m+mid-p+1,n,mid+1,q);
	return T;
}

// 基于先序和中序 重建二叉树
bitree* bitree_rebuild_pstin(char* preod, char* inod, int m, int n, int p, int q)
{
	
}