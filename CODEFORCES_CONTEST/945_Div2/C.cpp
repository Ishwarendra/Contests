#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    
    auto work = [&](int st)
    {
        std::vector<int> q(n);
        std::set<int> have;
        for (int i = 1; i <= n; i++)
            have.emplace(i);
        
        std::vector<std::pair<int, int>> num_id;
        for (int i = st; i < n - 1; i += 2)
            num_id.emplace_back(a[i], i);
        std::sort(std::begin(num_id), std::end(num_id));
        
        auto get = [&](int i) { return a[i] + q[i]; };
        
        int max = n;
        std::vector<int> constraint(n, 2 * n);
        for (auto &[_, i] : num_id)
        {
            q[i] = max;
            have.erase(max);
            max--;
            
            if (i - 1 >= 0)
                constraint[i - 1] = std::min(constraint[i - 1], get(i));
            if (i + 1 < n)
                constraint[i + 1] = std::min(constraint[i + 1], get(i));
        }
            
        int start = (st == 1 ? 0 : 1);
        int end = (st == 1 ? n - 1 : n);
        for (int i = start; i < end; i++)
        {
            if (q[i])
                continue;
            
            auto min = constraint[i];
            auto it = have.lower_bound(min - a[i]);
            if (it != std::begin(have))
                it--;
            else
                it = std::prev(std::end(have));

            q[i] = *it;
            have.erase(it);
        }
        
        q[st == 1 ? n - 1 : 0] = *std::begin(have);
        
        int cnt = 0;
        for (int i = 1; i < n - 1; i++)
            cnt += get(i - 1) < get(i) and get(i) > get(i + 1);
        return std::pair { cnt, q };
    };
    
    auto [_, p] = std::max(work(1), work(2));
    assert(_ == n / 2 - 1);
    for (int i = 0; i < n; i++)
        std::cout << p[i] << " \n"[i == n - 1];
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