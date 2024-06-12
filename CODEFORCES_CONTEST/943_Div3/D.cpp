#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * Permutations always form disjoint cycles
 * So each player will move in his/her cycle
 * Fix the prefix of numbers you want to play in
 * On last element spend rest of your turn
 * Do this for all prefix and get best answer for each player
 */

void solve()
{
    int n, k, pb, ps;
    std::cin >> n >> k >> pb >> ps;
    
    std::vector<int> p(n), a(n);
    for (int i = 0; i < n; i++)  
    {
        std::cin >> p[i];
        p[i]--;
    }
    
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    
    pb--, ps--;
    std::vector<i64> b, s;
    
    auto work = [&](auto &val, int st)
    {
        while (std::size(val) < std::min(n, k))   
        {   
            val.emplace_back(a[st]);
            st = p[st];
        }
    };

    work(b, pb);
    work(s, ps);
    
    auto get = [&](std::vector<i64> &p)
    {
        int sz = std::size(p);
        std::vector<i64> psum(sz);
        psum[0] = p[0];
        
        for (int i = 1; i < sz; i++)  
            psum[i] += psum[i - 1] + p[i];
        
        i64 ans = p[0] * k;
        for (int i = 1; i < sz; i++)
        {
            i64 s = psum[i - 1];
            i64 m = p[i];
            
            i64 cur = s + (k - i) * m;
            ans = std::max(ans, cur);
        }
        
        return ans;
    };
    
    i64 bodya = get(b);
    i64 sasha = get(s);
    // print(bodya, sasha)
    
    if (bodya > sasha)
        std::cout << "Bodya\n";
    else if (bodya < sasha)
        std::cout << "Sasha\n";
    else
        std::cout << "Draw\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}