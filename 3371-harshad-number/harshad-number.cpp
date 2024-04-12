#include <vector>

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int original = x;
        int sumOfDigits = 0;

        // Calculate the sum of digits
        while (x > 0) {
            sumOfDigits += x % 10;
            x /= 10;
        }

        // Check if it's a Harshad number
        if (original % sumOfDigits == 0) {
            return sumOfDigits;
        } else {
            return -1;
        }
    }
};
