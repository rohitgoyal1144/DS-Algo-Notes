#include<stdio.h>
typedef struct nodes{
    int val;
    struct nodes *next;
}node;
node * push(node * head)
{
    node *t,*head2,*tem;
    t=head;

    int i=0;
    while(head!=NULL)
    {
        tem=(node*)malloc(sizeof(node));
        tem->val=head->val;
        tem->next=head2;
        head2=tem;
        head=head->next;
    }
    return (head2);
}
int pop(node *nhead)
{
    node *tem,*head;
    node *head2;
    while(head!=NULL)
    {
        tem=(node*)malloc(sizeof(node));
        tem->val=nhead->val;
        tem->next=head;
        head=tem;
       nhead=nhead->next;
    }
    return 0;
}
        





int doit(node *head)
{
    node*t,*q,*newHead;
    t=(node*)malloc(sizeof(node));
    newHead=push(head);
    q=newHead;
    newHead=newHead->next;
    free(q);
    pop(newHead);
    return 0;
}







int main()
{
    int a;
    char c;
    node *head,*temp;
    while(1)
    {
        scanf("%c",&c);
        if(c=='s')
            break;
        if(c=='I')
        {
            scanf("%d",&a);
            temp=(node*)malloc(sizeof(node));
            temp->val=a;
            temp->next=head;
            head=temp;
        }
        if(c=='D')
        {
            free(head);
            head=head->next;

        }
        if(c=='T')
           printf("%d\n",head->val);
        if(c=='p')
        {

            doit(head);
            while(head!=NULL)
            {
            printf("%d " ,head->val);
            head=head->next;
            }
        }
    }

    return 0;
}

