
class Solution {
public:
    long long continuousSubarrays(vector<int>& n) {
        long long left = 0, count = 0;
        deque<int> minDeque, maxDeque;  // Deques to store the indices of min and max elements

        for (int right = 0; right < n.size(); ++right) {
            // Maintain the deques: minDeque for the smallest element, maxDeque for the largest element
            while (!minDeque.empty() && n[minDeque.back()] >= n[right]) {
                minDeque.pop_back();  // Pop elements that are greater than the current element
            }
            while (!maxDeque.empty() && n[maxDeque.back()] <= n[right]) {
                maxDeque.pop_back();  // Pop elements that are smaller than the current element
            }

            minDeque.push_back(right);  // Add current element index to the min deque
            maxDeque.push_back(right);  // Add current element index to the max deque

            // Ensure the window is valid (max - min <= 2)
            while (n[maxDeque.front()] - n[minDeque.front()] > 2) {
                // Shrink the window by moving the left pointer
                if (minDeque.front() == left) minDeque.pop_front();
                if (maxDeque.front() == left) maxDeque.pop_front();
                left++;
            }

            // All subarrays ending at 'right' and starting from 'left' to 'right' are valid
            count += (right - left + 1);  // Add the count of valid subarrays
        }

        return count;
    }
};