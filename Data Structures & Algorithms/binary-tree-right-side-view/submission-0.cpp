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

class Solution {
public:
    #define TERM 999999999
    void f(TreeNode* root,vector<int>& soln){
        soln.push_back(root->val);

        if((root->left == nullptr)&&(root->right == nullptr))return;

        else if(root->right != nullptr){
            f(root->right,soln);
        }
        else f(root->left,soln);

    }



    vector<int> rightSideView(TreeNode* root) {
        vector<int> soln;
        if(root == nullptr)return soln;

        queue<TreeNode*> q1;
        TreeNode* prev = nullptr;
        TreeNode* levelEnd = new TreeNode(TERM);
        q1.push(root);
        q1.push(levelEnd);

        while(!q1.empty()){
            TreeNode* t = q1.front();
            q1.pop();
            if(t->val == TERM){
                if(prev == t)break;
                soln.push_back(prev->val);
                q1.push(t);
                prev = t;
                continue;
            }

            if(t->left != nullptr)q1.push(t->left);
            if(t->right != nullptr)q1.push(t->right);
            prev = t;

        }
        return soln;

    }
};
