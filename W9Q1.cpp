#include <iostream>
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
  }
  /*
  return 1 if result fit the rule.
  return 0 if result not fit the rule.
  */
  int isCorrect()
  {
  }
private:
  //請設計你自己的資料結構來儲存遊戲的結果
  //Please design your own data structure to keet the result
};
int main() {
  int n, j, l, k;
  char game[20][20] = { {'W', 'W', 'W', '1', 'W'},
                       {'W', '.', 'W', 'W', 'W'},
                       {'W', '2', 'W', '.', '3'},
                       {'3', 'W', 'W', '.', 'W'},
                       {'.', '.', 'W', 'W', 'W'} };
  std::cin>>n;
  for(j = 0;j < n;j ++)
    for(k = 0;k < n;k ++)
      std::cin>>game[j][k];
  Nurikabe *a = new Nurikabe(game, n);
  std::cout<<a->isCorrect();
  return 0;
}
