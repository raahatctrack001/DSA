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



//  For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
// For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        // queue<treenode, level> q
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()){
            int level = q.front().second;
            int len = q.size();
            
            if(!(level&1)){ //even index level
                int previousValue = INT_MIN;
                for(int i = 0; i < len; i++){
                    TreeNode *currentNode = q.front().first;
                    q.pop();
                    int currentValue = currentNode->val;

                    //cout<<currentValue<<" ";
                    //all nodes at the level have odd integer values in strictly increasing order (from left to right).
                    if((currentValue&1) and (previousValue < currentValue))
                        previousValue = currentValue;
                    else
                        return false;

                    if(currentNode->left)
                        q.push({currentNode->left, level+1});
                    if(currentNode->right)
                        q.push({currentNode->right, level+1});

                }
                //cout<<endl;
            }
            else{
                int previousValue = INT_MAX;
                for(int i = 0; i < len; i++){
                    TreeNode *currentNode = q.front().first;
                    q.pop();
                    int currentValue = currentNode->val;

                    //cout<<currentValue<<" ";
                    //all nodes at the level have even integer values in strictly decreasing order (from left to right).
                    if(!(currentValue&1) and (previousValue > currentValue))
                        previousValue = currentValue;
                    else
                        return false;

                    if(currentNode->left)
                        q.push({currentNode->left, level+1});
                    if(currentNode->right)
                        q.push({currentNode->right, level+1});

                }
                //cout<<endl;
            }
        }
        return true;
    }
};