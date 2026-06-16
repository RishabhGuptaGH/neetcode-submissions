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

int d(TreeNode* n1, int& ans){
    if(!n1)return 0;

    int a = d(n1->left, ans);
    int b = d(n1->right, ans);

    ans = max(ans, a+b+1);

    return max(a,b)+1;
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        d(root, ans);
        return ans - 1;
    }
};