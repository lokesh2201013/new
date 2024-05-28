
class Solution {
public:
    int equalSubstring(std::string s, std::string t, int m) {
        // Vector to store the absolute differences between corresponding characters of s and t
        std::vector<int> d;
        for (int i = 0; i < s.size(); ++i) {
            d.push_back(std::abs(s[i] - t[i]));
        }

        // Sliding window approach to find the maximum length of substring with cost <= m
        int l = 0;
        int sum = 0;
        int maxLength = 0;

        for (int r = 0; r < d.size(); ++r) {
            sum += d[r];

            // If the sum exceeds m, shrink the window from the left
            while (sum > m) {
                sum -= d[l];
                ++l;
            }

            maxLength = std::max(maxLength, r - l + 1);
        }

        return maxLength;
    }
};