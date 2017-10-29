#include <iostream>
#include <vector>
using namespace std;

class Node
{
  Node *left, *right;
  int data;
public:
  Node(int d)
  {
    data = d;
    left = 0;
    right = 0;
  }
  Node *insertLeft(int item)
  {
    left = new Node(item);
    return left;
  }
  Node *insertRight(int item)
  {
    right = new Node(item);
    return right;
  }

  friend ostream& operator << (ostream& o, Node *s);
};

ostream& operator << (ostream& o, Node *n)
{
  if (n==0) return o;
  o << n->left;
  o << n->right;
  o << n->data << " ";
  return o;
}

int main()
{
  Node root(10); 
  Node *rl = root.insertLeft(4);
  Node *rr = root.insertRight(5);
  Node *rll = rl->insertLeft(6);
  Node *rlr = rl->insertRight(7);
  Node *rrr = rr->insertRight(9);
  cout << &root;
  cout << "\n";
}
