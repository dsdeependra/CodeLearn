#include<iostream>
#include<list>

using namespace std;

class Graph{
    int V;
    list<int> *adj;
    void DFS_util(int v, bool visited[]);
    public:
        Graph(int V);
        void addEdge(int v, int w);
        void DFS(int s);
};

Graph::Graph(int V){
    this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::DFS_util(int v , bool visited[]){
    visited[v] = true;
    cout<<v<<" ";

    //iterator to go through the adjecency list of v
    list<int>::iterator it;
    for(it = adj[v].begin(); it != adj[v].end(); ++it){
        if(visited[*it] == false){
            DFS_util(*it,visited);
        }
    }
}

void Graph::DFS(int s){
    bool *visited = new bool[V];
    for(int i=0;i<V;i++){
        visited[i] = false;
    }

    DFS_util(s,visited);
}

int main(){
    Graph g(5);
    g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(2,4);
	g.addEdge(2,3);
	g.addEdge(4,5);
	g.addEdge(5,3);

	cout<<"THE DFS traversal is"<<endl;

	g.DFS(1);
    return 0;
}