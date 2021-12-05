#include<iostream>
#include<cstdlib>

using namespace std;
#define INT_MAX 50;

struct Node
{
	Node()
	{
	    data=0;
	    next=NULL;
	}
	Node(char x)
	{
	    data=x;
	    next=NULL;
	}
	char data;
	Node *next;
};

class wordSet
{
public:
	wordSet()
	{
	}

	wordSet(const wordSet &a)
	{
	    Node *original=a.element;
		while(original != NULL)
		{
			addElement(original->data);
			original=original->next;
		}
	}

	wordSet(string s)
	{
	    for(int y = 0; y < s.size(); y++)
        {
            addElement(s[y]);
        }
	}

	char addElement(char e)
	{
	    Node* temp=new Node(e);
	    //Checks if theres any element at all
	    if(element==NULL)
        {
            element=temp;
            return e;
        }
        else if(e<element->data)
        {
            temp->next=element;
            element=temp;
            return e;
        }

        //Checks all the elements until the end to see if it is repeated
	    Node *cur = element;
		while(/*e>cur->data&&*/cur->next!=NULL)
        {
            //if(e<cur->next->data)break;
            cur = cur->next;
        }
        //if(cur->data==e)return false;


		//If found then does nothing if not found then it is added
		temp->next=cur->next;
		cur->next=temp;
		return e;
	}

	wordSet *setUnion(const wordSet *b) const
	{
	    wordSet* Juntos=new wordSet(*this);
	    Node *cur = b->element;
		while(cur != NULL)
		{
			Juntos->addElement(cur->data);
			cur = cur->next;
		}
		return Juntos;
	}

	wordSet *setIntersection(const wordSet *b) const
	{
	    wordSet* Inter=new wordSet();
	    for(Node* x=element; x != NULL;x=x->next)
        {
            for(Node* y=b->element;y!=NULL;y=y->next)
            {
                if(x->data==y->data)Inter->addElement(y->data);
            }
        }
        return Inter;
	}

	wordSet *setDifference(const wordSet *b) const
	{
	    wordSet* Diff=new wordSet(*this);
	    wordSet* Inter;
	    Inter = this->setIntersection(b);
	    bool found;
	    for(Node* x=element; x != NULL;x=x->next)
        {
            found=false;
            for(Node* y=Inter->element;y!=NULL;y=y->next)
            {
                if(x->data==y->data)found=true;
            }
            if(!found)Diff->addElement(x->data);
        }
        return Diff;
	}

	int compareWordSets(const wordSet *b) const
	{

        bool subset=true;
        bool superset=true;
        //IF THE SETS ARE SAME SIZE ONLY ONE IS NEEDED
        for(Node* x=element; x != NULL;x=x->next)
        {
            bool found=false;
            for(Node* y=b->element;y!=NULL;y=y->next)
            {
                if(x->data==y->data)found=true;
            }
            if(found==false){subset=false;break;}
        }

        //IF NOT SAME SIZE ANOTHER ONE IS NEEDED TO MAKE SURE THEY'RE NOT SUBSETS
        for(Node* x=b->element; x != NULL;x=x->next)
        {
            bool found=false;
            for(Node* y=element;y!=NULL;y=y->next)
            {
                if(x->data==y->data)found=true;
            }
            if(found==false){superset=false;break;}
        }

        if(subset&&superset)return 0;
        else if(subset)return -1;
        else if(superset)return 1;
        else return INT_MAX;
	}

	void listAll() const
	{
		Node *cur = element;
		while(cur != NULL)
		{
			cout<<cur->data;
			cur = cur->next;
		}
		cout<<endl;
	}
private:
	Node *element=NULL;
};

int main()
{
	wordSet *a = new wordSet("avion");
	wordSet *b = new wordSet();
	wordSet *c;
	Node *cur;

	b->addElement('3');
	b->addElement('4');
	b->addElement('5');
	b->addElement('5');

	a->listAll();
	b->listAll();
	cout<<a->compareWordSets(b)<<endl;

	b=new wordSet("avio");
	a->listAll();
	b->listAll();
	cout<<a->compareWordSets(b)<<endl;

	a=new wordSet("av");
	a->listAll();
	b->listAll();
	cout<<a->compareWordSets(b)<<endl;

	a=new wordSet("avio");
	a->listAll();
	b->listAll();
	cout<<a->compareWordSets(b)<<endl;
}
