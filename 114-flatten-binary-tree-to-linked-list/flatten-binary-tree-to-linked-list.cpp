class Solution {
public:
    void flatten(TreeNode* r) {
        if (!r) return; 
        stack<TreeNode*> s;
        s.push(r);
        TreeNode* cur;
        while (!s.empty()) {
            cur = s.top();
            s.pop();
            if (cur->right) s.push(cur->right);
            if (cur->left) s.push(cur->left);
            if (!s.empty()) {
                cur->right = s.top();
            }
            cur->left = nullptr; 
        }
    }
};
