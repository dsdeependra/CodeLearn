#include<iostream>
#include<vector>
using namespace std;

class Solution {
    vector<int>rowD {1,-1,0,0};
    vector<int>colD {0,0,1,-1};
    bool backtrack(vector<vector<char> > &board,int x, int y,string &word, int index){
        if(index >= word.length())
            return true;
        
        if(x <0 || x == board.size() || y< 0 || y == board[0].size() || board[x][y] != word[index])
            return false;
        
        board[x][y] = '#';  // backtrack init
        for(int i =0;i<4;i++){
            int r = x + rowD[i];
            int c = y + colD[i];
            if(backtrack(board,r,c,word,index+1))
                return true;
        }
        
        board[x][y] = word[index];  // backtrack end
        return false;
    }
public:
    bool exist(vector<vector<char> >& board, string word) {
        int r = board.size();
        int c = board[0].size();        
        for(int i=0;i<r;i++){
            for(int j = 0;j<c;j++){
                if(backtrack(board,i,j,word,0)){
                    return true;                    
                }
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<vector<char>> b = {
                            {'a','b','c','e'},
                              {'s','f','c','s'},
                              {'a','d','e','e'}};
    string word = "abcced";
    cout<<s.exist(b,word)<<endl;
    return 0;
}