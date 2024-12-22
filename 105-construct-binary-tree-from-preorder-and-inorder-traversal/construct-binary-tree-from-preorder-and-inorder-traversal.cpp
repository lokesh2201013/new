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
    TreeNode* buildTree(vector<int>& p, vector<int>& in) {
        map<int, int> m;
        for (int i = 0; i < in.size(); i++) {
            m[in[i]] = i;
        }
        return build(p, 0, p.size() - 1, in, 0, in.size() - 1, m);
    }

    TreeNode* build(vector<int>& p, int ps, int pe, vector<int>& in, int ins, int ine, map<int, int>& m) {
        if (ps > pe || ins > ine) return nullptr;

        TreeNode* r = new TreeNode(p[ps]);
        int inr = m[r->val];
        int nl = inr - ins;

        r->left = build(p, ps + 1, ps + nl, in, ins, inr - 1, m);
        r->right = build(p, ps + 1 + nl, pe, in, inr + 1, ine, m);

        return r;
    }
};
