// space - O(1)
// time - O(n)
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        int first = 1, second = 2;
        int ans;
        for (int i = 3; i <= n; i++) {
            ans = first + second;
            first = second;
            second = first;
        }
        return ans;
    }
};