#include<iostream>
#include<cstdlib>
#include<ctime>
#include <queue>

using namespace std;

class Node
{
public:
    Node()
    {
    }
    Node(int x)
    {
        data=x;
    }
	int level, data;
	Node
	//Left and right childs in tree
	*left, *right,
	//Next and Previous in Set
	*next, *prev,
	//Next and previous in Linked list
	*avanzare, *ritorno;
};

class Set
{
public:
	Set()
	{
	}

	int addElement(struct Node *n)
	{
	    Node* temp=n;
	    //Checks if theres any element at all
	    if(element==NULL)
        {
            element=temp;
            return true;
        }
        else if(n->data<element->data)
        {
            temp->next=element;
            element=temp;
            return true;
        }

        //Checks all the elements until the end to see if it is repeated
	    Node *cur = element;
		while(n->data>cur->data&&cur->next!=NULL)
        {
            if(n->data<cur->next->data)break;
            cur = cur->next;
        }

        //If found adds it to the end of list
        if(cur->data==n->data){
            if(cur->avanzare==NULL){
                temp->ritorno=cur;
                cur->avanzare=temp;
                return false;
            }
            else while(cur->avanzare==NULL){
                cur=cur->avanzare;
            }
            temp->ritorno=cur;
            cur->avanzare=temp;
            return false;
        }

		//If not found then it is added
		temp->next=cur->next;
		cur->next=temp;
		return true;
	}

	void listAll() const
	{
		Node *cur = element;
		while(cur != NULL)
		{
			cout<<cur->data<<" ";
			cur = cur->next;
		}
	}
	void listEvery(int x) const
	{
	    Node* temp = element;
	    while(temp->data!=x&&temp->next!=NULL)
        {
            temp=temp->next;
        }
        if(temp->data!=x&&temp->next==NULL)cout<<"not found"<<endl;
        else do{
            cout<<temp->data<<" ";
            temp=temp->avanzare;
        }while(temp->avanzare!=NULL);
	}
private:
	Node *element=NULL;
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
	Set List;

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
        List.addElement(n);
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

    cout<<"Inorder: "<<endl;
	tree->inorder();
	cout<<endl;

	cout<<"Linked Set: "<<endl;
	tree->List.listAll();
	cout<<endl;


	int randnum=rand()%10;
	cout<<"All "<<randnum<<": "<<endl;
	tree->List.listEvery(randnum);

}
