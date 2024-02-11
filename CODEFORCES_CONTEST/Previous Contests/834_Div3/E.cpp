#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    i64 h;
    std::cin >> n >> h;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));
    std::vector<int> index {2, 2, 3};

    int ans = 0;
    do
    {
        int max = 0;
        i64 cur_h = h;
        int pos = 0;

        int i;
        for (i = 0; i < n;)
        {
            if (cur_h > a[i])
                cur_h += a[i++] / 2;
            else if (pos < 3)
            {
                cur_h *= index[pos++];
                if (cur_h > a[i])                
                    cur_h += a[i++] / 2;
                else
                    continue;
            }
            else
                break;
        }

        ans = std::max(ans, i);

    } while (std::next_permutation(std::begin(index), std::end(index)));

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}