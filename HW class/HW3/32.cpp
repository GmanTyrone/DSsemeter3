#include <iostream>
#include <string>
#define MAXZISE 100

using namespace std;

template <class T>
class Node
{
public:
	T data;
	Node *next=nullptr;
	Node *prev=nullptr;
};

template <class T>
class Queue
{
public:
	Queue()
	{
        top=new Node<T>;
        bot=top;
        mid=top;
        count=0;
	}

	//TOP
	int addFront(T d)
	{
	    if(count=0){
            top->data=d;
        }
        else if (!this.isFull()){
            Node<T> *temp=top;
            top=new Node<T>;
            top->data=d;
            temp->next=top;
            top->prev=temp;
            count++;
            return 1;
        }
        return -1;
	}
	int *deleteFront()
	{
	    if(count!=0){
            Node<T> *temp=top;
            top=top->prev;
            count--;
            if(count%2==0)mid=mid->prev;
            return &(temp->data);
        }
        else return nullptr;
	}

	//Middle
	int addMiddle(T d)
	{
	    if(count=0){
            top->data=d;
        }
        else if(count%2==0&&!this.isFull()){
            Node<T> *temp=mid;
            mid=new Node<T>;
            mid->data=d;
            mid->prev=temp;
            mid->next=temp->next;
            temp->next->prev=mid;
            temp->next=mid;
            count++;
            return 1;
        }
        return -1;
	}

	int *deleteMiddle()
	{
	    if(count!=0&&count%2!=0){
            Node<T> *temp=mid;
            mid->next->prev=mid->prev;
            mid->prev->next=mid->next;
            mid=mid->prev;
            count--;
            return &(temp->data);
        }
        else return nullptr;
	}


	//BOT
	int addRear(T d)
	{
	    if(count=0){
            top->data=d;
        }
        else if (!this.isFull()){
            Node<T> *temp=bot;
            bot=new Node<T>;
            bot->data=d;
            temp->prev=bot;
            bot->next=temp;
            count++;
            return 1;
        }
        return -1;
	}
	int *deleteRear()
	{
	    if(count!=0){
            Node<T> *temp=bot;
            bot=bot->next;
            count--;
            if(count%2==0)mid=mid->next;
            return &(temp->data);
        }
        else return nullptr;
	}

	bool isFull()
	{
	    if(count==MAXZISE)return true;
	    return false;
	}

	bool isEmpty()
	{
	    if(count==0)return true;
	    return false;
	}


private:
	Node<T> *top;
    Node<T> *bot;
    Node<T> *mid;
    int count;
};

int main(void)
{

}
