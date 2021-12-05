#include <iostream>
#include <string>
#define MAXZISE 100

using namespace std;

template <typename T>
class Node
{
public:
	T data;
	Node *next=nullptr;
	Node *prev=nullptr;
};


template <typename T>
class Queue
{
public:
	Queue()
	{
        top=new Node<T>;
        bot=top;
        count=0;
	}

	~Queue()
	{
        count=0;
        Node<T> *temp=bot;
        while(temp){
            bot=bot->next;
            delete &temp;
            temp=bot;
        }
	}

	//TOP
	int AddFront(T d)
	{
	    if(count==0){
            top->data=d;
        }
        else{
            Node<T> *temp=top;
            top=new Node<T>;
            top->data=d;
            temp->next=top;
            top->prev=temp;
        }
        count++;
        return 1;
	}
	T *DeleteFront()
	{
	    if(count!=0){
            Node<T> *temp=top;
            top=top->prev;
            top->next=nullptr;
            count--;
            return &(temp->data);
        }
        else return nullptr;
	}


	//BOT
	int AddRear(T d)
	{
	    if(count==0){
            top->data=d;
        }
        else{
            Node<T> *temp=bot;
            bot=new Node<T>;
            bot->data=d;
            temp->prev=bot;
            bot->next=temp;
        }
        count++;
        return 1;
	}
	T *DeleteRear()
	{
	    if(count!=0){
            Node<T> *temp=bot;
            bot=bot->next;
            bot->prev=nullptr;
            count--;
            return &(temp->data);
        }
        else return nullptr;
	}

	bool isEmpty()
	{
	    if(count==0)return true;
	    else return false;
	}

	T checkFront()
	{
	    if(count!=0)return top->data;
	    else return NULL;
	}

	T CheckRear()
	{
	    if(count!=0)return bot->data;
	    else return NULL;
	}

	void reverse()
	{
	    Node<T> *temp=bot;
	    Node<T> *newnext;
	    Node<T> *newprev;
	    do{
            newprev=temp->next;
            newnext=temp->prev;
            temp->prev=newprev;
            temp->next=newnext;
            temp=temp->prev;
        }while(temp);
        newnext=bot;
        bot=top;
        top=newnext;
        return;
	}

	void printQueue()
	{
	    Node<T> *temp=bot;
	    while(temp){
            cout<<temp->data;
            if(temp!=top)cout<<",";
            temp=temp->next;
	    }
	    if(top!=bot)cout<<endl;
	}

private:
	Node<T> *top;
    Node<T> *bot;
    int count;
};

int main(void)
{
    Queue <int> test;
    for(int i = 1; i <= 10; i++){
        test.AddFront(i);
    }
    test.printQueue();
    test.DeleteFront();
    test.printQueue();
    test.DeleteRear();
    test.printQueue();
    test.reverse();
    test.printQueue();
    test.reverse();
    test.printQueue();
    return 0;
}
