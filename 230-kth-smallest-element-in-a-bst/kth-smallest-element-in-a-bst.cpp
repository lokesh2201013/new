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
void give(TreeNode* r,vector<int>&s){
    if(r==NULL)return;

    give(r->left,s);
    s.push_back(r->val);
     give(r->right,s);
}
    int kthSmallest(TreeNode* r, int k) {
        vector<int>s;
        give(r,s);
        return s[k-1];
    }
};