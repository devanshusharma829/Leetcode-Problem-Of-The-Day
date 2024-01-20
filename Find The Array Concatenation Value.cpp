#define ll long long int
class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        ll ans = 0;
        if (n % 2) {
            ans += nums[n / 2];
        }
        for (int i = 0; i < n / 2; i++) {
            int s = i;
            int e = n - 1 - i;
            string conc = to_string(nums[s]) + to_string(nums[e]);
            ll val = stoll(conc);
            ans += val;
        }
        return ans;
    }
};