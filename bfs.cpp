#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Graph{

private:
    int N;
    int E;
    vector<vector<int> > adjList;

public:
     Graph(int n)
     {
          N=n;
          E=0;          
          for(;n > 0; n--)
          {
              vector<int> row;
              adjList.push_back(row);
          }
     }
     //# of vertices
     int Vertices()
     {
         return N;
     }
     //# of Edges
     int Edges()
     {
          return E;
     }
     void addEdge(int v, int w)
     {
          adjList[v].push_back(w);
          adjList[w].push_back(v);
          ++E;
     }

    //  void  adjVertices(int v)
    //  {
    //     std::cout<<"Adjacent vertices of"<< v <<std::endl;
    //     for(auto &x : adjList[v])
    //        std::cout<< x << std::endl;
    //  }
     void BFS(int s);

};


void Graph::BFS(int s){
    
    vector<bool> vis (N, false);
    
    int level[N]; // just to determine the level for each element in the graph
    queue<int> q;
    q.push(s);
    vis[s] = true;
    level[s] = 0;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        cout<<p<<" "; // we can decide what to do with the element
        // now all the element of the popped element needs to be checked
        for(int i=0;i<adjList[p].size();i++){
            if(vis[adjList[p][i]] == false){
                q.push(adjList[p][i]);
                level[adjList[p][i]] = level[p] +1;
                vis[adjList[p][i]] = true;
            }
        }
    }

    for(int i=0;i<N;i++){
        cout<<i<<" "<<level[i]<<endl;
    }
}


int main(){
     Graph G(10);
     G.addEdge(3, 4);
     G.addEdge(0, 2);
     G.addEdge(0, 4);
     G.addEdge(0, 9);
    //  G.adjVertices(0);
    //  G.adjVertices(4);

     G.BFS(0);

    //BFS(adjacency_list,0,v);

    return 0;

}