#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <ctime>

template<class T>
class Node
{
protected:
	T *data;

public:
    //Default empty node
	Node()
	{
		data = new T;
	}
	//Node with value
	Node(T d)
	{
		data = new T;
		(*data) = d;
	}

	//Change value of Node data to d with = sign, returns Node
	Node &operator=(T d)
	{
		(*data) = d;
		return *this;
	}

	//lets use << on node to output data
	friend std::ostream &operator<<(std::ostream &out, Node n)
	{
		out<<*(n.data);
		return out;
	}

	//lets use << on node pointer to output data
	friend std::ostream &operator<<(std::ostream &out, Node *n)
	{
		out<<*(n->data);
		return out;
	}

	//Sets data of node to D but returns nothing
	void setData(T d)
	{
		*data = d;
	}

	//Gets data from Node
	T &getData() const
	{
		return *data;
	}
};


//Linked list to store the nodes childs from tree
template<class T>
class ListNode : public Node<T>
{
private:
	ListNode *prev, *next;

public:

    //Creates default listnode
	ListNode() : Node<T>()
	{
		prev = NULL;
		next = NULL;
	}

	//Creates listnode with value d and empty childs
	ListNode(T d) : Node<T>(d)
	{
		prev = NULL;
		next = NULL;
	}

	//Creates listnode with empty data but prev and next listnodes
	ListNode(ListNode *p, ListNode *n) : Node<T>()
	{
		prev = p;
		next = n;
	}

	//Creates listnode with data d, and prev and next listnodes
	ListNode(T d, ListNode *p, ListNode *n) : Node<T>(d)
	{
		prev = p;
		next = n;
	}

	//Gets next listnode from a listnode
	ListNode *getNext() const
	{
		return next;
	}

	//Gets prev listnode from a listnode
	ListNode *getPrev() const
	{
		return prev;
	}

	//Sets next listnode
	void setNext(ListNode *n)
	{
		next = n;
	}

	//Sets prev listnode
	void setPrev(ListNode *p)
	{
		prev = p;
	}

	//Overloads = operator to asign data to a listnode, returns listnode
	ListNode &operator=(T d)
	{
		this->setData(d);
		return *this;
	}
};

template<class T>
class LinkList
{
protected:
	ListNode<T> *head, *tail;

public:

    //Default empty constructor
	LinkList()
	{
		head = NULL;
		tail = NULL;
	}


	//Creates new node making it head and changing the pointers of head and tail(if necessary)
	//Next refers to nodes after head; head->next->next->tail;
	void addFromHead(T d)
	{
		ListNode<T> *node = new ListNode<T>(d);
		if(head != NULL)
		{
			head->setPrev(node);
		}
		node->setNext(head);
		head = node;
		if(tail == NULL)
			tail = node;
	}

	//Creates new node making it tail and changing the pointers of tail and head(if necessary)
	//Prev refers to nodes before tail; head<-prev<-prev<-tail;
	void addFromTail(T d)
	{
		ListNode<T> *node = new ListNode<T>(d);
		if(tail != NULL)
		{
			tail->setNext(node);
		}
		node->setPrev(tail);
		tail = node;
		if(head == NULL)
			head = node;
	}

	//adds node at a place
	void addAfter(ListNode<T> *at, T d)
	{
		if(!exist(at))
			return;
		ListNode<T> *node = new ListNode<T>(d);
		if(at->getNext() != NULL)
			at->getNext()->setPrev(node);
		node->setNext(at->getNext());
		at->setNext(node);
		node->setPrev(at);
		if(node->getNext() == NULL)
			tail = node;
	}

	//removes head node, makes the next one the head
	ListNode<T> *removeFromHead()
	{
		ListNode<T> *n = head;
		if(head != NULL)
		{
			head = head->getNext();
			if(head != NULL)
				head->setPrev(NULL);
			else
				tail = NULL;
			n->setNext(NULL);
		}
		return n;
	}

	//removes tail node, makes the prev one the head
	ListNode<T> *removeFromTail()
	{
		ListNode<T> *n = tail;
		if(tail != NULL)
		{
			tail = tail->getPrev();
			if(tail != NULL)
				tail->setNext(NULL);
			else
				head = NULL;
			n->setPrev(NULL);
		}
		return n;
	}

	//removes node at place n
	ListNode<T> *remove(ListNode<T> *n)
	{
		if(!exist(n))
			return NULL;
		if(n == head)
			return removeFromHead();
		if(n == tail)
			return removeFromTail();
		n->getPrev()->setNext(n->getNext());
		n->getNext()->setPrev(n->getPrev());
		n->setNext(NULL);
		n->setPrev(NULL);
		return n;
	}

	//returns node if the data d exists
	ListNode<T> *exist(T d)
	{
		ListNode<T> *j = head;
		while(j != NULL)
		{
			if(j->getData() == d)
				return j;
			j = j->getNext();
		}
		return NULL;
	}

	//returns true or false if the node at n exists
	bool exist(ListNode<T> *n)
	{
		ListNode<T> *j = head;
		while(j != NULL)
		{
			if(j == n)
				return true;
			j = j->getNext();
		}
		return false;
	}

	//Overloads operator [] to subscript node
	ListNode<T> &operator[](int i)
	{
		ListNode<T> *j = head;
		int k;
		for(k = 0;k < i && j != NULL;k ++)
			j = j->getNext();
		if(j == NULL)
			throw std::invalid_argument("index does not exist.");
		return *j;
	}


	//prints the list
	void print() const
	{
		ListNode<T> *j;
		j = head;
		while(j != NULL)
		{
			std::cout<<(*j)<<" ";
			j = j->getNext();
		}
		std::cout<<std::endl;
	}

	int count () const
	{
		ListNode<T> *j;
		int size=0;
		j = head;
		while(j != NULL)
		{
			size++;
			j = j->getNext();
		}
		return size;
	}
};

/*
	Please finish the TreeNode class, TreeNode class respresent a node in a general tree.
	A general tree is different from binary tree, every node in binary tree have at most two child node, but a node in general tree may have more than two child node.
*/
template<class T>
class TreeNode : public Node<T>
{
private:
    //a treenode stores its childs as a linked list
	LinkList<T> *childs;

public:

    //Default constructor for tree node with no value, inherits node and has a list of childs
	TreeNode() : Node<T>()
	{
	}
	//Default constructor for tree node with value d, inherits node and has a list of childs
	TreeNode(T d) : Node<T>(d)
	{
	}
	/*
		Add a child to this node.
	*/
	void addChild(TreeNode *n)
	{
	    childs->addChild(n->getData());
	}
	/*
		Add a child to this node.
	*/
	void addChild(T d)
	{
	    childs->addFromHead(d);
	}
	/*
		Return the nth child of the node.
	*/
	TreeNode *operator[](int n)
	{
	    childs[n];
	}
};

/*
	Please finish the Tree class. Tree class respresent a general tree, that means node on this tree may have more than two child node.

*/
template<class T>
class Tree
{
private:
	LinkList<T> *root;

public:
	Tree()
	{
	}
	/*
		return the nth node on this tree with level order.
	*/
	TreeNode<T> *operator[](int n)
	{
	    root[n];
	}
	/*
		return the number of nodes on this tree.
	*/
	int count()
	{
	    return root->count();
	}
	/*
		print all the node on this tree with level order.
	*/
	void levelOrder()
	{
	}
	/*
		print all the node on this tree with preorder.
	*/
	void preorder()
	{
	}
	/*
		print all the node on this tree with postorder.
	*/
	void postorder()
	{
	}
	/*
		set the root of this tree.
	*/
	void setRoot(T d)
	{
	}
};

int main()
{
	Tree<int> *tree = new Tree<int>();
	srand(0);
	int j, k, i;
	for(j = 0;j < 20;j ++)
	{
		if(tree->count() == 0)
			tree->setRoot(rand() % 100);
		else
		{
			k = rand() % tree->count();
			(*tree)[k]->addChild(rand() % 100);
		}
	}
	tree->levelOrder();
	tree->preorder();
	tree->postorder();
}
