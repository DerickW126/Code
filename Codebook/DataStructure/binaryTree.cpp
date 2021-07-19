#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode* insert(TreeNode* root, int x){
    if(root == nullptr){
        root = new TreeNode();
        root -> val = x;
        return root;
    }
    TreeNode* ptr = root;
    while(true){
        if(x > ptr->val){
            if(ptr->right == nullptr){
                ptr -> right = new TreeNode();
                ptr -> right -> val = x;
                break;
            } else {
                ptr = ptr -> right;
            }
        } else if(x < ptr->val){
            if(ptr->left == nullptr){
                ptr -> left = new TreeNode();
                ptr -> left -> val = x;
                break;
            } else {
                ptr = ptr -> left;
            }
        }
    }
    return root;
}
void printTree(TreeNode* root){
    if(root == nullptr){
        cout << endl;
        return;
    } 
    printTree(root->left);
    printTree(root->right);
    cout << root->val << ' ';
    return;
}
int main(){
    TreeNode *root = nullptr;
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 12);
    root = insert(root, 9);
    printTree(root);
}

