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
    int findBottomLeftValue(TreeNode* root) {
        //container to store nodes in order to track them later on
        queue<TreeNode *> q;
        q.push(root);
        
        TreeNode *front = root;
        while(!q.empty()){
            front = q.front();
            q.pop();    
            //pushing right node first as we require left node at the end
            if(front->right)
                q.push(front->right);

            if(front->left)
                q.push(front->left);
        }
        //last node that front is having is the left most in last row
        return front->val;
    }
};