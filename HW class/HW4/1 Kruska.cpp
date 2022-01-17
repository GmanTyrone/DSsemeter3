#include<iostream>
using namespace std;

#define MAX_SIZE 100

class Graph
{
private:
    int **vertArr;
    int size;
    int edges=0;
    int *KruskaTree;


    //helping function allocarray
    void allocArray(int ***p, int m, int n)
    {
        int *bloque = new int[m*n];
        *p = new int* [m];
        for(int i=0;i<m;++i){
            (*p)[i]=&bloque[i*n];
        }
    }

    //helping function for kruska
    int find(int i)
    {
        while (KruskaTree[i] != i)
            i = KruskaTree[i];
        return i;
    }

    void unions(int i, int j)
    {
        int a = find(i);
        int b = find(j);
        KruskaTree[a] = b;
    }


public:
    //Default Constructor
    Graph()
    {
        size=MAX_SIZE;
        allocArray(&vertArr,size,size);
        for(int i = 0; i < size; i++) {
                for(int j = 0; j < size; j++) {
                    vertArr[i][j]=INT_MAX;
                }
        }
        KruskaTree=new int[size];
    }

    //Constructor of size X
    Graph(int x)
    {
        size=x+1;
        allocArray(&vertArr,size,size);
        for(int i = 0; i < size; i++) {
                for(int j = 0; j < size; j++) {
                    vertArr[i][j]=INT_MAX;
                }
        }
        KruskaTree=new int[size];
    }


    void displayMatrix() {
        for(int i = 0; i < size; i++) {
                for(int j = 0; j < size; j++) {
                    if(vertArr[i][j]==INT_MAX)cout << 0 << " ";
                    else cout << vertArr[i][j] << " ";
                }
                cout << endl;
        }
    }

    void add_edge(int u, int v, int w) {
        if(u>=size||v>=size){
            cerr<<"out of range"<<endl;
            return;
        }
        else{
            vertArr[u][v] = w;
            vertArr[v][u] = w;
            edges++;
        }
    }


    //Kruska
    void kruskalMST()
    {
        int mincost = 0;

    // Every vertex is just parent to itself
        for (int i = 0; i < size; i++)
            KruskaTree[i] = i;

    // Include minimum weight edges one by one
        int edge_count = 0;
        while (edge_count < size - 1) {
            int min = INT_MAX, a = -1, b = -1;
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    if (find(i) != find(j) && vertArr[i][j] < min) {
                        min = vertArr[i][j];
                        a = i;
                        b = j;
                    }
                }
            }

            unions(a, b);
            printf("Edge %d:(%d, %d) cost:%d \n",edge_count++, a, b, min);
            mincost += min;
        }
        printf("\nMinimum cost= %d \n", mincost);
    }

};


int main(void) {

    int v = 6;    //there are 6 vertices in the graph



    Graph Grafica1=Graph(v);
    Grafica1.add_edge(0, 1, 28);
    Grafica1.add_edge(0, 5, 10);
    Grafica1.add_edge(1, 2, 16);
    Grafica1.add_edge(1, 6, 14);
    Grafica1.add_edge(5, 4, 25);
    Grafica1.add_edge(4, 6, 24);
    Grafica1.add_edge(3, 4, 22);
    Grafica1.add_edge(3, 6, 18);
    Grafica1.add_edge(3, 2, 12);
    Grafica1.displayMatrix();

    cout<<endl;

    Grafica1.kruskalMST();

    return 0;
}




