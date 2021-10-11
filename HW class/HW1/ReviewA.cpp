#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    srand((unsigned)time(0));
    int tries=0,low=1,upper=600,range,GL,GUP;
    string answer;
    while(tries<4){
        range=upper-low;
        GL=rand()%range+low;
        range=upper-GL;
        GUP=rand()%range+GL;
        if(GL==GUP)cout<<"Number is "<<GL<<endl;
        else cout<<"Number is between "<<GL<<" and "<<GUP<<"?"<<endl;
        cin>>answer;
        while(1){
            if(answer=="below"){
                upper=GL;
                tries++;
                break;
            }
            else if(answer=="above"){
                low=GUP;
                tries++;
                break;
            }
            else if(answer=="within"){
                low=GL;
                upper=GUP;
                break;
            }
            else if(answer=="yes"){
                cout<<"Computer wins"<<endl;
                return 0;
            }
            else cin>>answer;
        }
    }
    cout<<"Computer is stupid"<<endl;
    return 0;
}
