class Solution {
public:
    int findLeastNumOfUniqueInts(std::vector<int>& a, int k) {
        std::map<int, int> frequencyMap;
        
        // Count the frequency of each element
        for (int i : a) {
            frequencyMap[i]++;
        }

        // Store the frequencies in a vector and sort it
        std::vector<int> sortedFrequencies;
        for (const auto& pair : frequencyMap) {
            sortedFrequencies.push_back(pair.second);
        }
        std::sort(sortedFrequencies.begin(), sortedFrequencies.end());

        int removedCount = 0;
        for (int frequency : sortedFrequencies) {
            if (k >= frequency) {
                k -= frequency;
                removedCount++;
            } else {
                break;
            }
        }

        return sortedFrequencies.size() - removedCount;
    }
};
