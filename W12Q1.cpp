#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <queue>

using namespace std;

template<class T>
class Node
{
protected:
    T *data;
public:

    Node()
    {
        data = new T;
    }
    Node(T d)
    {
        data = new T;
        (*data) = d;
    }
    Node &operator=(T d)
    {
        (*data) = d;
        return *this;
    }
    friend ostream &operator<<(ostream &out, Node n)
    {
        out << *(n.data);
        return out;
    }
    friend ostream &operator<<(ostream &out, Node *n)
    {
        out << *(n->data);
        return out;
    }
    void setData(T d)
    {
        *data = d;
    }
    T &getData() const
    {
        return *data;
    }
};

template<class T>
class ListNode : public Node<T>
{
private:
    ListNode *prev, *next;
public:
    ListNode() : Node<T>()
    {
        prev = NULL;
        next = NULL;
    }
    ListNode(T d) : Node<T>(d)
    {
        prev = NULL;
        next = NULL;
    }
    ListNode(ListNode *p, ListNode *n) : Node<T>()
    {
        prev = p;
        next = n;
    }
    ListNode(T d, ListNode *p, ListNode *n) : Node<T>(d)
    {
        prev = p;
        next = n;
    }
    ListNode *getNext() const
    {
        return next;
    }
    ListNode *getPrev() const
    {
        return prev;
    }
    void setNext(ListNode *n)
    {
        next = n;
    }
    void setPrev(ListNode *p)
    {
        prev = p;
    }
    ListNode &operator=(T d)
    {
        this -> setData(d);
        return *this;
    }
};

template<class T>
class LinkList
{
public:
    LinkList()
    {
        head = NULL;
        tail = NULL;
    }
    void addFromHead(T d)
    {
        ListNode<T> *node = new ListNode<T>(d);
        if (head != NULL)
        {
            head -> setPrev(node);
        }
        node -> setNext(head);
        head = node;
        if (tail == NULL) tail = node;
    }
    void addFromTail(T d)
    {
        ListNode<T> *node = new ListNode<T>(d);
        if (tail != NULL)
        {
            tail -> setNext(node);
        }
        node -> setPrev(tail);
        tail = node;
        if (head == NULL) head = node;
    }
    void addAfter(ListNode<T> *at, T d)
    {
        if (!exist(at)) return;
        ListNode<T> *node = new ListNode<T>(d);
        if (at->getNext() != NULL) at -> getNext() -> setPrev(node);
        node -> setNext(at->getNext());
        at -> setNext(node);
        node -> setPrev(at);
        if (node -> getNext() == NULL) tail = node;
    }
    ListNode<T> *removeFromHead()
    {
        ListNode<T> *n = head;
        if (head != NULL)
        {
            head = head -> getNext();
            if (head != NULL)
            {
                head->setPrev(NULL);
            }
            else
            {
                tail = NULL;
            }
            n -> setNext(NULL);
        }
        return n;
    }
    ListNode<T> *removeFromTail()
    {
        ListNode<T> *n = tail;
        if (tail != NULL)
        {
            tail = tail -> getPrev();
            if (tail != NULL)
            {
                tail->setNext(NULL);
            }
            else
            {
                head = NULL;
            }
            n -> setPrev(NULL);
        }
        return n;
    }
    ListNode<T> *remove(ListNode<T> *n)
    {
        if (!exist(n)) return NULL;
        if (n == head) return removeFromHead();
        if (n == tail) return removeFromTail();
        n -> getPrev() -> setNext(n -> getNext());
        n -> getNext() -> setPrev(n -> getPrev());
        n -> setNext(NULL);
        n -> setPrev(NULL);
        return n;
    }
    ListNode<T> *exist(T d)
    {
        ListNode<T> *j = head;
        while (j != NULL)
        {
            if (j -> getData() == d) return j;
            j = j -> getNext();
        }
        return NULL;
    }
    bool exist(ListNode<T> *n)
    {
        ListNode<T> *j = head;
        while (j != NULL)
        {
            if (j == n) return true;
            j = j->getNext();
        }
        return false;
    }
    ListNode<T> &operator[](int i)
    {
        ListNode<T> *j = head;
        for (int k = 0; k < i && j != NULL; k++)
        {
            j = j -> getNext();
        }
        if (j == NULL) throw std::invalid_argument("index does not exist.");
        return *j;
    }
    void print() const
    {
        ListNode<T> *j;
        j = head;
        while (j != NULL)
        {
            cout << (*j) << " ";
            j = j -> getNext();
        }
        cout << endl;
    }
protected:
    ListNode<T> *head, *tail;
};

/*
    Please finish the TreeNode class, TreeNode class represent a node in a general tree.
    A general tree is different from binary tree, every node in binary tree have at most two child node, but a node in general tree may have more than two child node.
*/
template<class T>
class TreeNode : public Node<T>
{
public:
    TreeNode() : Node<T>()
    {
        child = new LinkList<TreeNode<T> *>();
    }
    TreeNode(T d) : Node<T>(d)
    {
        child = new LinkList<TreeNode<T> *>();
        this->setData(d);
    }
    /*
        Add a child to this node.
    */
    void addChild(TreeNode *n)
    {
        child->addFromTail(n);
    }
    /*
        Add a child to this node.
    */
    void addChild(T d)
    {
        child->addFromTail(new TreeNode<T>(d));
    }
    /*
        Return the nth child of the node.
    */
    TreeNode<T> *operator[](int n)
    {
        //return child->operator[](n).getData();
        return (*child)[n].getData();
    }
private:
    LinkList<TreeNode<T> *> *child;
};

/*
    Please finish the Tree class. Tree class respresent a general tree, that means node on this tree may have more than two child node.

*/
template<class T>
class Tree
{
public:
    Tree()
    {
        root = NULL;
    }
    /*
        return the nth node on this tree with level order.
    */
    TreeNode<T> *operator[](int n)
    {
        if (root == NULL) return NULL;
        //queue of tree nodes
        queue<TreeNode<T>*> q;
        q.push(root);

        //pointing at the treenode on the front
        TreeNode<T> *cur = q.front();

        //q.pop();
        //q.p
        q.pop();

        //starts at 0
        for (int i = 0; i < n; i++)
        {
            for(int j=0;1;j++)
            {
                try
                {
                    //pushes every child node in order
                    //(of the actual node)
                    TreeNode<T> *t = (*cur)[j];
                    q.push(t);
                }
                catch(invalid_argument e){break;}
            }
            //moves to the next one on the front (first child?)
            cur = q.front();
            //pops the first one
            q.pop();
        }

        //Ok, goes after all until it gets to the n node
        return cur;
    }
    /*
        return the number of nodes on this tree.
    */
    int count()
    {
        if (root == NULL) return 0;
        queue<TreeNode<T>*> q;


        q.push(root);

        //tamano
        int tamano = 0;

        //q.pop()
        while (!q.empty())
        {
            //adds the size of the queue to the count
            int size = q.size();
            tamano += size;
            //Goes for every node  adding the childs to the queue
            for (int i = 0; i < size; i++)
            {
                TreeNode<T> *cur = q.front();
                q.pop();
                for(int j=0;1;j++)
                {
                    try
                    {
                        TreeNode<T> *t = (*cur)[j];
                        q.push(t);
                    }
                    catch(invalid_argument e){break;}
                }
            }
        }
        return tamano;
    }
    /*
        print all the node on this tree with level order.
    */
    void levelOrder()
    {
        if (root == NULL) return;
        cout << "LevelOrder: ";


        queue<TreeNode<T>*> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode<T> *cur = q.front();
                q.pop();
                cout << cur << " ";
                for(int j=0;1;j++)
                {
                    try
                    {
                        TreeNode<T> *t = (*cur)[j];
                        q.push(t);
                    }
                    catch(invalid_argument e){break;}
                }
            }
        }
        cout << endl;
    }
    /*
        print all the node on this tree with preorder.
    */
    void preorder()
    {
        cout << "PreOrder: ";
        preorder(root);
        cout<<endl;
    }
    /*
        print all the node on this tree with postorder.
    */
    void postorder()
    {
        cout << "PostOrder: ";
        postorder(root);
        cout<<endl;
    }
    /*
        set the root of this tree.
    */
    void setRoot(T d)
    {
        root = new TreeNode<T>(d);
    }
    TreeNode<T> *getRoot()
    {
        return root;
    }
private:
    TreeNode<T> *root;
    void preorder(TreeNode<T> *r)
    {
        if (r == NULL) return;
        //visits node
        cout << r << " ";
        //then visits childs from left to right
        for (int i = 0;1; i++)
        {
            try
            {
                preorder((*r)[i]);
            }
            catch(invalid_argument e){break;}
        }
    }
    void postorder(TreeNode<T> *r)
    {
        if (r == NULL) return;
        int j = 0;
        //visits child from left to right
        for (int i = 0;1; i++)
        {
            try
            {
                postorder((*r)[j]);
            }
            catch(invalid_argument e){break;}
            j++;
        }
        //then visits node
        cout << r << " ";
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

/*
int main()
{
    Tree<int> *tree = new Tree<int>();
    srand(0);
    for (int j = 0; j < 10; j ++)
    {
        if (tree->count() == 0)
        {
            tree -> setRoot(j);
        }
        else
        {
            int k = rand() % tree->count();
            cout << k << ", " << (*tree)[k] << ", " << j << endl;
            (*tree)[k] -> addChild(j);
        }
    }
    cout << tree -> count() << endl;
    tree -> levelOrder();
    tree -> preorder();
    tree -> postorder();
    return 0;
}
*/
