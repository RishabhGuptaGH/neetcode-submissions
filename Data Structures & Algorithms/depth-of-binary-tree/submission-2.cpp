/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
int f(TreeNode* n){
    if(!n)return 0;
    return 1+max(f(n->left), f(n->right));
}

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return f(root);
    }
};
