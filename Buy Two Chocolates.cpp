class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int firstMin=min(prices[0],prices[1]);
        int secondMin=max(prices[0],prices[1]);
        for(int i=2;i<prices.size();i++){
            if(prices[i]<firstMin){
                secondMin=firstMin;
                firstMin=prices[i];
            }
            else if(prices[i]<secondMin){
                secondMin=prices[i];
            }
        }
        if(money-(firstMin+secondMin)>=0){
            return money-(firstMin+secondMin);
        }
        return money;
    }
};