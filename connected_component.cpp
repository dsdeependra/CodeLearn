#include<iostream>
#include<cstring>
#include<queue>

#define ROW 5
#define COL 5
using namespace std;

bool isSafe(int M[][COL], int i, int j, bool visited[][COL]){
    return ((i < ROW && i >= 0 && j < COL && j >=0 ) && (M[i][j] && !visited[i][j]));
}



void DFS(int M[][COL], int i, int j, bool visited[][COL]){
    int rowArray[] = {-1, -1 ,-1,0,0,1,1,1};
    int colArray[] = {-1,0,1,-1,1,-1,0,1};
    //mark this current cell as visited
    visited[i][j] = true;

    //check all 8 locations if its safe or not
    for(int k =0; k< 8; k++){
        if(isSafe(M,i+rowArray[k],j+colArray[k],visited)){
            DFS(M,i+rowArray[k],j+colArray[k],visited);
        }
    }
    
}

int countIslands(int M[][COL]){
    //setting up the visited array
    bool visited[ROW][COL];
    memset(visited,0,sizeof(visited));

    //iterate through all the nodes
    int count =0;
    for(int i=0; i<ROW; i++){
        for(int j = 0; j<COL; j++){
            //if M[i][j] is 1 and not visited then run DFS on that
            if(M[i][j] && visited[i][j]){
                DFS(M,i,j,visited);
                ++count;
            }
        }
    }
    return count;
}

int main(){
    int M[][COL] = { { 1, 1, 0, 0, 0 }, 
                     { 0, 1, 0, 0, 1 }, 
                     { 1, 0, 0, 1, 1 }, 
                     { 0, 0, 0, 0, 0 }, 
                     { 1, 0, 1, 0, 1 } }; 
  
    cout << "Number of islands is: " << countIslands(M); 

    return 0;
}