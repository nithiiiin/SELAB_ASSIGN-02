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

   void BFS(vector<int> vertices, int k);

};

graph::graph(int V)
{
    this->V = V;
    adj = new vector<int>[V];
}

void graph::edge(int m, int n){

    adj[m].push_back(n);
}

void graph::BFS(vector<int> vertices, int k){
    int visited[6] = {0};
    cout << k << " ";
    visited[k-1] = 1;
    list<int> queue;
    do
    {
    
    for(auto x = adj[k].begin(); x != adj[k].end(); ++x)
    {
        // cout << *x << " ";
        if (visited[*x-1] == 0)
        {
            queue.push_back(*x);
            visited[*x-1] = 1;
        }
    }
     // cout<<endl;
     if (queue.empty())
     {
       return ;
     }
     else
     {
        k = queue.front();
        cout << k << " ";
        queue.pop_front();
     }
     // cout<<endl;
    }while(!queue.empty());

}
int main()
{
    
    vector<int> vertices = {1, 2, 3, 4, 5, 6};
    graph G(6);
    G.edge(1, 2);
    G.edge(1, 3);
    G.edge(2, 3);
    G.edge(2, 4);
    G.edge(2, 5);
    G.edge(4, 5);
    G.edge(3, 6);
    G.BFS(vertices, 1);
    return 0;
}