#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

typedef struct BtreeNode{
  long long int *keys;
  long long int minKeys;
  BtreeNode **C;
  long long int countKeys;
  bool isLeaf;
}BtreeNode;

struct Btree{
  BtreeNode *root;
  long long int minKeys;
};

void splitNode(struct BtreeNode **node,struct BtreeNode **child,long long int i);
struct BtreeNode *insertNonFull(struct BtreeNode *node,long long int key);
void printNode(struct BtreeNode *head);

long long int blockSize = 3;
long long int depth = 0;

struct BtreeNode *nodeConstrutor(long long int minKeys,bool isLeaf){
  BtreeNode *temp = (BtreeNode *)malloc(sizeof(BtreeNode));
  temp->minKeys = minKeys;
  temp->isLeaf = isLeaf;
  temp->countKeys = 0;
  temp->keys = new long long int[2*minKeys - 1];
  temp->C = new BtreeNode *[2*minKeys];
  temp->C[0] = NULL;
  for(long long int i=0;i<2*minKeys-1;i++){
    temp->C[i+1] = NULL;
    temp->keys[i] = 0;
  }
  return temp;
}

struct Btree *treeConstrutor(long long int minKeys){
  Btree *temp = (Btree *)malloc(sizeof(Btree));
  temp->minKeys = minKeys;
  temp->root = NULL;
  return temp;
}

struct Btree *insert(struct Btree *head,long long int key){
  if(head->root==NULL){
    head->root = nodeConstrutor(blockSize,true);
    head->root->keys[0] = key;
    head->root->countKeys += 1;
  }
  else{
    if(head->root->countKeys == 2*blockSize - 1){
      BtreeNode *s = nodeConstrutor(head->root->minKeys, false);
			s->C[0] = head->root;
			splitNode(&s,&(s->C[0]),0);
			long long int i = 0;
			if (s->keys[0] < key)
				i++;
			s->C[i] = insertNonFull(s->C[i],key);
			head->root = s;
    }
    else{
      head->root = insertNonFull(head->root,key);
    }
  }
  return head;
}

void printNode(struct BtreeNode *head){
  for(long long int i=0;i<head->countKeys;i++)
    cout << head->keys[i] << " ";
  cout << endl;
  return;
}

struct BtreeNode *insertNonFull(struct BtreeNode *node,long long int key){
  long long int i = node->countKeys - 1;
  if(node->isLeaf){
    while(i>=0 && node->keys[i]>=key){
      node->keys[i+1] = node->keys[i];
      i--;
    }
    node->keys[i+1] = key;
    node->countKeys += 1;
  }
  else{
    while(i>=0 && node->keys[i]>=key)
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

void splitNode(struct BtreeNode **node,struct BtreeNode **child,long long int i){
  BtreeNode *z = nodeConstrutor((*child)->minKeys, (*child)->isLeaf);
	z->countKeys = (*node)->minKeys - 1;
  long long int t = (*node)->minKeys;
	for (long long int j = 0; j < t-1; j++)
		z->keys[j] = (*child)->keys[j+t];
	if ((*child)->isLeaf == false)
	{
		for (long long int j = 0; j < t; j++)
			z->C[j] = (*child)->C[j+t];
	}
  else{
    (*child)->C[1] = (*child)->C[0];
    (*child)->C[0] = z;
    z->C[0] = (*child)->C[1];
  }
	(*child)->countKeys = t;
  long long int n = (*node)->countKeys;
	for (long long int j = n; j >= i+1; j--)
		(*node)->C[j+1] = (*node)->C[j];
	(*node)->C[i+1] = z;
	for (long long int j = n-1; j >= i; j--)
		(*node)->keys[j+1] = (*node)->keys[j];
	(*node)->keys[i] = (*child)->keys[t-1];
	(*node)->countKeys += 1;
}

void printFormat(long long int data){
  string s = to_string(data);
  int l = s.size();
  int t = ceil(s.size()*1.0/3);
  int l1 = l-((t-1)*3);
  cout << atoi(s.substr(0,l1).c_str()) << " ";
  for(int i=0;i<t-1;i++)
    cout << atoi(s.substr(l1+(3*i),3).c_str()) << " ";
  cout << endl;
}
void printLink(struct BtreeNode *head){
  if(head==NULL)
    return;
  for(long long int i=0;i<head->countKeys;i++)
    printFormat(head->keys[i]);
  // cout << endl;
  return printLink(head->C[0]);
}

void traverseTree(struct BtreeNode *head){
  depth++;
  if(!head->isLeaf)
    return traverseTree(head->C[0]);
  return printLink(head);
}

long long int searchKey(struct BtreeNode *head,long long int key){
  if(head==NULL)
    return -1;
  for(long long int i=0;i<head->countKeys;i++){
    if(head->keys[i]==key)
      return key;
    if(!head->isLeaf){
      if(i==0 && key<head->keys[0])
          return searchKey(head->C[0],key);
      else if(i==head->countKeys-1){
        if(key>head->keys[head->countKeys-1])
          return searchKey(head->C[head->countKeys],key);
        else
          return searchKey(head->C[head->countKeys-1],key);
      }
      else
        if(head->keys[i]<key && head->keys[i+1]>key)
          return searchKey(head->C[i+1],key);
    }
  }
  return -1;
}

vector <string> readData(ifstream& in,long long int M){
  long long int i = 0;
  string line;
  const char* delim = " ";
  vector <string> ans;
  while(i<M && getline(in,line)){
    char * dup = strdup(line.c_str());
    char * token = strtok(dup, delim);
    vector <string> v;
    while(token != NULL){
      v.push_back(string(token));
      token = strtok(NULL, delim);
    }
    string finalStr = v[0];
    for(long long int k=1;k<v.size();k++){
      long long int l = v[k].size();
      string temp = v[k];
      for(long long int j=0;j<3-l;j++){
        temp = "0" + temp;
      }
      finalStr += temp;
    }
    ans.push_back(finalStr);
    free(dup);
    i++;
  }
  return ans;
}

int main(int argc, char** argv){
  if(argc<3){
    cout << "Check Input Format" << endl;
    return 0;
  }
  Btree *head = treeConstrutor(blockSize);
  vector<string> ans;
  ifstream infile;
  infile.open("data.txt");
  if(!infile.is_open()){
    cout << "Error : Check Filename " << endl;
    return 0;
  }
  long long int M = 1024*1024*atoi(argv[2]);
  ans = readData(infile,M);
  while(ans.size()!=0){
    for(long long int i=0;i<ans.size();i++)
      if(searchKey(head->root,atoll(ans[i].c_str()))==-1)
        head = insert(head,atoll(ans[i].c_str()));
    ans.clear();
    ans = readData(infile,M);
  }
  depth = 0;
  infile.close();
  traverseTree(head->root);
  return 0;
}
