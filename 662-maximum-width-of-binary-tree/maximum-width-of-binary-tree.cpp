class Solution {
public:
    int widthOfBinaryTree(TreeNode* r) {
        if (!r) return 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({r, 0});
        long long a = 0;
        while (!q.empty()) {
            long long n = q.size();
            long long nmin = q.front().second;
            long long mi = 0, ma = 0;
            for (int i = 0; i < n; i++) {
                long long cuid = q.front().second - nmin;
                TreeNode* node = q.front().first;
                q.pop();
                if (i == 0) mi = cuid;
                if (i == n - 1) ma = cuid;
                if (node->left) q.push({node->left, cuid * 2 + 1});
                if (node->right) q.push({node->right, cuid * 2 + 2});
            }
            a = max(a, ma - mi + 1);
        }
        return static_cast<int>(a);
    }
};
