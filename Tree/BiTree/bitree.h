#ifndef BITREE_H
#define BITREE_H

typedef struct bitree_node 
{
	char data;
	struct bitree_node * lchild;
	struct bitree_node * rchild;
}bitree;

bitree* bitree_preorder_create();
bitree* bitree_levelorder_create();
void bitree_preorder_traverse(bitree*,void(*)(char));
void bitree_inorder_traverse(bitree*,void(*)(char));
void bitree_postorder_traverse(bitree*,void(*)(char));
void bitree_levelorder_traverse(bitree*,void(*)(char));

#endif