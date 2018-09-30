#include <bits/stdc++.h>
using namespace std;

class Graph
{
  int V;
  list<int> *adj;

  public:
    Graph(int V);
    void addEdge(int v,int w);
    void dfs();
    void DFSUtil(int s,bool visited[]);
};

Graph::Graph(int V)
{
    this->V=V;
    adj=new list<int>[V];
}

void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
}

void Graph::DFSUtil(int s,bool visited[])
{
    visited[s]=true;
    cout<<s<<" ";
    list<int>::iterator i;

    for(i=adj[s].begin(); i!=adj[s].end(); i++)
    {
        if(visited[*i]==false)
            DFSUtil(*i,visited);
    }
}

void Graph::dfs()
{
    bool *visited=new bool[V];
    int i;

    for(i=0;i<V;i++)
        visited[i]=false;

    for(i=0;i<V;i++)
    {
        if(visited[i]==false)
            DFSUtil(i,visited);
    }
}

int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);

    g.dfs();
    return 0;
}
