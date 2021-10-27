#include<iostream>
#include<cstdlib>

using namespace std;

struct Node
{
	Node()
	{
	    data=0;
	    next=NULL;
	}
	Node(int x)
	{
	    data=x;
	    next=NULL;
	}
	int data;
	Node *next;
};

class Set
{
public:
	Set()
	{
	}

	Set(const Set &a)
	{
	    Node *original=a.element;
		while(original != NULL)
		{
			addElement(original->data);
			original=original->next;
		}
	}

	int addElement(int e)
	{
	    Node* temp=new Node(e);
	    //Checks if theres any element at all
	    if(element==NULL)
        {
            element=temp;
            return true;
        }
        else if(e<element->data)
        {
            temp->next=element;
            element=temp;
            return true;
        }

        //Checks all the elements until the end to see if it is repeated
	    Node *cur = element;
		while(e>cur->data&&cur->next!=NULL)
        {
            if(e<cur->next->data)break;
            cur = cur->next;
        }
        if(cur->data==e)return false;


		//If found then does nothing if not found then it is added
		temp->next=cur->next;
		cur->next=temp;
		return true;
	}

	Set *unions(const Set *b) const
	{
	    Set* Juntos=new Set(*this);
	    Node *cur = b->element;
		while(cur != NULL)
		{
			Juntos->addElement(cur->data);
			cur = cur->next;
		}
		return Juntos;
	}

	Set *intersetcions(const Set *b) const
	{
	    Set* Inter=new Set();
	    for(Node* x=element; x != NULL;x=x->next)
        {
            for(Node* y=b->element;y!=NULL;y=y->next)
            {
                if(x->data==y->data)Inter->addElement(y->data);
            }
        }
        return Inter;
	}

	bool equivalent(const Set *b) const
	{

        //IF THE SETS ARE SAME SIZE ONLY ONE IS NEEDED
        for(Node* x=element; x != NULL;x=x->next)
        {
            bool flag=false;
            for(Node* y=b->element;y!=NULL;y=y->next)
            {
                if(x->data==y->data)flag=true;
            }
            if(flag==false)return false;
        }

        //IF NOT SAME SIZE ANOTHER ONE IS NEEDED TO MAKE SURE THEY'RE NOT SUBSETS
        for(Node* x=b->element; x != NULL;x=x->next)
        {
            bool flag=false;
            for(Node* y=element;y!=NULL;y=y->next)
            {
                if(x->data==y->data)flag=true;
            }
            if(flag==false)return false;
        }
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
private:
	Node *element=NULL;
};

int main()
{
	Set *a = new Set();
	Set *b = new Set();
	Set *c;
	Node *cur;

	a->addElement(2);
	a->addElement(1);
	a->addElement(2);
	a->addElement(3);
	b->addElement(3);
	b->addElement(4);
	b->addElement(5);
	b->addElement(5);

	a->listAll();
	cout<<endl;
	b->listAll();
	cout<<endl;

	c = a->unions(b);
	c->listAll();
	cout<<endl;

	c = a->intersetcions(b);
	c->listAll();

	if(a->equivalent(b) == 0)
		cout<<"Not equivalent.\n";
	else
		cout<<"Equivalent!\n";
}
