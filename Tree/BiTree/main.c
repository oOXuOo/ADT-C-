#include <stdio.h>
#include "bitree.h"

void visit(char e)
{
	putchar(e);
}
int main(int argc, char **argv)
{
	//bitree* T = bitree_preorder_create();
	bitree* T = bitree_levelorder_create();
	bitree_preorder_traverse(T,visit);putchar('\n');
	bitree_inorder_traverse(T,visit);putchar('\n');
	bitree_postorder_traverse(T,visit);putchar('\n');
	bitree_levelorder_traverse(T,visit);putchar('\n');
	return 0;
}
