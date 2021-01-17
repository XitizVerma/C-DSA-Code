#include <stdio.h>
#define sz 100
#include <stdlib.h>
void insert (int cq[sz],int *rear,int item,int *count)
{
    *rear = (*rear+1)%sz;
    cq[*rear] = item;
    *count = *count+1;
}
void deletion (int cq[sz],int *front,int *count)
{
    if (*count == 0)
        printf ("No Job in Print Spool\n");
    else
    {
        printf ("%d Exits Print Spool\n",cq[*front]);
        *front = (*front+1)%sz;
        *count = *count-1;
    }
}
void display (int cq[sz],int front,int count)
{
    int i,j;
    if (count == 0)
        printf ("Print Spool is Empty\n");
    else
    {
        printf ("Content of Print Spool\n");
        j = front;
        for (i=1;i<=count;i++)
        {
            printf ("%d is printing\n",cq[j]);
            j = (j+1)%sz;
        }
    }
}
int main ()
{
    int cq[sz],rear=-1,count=0,front=0,item,ch;
    for (;;)
    {
        printf ("1:INSERT 2:DELETE 3:DISPLAY\n");
        scanf ("%d",&ch);
        switch (ch)
        {
            case 1: printf ("Enter the Print job in Spool\n");
            scanf ("%d",&item);
            insert (cq,&rear,item,&count);
            break;
            case 2: deletion( cq,&front,&count);
            break;
            case 3: display (cq,front,count);
            break;
            default: exit(0);
        }
    }
    return(0);
}
