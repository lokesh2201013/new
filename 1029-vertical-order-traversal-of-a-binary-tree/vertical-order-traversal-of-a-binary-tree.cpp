class Solution {
public:
    void groupAndPush(vector<tuple<int, int, int>>& a, vector<vector<int>>& af) {
        map<int, vector<int>> grouped;
        for (const auto& t : a) {
            int x = get<1>(t); // Extract vertical order (x)
            int val = get<0>(t); 
            grouped[x].push_back(val);
        }
        for (auto& group : grouped) {
            af.push_back(group.second);
        }
    }

    void traverse(TreeNode* r, vector<tuple<int, int, int>>& a, int x, int y) {
        if (!r) return;
        a.push_back({r->val, x, y});
        traverse(r->left, a, x - 1, y + 1);
        traverse(r->right, a, x + 1, y + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* r) {
        vector<tuple<int, int, int>> a; // Stores {value, x (vertical), y (horizontal)}
        traverse(r, a, 0, 0);

        // Sort by: vertical (x), then horizontal (y), then node value
        sort(a.begin(), a.end(), [](const tuple<int, int, int>& t1, const tuple<int, int, int>& t2) {
            if (get<1>(t1) != get<1>(t2)) return get<1>(t1) < get<1>(t2); // Compare x
            if (get<2>(t1) != get<2>(t2)) return get<2>(t1) < get<2>(t2); // Compare y
            return get<0>(t1) < get<0>(t2); // Compare value
        });

        vector<vector<int>> af;
        groupAndPush(a, af);
        return af;
    }
};
