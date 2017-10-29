#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	int height;
	struct node* left;
	struct node* right;
}node;
node* max(node* a,node* b)
{
	if(a!=NULL && b!=NULL)
		return (a->height)>(b->height)?a->height:b->height;
	if(a!=NULL)
		return a->height;
	if(b!=NULL)
		return b->height;
	else
		return 0;
}
node* srl(node** head)
{
	node *u,*v,*v1;
	v=(*head)->left;
	v1=v->right;
	u=(*head);
	v->right=u;
	u->left=v1;
	u->height=max(u->left,u->right)+1;
	v->height=max(v->left,v->right)+1;
	return v;
}
node* srr(node** head)
{
	node *u,*v,*v1;
	v=(*head)->right;
	v1=v->left;
	u=(*head);
	v->left=u;
	u->right=v1;
	u->height=max(u->left,u->right)+1;
	v->height=max(v->left,v->right)+1;
	return v;
}
node* drl(node** head)
{
	(*head)->left=srr(&((*head)->left));
	return srl(head);
}
node* drr(node** head)
{
	(*head)->right=srl(&((*head)->right));
	return srr(head);
}
void insert (node** head,int dat)
{
	if(*head==NULL)
	{
		node* temp;
		temp=(node*)malloc(sizeof(node));
		temp->data=dat;
		temp->height=1;
		temp->left=NULL;
		temp->right=NULL;
		*head=temp;
		return;
	}
	else 
	{
		if(dat>=(*head)->data)
			insert(&((*head)->right),dat);
		else
			insert(&((*head)->left),dat);
		(*head)->height=(max((*head)->left,(*head)->right))->height+1;
		if(((*head)->left)->height-((*head)->right)->height>1)
		{
			if((((*head)->left)->left)->height>=(((*head)->left)->right)->height)
				*head=srl(head);
			else
				*head=drl(head);
		}
		else if(((*head)->right)->height-((*head)->left)->height>=1)
		{
			if((((*head)->right)->right)->height>=(((*head)->right)->left)->height)
				*head=srr(head);
			else
				*head=drr(head);
		}
	}
	return;
}
void print(node** head)
{
	if(*head==NULL)
		return;
	print(&((*head)->left));
	printf("%d,%d; ",(*head)->data,(*head)->height);
	print(&((*head)->right));
	return;
}
node* search(node** head,int dat)
{
	if(*head==NULL)
	{
		printf("%d not found\n",dat);
		return NULL;
	}
	if((*head)->data==dat)
	{
		printf("%d found\n",dat);
		return (*head);
	}
	else
	{
		if(dat>=(*head)->data)
			search(&((*head)->right),dat);
		else
			search(&((*head)->left),dat);
	}
}
void delete(node** head,int dat)
{
	node* temp;
	temp=*head;
	node* temp1;
	node* temp2=NULL;
	node* temp3;
	//temp=search(head,dat);
	while(temp!=NULL && temp->data!=dat)
	{
		if(temp->data < dat)
		{
			temp3=temp;
			temp=temp->right;
		}
		else if(temp->data>dat)
		{
			temp3=temp;
			temp=temp->left;
		}
	}
	if(temp==NULL)
	{
		printf("wrong input\n");
		return;
	}
	else
	{
		temp1=temp;
		if(temp1->left!=NULL)
		{
			temp1=temp1->left;
			if(temp1->right==NULL)
			{
				temp->data=temp1->data;
				temp->left=temp1->left;
			}
			else
			{
				while(temp1->right!=NULL)
				{
					temp2=temp1;
					temp1=temp1->right;
				}
				temp->data=temp1->data;
				temp2->right=temp1->left;
			}	
			printf("%d\n",temp1->data);free(temp1);			
		}
		else if(temp1->right!=NULL)
		{
			temp1=temp1->right;
			temp2=temp1;
			if(temp1->left==NULL)
			{
				temp->data=temp1->data;
				temp->right=temp1->right;
			}
			else
			{
				while(temp1->left!=NULL)
				{
					temp2=temp1;
					temp1=temp1->left;
				}
				printf("%d\n",temp2->data);
				temp->data=temp1->data;
				temp2->right=temp1->right;
			}
			printf("%d\n",temp1->data);free(temp1);			
		}
		else
		{
			if(temp->data > temp3->data)
				temp3->right=NULL;
			else
				temp3->left=NULL;
		}
	}
	return;
}
int main()
{
	int i,j;
	node* root;
	root=NULL;
	/*for(i=10,j=5;i<15,j>0;i++,j--)
	{
		insert(&root,i);
		insert(&root,j);
	}*/
	int n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		insert(&root,a);
		print(&root);printf("\n");
	}
	//root=drr(&root);
	//print(&root);printf("\n");
	/*for(i=0;i<5;i++)
	{
		scanf("%d",&j);
		delete(&root,j);
		print(&root);printf("\n");
	}*/
	return 0;
}


