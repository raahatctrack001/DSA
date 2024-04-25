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
    int height(TreeNode *root){
        if(!root){
            return 0;
        }

        int left = 1 + height(root->left);
        int right = 1 + height(root->right);
        
        return max(left, right);
    }
    void levelOrderTraversalRec(TreeNode *root, vector<vector<int>> &ans, int i = 0){
        if(!root)
            return;

        ans[i].push_back(root->val);
        levelOrderTraversalRec(root->left, ans, i+1);
        levelOrderTraversalRec(root->right, ans, i+1);       
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int h = height(root);
        vector<vector<int>> ans(h);
        levelOrderTraversalRec(root, ans);
        return ans;
    }
};