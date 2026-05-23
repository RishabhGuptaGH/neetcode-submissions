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
void f(TreeNode* n){
    if(!n)return;
    TreeNode* l = n->left;
    TreeNode* r = n->right;
    n->left = r;
    n->right = l;
    f(n->left);
    f(n->right);
}

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        f(root);
        return root;
    }
};
