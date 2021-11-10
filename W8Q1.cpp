#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

class Node
{
public:
	int level, data;
	Node *left, *right;
};

class Tree
{
public:
	Tree()
	{
		root = NULL;
	}
	int insert(Node *n)
	{
		insert(&root, n);
	}
	void inorder()
	{
	}
	void preorder()
	{
	}
	void postorder()
	{
	}
	void levelorder()
	{
	}
private:
	Node *root;
	void insert(struct Node **r, struct Node *n)
	{
		if(*r == NULL)
			*r = n;
		else if(n->data > (*r)->data)
			insert(&((*r)->right), n);
		else
			insert(&((*r)->left), n);
	}
};

int main()
{
	Tree *tree = new Tree();
	Node *node;
	int j;
	srand(time(NULL));
	for(j = 0;j < 10;j ++)
	{
		node = new Node();
		node->data = rand();
		node->left = NULL;
		node->right = NULL;
		tree->insert(node);
	}
	tree->inorder();
	printf("\n");
	tree->preorder();
	printf("\n");
	tree->postorder();
	printf("\n");
	tree->levelorder();
	printf("\n");
}
