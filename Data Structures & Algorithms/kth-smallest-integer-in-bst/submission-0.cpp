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

void f(TreeNode* n, vector<int>& v1){
    if(!n)return;
    v1.push_back(n->val);
    f(n->left, v1);
    f(n->right, v1);
}

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans = {};
        f(root, ans);

        sort(ans.begin(), ans.end());

        return ans[k-1];
    }
};
