#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	long long int data;
	struct node * next;
}node;

int main()
{
	node *ll[1000];
	node *temp, *tm, *tmp, *prev;
	long long n,m,k,p,q,r,i;
	for(i=0;i<15;i++)
		(ll[i])=NULL;
	while(1)
	{
		char c;
		scanf("%c",&c);
		if(c=='b')
			break;
		if(c=='i')
		{
			scanf("%lld",&n);
			p=n%11;
			temp=(node *)malloc(sizeof(node));
			temp->data=n;
			temp->next=ll[p];
			ll[p]=temp;
		}
		int flag=0;
		if(c=='d')
		{
			scanf("%lld",&m);
			q=m%11;
			tmp=ll[q];
			if(tmp==NULL)
			{
				flag=1;
				printf("element to be deleted doesn't exist\n");
			}
				prev=tmp;
			if(flag==0)
			{
				while(tmp->data!=m)
				{
					prev=tmp;
					tmp=tmp->next;
					if(tmp==NULL)
					{
						flag=1;
						printf("element to be deleted doesn't exist\n");
					}
				}
				if(flag==0)
				{
					if(tmp==ll[q])
					{
						printf("debug\n");
						ll[q]=ll[q]->next;
					}
					else
						prev->next=tmp->next;
					printf("deletion successfull\n");
				}
			}
		}
		int flag2=0;
		if(c=='s')
		{
			scanf("%lld",&k);
			r=k%11;
			tm=ll[r];
			if(tm==NULL)
			{
				printf("search not found\n");
				flag2=1;
			}
			if(flag2==0)
			{
				while(tm->data!=k)
				{
					tm=tm->next;
					if(tm==NULL)
					{
						printf("search not found\n");
						flag2=2;
						break;
					}
				}
				if(flag2==0)
				printf("search found\n");
			}
		}
	}
	return 0;
}

