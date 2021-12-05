#include<iostream>
#include<cstdlib>
#include<ctime>
#include <queue>

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
        inorder(root);
	}
	void preorder()
	{
		preorder(root);
	}
	void postorder()
	{
		postorder(root);
	}
	void levelorder(){
	    queue<Node*> q;
	    Node* currentNode=root;
	    while(currentNode){
            cout<<currentNode->data<<" ";
            if(currentNode->left)q.push(currentNode->left);
            if(currentNode->right)q.push(currentNode->right);
            if(q.empty())return;
            currentNode=q.front();
            q.pop();
	    }
	}

private:
    void inorder(Node* currentNode){
		if(currentNode){
			inorder(currentNode->left);
            cout<<currentNode->data<<" ";
            inorder(currentNode->right);
		}
		return;
    }
    void preorder(Node* currentNode){

		if(currentNode){
			cout<<currentNode->data<<" ";
            preorder(currentNode->left);
            preorder(currentNode->right);;
		}
        return;
    }
    void postorder(Node* currentNode){
		if(currentNode){
			postorder(currentNode->left);
            postorder(currentNode->right);
            cout<<currentNode->data<<" ";;
		}
        return;
    }

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
		node->data = rand()%10;
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
