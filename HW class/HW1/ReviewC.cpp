#include <fstream>
#include <string>
#include <cstdio>


using namespace std;



int main()
{
    string sentence;
    fstream poem, chart;

    int alfabeto[26]={0};

    //Counting the letters
    poem.open("Poema.txt",ios::in);


    while(getline(poem,sentence)){
        for(int k=0;k<sentence.size();k++){

            int c=getchar();


            //FIRST IFS
            if(c>64&&c<91)c-=65;
            else if(c>96&&c<123)c-=97;
            else  c+=26;

            //THEN WE DECIDE WHAT TO DO WITH THE IF
            if(c<26)alfabeto[c]++;
        }
    }
    poem.close();

    //Printing it
    chart.open("histograma.txt",ios::out);
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

