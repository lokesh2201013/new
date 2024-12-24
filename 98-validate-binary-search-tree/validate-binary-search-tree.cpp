class Solution {
public:
    bool give(TreeNode* r, long long& p) {
        if (r == NULL) return true;

        if (!give(r->left, p)) return false;

        if (p >= r->val) return false;
        p = r->val;

        return give(r->right, p);
    }

    bool isValidBST(TreeNode* r) {
        long long prev = LONG_MIN;
        return give(r, prev);
    }
};
