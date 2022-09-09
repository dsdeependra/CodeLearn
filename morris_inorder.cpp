#include<iostream>

using namespace std;
struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
};
void inorder_morris(TreeNode *root){
    TreeNode *current= root;
    while(current != NULL)
    {
        if(current->left == NULL){
            cout<<current->data;
            current = current->right;
        }else{
            TreeNode *predecessor = current->left;
            while(predecessor->right != current && predecessor->right != NULL){
                predecessor = predecessor->right;
            }

            if(predecessor->right == NULL){
                predecessor->right = current;
                current = current->left;
            }else{ // current is already visited 
                predecessor->right = NULL;
                cout<<current->data<<" ";
                current = current->right;
            }
        }
    }
}
int main(){
    return 0;
}