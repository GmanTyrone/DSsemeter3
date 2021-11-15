#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
	int data;
	Node *next=nullptr;
};

class Queue
{
public:
	Queue()
	{
	}
	int enqueue(int d)
	{
	    if(count=0){
            top->data=d;
        }
        else{
            try{
            Node *temp=top;
            top=new Node;
            top->data=d;
            temp->next=top;
            }catch (const std::bad_alloc& e){return -1;}
        }
        count++;
        return 1;
	}
	int *dequeue()
	{
	    if(count!=0){
            Node *temp=bot;
            bot=bot->next;
            count--;
            return &(temp->data);
        }
        else return nullptr;
	}
private:
	Node *top=new Node;
    Node *bot=top;
    int count=0;
};

int main()
{
	int data, *temp;
	string command;
	Queue *queue = new Queue();
	while(1)
	{
		cin>>command;
		if(command.compare("exit") == 0)
		{
			break;
		}
		else if(command.compare("enqueue") == 0)
		{
			cout<<"Please input a integer data:";
			cin>>data;
			if(queue->enqueue(data) == 1)
			{
				cout<<"Successfully enqueue data "<<data<<" into queue."<<endl;
			}
			else
			{
				cout<<"Failed to enqueue data into queue."<<endl;
			}
		}
		else if(command.compare("dequeue") == 0)
		{
			temp = queue->dequeue();
			if(temp == NULL)
			{
				cout<<"Failed to dequeue a data from queue.\n";
			}
			else
			{
				cout<<"Dequeue data "<<*temp<<" from queue."<<endl;
			}
		}
	}
}
