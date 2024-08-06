
class Solution {
private:
    static bool compareByFrequency(const pair<char, int>& a, const pair<char, int>& b) {
        return a.second > b.second;
    }

public:
    int minimumPushes(const string& w) {
        set<char> uniqueChars(w.begin(), w.end());

        if (uniqueChars.size() == w.size()) {
            int n = w.size();
             if(n<=8)
        {
        int i=1;
            return n*i;
        }
        int sum=0;
        int i=0;
        while(n>8)
        {
            n=n-8;
            i++;
            sum=sum+(8*i);
        }
        i++;
        sum+=n*i;
        return sum;
        } else {
            map<char, int> charFrequency;
            for (char i : w) {
                charFrequency[i]++;
            }

            vector<pair<char, int>> charFreqVector(charFrequency.begin(), charFrequency.end());
            sort(charFreqVector.begin(), charFreqVector.end(), compareByFrequency);

            int sum = 0;
            int cnt = 0;
            int i = 1;

            for (const auto& pair : charFreqVector) {
                sum = sum + (pair.second * i);
                cnt++;

                if (cnt >= 8) {
                    i = (cnt / 8) + 1;
                }
            }

            return sum;
        }
    }
};