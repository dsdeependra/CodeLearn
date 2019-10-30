#include<iostream>
#include<list>
#include<cstring>

using namespace std;

//graph class for handling the edges and other things

class Graph{
    int V; 
    bool **tc;
    list<int> *adj;
    void DFSUtil(int u, int v);
    public:
        Graph(int V); // constructor
        void addEdge(int v, int w){
            adj[v].push_back(w);
        }

        void transitiveClosure();
};

Graph::Graph(int V){
    this->V= V;
    adj = new list<int>[V];

    // bool tc[4][4];
    // memset(tc,false,sizeof(tc));

    tc = new bool* [V]; 
    for (int i=0; i<V; i++) 
    { 
        tc[i] = new bool[V]; 
        memset(tc[i], false, V*sizeof(bool)); 
    } 
}

void Graph::DFSUtil(int s, int v){
    //mark the connection as true;
    tc[s][v] = true;

    //check for all the connection through s , via adjlist
    list<int>::iterator it;
    for(it = adj[v].begin(); it != adj[v].end(); ++it){
        if(tc[s][*it] == false){
            DFSUtil(s,*it);
        }
    }
}

void Graph:: transitiveClosure(){
    //call the DFSUtil for each node
    for(int i=0; i<V; i++){
        DFSUtil(i,i);
    }

    //print the rewsult

    for(int i=0; i<V; i++){
        for(int j =0; j<V;j++){
            cout<<tc[i][j]<<" ";
        }
        cout<<endl;
    }

}


int main(){

    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Transitive closure matrix is \n"; 
    g.transitiveClosure(); 
}