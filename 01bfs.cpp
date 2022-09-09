#include<iostream>
#include<vector>
#include<deque>
#include<queue>

using namespace std;

class graph{
    private:
        int N;
        int E;
       vector< vector <pair < int,int> > > edges;
    
    public:
        graph(int n);
        void addEdge(int v,int w, int wt);
        void bfs(int s);
};

graph::graph(int n){
    N=n;
    E=0;          
    for(;n > 0; n--)
    {
        vector<pair<int,int> >row;
        edges.push_back(row);
    }
}

void graph::addEdge(int v,int w, int wt){
    

    edges[v].push_back(make_pair(w,wt));
    edges[w].push_back(make_pair(v,wt));
    ++E;
}

void graph::bfs(int s){
    deque<int> q;
    q.push_back(s);
    vector<int>distance (N,INT_MAX);
    distance[s] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop_front();
        //cout<< v<<" ";
        for(int i=0;i < edges[v].size();i++){
            if(distance[edges[v][i].first] > (distance[v] + edges[v][i].second)){
                cout<<distance[edges[v][i].first]<<" "<<distance[v] + edges[v][i].second<<endl;
                distance[edges[v][i].first] = distance[v] + edges[v][i].second;
                if(edges[v][i].second == 0){
                    q.push_front(edges[v][i].first);
                }
                else{
                    q.push_back(edges[v][i].first);
                }
            }
        }
    }
    cout<<endl;
    for(int i=0;i<N;i++){
        cout<<i<<" "<<distance[i]<<endl;
    }
}

int main(){
    graph G(10);
     G.addEdge(0, 1 , 1);
     G.addEdge(0, 3 , 0);
     G.addEdge(0, 2 , 1);
     G.addEdge(1, 4 , 0);
     G.addEdge(3, 4 , 0);
     G.addEdge(2, 3 , 0);
     
    //  G.adjVertices(0);
    //  G.adjVertices(4);

     G.bfs(0);
    return 0;
}