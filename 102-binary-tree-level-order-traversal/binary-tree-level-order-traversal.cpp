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
    vector<vector<int>> levelOrder(TreeNode* r) {
        vector<vector<int>> a;
        if (r == nullptr) return a;
        
        queue<TreeNode*> q;
        q.push(r);  // Add the root node to the queue
        
        while (!q.empty()) {
            int n = q.size();
            vector<int> l;
            
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
                l.push_back(node->val);
            }
            
            a.push_back(l);
        }
        
        return a;
    }
};
