
class Solution {
public:
    int minIncrementForUnique(std::vector<int>& n) {
        std::sort(n.begin(), n.end());
        int c = 0;
        for (int i = 1; i < n.size(); i++) {
            if (n[i] <= n[i-1]) {
                int increment = n[i-1] - n[i] + 1;
                n[i] += increment;
                c += increment;
            }
        }
        return c;
    }
};