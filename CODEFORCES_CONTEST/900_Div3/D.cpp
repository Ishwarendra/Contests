#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    std::vector<int> l(k), r(k);
    for (int i = 0; i < k; i++)  
    {
        std::cin >> l[i];
        l[i]--;
    }

    for (int i = 0; i < k; i++)
    {
        std::cin >> r[i];
        r[i]--;
    }

    int q;
    std::cin >> q;

    std::vector<int> op(n);
    while (q--)
    {
        int x;
        std::cin >> x;
        op[x - 1] ^= 1;
    }

    for (int i = 0; i < k; i++)
    {
        int st = l[i], en = r[i];

        for (int id = st; id <= (en + st) / 2; id++)
        {
            op[id] = op[id] ^ op[en + st - id];
            if (id != st)
                op[id] ^= op[id - 1];
        }
        for (int id = st; id <= (en + st) / 2; id++)
        {
            if (op[id])
                std::swap(s[id], s[st + en - id]);
        }
    }

    std::cout << s << "\n";
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