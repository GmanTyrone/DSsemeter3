#ifndef _IOSTREAM_H
#include <iostream>
#define _IOSTREAM_H
#endif

using namespace std;

enum Boolean { FALSE, TRUE};

class Tree;

class TreeNode {
friend class Tree;
friend int equal(TreeNode*, TreeNode*);
private:
    TreeNode *LeftChild;
    int data;
    TreeNode *RightChild;
    TreeNode() {LeftChild = RightChild = 0;};
    TreeNode(int ch, TreeNode *Lefty, TreeNode *Righty)
    {
	data = ch;
	LeftChild = Lefty;
	RightChild = Righty;
    }
};

class Tree {
friend int operator==(const Tree&, const Tree&);
private:
    TreeNode *root;
    void inorder(TreeNode *);
    void preorder(TreeNode *);
    void postorder(TreeNode *);
    TreeNode* copy(TreeNode *);
    int size(TreeNode *);
    int sum(TreeNode *);
    int height(TreeNode *);
public:
    void setup();
    void inorder();
    void preorder();
    void postorder();
    Tree(const Tree&);
    Tree() {root = 0;};
    int height();
    int size();
    int sum();
};

void Tree::setup()
{
    root = new TreeNode(1,0,0);
    root->LeftChild = new TreeNode(2,0,0);
    root->LeftChild->LeftChild = new TreeNode(3, 0, 0);
    root->LeftChild->RightChild = new TreeNode(4, 0, 0);
    root->LeftChild->LeftChild->LeftChild = new TreeNode(5, 0, 0);
}

void Tree::inorder()
{
   inorder(root);
}

void Tree::preorder()
{
   preorder(root);
}

void Tree::postorder()
{
   postorder(root);
}

void Tree::inorder(TreeNode *CurrentNode)
{
     if (CurrentNode) {
	 inorder(CurrentNode->LeftChild);
	 cout << CurrentNode->data<<" ";
	 inorder(CurrentNode->RightChild);
     }
}

void Tree::preorder(TreeNode *CurrentNode)
{
     if (CurrentNode) {
	 cout << CurrentNode->data<<" ";
	 preorder(CurrentNode->LeftChild);
	 preorder(CurrentNode->RightChild);
     }
}

void Tree::postorder(TreeNode *CurrentNode)
{
     if (CurrentNode) {
	 postorder(CurrentNode->LeftChild);
	 postorder(CurrentNode->RightChild);
	 cout << CurrentNode->data<<" ";
     }
}

Tree::Tree(const Tree& s)
{
  root = copy(s.root);
}

TreeNode* Tree::copy(TreeNode *orignode)
{
  if (orignode) {
      TreeNode *temp = new TreeNode;
      temp->data = orignode->data;
      temp->LeftChild = copy(orignode->LeftChild);
      temp->RightChild = copy(orignode->RightChild);
      return temp;
  }
  else return 0;
}

int Tree::height()
{
    int h = height(root);
    return h;
}

int Tree::height(TreeNode *CurrentNode)
{
    // Get the height of the tree
    if (!CurrentNode)
        return 0;
    else
    {
        int leftH = height(CurrentNode->LeftChild);
        int rightH = height(CurrentNode->RightChild);
        if (leftH >= rightH)
            return leftH + 1;
        else
            return rightH + 1;
    }
}

int Tree::size()
{
    int total = size(root);
    return total;
}

int Tree::size(TreeNode *CurrentNode)
{
    if (!CurrentNode)
        return 0;
    else
    {
        int leftS = size(CurrentNode->LeftChild);
        int rightS = size(CurrentNode->RightChild);
        return leftS + rightS + 1;
    }
}
int Tree::sum()
{
    int total = sum(root);
    return total;
}
int Tree::sum(TreeNode *CurrentNode)
{
    if (!CurrentNode)
        return 0;
    else
    {
        return (CurrentNode->data + sum(CurrentNode->LeftChild) + sum(CurrentNode->RightChild));
    }
}


// Driver
int operator==(const Tree& s, const Tree& t)
{
   return equal(s.root, t.root);
}

// Workhorse
int equal(TreeNode *a, TreeNode *b)
/* This function returns 0 if the subtrees at @a@ and @b@ are not
   equivalent. Otherwise, it will return 1 */
{
 if ((!a) && (!b)) return 1;  // both @a@ and @b@ are 0
 if (a && b &&                // both @a@ and @b@ are non-0
    (a->data == b->data)      // @data@ is the same
    && equal(a->LeftChild, b->LeftChild) // left subtrees are the same
    && equal(a->RightChild, b->RightChild) ) // right subtrees are the same
       return 1;
 return 0;
}

int main()
{
Tree t;
t.setup();
Tree s = t;
cout<<"Elements: ";
s.inorder();
cout << endl;
cout<<"Equal?: ";
if (s == t) cout << 1; else cout << 0;
cout << endl;
cout<<"Size of tree: "<<s.size()<<endl;
cout<<"Height of tree: "<<s.height()<<endl;
cout<<"Sum of tree: "<<s.sum()<<endl;
return 0;
}

