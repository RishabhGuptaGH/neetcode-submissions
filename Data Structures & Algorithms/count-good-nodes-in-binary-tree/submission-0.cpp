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

void f(TreeNode* n1, int m, int& c){
    if(!n1)return;

    if(n1->val >= m)c++;
    
    m = max(m, n1->val);

    f(n1->left, m, c);
    f(n1->right, m, c);
}

class Solution {
public:
    int goodNodes(TreeNode* root) {
        int c = 0;
        f(root, root->val, c);
        return c;
    }
};
