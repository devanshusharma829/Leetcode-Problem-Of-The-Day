#define ll long long int
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;  // Max Heap
        int n=gifts.size();
        for(int i=0;i<n;i++){
            pq.push(gifts[i]);
        }
        while(k){
            k--;
            int tope=pq.top(); // max element
            pq.pop();
            int val=sqrt(tope);
            pq.push(val);
        }
        ll ans=0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};