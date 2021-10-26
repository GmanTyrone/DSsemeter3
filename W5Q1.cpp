#include<iostream>
#include<cstdlib>

using namespace std;

struct Node
{
	Node()
	{
	}
	Node(int x)
	{
	    data=x;
	}
	int data=0;
	Node *next=NULL;
};

class Set
{
public:
	Set()
	{
	}

	Set(const Set &a)
	{
	    Node *cur=element;
	    Node *original=a.element;
		while(original != NULL)
		{
			Node* temp=new Node;

			//Copies data and goes to next node
			cur->data=original->data;
			original = original->next;
			if(original==NULL)break;

			//If continues then makes a next node and makes it the current one
			cur->next=temp;
			cur=temp;
		}
	}

	int addElement(int e)
	{
	    //Checks if theres any element at all
	    if(element==NULL)
        {
            element=new Node(e);
            return true;
        }

        //Checks all the elements until the end to see if it is repeated
	    bool found=false;
	    Node *cur;
	    cur = element;
		while(cur != NULL)
		{
			if(cur->data==e){
                found=true;
			}
			cout<<"current element: "<<cur->data<<endl;
			cur = cur->next;
		}

		//If found then does nothing if not found then it is added
		if(found)return false;
		cur=new Node(e);
		return true;
	}

	Set *unions(const Set *b) const
	{
	    Set Juntos=Set(*this);
	    Node *cur = b->element;
		while(cur != NULL)
		{
			Juntos.addElement(cur->data);
			cur = cur->next;
		}
		return &Juntos;
	}

	Set *intersetcions(const Set *b) const
	{
	}

	bool equivalent(const Set *b) const
	{
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
private:
	Node *element=NULL;
};

int main()
{
	Set *a = new Set();
	Set *b = new Set();
	Set *c;
	Node *cur;

	a->addElement(1);
	a->addElement(2);
	a->addElement(3);
	/*b->addElement(3);
	b->addElement(4);
	b->addElement(5);
	b->addElement(5);*/

	a->listAll();

	//c = a->unions(b);
	//c->listAll();
/*
	c = a->intersetcions(b);
	c->listAll();

	if(a->equivalent(b) == 0)
		cout<<"Not equivalent.\n";
	else
		cout<<"Equivalent!\n";*/
}
