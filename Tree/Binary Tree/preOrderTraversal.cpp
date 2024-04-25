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
    void preOrder(TreeNode *root, vector<int> &ans){
        if(!root)
            return;
        
        ans.push_back(root->val);

        preOrder(root->left, ans);
        preOrder(root->right, ans);
    }
    vector<int> iterativeSolution(TreeNode *root){
        if(!root)
            return {};

        vector<int> ans;
        stack<TreeNode *> st;
        TreeNode *currNode = root;

        while(currNode  or !st.empty()){
            if(currNode){
                ans.push_back(currNode->val);
                st.push(currNode);
                currNode = currNode->left;
            }
            else{
                currNode = st.top();
                st.pop();
                currNode = currNode->right;
            }
        }

    return ans;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        // vector<int> ans;
        // preOrder(root, ans);

        return iterativeSolution(root);
        // return ans;
    }
};