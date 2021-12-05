#include<iostream>
#include <queue>
#include<cstdlib>
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
		while(root[index][0] != -1)
			index ++;
		if(index >= 20)
			return -1;
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
	void inorder(int x){

		if(root[x][2]!=-1){
			inorder(root[x][2]);
		}
		cout<<root[x][1]<<" ";
		if(root[x][3]!=-1){
			inorder(root[x][3]);
		}
		if(root[x][2] == -1 && root[x][3] == -1){
			return;
		}
	}
	void preorder(int x)
	{
		cout<<root[x][1]<<" ";
		if(root[x][2]!=-1){
			preorder(root[x][2]);
		}
		if(root[x][3]!=-1){
			preorder(root[x][3]);
		}
		if(root[x][2] == -1 && root[x][3] == -1){
			return;
		}
	}
	void postorder(int x)
	{
		if(root[x][2]!=-1){
			postorder(root[x][2]);
		}
		if(root[x][3]!=-1){
			postorder(root[x][3]);
		}
		cout<<root[x][1]<<" ";
		if(root[x][2] == -1 && root[x][3] == -1){
			return;
		}

	}

	void levelorder(int x){
		queue<int> q;
		q.push(x);
		while(!q.empty()){
			int index = q.front();
			cout<<root[index][1]<<" ";
			if(root[index][2]!=-1){
				q.push(root[index][2]);
			}
			if(root[index][3]!=-1){
				q.push(root[index][3]);
			}
			q.pop();

		}
	}


private:
	int root[20][4];
};

int main()
{
	Tree *tree = new Tree();
	int j, node;
	srand(time(NULL));
	for(j = 0;j < 10;j ++)
	{
		node =j; //rand()%10;
		tree->insert(node);
	}
	tree->inorder(1);
	printf("\n");
	tree->preorder(1);
	printf("\n");
	tree->postorder(1);
	printf("\n");
	tree->levelorder(1);
	printf("\n");
}
