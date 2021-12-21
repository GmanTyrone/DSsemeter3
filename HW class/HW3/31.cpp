#include <iostream>

using namespace std;

enum Boolean { FALSE, TRUE};
template <class Type> class List;
template <class Type> class ListIterator;

template <class Type>
class ListNode {
friend class List<Type>;
friend class ListIterator<Type>;
private:
    Type data;
    ListNode *link;
    ListNode(Type);
};

template <class Type>
ListNode<Type>::ListNode(Type element)
{
    data = element;
    link = 0;
}

template <class Type>
class List {
friend class ListIterator<Type>;
public:
    List() {first = 0;counter=0;};
    void Insert(Type);
    void Delete(Type);
    void Invert();
    void Concatenate(List<Type>);
    int length();
    Type atNth(int);
    ListNode<Type>* atNthPointer(int);
    void printAll();
    void deleteAll(int, Type);
    void shift(char, int);
    Boolean symmetric();
private:
    ListNode<Type> *first;
    int counter;
};

template <class Type>
void List<Type>::Insert(Type k)
{
ListNode<Type> *newnode = new ListNode<Type>(k);
newnode->link = first;
first = newnode;
counter++;
}

template <class Type>
void List<Type>::Delete(Type k)
{
    ListNode<Type> *previous = 0;
    ListNode<Type> *current = first;
    for (; current && current->data != k;
	previous = current, current = current->link){

    }
        if (current)
        {
            if (previous) previous->link = current->link;
            else first = first->link;
            delete current;
            counter--;
        }else{
            cout<<"Could not find match to delete : "<<k;
        }

}

template <class Type>
void List<Type>::Invert()
{
    ListNode<Type> *p = first, *q = 0; // q trails p
    while (p) {
       ListNode<Type> *r = q; q = p; // r trails q
       p = p->link; // p moves to next node
       q->link = r; // link q to preceding node
    }
    first = q;
}

template <class Type>
void List<Type>::Concatenate(List<Type> b)
{
    if (counter == 0){
        first = b.first;
        return;
    }
    else {
        ListNode<Type> *temp2 = b.first;
        for(int i=0; i < b.counter; i++){
            this->Insert(temp2->data);
            temp2 = temp2->link;
        }
    }
}

template<class Type>
void List<Type>::printAll(){
    ListNode<Type>*temp = first;
    for(int y=0; y<counter; y++){
        cout<<temp->data<<" ";
        temp = temp->link;
    }
}

template<class Type>
int List<Type>::length(){
    return counter;
}

template<class Type>
Type List<Type>::atNth(int a){
    ListNode<Type> *iterate = first;
    if(a > counter){
        cout<<"There aren't elements in that index.\n";
        return 0;
    }else{
        //cout<<"here";
        for(int y=0; y < a; y++){
            iterate = iterate->link;
        }
        return iterate->data;
    }
}
template <class Type>
ListNode<Type>* List<Type>::atNthPointer(int a){
   ListNode<Type> *iterate = first;
    if(a > counter){
        return 0;
    }else{
        for(int y=0; y < a; y++){
            iterate = iterate->link;
        }
        return iterate;
    }
}
template <class Type>
void List<Type>::deleteAll(int y, Type k){

    int tracker = 0;

    while(tracker < y){
    ListNode<Type> *previous = 0;
    ListNode<Type> *current = first;
    for (; current && current->data != k;
	previous = current, current = current->link){
    }
        if (current)
        {

            if (previous) previous->link = current->link;
            else first = first->link;
            delete current;
            counter--;
        }
        tracker++;
    }
}
template <class Type>
void List<Type>::shift(char n, int x){
    int place = counter;
    if(x == 0) return;
    if(x > place){
        x = x%place;
    }
    if(n == 'R'){
        x = place - x;
    }
    if(n == 'R' || n == 'L'){
        ListNode<Type>* hold = this->atNthPointer(x-1);
        ListNode<Type>* hold2 = hold;
        hold = this->atNthPointer(counter-1);
        hold->link = this->first;
        this->first = hold2->link;
        hold2->link = NULL;
    }
}
template <class Type>
Boolean List<Type>::symmetric(){
    int max=counter/2;
    if (counter%2!=0)max--;
    for(int y=0; y <= max; y++){
            if(this->atNth(y) != this->atNth(counter-1-y)){
                return FALSE;
            }
        }
    return TRUE;
}

template <class Type>
class ListIterator {
public:
    ListIterator(const List<Type>& l): list(l), current (l.first) {};
    Boolean NotNull();
    Boolean NextNotNull();
    Type* First();
    Type* Next();
private:
    const List<Type> &list;  // refers to an existing list
    ListNode<Type>* current; // points to a node in list
};

template <class Type> //check that current element in list is non-null
Boolean ListIterator<Type>::NotNull()
{
if (current) return TRUE;
else return FALSE;
}

template <class Type>  // check that the next element in list is non-null
Boolean ListIterator<Type>::NextNotNull()
{
if (current && current->link) return TRUE;
else return FALSE;
}

template <class Type> // return a pointer to the first element of list
Type* ListIterator<Type>::First() {
      if (list.first) return &list.first->data;
      else return 0;
}

template <class Type> // return a pointer to the next element of list
Type* ListIterator<Type>::Next() {
      if (current) {
	 current = current->link;
	 return &current->data;
      }
      else return 0;
}

int sum(const List<int>& l)
{
  ListIterator<int> li(l);
  if (!li.NotNull()) return 0;
  int retvalue = *li.First();
  while (li.NextNotNull())retvalue += *li.Next();
  return retvalue;
}



//template <class Type>
ostream& operator<<(ostream& os, List<char>& l)
{
    ListIterator<char> li(l);
    if (!li.NotNull()) return os;
    os << *li.First() << endl;
    while  (li.NextNotNull())
	 os << *li.Next() << endl;
    return os;
}

int main()
{
    List<int> intlist;
    List<int> intC;
    intC.Insert(1);
    intC.Insert(2);
    intC.Insert(3);
    intC.Insert(4);
    intC.Insert(3);
    intC.Insert(2);
    intC.Insert(1);
    cout<<"Symmetric: ";
    cout<<intC.symmetric()<<endl;
    intlist.Insert(5);
    intlist.Insert(7);
    intlist.Insert(6);
    intlist.Insert(6);
    intlist.Insert(6);
    intlist.Insert(6);
    cout<<"Lenght: ";
    cout<<intlist.length()<< endl;
    cout<<"Element at 0: ";
    cout<<intlist.atNth(0)<<endl;
    cout << "Sum: "<< sum(intlist) << endl<<endl;
    cout<<"Delete 6"<<endl;
    cout<<"Lenght: ";
    intlist.Delete(6);
    cout<<intlist.length()<<endl;
    cout<<"Sum: "<<sum(intlist)<<endl<<endl;
    cout<<"Deleting all 6"<<endl;
    //intlist.printAll();
    intlist.deleteAll(2,6);
    cout<<"Lenght: ";
    intlist.Delete(6);
    cout<<intlist.length()<<endl;
    cout<<"Sum: "<<sum(intlist)<<endl;
    cout<<endl;
    intlist.printAll();
    cout<<endl;
    intlist.Concatenate(intC);
    cout<<"Concatenate size: "<<intlist.length()<<endl;
    cout<<"List of elements"<<endl;
    intlist.printAll();

    cout<<endl;
    cout<<"Shifting to the right by 4 spaces:\n";
    intlist.shift('R', 4);
    intlist.printAll();cout<<endl;
    List<char> charlist;
    cout << "shd be empty: " << charlist << endl;
    charlist.Invert();
    cout << "shd be empty: " << charlist << endl;
    charlist.Insert('d');
    charlist.Invert();
    cout << "shd have d : \n" << charlist << endl;
    charlist.Insert('c');
    charlist.Insert('b');
    charlist.Insert('a');
    cout << "shd have abcd: \n";
    cout << charlist << endl;
    charlist.Invert();
    cout << "shd invert prev list:\n";
    cout << charlist << endl;
    List<char> char2list;
    charlist.Concatenate(char2list);
    cout << charlist << endl;
    char2list.Insert('e');
    char2list.Insert('f');
    char2list.Concatenate(charlist);
    charlist.Delete('e');
    cout<<endl;
    charlist.Delete('c');
    cout<<endl;
    cout << char2list << endl;
    char2list.Invert();
    cout << char2list << endl;
    return 0;
}
