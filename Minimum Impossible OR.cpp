#define ll long long int
class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        ll val=1;
        while(1){
            if(mp[val]==0){
                return (int)val;
            }
            val=val*2;
        }
        return val;
    }
};