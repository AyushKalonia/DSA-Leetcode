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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)    return root;
        int curr = root->val;
        if(q->val < curr && p->val < curr){
            return lowestCommonAncestor(root->left, p, q);
        }
        if(q->val > curr && p->val > curr){
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};