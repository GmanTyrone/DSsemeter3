#include <iostream>
#include<cstdlib>
#include <queue>

using namespace std;

class Nurikabe
{
public:
  /*
  n is the size of the Nurikabe, n >= 5, n <= 20
  game is the result from some player
  here is one example
  n: 5
  game = { {'W', 'W', 'W', '1', 'W'},
           {'W', '.', 'W', 'W', 'W'},
           {'W', '2', 'W', '.', '3'},
           {'3', 'W', 'W', '.', 'W'},
           {'.', '.', 'W', 'W', 'W'} };
  W represent wall
  */
  Nurikabe(char game[20][20], int n)
  {
      size=n;
      for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            mapa[i][j]=game[i][j];
  }
  /*
  return 1 if result fit the rule.
  return 0 if result not fit the rule.
  */
  int iscorrect()
  {
      //creates dummy
      char dummy[size+2][size+2];
      for(int i=0;i<size+2;i++)
        for(int j=0;j<size+2;j++)
            dummy[i][j]='*';

      for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
            dummy[i+1][j+1]=mapa[i][j];


      bool found=false;
      int walli, wallj;

      //Looks for invalid Chars and the first wall
      //the first wall
      //Looks if theres a square region of walls
      for(int i=1;i<size+1;i++){
        for(int j=1;j<size+1;j++){
            if(dummy[i][j]!='.'&&dummy[i][j]!='W'&&!(dummy[i][j]>'0'&&dummy[i][j]<='9'))return 0;
            if(!found&&mapa[i][j]=='W'){walli=i;wallj=j;found=true;}
            if(dummy[i][j]=='W'&&dummy[i+1][j+1]=='W'&&dummy[i+1][j]=='W'&&dummy[i][j+1]=='W')return 0;
        }
        }

      //Looks for islands and see if they match their number
      for(int i=1;i<size+1;i++){
        for(int j=1;j<size+1;j++){
            if(dummy[i][j]>'0'&&dummy[i][j]<='9'){
                int number=dummy[i][j]-'0';
                int count=0,x,y;
                queue<int> Ix,Iy;
                Ix.push(i);Iy.push(j);
                dummy[i][j]='-';
                while(!Ix.empty()&&!Iy.empty()){
                        x=Ix.front();y=Iy.front();
                        if(dummy[x+1][y]=='.'){Ix.push(x+1);Iy.push(y);dummy[x+1][y]='-';count++;}else if(dummy[x+1][y]>'0'&&dummy[x+1][y]<='9')return 0;
                        if(dummy[x-1][y]=='.'){Ix.push(x-1);Iy.push(y);dummy[x-1][y]='-';count++;}else if(dummy[x-1][y]>'0'&&dummy[x-1][y]<='9')return 0;
                        if(dummy[x][y+1]=='.'){Ix.push(x);Iy.push(y+1);dummy[x][y+1]='-';count++;}else if(dummy[x][y+1]>'0'&&dummy[x][y+1]<='9')return 0;
                        if(dummy[x][y-1]=='.'){Ix.push(x);Iy.push(y-1);dummy[x][y-1]='-';count++;}else if(dummy[x][y-1]>'0'&&dummy[x][y-1]<='9')return 0;
                        if(count>number)return 0;
                        Ix.pop();Iy.pop();
                }
            }
        }
        }

        //Does continuous wall
        int x,y;
        queue<int> Ix,Iy;
        Ix.push(walli);Iy.push(wallj);
        dummy[walli][wallj]='B';
        while(!Ix.empty()&&!Iy.empty()){
                x=Ix.front();y=Iy.front();
                if(dummy[x+1][y]=='W'){Ix.push(x+1);Iy.push(y);dummy[x+1][y]='B';}
                if(dummy[x-1][y]=='W'){Ix.push(x-1);Iy.push(y);dummy[x-1][y]='B';}
                if(dummy[x][y+1]=='W'){Ix.push(x);Iy.push(y+1);dummy[x][y+1]='B';}
                if(dummy[x][y-1]=='W'){Ix.push(x);Iy.push(y-1);dummy[x][y-1]='B';}
                Ix.pop();Iy.pop();
                }

        //Looks for discontinuous isands and walls
        for(int i=1;i<size+1;i++){
        for(int j=1;j<size+1;j++){
            //if(dummy[i][j]=='.'||dummy[i][j]=='W')return 0;
            cout<<dummy[i][j]<<" ";
        }
        cout<<endl;
        }

        return 1;
  }
private:
  //請設計你自己的資料結構來儲存遊戲的結果
  //Please design your own data structure to keep the result
  char mapa[20][20];
  int size;
};
int main() {
  int n=5, j, l, k;
  char game[20][20] = { {'W', 'W', 'W', '1', 'W'},
                       {'W', '.', 'W', 'W', 'W'},
                       {'W', '2', 'W', '.', '3'},
                       {'3', 'W', 'W', '.', 'W'},
                       {'.', '.', 'W', 'W', 'W'} };
  /*std::cin>>n;
  for(j = 0;j < n;j ++)
    for(k = 0;k < n;k ++)
      std::cin>>game[j][k];*/
  Nurikabe *a = new Nurikabe(game, n);
  std::cout<<a->iscorrect();
  return 0;
}
