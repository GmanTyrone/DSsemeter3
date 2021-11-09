#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

#define SIZE 10
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

class Grid
{
public:
	Grid(): Grid(0)
	{
	}
	Grid(int s)
	{
		state = s;
		dir[UP] = NULL;
		dir[DOWN] = NULL;
		dir[LEFT] = NULL;
		dir[RIGHT] = NULL;
	}
	Grid *getDir(int d) const { return dir[d]; }
	int getState() const { return state; }
	void setDir(int d, Grid *g) { dir[d] = g; }
	void setState(int s) { state = s;}
private:
	Grid *dir[4];
	int state;
};

class List
{
public:
	List()
	{
		top = 0;
		empty=true;
	}
	/*
	Insert an element from top
	*/
	void addElement(Grid *g)
	{
	    if(empty){
            empty=false;
            data[top]=g;
	    }
	    else{
            top++;
            data[top]=g;
	    }
	}
	/*
	remove an element from top and return a pointer point to the element.
	If list is empty, return NULL.
	*/
	Grid *removeElement()
	{
	    if(empty)return NULL;
	    if(top==0)empty=true;
	    else top--;
	    return data[top+1];
	}
	void printPath() const
	{
		if(empty)return;
		int j;
		for(j = 1;j < top;j ++)
		{
			if(data[j] == data[j - 1]->getDir(UP))
			{
				cout<<"UP\n";
			}
			else if(data[j] == data[j - 1]->getDir(DOWN))
			{
				cout<<"DOWN\n";
			}
			else if(data[j] == data[j - 1]->getDir(LEFT))
			{
				cout<<"LEFT\n";
			}
			else if(data[j] == data[j - 1]->getDir(RIGHT))
			{
				cout<<"RIGHT\n";
			}
		}
	}
	bool isEmpty(){return empty;}
	Grid* getTop(){return data[top];}
private:
	Grid *data[SIZE * SIZE];
	int top;
	bool empty;
};

class Maze
{
public:
	Maze()
	{
		initMaze(SIZE);
	}
	/*
	function initMaze
	Alocate a 2-D link list with s * s sizes as the map of maze.
	Inside the maze enery gird with state 0 represent empty space and 1 represent wall.
	The gird in left top is start point and right bottom is finish point.
	Randomly generate 20% wall in the maze.
	Make sure start point and finish point are 0

	動態配置一個二維的鏈結串列，大小是 s * s，用這個鏈結串列表示迷宮的地圖
	節點中 0 的值表示可以移動的空間， 1 表示牆壁
	左上角的位置表示起點，右下角的位置表示終點
	請在迷宮中加入 20% 的牆壁
	然後確定起點跟終點都是可以移動的位置
	*/
	void initMaze(int s)
	{
	    size=s;

	    //Points to a memory space
	    maze = new Grid[s*s];

		for(int i=0;i<s*s;++i)
		{
			//Points DOWN
			if(i<(s*s)-s)maze[i].setDir(DOWN,&maze[i+s]);

			//Points UP
			if(i>=s)maze[i].setDir(UP,&maze[i-s]);

			//Points LEFT
			if(i%s!=0)maze[i].setDir(LEFT,&maze[i-1]);

			//Points RIGHT
			if((i+1)%s!=0)maze[i].setDir(RIGHT,&maze[i+1]);
		}


        //puts 1's
        srand((unsigned)time(0));
        int x;
        int unos=s*s/5;


        while(unos>0)
        {
            x=rand()%(s*s);
            while(maze[x].getState()==1||x==0||x==s*s-1){
                    x=rand()%(s*s);
            }
            maze[x].setState(1);
            --unos;
        }
	}
	Maze(const Maze &original)
	{
	    size=original.size;
	    maze = new Grid[size*size];
        *maze=*original.maze;
	}
	/*
	function getPath
	This function will find a path between start point and finish point.
	Return a list content the path information inside.
	If there is no path between two point then the list will be empty.

	這個函數會找到起點到終點間的一條路徑
	回傳一個 list 包含著路徑的資訊
	如果找不到路徑的話 list 就會是空的
	*/
	List *getPath()
	{
        Maze Dummie=Maze(*this);
	    List* camino = new List();
	    Grid *i=Dummie.maze;
	    //Grid *i=maze;
        camino->addElement(i);
        i->setState(1);
        while(!camino->isEmpty()){
            i=camino->getTop();

            if(i->getDir(DOWN)==NULL && i->getDir(RIGHT)==NULL){camino->addElement(i);return camino;}
            if(i->getDir(RIGHT)!=NULL){if(i->getDir(RIGHT)->getState()!=1){camino->addElement(i->getDir(RIGHT));i->getDir(RIGHT)->setState(1);continue;}}
            if(i->getDir(DOWN) !=NULL){if(i->getDir(DOWN) ->getState()!=1){camino->addElement(i->getDir(DOWN)) ;i->getDir(DOWN) ->setState(1);continue;}}
            if(i->getDir(LEFT) !=NULL){if(i->getDir(LEFT) ->getState()!=1){camino->addElement(i->getDir(LEFT)) ;i->getDir(LEFT) ->setState(1);continue;}}
            if(i->getDir(UP)   !=NULL){if(i->getDir(UP)   ->getState()!=1){camino->addElement(i->getDir(UP))   ;i->getDir(UP)   ->setState(1);continue;}}
            camino->removeElement();
        }
        delete camino;
        return new List();
	}
	void printMaze() const
	{
		Grid *j = maze, *k;
		while(j != NULL)
		{
			k = j;
			while(k != NULL)
			{
				cout<<k->getState();
				k = k->getDir(RIGHT);
			}
			cout<<endl;
			j = j->getDir(DOWN);
		}
	}
private:
	Grid *maze;
	int size;
};

int main()
{
	Maze *maze = new Maze();
	maze->printMaze();
	maze->getPath()->printPath();
}
