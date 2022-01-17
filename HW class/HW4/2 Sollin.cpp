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
        int mincost = 0;
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
            for (int i=0; i<edges; i++)
        {
            // Find components (or sets) of two corners
            // of current edge
            int set1 = find2(, edge[i].src);
            int set2 = find2(subsets, edge[i].dest);

            // If two corners of current edge belong to
            // same set, ignore current edge
            if (set1 == set2)
                continue;

            // Else check if current edge is closer to previous
            // cheapest edges of set1 and set2
            else
            {
               if (cheapest[set1] == -1 ||
                   edge[cheapest[set1]].weight > edge[i].weight)
                 cheapest[set1] = i;

               if (cheapest[set2] == -1 ||
                   edge[cheapest[set2]].weight > edge[i].weight)
                 cheapest[set2] = i;
            }
        }

        // Consider the above picked cheapest edges and add them
        // to MST
        for (int i=0; i<V; i++)
        {
            // Check if cheapest for current set exists
            if (cheapest[i] != -1)
            {
                int set1 = find(subsets, edge[cheapest[i]].src);
                int set2 = find(subsets, edge[cheapest[i]].dest);

                if (set1 == set2)
                    continue;
                MSTweight += edge[cheapest[i]].weight;
                printf("Edge %d-%d included in MST\n",
                       edge[cheapest[i]].src, edge[cheapest[i]].dest);

                // Do a union of set1 and set2 and decrease number
                // of trees
                Union(subsets, set1, set2);
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




