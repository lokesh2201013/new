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
    int minimumOperations(TreeNode* r) {
        vector<vector<int>> s;
        queue<pair<TreeNode*, int>> q;
        q.push({r, 0});
        
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int lvl = q.front().second;
            q.pop();
            
            if (s.size() <= lvl) {
                s.push_back({});
            }
            
            s[lvl].push_back(node->val);
            
            if (node->left != nullptr) q.push({node->left, lvl + 1});
            if (node->right != nullptr) q.push({node->right, lvl + 1});
        }
        
        int c = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < s[i].size(); j++) {
                int m = *min_element(s[i].begin() + j, s[i].end());
                if (s[i][j] == m) continue;
                else {
                    auto it = find(s[i].begin() + j, s[i].end(), m);
                    if (it != s[i].end()) {
                        int fo = distance(s[i].begin(), it);
                        swap(s[i][j], s[i][fo]);
                        c++;
                    }
                }
            }
        }
        return c;
    }
};
