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


int d(TreeNode* n1, bool& ans){
    if(!n1)return 0;

    int a = d(n1->left, ans);
    int b = d(n1->right, ans);

    if(abs(a-b)>1)ans = false;

    return max(a,b)+1;
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        d(root, ans);
        return ans;
    }
};
