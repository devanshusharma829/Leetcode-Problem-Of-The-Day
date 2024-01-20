class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        unordered_map<int, int> mpa;
        unordered_map<int, int> mpb;
        for (int i = 0; i < A.size(); i++) {
            mpa[A[i]]++;
            mpb[B[i]]++;
            int ct = 0;
            for (int j = 1; j <= A.size(); j++) {
                if (mpa[j] && mpb[j]) {
                    ct++;
                }
            }
            ans.push_back(ct);
        }
        return ans;
    }
};