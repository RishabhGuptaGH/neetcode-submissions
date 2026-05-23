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
bool f(TreeNode* n, TreeNode* p, TreeNode* q, TreeNode*& lca){
    if(!n)return false;

    bool ans = false;
    if(n == p || n == q){
        ans = ans || f(n->left,p,q,lca) || f(n->right,p,q,lca);
        if(ans){
            lca = n;
            return true;
        }
        else return true;
    }
    if(f(n->left,p,q,lca)&&f(n->right,p,q,lca)){
        lca = n;
        return true;
    }
    if(f(n->left,p,q,lca)||f(n->right,p,q,lca)){
        return true;
    }
    return false;
}
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* fans;
        f(root, p, q, fans);
        return fans;
    }
};
