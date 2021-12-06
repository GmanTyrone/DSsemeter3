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
		int j, k;
		for(j = 0;j < 20;j ++)
			for(k = 0;k < 4;k ++)
				root[j][k] = -1;
	}
	int insert(int node)
	{
		int f = 0, index = 0;

		//Increases until finding next index
		while(root[index][0] != -1)index ++;

		if(index >= 20)return -1;
		if(index == 0)
		{
			root[0][0] = 1;
			root[0][1] = node;
			return 1;
		}
		else
		{
			root[index][0] = 1;
			root[index][1] = node;
			while(1)
			{
				if(root[f][1] < node)
				{
					if(root[f][3] == -1)
					{
						root[f][3] = index;
						return 1;
					}
					else
					{
						f = root[f][3];
					}
				}
				else
				{
					if(root[f][2] == -1)
					{
						root[f][2] = index;
						return 1;
					}
					else
					{
						f = root[f][2];
					}
				}
			}
		}
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
	    queue<int> q;
	    int x=0;
	    while(root[x][0]!=-1){
            cout<<root[x][1]<<" ";
            if(root[x][2]!=-1)q.push(root[x][2]);
            if(root[x][3]!=-1)q.push(root[x][3]);
            if(q.empty())return;
            x=q.front();
            q.pop();
	    }
	}
private:
    void inorder(int x)
    {
		if(root[x][0]!=-1){
			if(root[x][2]!=-1)inorder(root[x][2]);
            cout<<root[x][1]<<" ";
            if(root[x][3]!=-1)inorder(root[x][3]);
		}
		return;

    }
    void preorder(int x)
    {
        if(root[x][0]!=-1){
			cout<<root[x][1]<<" ";
			if(root[x][2]!=-1)preorder(root[x][2]);
            if(root[x][3]!=-1)preorder(root[x][3]);
		}
		return;
    }
    void postorder(int x)
    {
        if(root[x][0]!=-1){
			if(root[x][2]!=-1)postorder(root[x][2]);
            if(root[x][3]!=-1)postorder(root[x][3]);
            cout<<root[x][1]<<" ";
		}
		return;
    }

	int root[20][4];
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
