
class Solution {
public:
    int numberOfAlternatingGroups(std::vector<int>& colors) {
        int count = 0;
        int n = colors.size();

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (colors[i] != colors[i + 1] && colors[i] != colors[n - 1]) {
                    count++;
                }
            } else if (i == n - 1) {
                if (colors[i] != colors[i - 1] && colors[i] != colors[0]) {
                    count++;
                }
            } else if (colors[i] != colors[i + 1] && colors[i] != colors[i - 1]) {
                count++;
            }
        }

        return count;
    }
};