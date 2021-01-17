#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;
NODE insertLoc(NODE first)
{
    int loc,count;
    NODE temp,cur;
    printf("\nEnter the location\n");
    scanf("%d",&loc);
    temp = (NODE)malloc(sizeof(struct node));
    printf("\nEnter the data\n");
    scanf("%d",&temp->info);
    temp->link=NULL;
    if(first==NULL)
    {
        if(loc==1)
            first = temp;
        else
            printf("Invalid location\n");
    }
    else if(loc==1)
    {
        temp->link=first;
        first=temp;
    }
    else
    {
        cur=first;
        count=1;
        while(cur!=NULL)
        {
            if(count==loc-1)
            {
                temp->link=cur->link;
                cur->link=temp;
                break;
            }
            cur=cur->link;
            count++;
        }
        if(cur==NULL)
            printf("Invalid location\n");
    }
    return first;
}
NODE delete (NODE first)
{
    NODE temp;
    if (first == NULL)
    {
        printf ("List Empty\n");
        return first;
    }
    temp = first;
    first = first->link;
    printf ("%d is deleted\n",temp->info);
    free (temp);
    return first;
}
void display (NODE first)
{
    NODE temp;
    if (first == NULL)
        printf ("List is Empty\n");
    else
    {
        printf ("Content of List\n");
        temp = first;
        while (temp != NULL)
        {
            printf ("%d\t",temp->info);
            temp = temp->link;
        }
        printf ("\n");
    }
}
int main ()
{
    int ch;
    NODE first = NULL;
    for (;;)
    {
        printf ("1:INSERT 2:DELETE 3:DISPLAY 4.EXIT\n");
        scanf ("%d",&ch);
        switch (ch)
        {
            case 1: first = insertLoc (first);
            break;
            case 2: first = delete (first);
            break;
            case 3: display (first);
            break;
            default: exit(0);
        }
    }
}
