#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	int lines;
	char input[10000];
	scanf("%d",&lines);
	getchar();
	
	while(lines--)
		{
		gets(input);
		int i,length = strlen(input);
		struct stack* s = stack_create(length);
		for(i=0;i<length;i++)
			{
			if(input[i]=='['||input[i]=='(')
				stack_push(s,input[i]);
			else if(input[i]==']')	
				{
				if( (!stack_is_empty(s)) && (stack_get_pop(s) == '[') )
					stack_pop(s);
				else {printf("No\n");break;}
				}
			else if(input[i]==')')	
				{
				if( (!stack_is_empty(s)) && (stack_get_pop(s) == '(') )
					stack_pop(s);
				else {printf("No\n");break;}
				}
			else;
			}
		if(stack_is_empty(s)&&i==length)
			printf("Yes\n");
		stack_delete(s);
		}
		
	return 0;
}
