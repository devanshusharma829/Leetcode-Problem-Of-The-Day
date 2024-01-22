#define ll long long int
class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        unordered_map<ll, ll> mp1;
        unordered_map<ll, ll> mp2;
        ll min_val = INT_MAX;
        ll flag = 0;
        for (auto el : b1) {
            mp1[el]++;
            min_val = min(min_val, el * 1ll);
        }
        for (auto el : b2) {
            mp2[el]++;
            min_val = min(min_val, el * 1ll);
        }
        vector<ll> v1;
        vector<ll> v2;
        for (auto p : mp1) {
            ll el = p.first;
            ll freq = p.second;
            if (freq == mp2[el] || freq < mp2[el]) {
                continue;
            }
            if ((freq - mp2[el]) % 2 != 0) {
                return -1;
            } else {
                ll nf = (freq - mp2[el]) / 2;
                while (nf) {
                    nf--;
                    v1.push_back(el);
                }
            }
        }
        for (auto p : mp2) {
            ll el = p.first;
            ll freq = p.second;
            if (freq == mp1[el] || freq < mp1[el]) {
                continue;
            }
            if ((freq - mp1[el]) % 2 != 0) {
                return -1;
            } else {
                ll nf = (freq - mp1[el]) / 2;
                while (nf) {
                    nf--;
                    v2.push_back(el);
                }
            }
        }
        if (v1.size() != v2.size()) {
            return -1;
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        ll ans = 0;
        ll m = v1.size();
        for (int i = 0; i < m; i++) {
            ll val = min(v1[i], v2[m - 1 - i]);
            ans = ans + min(val, min_val * 2);
        }
        return ans;
    }
};