#include <iostream>
#include <string>

#define SIZE 100

using namespace std;

class Node
{
public:
	int data;
	Node *next=nullptr;
};

class Stack
{
public:
    Stack()
    {
    }
    int push(int d)
    {
        try{
        Node *temp=new Node();
        temp->data=d;
        temp->next=top;
        top=temp;
        }catch (const std::bad_alloc& e){return -1;}
        count++;
        return 1;
    }

    int *pop()
    {
        if(count!=0){
            Node *temp=top;
            top=top->next;
            count--;
            return &(temp->data);
        }
        else return nullptr;
    }
private:
    Node *top=nullptr;
    int count=0;
};

int main()
{
    int data, *temp;
    string command;
    Stack *stack = new Stack();
    while(1)
    {
        cin>>command;
        if(command.compare("exit") == 0)
        {
            break;
        }
        else if(command.compare("push") == 0)
        {
            cout<<"Please input a integer data:";
            cin>>data;
            if(stack->push(data) == 1)
            {
                cout<<"Successfully push data %d into stack.\n";
            }
            else
            {
                cout<<"Failed to push data into stack.\n";
            }
        }
        else if(command.compare("pop") == 0)
        {
            temp = stack->pop();
            if(temp == NULL)
            {
                cout<<"Failed to pop a data from stack.\n";
            }
            else
            {
                cout<<"Pop data %d from stack.\n"<<*temp;
            }
        }
    }
}

