#define ll long long int
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        deque<int> v;
        for (auto el : nums) {
            v.push_back(el);
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            v.pop_front();
            auto low = lower_bound(v.begin(), v.end(), lower - nums[i]);
            auto high = upper_bound(v.begin(), v.end(), upper - nums[i]);
            ans += (high - low);
        }
        return ans;
    }
};