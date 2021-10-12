#include <iostream>

using namespace std;

int calculate(char operador, int a, int b)
{
    try{
        if(operador!='*'&&operador!='/'&&operador!='-'&&operador!='+')
            throw operador;
        }
        catch(char x){
            cerr<<"Invalid operator "<<x<<endl;
            return NULL;
        }
    switch(operador){
    case '*':
        return a*b;
    case '+':
        return a+b;
    case '-':
        return a-b;
    case '/':
        try{
            if(b==0)throw &operador;
            return a/b;
        }catch(char* operador){
            cerr<<"Division by 0"<<endl;
            return NULL;
        }
    }
}


int main(void)
{
    int x,y,z;
    char op;
    while(1)
    {
        cin>>x>>op>>y;
        z=calculate(op,x,y);
        cout<<z<<endl;
    }
    return 0;
}
