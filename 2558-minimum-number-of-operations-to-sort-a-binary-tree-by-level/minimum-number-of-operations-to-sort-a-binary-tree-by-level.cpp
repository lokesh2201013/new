/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x, left(left), right(right)) {}
 * };
 */
class Solution {
public:
    int minimumOperations(TreeNode* r) {
        vector<vector<int>> levels;
        queue<pair<TreeNode*, int>> q;
        q.push({r, 0});
        
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int lvl = q.front().second;
            q.pop();

            if (levels.size() <= lvl) {
                levels.push_back({});
            }
            levels[lvl].push_back(node->val);

            if (node->left != nullptr) q.push({node->left, lvl + 1});
            if (node->right != nullptr) q.push({node->right, lvl + 1});
        }

        int swaps = 0;

        for (auto& level : levels) {
            vector<pair<int, int>> valIndexPairs;

            for (int i = 0; i < level.size(); i++) {
                valIndexPairs.push_back({level[i], i});
            }

            sort(valIndexPairs.begin(), valIndexPairs.end());

           
            vector<bool> visited(level.size(), false);
            for (int i = 0; i < valIndexPairs.size(); i++) {
                if (visited[i] || valIndexPairs[i].second == i) {
                    continue;
                }
                int cycleSize = 0;
                int j = i;

                while (!visited[j]) {
                    visited[j] = true;
                    j = valIndexPairs[j].second;
                    cycleSize++;
                }
                if (cycleSize > 1) {
                    swaps += (cycleSize - 1);
                }
            }
        }

        return swaps;
    }
};
