class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int max_el=0;
        for(auto el:nums){
            max_el=max(max_el,el);
        }
        return (max_el*k)+(k*(k-1))/2;
    }
};