#include<iostream>
#include<cstdlib>
#include<ctime>

#define SIZE 10

using namespace std;

class Node
{
public:
	Node(): Node(0, 0)
	{
	}
	Node(int r, int c)
	{
		row = r;
		col = c;
	}
	int getRow() const { return row; }
	int getCol() const { return col; }
	void setRow(int r)
	{
		if(r >= 0 && r < SIZE)
			row = r;
	}
	void setCol(int c)
	{
		if(c >= 0 && c < SIZE)
			col = c;
	}
private:
	int col, row, data;
};

class List
{
public:
	List()
	{
		top = -1;
	}
	/*
	function addElement
	Insert an element into list
	*/
	void addElement(int r, int c)
	{
	    data[top+1]=Node(r,c);
	    top++;
	}
	/*
	function removeElement
	remove an element from list and return a pointer point to the element.
	If list is empty, return NULL.
	*/
	Node *removeElement()
	{
	    top--;
	    if(top<0)return NULL;
	    return &data[top+1];
	}
	void printList()
	{
		int j;
		for(j = 0;j <= top;j ++)
		{
			cout<<"("<<data[j].getRow()<<", "<<data[j].getCol()<<")"<<endl;
		}
	}
	int topC(){
	    return data[top].getCol();
	}
	int topR(){
	    return data[top].getRow();
	}
	int getTop(){
	    return top;
	}

private:
	Node data[SIZE * SIZE];
	int top;
};

class Maze
{
public:
	Maze()
	{
		initMaze(SIZE);
		size=SIZE;
	}
	/*
	function initMaze
	Alocate a 2-D array with s * s sizes as the map of maze.
	Inside the maze where 0 represent empty space and 1 represent wall.
	[0][0] is start point and [s - 1][s - 1] is finish point.
	Randomly generate 20% wall in the maze.
	Make sure [0][0] and [s - 1][s - 1] are 0
	*/
	void initMaze(int s)
	{
	    size=s;
	    int j,k;


	    //Points to a memory space
	    int *bloque = new int[s*s];
        maze = new int* [s];
        for(int i=0;i<s;i++){
            (maze)[i]=&bloque[i*s];
        }

        //puts 0's
        for(j = 0;j < s;j++){
                for(k = 0;k < s;k++){
                        maze[j][k] == 0;
                }
        }

        //puts 1's
        srand((unsigned)time(0));
        int unos=s*s/5;
        int x=rand()%s;
        int y=rand()%s;

        while(unos>0&&(maze[x][y]==1||(x==0&&y==0)||(x==size-1&&y==size-1)))
        {
            x=rand()%s;
            y=rand()%s;
            maze[x][y]=1;
            --unos;
        }
	}
	/*
	function getPath
	This function will find a path between start point and finish point.
	Return a list content the path information inside.
	If there is no path between two point then the list will be empty.
	*/
	List *getPath()
	{

	    //Makes a dummie maze
	    int dummie[size+2][size+2];
	    for(int i=0;i<size+2;++i)
        {
            for(int j=0;j<size+2;++j)
            {
                dummie[i][j]=1;
            }
        }

        //Copies into dummie maze
	    for(int i=1;i<size+1;++i)
        {
            for(int j=1;j<size+1;++j)
            {
                dummie[i][j]=maze[i-1][j-1];
            }
        }


        //Algorithm to find the path
        int i, j;
        List* camino = new List();
        camino->addElement(0,0);
        dummie[1][1]=1;
        while(camino->getTop()>=0){
            i=camino->topR()+1;j=camino->topC()+1;
            if(i==size&&j==size){return camino;}
            else if(dummie[i-1][j]!=1){camino->addElement(i-2,j-1);dummie[i-1][j]=1;}
            else if(dummie[i+1][j]!=1){camino->addElement(i,j-1);dummie[i+1][j]=1;}
            else if(dummie[i][j-1]!=1){camino->addElement(i-1,j-2);dummie[i][j-1]=1;}
            else if(dummie[i][j+1]!=1){camino->addElement(i-1,j);dummie[i][j+1]=1;}
            else camino->removeElement();
        }
        delete camino;
        return new List();
	}
	void printMaze()
	{
		int j, k;
		for(j = 0;j < size;j ++)
		{
			for(k = 0;k < size;k ++)
			{
				if(maze[j][k] == 0)
					cout<<"0";
				else if(maze[j][k] == 1)
					cout<<"1";
			}
			cout<<"\n";
		}
	}
private:
	int **maze;
	int size;
};

int main()
{
	Maze *maze = new Maze();
	maze->printMaze();
	maze->getPath()->printList();
}
