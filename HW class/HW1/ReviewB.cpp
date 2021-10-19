#include <iostream>
#include <string>
#include <map>

using namespace std;

class hanoiTower{

    public:
        map<char,string>palos;
        int discos=3;

    hanoiTower(){
    }
    hanoiTower(int n){
        discos = n;
    }
    void evaluar(){
        setUp();
        printActual();
        Resolver(discos, 'A' , 'C' , 'B');
    }
    void setUp(){
        palos.clear();

        for(int u = discos; u >= 1; u--)palos['A'].push_back((u) + '0');
        palos['B'];
        palos['C'];
    }
    void printActual(){

        for(map<char, string>::const_iterator it = palos.begin(); it != palos.end(); it++)
        {
             cout<<it->first<<" "<< it->second<<"\n";
        }
        cout<<endl;
    }
    void MOVER(int n, char from, char destination){
        cout <<"Disco: "<<n<<" from peg "<< from <<" to peg "<<destination<<endl;
        palos[from].pop_back();
        palos[destination].push_back(n + '0');
    }
    void Resolver(int n, char from, char destination, char temp )
    {
        if(n==1){
            MOVER(n, from, destination);
            printActual();
        }
        else{
            Resolver(n - 1, from, temp, destination);
            MOVER(n, from, destination);
            printActual();
            Resolver(n - 1, temp, destination, from);
        }
    }


};

int main(){
    hanoiTower Torre;
    Torre.evaluar();
}
