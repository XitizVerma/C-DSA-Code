#include<stdio.h>
#define STACK_SIZE 3
int s[STACK_SIZE];
int top=-1;
void push()
{
int n;
if(top==STACK_SIZE-1)
printf("\nStack overflow\n");
else
{
printf("\nEnter the data to be pushed\n");
scanf("%d",&n);
s[++top]=n;
}
}
void pop()
{
if(top==-1)
printf("\nStack empty\n");
else
printf("\n%d is popped\n", s[top--]);
}
void display()
{
int i;
if(top==-1)
printf("\nStack empty\n");
else
{
printf("\nStack elements are\n");
for(i=top;i>=0;i--)
printf("%d\n",s[i]);
}
}
int main()
{
int ch;
for(;;)
{
printf("\n1.PUSH\t2.POP\t3.DISPLAY\t4.EXIT\n");
printf("\nEnter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: push();
break;
case 2: pop();
break;
case 3: display();
break;
case 4: return 0;
default: printf("\nInvalid choice\n");
}
}
}
