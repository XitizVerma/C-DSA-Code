#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;
NODE first = NULL,last = NULL;
void insert (int data)
{
    NODE newnode;
    newnode = (NODE)malloc(sizeof(struct node));
    newnode->info = data;
    newnode->llink = NULL;
    newnode->rlink = NULL;
    if(first == NULL)
    {
        first=last=newnode;
        return;
    }
    newnode->rlink = first;
    first->llink = newnode;
    first = newnode;
    }
void delete (int key)
{
    int flag =0;
    NODE prev,cur,next;
    if (first == NULL)
    {
        printf ("List Empty\n");
        return;
    }
    if(first->rlink == NULL) // one node in the list
    {
        if (first->info == key)
        {
            printf ("%d is deleted\n",first->info);
            free (first);
            first=last=NULL;
            return ;
        }
    }
    if(key == first->info)
    {
        printf("\n%d is deleted\n",first->info);
        cur = first;
        first = first->rlink;
        first->llink = NULL;
        free(cur);
        cur=NULL;
        return;
    }
    if(key == last -> info)
    {
        printf("\n%d is deleted\n",last->info);
        cur = last;
        last = last->llink;
        last->rlink = NULL;
        free(cur);
        cur=NULL;
        return;
    }
    cur = first->rlink;
    while(cur!=last)
    {
        if(cur->info==key)
        {
            prev = cur->llink;
            next = cur->rlink;
            printf("\n%d is deleted\n",cur->info);
            prev->rlink = next;
            next->llink = prev;
            free(cur);
            cur = NULL;
            flag =1;
            break;
        }
        cur=cur->rlink;
    }
    if(flag==0)
        printf("\nKey not found\n");
}
void display ()
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
            temp = temp->rlink;
        }
        printf ("\n");
    }
}
int main ()
{
    int ch,data;
    while(1)
    {
        printf ("1:INSERT 2:DELETE 3:DISPLAY 4:EXIT\n");
        scanf ("%d",&ch);
        switch (ch)
        {
            case 1: printf ("Enter the data\n");
                    scanf ("%d",&data);
                    insert (data);
                    break;
            case 2: printf ("Enter the data to be deleted\n");
                    scanf ("%d",&data);
                    delete (data);
                    break;
            case 3: display ();
                    break;
            default: exit(0);
        }
    }
}
