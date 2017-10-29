#include <bits/stdc++.h>
using namespace std;

typedef struct BtreeNode{
  int *keys;
  int minKeys;
  BtreeNode **C;
  int countKeys;
  bool isLeaf;
}BtreeNode;

struct Btree{
  BtreeNode *root;
  int minKeys;
};

void splitNode(struct BtreeNode **node,struct BtreeNode **child,int i);
struct BtreeNode *insertNonFull(struct BtreeNode *node,int key);

int blockSize = 3;

struct BtreeNode *nodeConstrutor(int minKeys,bool isLeaf){
  BtreeNode *temp = (BtreeNode *)malloc(sizeof(BtreeNode));
  temp->minKeys = minKeys;
  temp->isLeaf = isLeaf;
  temp->countKeys = 0;
  temp->keys = new int[2*minKeys - 1];
  temp->C = new BtreeNode *[2*minKeys];
  return temp;
}

struct Btree *treeConstrutor(int minKeys){
  Btree *temp = (Btree *)malloc(sizeof(Btree));
  temp->minKeys = minKeys;
  temp->root = NULL;
  return temp;
}

struct Btree *insert(struct Btree *head,int key){
  if(head->root==NULL){
    head->root = nodeConstrutor(blockSize,true);
    head->root->keys[0] = key;
    head->root->countKeys += 1;
  }
  else{
    if(head->root->countKeys == 2*blockSize - 1){
      BtreeNode *s = nodeConstrutor(head->root->minKeys, false);
			s->C[0] = head->root;
			splitNode(&s,&(head->root),0);
			int i = 0;
			if (s->keys[0] < key)
				i++;
			s->C[i] = insertNonFull(s->C[i],key);
			head->root = s;
    }
    else{
      head->root = insertNonFull(head->root,key);
    }
  }
  // cout << key << endl;
  return head;
}

struct BtreeNode *insertNonFull(struct BtreeNode *node,int key){
  int i = node->countKeys - 1;
  if(node->isLeaf){
    while(i>=0 && node->keys[i]>key){
      node->keys[i+1] = node->keys[i];
      i--;
    }
    node->keys[i+1] = key;
    node->countKeys += 1;
  }
  else{
    while(i>=0 && node->keys[i]>key)
      i--;
    if(node->C[i+1]->countKeys == ((2*node->minKeys) - 1)){
      splitNode(&node,&(node->C[i+1]),i+1);
      if(node->keys[i+1]<key)
        i++;
    }
    node->C[i+1] = insertNonFull(node->C[i+1],key);
  }
  return node;
}

void splitNode(struct BtreeNode **node,struct BtreeNode **child,int i){
  BtreeNode *z = nodeConstrutor((*child)->minKeys, (*child)->isLeaf);
	z->countKeys = (*node)->minKeys - 1;
  int t = (*node)->minKeys;
	for (int j = 0; j < t-1; j++)
		z->keys[j] = (*child)->keys[j+t];
	if ((*child)->isLeaf == false)
	{
		for (int j = 0; j < t; j++)
			z->C[j] = (*child)->C[j+t];
	}
	(*child)->countKeys = t - 1;
  int n = (*node)->countKeys;
	for (int j = n; j >= i+1; j--)
		(*node)->C[j+1] = (*node)->C[j];
	(*node)->C[i+1] = z;
	for (int j = n-1; j >= i; j--)
		(*node)->keys[j+1] = (*node)->keys[j];
	(*node)->keys[i] = (*child)->keys[t-1];
	(*node)->countKeys += 1;
}

void traverseTree(struct BtreeNode *head){
  for(int i=0;i<head->countKeys;i++){
    if(!head->isLeaf)
      traverseTree(head->C[i]);
    cout << head->keys[i] << " ";
  }
  if(!head->isLeaf)
    traverseTree(head->C[head->countKeys]);
  return;
}

int searchKey(struct BtreeNode *head,int key){
  for(int i=0;i<head->countKeys;i++){
    if(head->keys[i]==key)
      return key;
    if(!head->isLeaf){
      if(i==0)
        if(key<head->keys[0])
          return searchKey(head->C[0],key);
      else if(i==head->countKeys-1)
        if(key>head->keys[head->countKeys-1])
          return searchKey(head->C[head->countKeys],key);
      else
        if(head->keys[i]<key && head->keys[i+1]>key)
          return searchKey(head->C[i+1],key);
    }
  }
  return -1;
}

int main(){
  Btree *head = treeConstrutor(blockSize);
  cout << "insert started" << endl;
  for(int i=0;i<10;i++){
    head = insert(head,i);
    head = insert(head,10*i);
  }
  // head = insert(head,10);
  // head = insert(head,2);
  // head = insert(head,3);
  // head = insert(head,4);
  // head = insert(head,50);
  // head = insert(head,15);
  // head = insert(head,70);
  // head = insert(head,80);
  // head = insert(head,90);
  // head = insert(head,100);
  cout << head->root->countKeys << endl;
  traverseTree(head->root);
  cout <<  endl;
  cout << searchKey(head->root,10) << " " << searchKey(head->root,10) << " " << searchKey(head->root,15) << " " << searchKey(head->root,100) << " " << endl;
  return 0;
}
