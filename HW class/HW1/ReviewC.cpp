#include <fstream>
#include <string>
#include <cstdio>


using namespace std;

int alfabeto[26]={0};

int main()
{
    string filename="Ode to a Nightingale", fileoutput="histograma";
    ifstream poem;
    ofstream chart;

    //Counting the letters
    poem.open(filename);
    while(!(poem.eof())){
        int c=getchar();
        if(c>64&&c<91)c-=65;
        else if(c>96&&c<123)c-=97;
        else  c+=100;
        if(c<26)alfabeto[c]++;
    }


    //Printing it
    chart.open(fileoutput);
    for(int i=0;i<=25;i++){
        if(alfabeto[i]!=0){
            chart<<(char)(i+97);
            for(int j=0;j<=alfabeto[i];j++){
                chart<<"*";
            }
            chart<<alfabeto[i]<<endl;
        }
    }
    chart.close();
    return 0;
}

