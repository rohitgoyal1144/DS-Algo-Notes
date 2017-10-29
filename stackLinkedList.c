#include<stdio.h>
typedef struct nodes{
    int val;
    struct nodes *next;
}node;



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

    }
    return 0;
}
