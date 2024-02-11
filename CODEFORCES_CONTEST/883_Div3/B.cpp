#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::vector<std::string> a(3);
    for (int i = 0; i < 3; i++)  
        std::cin >> a[i];

    auto check = [&](char ch)
    {
        int ok = 0;
        std::array<int, 2> cntD{};
        for (int i = 0; i < 3; i++)
        {
            if (a[i] == std::string(3, ch))
                ok |= 1;

            int cnt = 0;
            for (int j = 0; j < 3; j++)
                cnt += a[j][i] == ch;

            ok |= cnt == 3;
            cntD[0] += a[i][i] == ch;
            cntD[1] += a[i][2 - i] == ch;
        }

        ok |= cntD[0] == 3 or cntD[1] == 3;
        return ok;
    };

    for (auto ch : {'+', 'X', 'O'})
    {
        if (check(ch))
        {
            std::cout << ch << "\n";
            return;
        }
    }

    std::cout << "DRAW\n";
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