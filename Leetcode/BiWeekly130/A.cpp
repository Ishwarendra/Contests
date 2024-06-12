#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
#else
#define print(...) 1;
#endif

using namespace std;
using i64 = long long;

template<class T>
T power(T a, T b, T mod) {
    T res = 1;
    for (; b; b /= 2, a = (a * a) % mod) {
        if (b % 2) {
            res = (res % mod) * (a % mod) % mod;
        }
    }
    return (res % mod);
}

class Solution 
{
    using i64 = long long;
    
    int get(i64 l, i64 r, const i64 MOD)
    {
        i64 ans = 1;
        for (int bit = 0; bit < 5; bit++)
        {
            auto f = [&](i64 x)
            {
                i64 rank = x & ((1LL << bit) - 1);
                x -= rank;
                i64 g = x >> bit;
                
                return ((g >> 1) << bit) + (g % 2 ? rank + 1 : 0);
            };
            
            int cnt = f(r) - f(l - 1);
            ans = (ans * power<i64>(1LL << bit, cnt, MOD));
        }
        
        return int(ans);
    }
public:
    vector<int> findProductsOfElements(vector<vector<i64>>& queries) 
    {
        std::vector<int> ans;
        for (auto &query : queries)
        {
            i64 l = query[0], r = query[1];
            const i64 MOD = query[2];
            ans.emplace_back(get(l, r, MOD));
            break;
        }
        
        return ans;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<vector<i64>> q(n);
    for (int i = 0; i < n; i++)
    {
        i64 yy, xx, dd;
        std::cin >> yy >> xx >> dd;
        q[i] = {yy, xx, dd};
    }

    Solution sol;
    print(sol.findProductsOfElements(q));


    return 0;
}