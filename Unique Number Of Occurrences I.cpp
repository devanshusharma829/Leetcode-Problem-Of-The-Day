class Solution {
public:
    int K = 1000;
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> freq(2 * K  + 1);
        for (int el : arr) freq[el + K]++;

        sort(freq.begin(), freq.end());

        for (int i = 0; i < 2 * K; i++) {
            if (freq[i] != 0 && freq[i] == freq[i + 1]) return false;
        }

        return true;
    }
};