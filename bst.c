#include<stdio.h>
#include<stdlib.h>
struct elem{
	int data;
	struct elem* right;
	struct elem* left;
};
typedef struct elem node;
node* root=NULL;
node* del=NULL;
node* del2=NULL;
int flag=0;
node * insert(node* top,int value){
	if(top==NULL){
		node *temp=(node*)malloc(sizeof(node));
		temp->right=NULL;
		temp->left=NULL;
		temp->data=value;
		top=temp;
	}
	else{
		if(top->data>value){
			top->left = insert(top->left,value);
		}
		else{
			top->right = insert(top->right,value);
		}
	}
	return top;
}
void inorder(node* temp){
	if(temp==NULL){
		return;
	}
	else{
		if(temp->left!=NULL)
			inorder(temp->left);
		printf("%d ",temp->data);
		if(temp->right!=NULL)
			inorder(temp->right);
		return;
	}
}
void search(node* temp,int num){
	if(temp==NULL){
		printf("NO\n");
		return;
	}
	else{
		if(num==temp->data){
			printf("YES\n");
			return;
		}
		else if(num>temp->data){
			search(temp->right,num);
		}
		else if(num<temp->data){
			search(temp->left,num);
		}
	}
}
void delete(node* temp,int num){
	node* temp2=NULL;
	if(temp==NULL){
		printf("NOT FOUND\n");
		return;
	}
	else{
		if(num==temp->data){
			if(temp->left==NULL&&temp->right==NULL){
				if(temp==root){
					root=NULL;
				}
				else{
					if(flag==0){
						del->right=NULL;
					}
					else if(flag==1){
						del->left=NULL;
					}
				}

			}
			else if(temp->left==NULL&&temp->right!=NULL){
				if(temp==root){
					root=temp->right;
				}
				else{
					if(flag==0){
						del->right=temp->right;
					}
					else if(flag==1){
						del->left=temp->right;
					}
				}
			}
			else if(temp->left!=NULL&&temp->right==NULL){
				if(temp==root){
					root=temp->left;
				}
				else{
					if(flag==0){
						del->right=temp->left;
					}
					else if(flag==1){
						del->left=temp->left;
					}
				}
			}
			else{
				temp2=temp->left;
				del2=temp;
				while(temp2->right!=NULL){
					del2=temp2;
					temp2=temp2->right;
				}
				if(temp==root){
					root=temp2;
					if(temp2->left!=NULL){
						if(del2!=temp){
							del2->right=temp2->left;
							temp2->left=temp->left;
							temp2->right=temp->right;
						}
					}
					temp2->right=temp->right;
				}
				else{

					if(flag==0){
						del->right=temp2;
						if(temp2->left!=NULL){
							del2->right=temp2->left;
						}
						temp2->left=temp->left;
						temp2->right=temp->right;
						//free temp
					}
					else if(flag==1){
						del->left=temp2;
						if(temp2->left!=NULL){
							del2->right=temp2->left;
						}
						temp2->left=temp->left;
						temp2->right=temp->right;
						//free temp
					}
				}
			}
			return;
		}
		else if(num>temp->data){
			flag=0;
			del=temp;
			delete(temp->right,num);
		}
		else if(num<temp->data){
			flag=1;
			del=temp;
			delete(temp->left,num);
		}
	}
}
int main(){
	int num,i,value,x;
	printf("number of insertions:");
	scanf("%d",&num);
	for(i=1;i<=num;i++){
		scanf("%d",&value);
		root = insert(root,value);
	}
	printf("printing tree\n");
	inorder(root);
	printf("\n");
	search(root,10);
	printf("deleting 3\n");
	delete(root,10);
	printf("printing tree\n");
	inorder(root);
	printf("\n");
	return 0;
}
