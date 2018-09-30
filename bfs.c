#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

    public:
        Graph(int V);
        void addEdge(int v,int w);
        void bfs(int s);
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

void Graph::bfs(int s)
{
    int j;
    list<int>::iterator i;
    list<int> queue;

    bool *visited=new bool[V];

    for(j=0;j<V;j++)
        visited[j]=false;

    //enqueue
    queue.push_back(s);
    visited[s]=true;

    while(!queue.empty())
    {
        //dequeue
        s=queue.front();
        cout<<s<<" ";

        queue.pop_front();

        for(i = adj[s].begin();i != adj[s].end();i++)
        {
            if(visited[*i]==false)
            {
                visited[*i]=true;
                queue.push_back(*i);
            }
        }
    }
}

int main()
{
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.bfs(2);
    return 0;
}
