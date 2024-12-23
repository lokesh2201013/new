class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* r, int v) {
        if(r==NULL)return new TreeNode(v);
        TreeNode* c = r;
        while (c != NULL) {
            if (v > c->val) {
                if (c->right == NULL) {
                    c->right = new TreeNode(v);
                    break;
                }
                c = c->right;
            } else {
                if (c->left == NULL) {
                    c->left = new TreeNode(v);
                    break;
                }
                c = c->left;
            }
        }
        return r;
    }
};
