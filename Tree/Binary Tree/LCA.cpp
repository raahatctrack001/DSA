/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findPath(TreeNode *root, vector<TreeNode *> &path, TreeNode *toFind){
        if(!root)
            return true;

        path.push_back(root);
        if(root == toFind)
            return true;

        if((root->left and findPath(root->left, path, toFind)) or (root->right && findPath(root->right, path, toFind)))
            return true;

        path.pop_back();
        return false;
    }
    TreeNode *LCA(TreeNode *root, TreeNode *p, TreeNode *q){
        if(!root)
            return NULL;
        
        if(root == p or root == q)
            return root;

        TreeNode *left = LCA(root->left, p, q);
        TreeNode *right = LCA(root->right, p, q);

        if(left and right)
            return root;

        if(left and !right)
            return left;

        if(!left and right)
            return right;        
        
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCA(root, p, q);
    }
};