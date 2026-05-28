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

bool eq(TreeNode* n1, TreeNode* n2){
    if((n1&&!n2)||(n2&&!n1))return false;
    if(!n1&&!n2)return true;

    if(n1->val != n2->val)return false;

    return eq(n1->left, n2->left)&&eq(n1->right, n2->right);
}

bool st(TreeNode* n1, TreeNode* n2){
    if(!n1)return false;
    return st(n1->left, n2)||st(n1->right, n2)||eq(n1,n2);
}

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return st(root, subRoot);
    }
};
