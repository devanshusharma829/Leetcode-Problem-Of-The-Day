class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int el : arr) freq[el]++;
        
        unordered_set<int> freqSet;
        for (auto [key, value] : freq) freqSet.insert(value);

        return freqSet.size() == freq.size();
    }
};