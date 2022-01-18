#include <iostream>

using namespace std;


class Edge
{
public:
    int v1;
    int v2;
    int cost;
};
class Subset
{
public:
    int parent;
    int rank;
};
int find(Subset* subsets,int V)
{
    if(subsets[V].parent!=V)
        subsets[V].parent= find(subsets,subsets[V].parent);
    return subsets[V].parent;
}
void Union(Subset* subsets,int x,int y)
{
    if(subsets[x].rank>subsets[y].rank)
        subsets[y].parent=x;
    else   if(subsets[x].rank<subsets[y].rank)
                subsets[x].parent=y;
    else
        {
              subsets[y].parent=x;
              subsets[x].rank++;
        }
}
void Sollin(Edge* list,int V,int E)
{
    Subset* subsets=new Subset[V];
    int *mincost = new int[V];
    for(int i=0;i<V;i++)
    {
        subsets[i].parent=i;
        subsets[i].rank=0;
        mincost[V] = -1;
    }
    int noOfTrees = V;
    int MSTcost = 0;
    while (noOfTrees > 1)
    {
          for (int v = 0; v < V; v++)
           {
               mincost[v] = -1;
           }
        for (int i=0; i<E; i++)
        {
            int x = find(subsets, list[i].v1);
            int y = find(subsets, list[i].v2);
            if (x!=y)
             {
               if (mincost[x] == -1 || list[mincost[x]].cost > list[i].cost)
                 mincost[x] = i;

               if (mincost[y] == -1 ||list[mincost[y]].cost > list[i].cost)
                 mincost[y] = i;
            }
        }
        for (int i=0; i<V-1; i++)
        {
            if (mincost[i] != -1)
            {
                int x = find(subsets, list[i].v1);
                int y = find(subsets, list[i].v2);
                if (x==y)
                continue;
                if (mincost[x] == list[i].cost || mincost[y] == list[i].cost) {
                MSTcost += list[mincost[i]].cost;
                Union(subsets, x, y);
                Union(subsets, x, y);
                }
                noOfTrees--;
            }
        }
    }

    cout<<"Cos of minimun cost path: "<<MSTcost<<endl;
    return;
}


int main(void)
{
    int V, E, A, B,value;
    cin >>V>>E;
    Edge* list=new Edge[E];
    for(int i=0;i<E;i++)
    {
        cin>>A>>B>>value;
        list[i].v1=A;
        list[i].v2=B;
        list[i].cost=value;
    }
    //sort(list,list+E,comp);
    Sollin(list,V,E);
    return 0;
}
