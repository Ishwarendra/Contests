#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;

    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        a[i] = {i + 1, 0};

    int head = 0;

    while (q--)
    {
        int t;
        std::cin >> t;

        if (t == 1)
        {
            char ch;
            std::cin >> ch;

            auto old = a[head];
            head--;
            if (head < 0)
                head += n;

            a[head] = old;

            if (ch == 'R')
                a[head].first++;
            else if (ch == 'L')
                a[head].first--;
            else if (ch == 'U')
                a[head].second++;
            else
                a[head].second--;
        }
        else
        {
            int p;
            std::cin >> p;
            p--;

            std::cout << a[(head + p) % n].first << " " << a[(head + p) % n].second << "\n";
        }
    }
    
    return 0;
}