#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

class node
{
public:
    int data;
    class node *next;
    class node *prev;

};

class dqueue : public node

{
    node *head, *tail,*mid;
    int top1, top2,middle;

    public:

    dqueue()
    {
        top1 = 0;
        top2 = 0;
        mid = 0;
        head = NULL;
        tail = NULL;
    }

    void push(int x) {
        node *temp;
        int ch;
        if (top1 + top2 >= 5)
        {
            cout << "dqueue overflow";
            return;
        }
        if (top1 + top2 == 0)
        {
            head = new node;
            head->data = x;
            head->next = NULL;
            head->prev = NULL;
            tail = head;
            top1++;
        }
        else
        {
            cout << " Add element 1.FIRST 2.Middle 3.LAST\n enter ur choice:";
            cin >> ch;
            if (ch == 1)
            {
                top1++;
                temp = new node;
                temp->data = x;
                temp->next = head;
                temp->prev = NULL;
                head->prev = temp;
                head = temp;
            }
            else if(ch==2)
            {
                middle = top1 + top2;
                temp = new node;
                mid->next = temp;
                temp->next = mid->next;
                temp->prev = temp;
            }
            else
            {
                top2++;
                temp = new node;
                temp->data = x;
                temp->next = NULL;
                temp->prev = tail;
                tail->next = temp;
                tail = temp;
            }
        }

    }

    void pop()
    {
        int ch;
        cout << "Delete 1.First Node 2.Last Node 3.Middle Node\n Enter ur choice:";
        cin >> ch;
        if (top1 + top2 <= 0)
        {
            cout << "\nDqueue under flow";
            return;
        }
        if (ch == 1)
        {
            head = head->next;
            head->prev = NULL;
            top1--;
        }
        else if(ch==2)
        {
            top2--;
            tail = tail->prev;
            tail->next = NULL;
        }
        else
        {
            middle=top1+top2;
            mid->next = mid->next->next;
            mid->prev = mid->prev->prev;
        }
    }

    void display()
    {
        int ch;
        node *temp;
        cout << "Display from 1.Staring 2.Ending\n Enter ur choice";
        cin >> ch;
        if (top1 + top2 <= 0)
        {
            cout << "under flow";
            return;
        }
        if (ch == 1)
        {
            temp = head;
            while (temp != NULL)
            {
                cout << temp->data << " \n";
                temp = temp->next;
            }
        }
        else
        {
            temp = tail;
            while (temp != NULL)
            {
                cout << temp->data << " \n";
                temp = temp->prev;
            }
        }
    }
};

int main()

{

dqueue d1;

int ch;

while (1) {

cout << "1.INSERT 2.DELETE 3.DISPLAY 4.EXIT\n Enter ur choice:";

cin >> ch;

switch (ch)

{

case 1: cout << "Enter element";

cin >> ch;

d1.push(ch); break;

case 2: d1.pop(); break;

case 3: d1.display(); break;

case 4: exit(1);

}

}

return 0;

}
