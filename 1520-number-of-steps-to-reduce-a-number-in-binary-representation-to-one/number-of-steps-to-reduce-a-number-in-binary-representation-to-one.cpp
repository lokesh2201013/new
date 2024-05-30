class Solution {
public:
    int numSteps(std::string s) {
        std::bitset<500> b(s);
        int length = s.size();
        int steps = 0;

        while (length > 1) {
            if (b[0] == 0) { // Even number
                b >>= 1;
                --length;
            } else { // Odd number
                int i = 0;
                while (i < length && b[i] == 1) {
                    b[i] = 0;
                    ++i;
                }
                if (i == length) {
                    b[i] = 1;
                    ++length;
                } else {
                    b[i] = 1;
                }
            }
            ++steps;
        }
        return steps;
    }
};