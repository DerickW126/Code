#include <iostream>
#include <unordered_map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};
class Solution {
public:
    unordered_map <TreeNode*, int> mp;
    int depth(TreeNode* root){
        if(root == nullptr) return -1;
        if(mp.count(root)) return mp[root];
        mp[root] = max(depth(root->left), depth(root->right)) + 1;
        return mp[root];
    }
    int longestPathOnTree(TreeNode *root){
        if(root == nullptr) return 0;
        int ans = depth(root->left)+depth(root->right)+2;
        ans = max(ans, longestPathOnTree(root->left));
        ans = max(ans, longestPathOnTree(root->right));
        return ans;
    }
};
TreeNode* readTree(){
    int n;
    cin >> n;
    if(n == -1) return nullptr;
    else {
        TreeNode* tmp = new TreeNode();
        tmp -> val = n;
        tmp -> left = readTree();
        tmp -> right = readTree();
        return tmp;
    }
}
int main(){
    Solution s;
    TreeNode* root = readTree();
    cout << s.longestPathOnTree(root) << endl;
}
