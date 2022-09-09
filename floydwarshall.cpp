#include<iostream>
#include<cstring>

using namespace std;
#define INF 999999
#define V 4

void printResult(int dist[][V]){
    for(int i = 0; i<V; i++){
        for(int j =0; j<V; j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}

void floydWarshall(int graph[][V]){
    int dist[V][V];

    //create the result as input graph
    for(int i=0; i<V;i++){
        for(int j=0; j<V; j++){
            dist[i][j] = graph[i][j];
        }
    }

    //for all the nodes , get the intermediate node as k and do the logic of dis[i][j] = dis[i][k] + dis[k][j]
    for(int i=0;i<V;i++){
        for(int j =0; j<V; j++){
            for(int k= 0; k<V; k++){
                if(dist[i][j] > (dist[i][k] + dist[k][j])){
                    dist[i][j] = dist[i][k] + dist[k][j]; 
                }
            }
        }
    }

    printResult(dist);
}

int main(){
    // int graph[V][V] = { {0, 5, INF, 10},  
    //                     {INF, 0, 3, INF},  
    //                     {INF, INF, 0, 1},  
    //                     {INF, INF, INF, 0}  
    //                 }; 

     int graph[V][V] = { {0, 1, 1, INF},  
                        {INF, 0, 1, INF},  
                        {1, INF, 0, 1},  
                        {INF, INF, INF, 0}  
                    };  
  
    // Print the solution  
    floydWarshall(graph);  
    return 0;    
}