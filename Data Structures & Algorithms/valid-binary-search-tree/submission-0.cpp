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
    #define ll long long int
    void f(TreeNode* root, bool& ans, ll low, ll high){
        if((root->left == nullptr)&&(root->right == nullptr)){
            if((root->val <= low)||(root->val >= high)){
                ans = false;
                return;
            }
        }

        else if(root->left == nullptr){
            if((root->val <= low)||(root->val >= high)){
                ans = false;
                return;
            }
            f(root->right, ans, max(low,(ll)root->val),high);
        }
        else if(root->right == nullptr){
            if((root->val <= low)||(root->val >= high)){
                ans = false;
                return;
            }
            f(root->left, ans, low,min((ll)root->val,high));
        }
        else{
            if((root->val <= low)||(root->val >= high)){
                ans = false;
                return;
            }
            f(root->left, ans, low,min((ll)root->val,high));
            f(root->right, ans, max(low,(ll)root->val),high);
        }
        return;

    }

    bool isValidBST(TreeNode* root) {
        bool ans = true;
        f(root,ans,INT64_MIN,INT64_MAX);
        if((root->left == nullptr)&&(root->right == nullptr))ans = true;

        return ans;
    }
};
