/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* node = root;
        TreeNode* prev = nullptr;

        while (node || !st.empty()) {
            while (node) {
                st.push(node);
                node = node->left;
            }

            node = st.top();
            st.pop();

            if (prev && prev->val >= node->val)
                return false;

            prev = node;
            node = node->right;
        }

        return true;
    }
};