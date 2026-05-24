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
#define K 12345

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q1;

        if(!root)return {};

        TreeNode* k = new TreeNode(K);

        q1.push(root);
        q1.push(k);

        vector<vector<int>> ans = {};
        vector<int> curr = {};

        while(!q1.empty()){
            TreeNode* t = q1.front();
            q1.pop();

            if(t->val == K){
                ans.push_back(curr);
                curr = {};
                if(!q1.empty())q1.push(t);
            }
            else{
                curr.push_back(t->val);
                if(t->left)q1.push(t->left);
                if(t->right)q1.push(t->right);
            }
        }
        return ans;
    }
};
