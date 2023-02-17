#include <iostream>
#include <list>
#include <vector>

using namespace std;

class graph
{
private:
    int V;
   // list<int> *adj;
   vector<int> *adj;
public:
    graph(int V);

   void edge(int m, int n);

   void DFS(int* visisited, int k);

};
graph::graph(int V)
{
    this->V = V;
    adj = new vector<int>[V];
}

void graph::edge(int m, int n){

    adj[m].push_back(n);
}

void graph::DFS(int* visited, int k){
    
    visited[k] = 1;
    cout << k << " ";     
    for(auto x = adj[k].begin(); x != adj[k].end(); ++x){
        if (visited[*x] == 0)
        {
           DFS(visited, *x);
        }
    }
    
}

int main()
{
    
    vector<int> vertices = {0, 1, 2, 3, 4, 5};
    graph G(6);
    G.edge(0, 1);
    G.edge(0, 2);
    G.edge(1, 2);
    G.edge(2, 0);
    G.edge(2, 3);
    G.edge(3, 3);
    G.edge(3, 4);
    G.edge(4, 5);
    G.edge(2, 5);
    int visited[6] = {0};
    G.DFS(visited, 0);
    return 0;
}
