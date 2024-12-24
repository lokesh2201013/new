class Solution {
public:
    int give(TreeNode* r, int& c, int k) {
        if (r == NULL) return -1;

        int left = give(r->left, c, k);
        if (left != -1) return left;

        c++;
        if (c == k) return r->val;

        return give(r->right, c, k);
    }

    int kthSmallest(TreeNode* r, int k) {
        int c = 0;
        return give(r, c, k);
    }
};
