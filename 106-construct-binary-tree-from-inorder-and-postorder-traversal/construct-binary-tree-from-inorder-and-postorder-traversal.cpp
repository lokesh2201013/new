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
    TreeNode* buildTree(vector<int>& in, vector<int>& p) {
        map<int, int> m;
        for (int i = 0; i < in.size(); i++) {
            m[in[i]] = i;
        }
        return build(p, in, 0, p.size() - 1, 0, in.size() - 1, m);
    }

private:
    TreeNode* build(vector<int>& p, vector<int>& in, int ps, int pe, int ins, int ine, map<int, int>& m) {
        if (ps > pe || ins > ine) return nullptr;

        TreeNode* root = new TreeNode(p[pe]);

        int inRootIndex = m[root->val];

        int numLeft = inRootIndex - ins;

        root->left = build(p, in, ps, ps + numLeft - 1, ins, inRootIndex - 1, m);
        root->right = build(p, in, ps + numLeft, pe - 1, inRootIndex + 1, ine, m);

        return root;
    }
};
