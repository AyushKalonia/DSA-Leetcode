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
    void inorder(TreeNode* root, vector<int> &ans){
        if(root == NULL)    return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    bool twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l = 0, r = n-1;
        while(l<r){
            if(numbers[l] + numbers[r] == target) return true;
            else if(numbers[l] + numbers[r] > target) r--;
            else if(numbers[l] + numbers[r] < target) l++;
        }
        return false;
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> in;
        inorder(root, in);
        return twoSum(in, k);
    }
};