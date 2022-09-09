#include<iostream>
#include<vector>
#include<queue>


using  namespace std;

vector<vector<int> > sol;
    vector<int> temp;
    queue<TreeNode*> q;
    queue<int> level;
    
    if(A == NULL){
        return sol;
    }
    
    q.push(A);
    level.push(0);
    
    while(!q.empty()){
        TreeNode* curr = q.front();
        int lev = level.front();
        if(sol.size() != level.front()+1){
            sol.push_back(temp);
        }
        sol[lev].push_back(curr->val);
        if(curr->left != NULL){
            q.push(curr->left);
            level.push(lev+1);
        }
        if(curr->right != NULL){
            q.push(curr->right);
            level.push(lev+1);
        }
        q.pop();
        level.pop();
    }
    
    return sol;
}