class Solution {
private:
    void give(int i, std::vector<std::vector<int>>& a, std::vector<int>& p, std::vector<int>& n, std::vector<bool>& used) {
        if (i == n.size()) {
            a.push_back(p);
            return;
        }
        for (int j = 0; j < n.size(); ++j) {
            if (!used[j]) {
                used[j] = true;
                p.push_back(n[j]);
                give(i + 1, a, p, n, used);
                p.pop_back();
                used[j] = false;
            }
        }
    }

public:
    std::vector<std::vector<int>> permute(std::vector<int>& n) {
        std::vector<std::vector<int>> a;
        std::vector<int> p;
        std::vector<bool> used(n.size(), false);
        give(0, a, p, n, used);
        return a;
    }
};