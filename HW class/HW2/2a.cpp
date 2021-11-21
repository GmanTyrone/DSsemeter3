#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int*  setIntersection(int* a, int *b)
{
    int Inter[50];
    int count=0;
	    for(int i=0; a[i]!= NULL;i++)
        {
            for(int j=0;b[j]!=NULL;j++)
            {
                if(a[i]==b[j]){Inter[count]=b[j];count++;break;}
            }
        }
        Inter[count]=NULL;
        return Inter;
}

//int *setIntersection and setDifference

int main(void)
{
    int a[8]={0,1,2,3,4,5,6,7};
    int b[6]={0,3,5,9,7,10};
    int* c;
    c=setIntersection(a,b);
    for(int i=0;c[i]!=NULL;i++){
        cout<<c[i]<<endl;
    }
    return 0;
}
