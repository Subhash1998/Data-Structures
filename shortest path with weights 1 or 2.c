#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v, int w, int weight);

    int findShortestPath(int s, int d);

    int printShortestPath(int parent[], int s, int d);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[2*V];
}

void Graph::addEdge(int v,int w,int weight)
{
    if(weight==2)
    {
        adj[v].push_back(v+V);
        adj[v+V].push_back(w);
    }

    else
        adj[v].push_back(w);
}

int Graph::printShortestPath(int parent[],int s,int d)
{
    int static level=0;
    if(parent[s]==-1)
    {
        cout<<"Shortest path is :- "<<s<<" ";
        return level;
    }
    printShortestPath(parent,parent[s],d);

    level++;
    if(s<V)
        cout<<s<<" ";

    return level;
}

int Graph::findShortestPath(int s,int d)
{
    bool *visited=new bool[2*V];
    int *parent=new int[2*V];
    int j;
    list<int> queue;
    list<int>::iterator i;

    for(j=0;j<2*V;j++)
    {
        visited[j]=false;
        parent[j]=-1;
    }

    queue.push_back(s);
    visited[s]=true;

    while(!queue.empty())
    {
        s=queue.front();

        if(s==d)
            return printShortestPath(parent,s,d);

        queue.pop_front();

        for(i=adj[s].begin();i!=adj[s].end();i++)
        {
            if(visited[*i]==false)
            {
                visited[*i]=true;
                parent[*i]=s;
                queue.push_back(*i);
            }
        }
    }

}

int main()
{
    int V = 4;
    Graph g(V);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 0, 1);
    g.addEdge(2, 3, 2);
    g.addEdge(3, 3, 2);

    int src = 0, dest = 3;
    cout << "\nShortest Distance between " << src
         << " and " << dest << " is "
         << g.findShortestPath(src, dest);

    return 0;
}
