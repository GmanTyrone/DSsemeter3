#include<iostream>
#include<cstdlib>
#include<queue>
#include<ctime>

using namespace std;

class Tree
{
public:
	Tree()
	{
		int j;
		for(j = 0;j < 2000;j ++)
			root[j] = -1;
	}
	int insert(int node)
	{
		int index = 0;
		while(index < 2000 && root[index] != -1)
		{
			if(root[index] < node)
				index = index * 2 + 2;
			else
				index = index * 2 + 1;
		}
		root[index] = node;
	}
	void inorder()
	{
	    inorder(0);
	}
	void preorder()
	{
	    preorder(0);
	}
	void postorder()
	{
	    postorder(0);
	}
	void levelorder()
	{
	    for(int i=0;i<2000;i++)
            if(root[i]!=-1)cout<<root[i]<<" ";
	    /*queue<int> q;
	    int x=0;
	    while(root[x]!=-1&&x<2000){
            cout<<root[x]<<" ";
            if(root[x*2+1]!=-1&&(x*2+1)<2000)q.push(x*2+1);
            if(root[x*2+2]!=-1&&(x*2+2)<2000)q.push(x*2+2);
            if(q.empty())return;
            x=q.front();
            q.pop();
	    }*/
	}
private:
    void inorder(int x)
    {
        if(root[x]!=-1&&x<2000){
			inorder(x * 2 + 1);
            cout << root[x] << " ";
            inorder(x * 2 + 2);
		}
		return;
    }
    void preorder(int x)
    {
        if(root[x]!=-1&&x<2000){
            cout << root[x] << " ";
			preorder(x * 2 + 1);
            preorder(x * 2 + 2);
		}
		return;
    }
    void postorder(int x)
    {
        if(root[x]!=-1&&x<2000){
			postorder(x * 2 + 1);
            postorder(x * 2 + 2);
            cout << root[x] << " ";
		}
		return;
    }

	int root[2000];
};

int main()
{
	Tree *tree = new Tree();
	int j, node;
	srand(time(NULL));
	for(j = 0;j < 10;j ++)
	{
		node = rand();
		tree->insert(node);
	}
	tree->inorder();
	printf("\n");
	tree->preorder();
	printf("\n");
	tree->postorder();
	printf("\n");
	tree->levelorder();
	printf("\n");
}
