#include<iostream>
using namespace std;

#define MAX_SIZE 100

class Graph
{
private:
    int **vertArr;
    int size;
    int edges=0;
    int **SollinTree;



    //helping function allocarray
    void allocArray(int ***p, int m, int n)
    {
        int *bloque = new int[m*n];
        *p = new int* [m];
        for(int i=0;i<m;++i){
            (*p)[i]=&bloque[i*n];
        }
    }



    int find(int i)
    {
        while (SollinTree[i][0] != i)
            i = SollinTree[i][0];
        return i;
    }

    void unions(int i, int j)
    {
        int a = find(i);
        int b = find(j);
        SollinTree[a][0] = b;



        // Attach smaller rank tree under root of high
        // rank tree (Union by Rank)
        if (SollinTree[a][1] < SollinTree[b][1])
            SollinTree[a][0] = b;
        else if (SollinTree[a][1] > SollinTree[b][1])
            SollinTree[b][0] = a;

        // If ranks are same, then make one as root and
        // increment its rank by one
        else
        {
            SollinTree[b][0] = a;
            SollinTree[a][1]++;
        }


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
        allocArray(&SollinTree,size,2);
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
        allocArray(&SollinTree,size,2);
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


    //Sollin
    void sollinMST()
    {
        int MSTweight = 0;
        int numTrees = size;

    // Every vertex is just parent to itself and rank 0

        int minimumcost[size];
        for (int i = 0; i < size; i++){
            SollinTree[i][0] = i;
            SollinTree[i][1] = 0;
            minimumcost[i]=-1;
        }

        while (numTrees > 1)
        {
            // Everytime initialize cheapest array
            for (int i = 0; i < size; ++i)
            {
               minimumcost[i] = -1;
            }

            // Traverse through all edges and update
            // cheapest of every component
            int a=0, b=0;
            for (int i=0; i<edges; i++)
            {

                for(a=i;a<size;a++){
                    for(b=a+1;b<size;b++)
                    {
                        if(vertArr[a][b]!=INT_MAX)goto exit;
                    }
                }
            exit:
            // Find components (or sets) of two corners
            // of current edge
            int set1 = find(a);
            int set2 = find(b);

            // If two corners of current edge belong to
            // same set, ignore current edge
            if (set1 == set2)
                continue;

            // Else check if current edge is closer to previous
            // cheapest edges of set1 and set2
            else
            {
               if (minimumcost[set1] == -1 || vertArr[set1][minimumcost[set1]] > vertArr[a][b])
                 minimumcost[set1] = i;

               if (minimumcost[set2] == -1 || vertArr[set1][minimumcost[set2]] > vertArr[a][b])
                 minimumcost[set2] = i;
            }
            }

            // Consider the above picked cheapest edges and add them
            // to MST
            for (int i=0; i<size; i++)
            {
                // Check if cheapest for current set exists
                if (minimumcost[i] != -1)
                {
                int set1 = find(minimumcost[a]);
                int set2 = find(minimumcost[b]);

                if (set1 == set2)continue;

                MSTweight += vertArr[set1][minimumcost[set1]];
                printf("Edge %d-%d included in MST\n",a, b);

                // Do a union of set1 and set2 and decrease number
                // of trees
                unions(set1, set2);
                numTrees--;
                }
            }
        }

    printf("Weight of MST is %d\n", MSTweight);
    return;
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

    Grafica1.sollinMST();

    return 0;
}




