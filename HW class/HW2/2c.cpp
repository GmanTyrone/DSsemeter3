#include <iostream>
#include <string>
#define MAXZISE 100

using namespace std;

class Node
{
public:
	int data;
	Node *next=nullptr;
	Node *prev=nullptr;
};

class Queue
{
public:
	Queue()
	{
        top=new Node;
        bot=top;
        mid=top;
        count=0;
	}

	//TOP
	int AddFront(int d)
	{
	    if(count=0){
            top->data=d;
        }
        else{
            Node *temp=top;
            top=new Node;
            top->data=d;
            temp->next=top;
            top->prev=temp;
        }
        count++;
        return 1;
	}
	int *DeleteFront()
	{
	    if(count!=0){
            Node *temp=top;
            top=top->prev;
            count--;
            if(count%2==0)mid=mid->prev;
            return &(temp->data);
        }
        else return nullptr;
	}

	//BOT
	int AddRear(int d)
	{
	    if(count=0){
            top->data=d;
        }
        else{
            Node *temp=bot;
            bot=new Node;
            bot->data=d;
            temp->prev=bot;
            bot->next=temp;
        }
        count++;
        return 1;
	}
	int *DeleteRear()
	{
	    if(count!=0){
            Node *temp=bot;
            bot=bot->next;
            count--;
            if(count%2==0)mid=mid->next;
            return &(temp->data);
        }
        else return nullptr;
	}

	bool IsEmpty()
	{
	    if(count==0)return true;
	    return false;
	}

	int CheckFront()
	{
	    if(count==0)return NULL;
	    else return top->data;
	}


private:
	Node *top;
    Node *bot;
    Node *mid;
    int count;
};

int main(void)
{

}
