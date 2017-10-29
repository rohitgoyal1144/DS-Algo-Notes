#include<stdio.h>
typedef struct nodes{
    int val;
    struct nodes *next;
    struct nodes *prev;
}node;



int main()
{
    int a;
    char c;

    node *head,*temp,*last;
    int i=0;
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
            last->next=temp;
            last=temp;

            if(i!=0)
            {
            temp->prev=last;
            temp->next=head;
            }
            if(i==0)
            {
                head=temp;
                last=temp;
                temp->next=NULL;
                temp->prev=NULL;
            }
        }
        if(c=='D')
        {
            last=last->prev;
            free(last);
        }
        if(c=='T')
           printf("%d\n",(head->val));

        if(c=='L')
            printf("%d\n",last->val);
        i++;
    }
    return 0;
}
