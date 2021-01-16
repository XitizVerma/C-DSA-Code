#include<stdio.h>
#define maxsize 3
int q[maxsize], front=0,rear=-1;
void insert()
{
    int n;
    if(rear==maxsize-1)
        printf("\nQueue Overflow \n");
    else
    {
        printf("\nEnter the data to be added\n");
        scanf("%d", &n);
        q[++rear]=n;
    }
}
void delete()
{
    if(front>rear)
    printf("\nQueue is empty\n");
    else
    {
        printf("\n%d is deleted\n",q[front++]);
        if(front>rear && rear==maxsize-1)
        {
            printf("\n Reinitialising the queue array to Original Constraint Values\n");
            front=0; rear=-1;
        }
    }
}
void display()
{
    int i;
    if(front>rear)
        printf("\nQueue is empty\n");
    else
    {
        printf("\nQueue status is\n");
        for(i=front;i<=rear;i++)
            printf("%d\t",q[i]);
    }
}
int main()
{
    int ch;
    while(1)
    {
        printf("1.Insert \n 2.Delete \n 3.Display \n 4.Exit\ n");
        puts("\nEnter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: return 0;
            default :printf("\nInvalid choice\n");
        }
    }
}
