#include<iostream>
#include<cstring>

#define ROW 5
#define COL 5

using namespace std;

bool isSafe(int M[][COL], int row, int col, bool visited[][COL]){
    return ((row >=0) && (row < ROW) && (col >=0) &&(col < COL) && M[row][col] && !visited[row][col]);
}

void DFS(int M[][COL] , int row, int col, bool visited[][COL]){
    //make the cell visited
    visited[row][col] = true;

    int rowArray[] = {-1,-1,-1,0,0,1,1,1};
    int colArray[] = {-1,0,1,-1,1,-1,0,1};

    for(int i =0; i<8; i++){
        if(isSafe(M,row+rowArray[i] , col+ colArray[i] ,visited)){
            DFS(M,row+rowArray[i], col+colArray[i], visited);
        }
    }
}

int connectedComponents(int M[][COL]){
    bool visited[ROW][COL];
    memset(visited,0,sizeof(visited));
    
    int count = 0;
    for(int i = 0; i < ROW; i++){
        for(int j = 0;j < COL; j++){
            //if not visited and cell value is 1 then do DFS
            if(M[i][j] && !visited[i][j]){
                DFS(M,i,j,visited);
                count++;
            }
        }
    }
    return count;        
}

int main(){
    int M[][COL] = { { 1, 1, 0, 0, 0 }, 
                     { 0, 0, 0, 0, 1 }, 
                     { 1, 0, 0, 1, 1 }, 
                     { 0, 0, 0, 0, 0 }, 
                     { 1, 0, 1, 0, 1 } }; 

    cout <<"connected component count is "<< connectedComponents(M);

    return 0;
}