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
int f(TreeNode* n, unordered_map<TreeNode*, int>& m1){
    if(!n)return 0;
    if(m1.find(n) != m1.end())return m1[n];

    return m1[n] = max(0,n->val + max(f(n->left, m1), f(n->right, m1)));
}

void g(TreeNode* root, unordered_map<TreeNode*, int>& m1, int* ans){
    if(!root)return;

    *ans = max(*ans, root->val+f(root->left, m1)+f(root->right, m1));
    g(root->left, m1, ans);
    g(root->right, m1, ans);
}


class Solution {
public:
    int maxPathSum(TreeNode* root) {
        unordered_map<TreeNode*, int> m1;
        int ans = INT32_MIN;
        f(root, m1);
        g(root, m1, &ans);
        return ans;
    }
};
