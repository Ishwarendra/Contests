#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::string s;
    std::cin >> n >> k >> s;  

    for (int i = 0; i < k; i++)
    {
        char ch = '?';
        for (int j = i; j < n; j += k)
        {
            if (s[j] != '?')
            {
                ch = s[j];
                break;
            }
        }

        for (int j = i; j < n; j += k)
        {
            if (s[j] == '?')
                s[j] = ch;
            else if (s[j] != ch)
            {
                std::cout << "NO\n";
                return;
            }
        }
    }

    int one = 0, zero = 0, quest = 0;

    for (int i = 0; i < k - 1; i++)
    {
        if (s[i] == '?')
            quest++;
        one += s[i] == '1';
        zero += s[i] == '0';
    }

    for (int i = k - 1; i < n; i++)
    {
        one += s[i] == '1';
        zero += s[i] == '0';
        quest += s[i] == '?';

        if (one > k / 2 or zero > k / 2)
        {
            std::cout << "NO\n";
            return;
        }

        one -= s[i - k + 1] == '1';
        zero-= s[i - k + 1] == '0';
        quest -= s[i - k + 1] == '?';
    }

    std::cout << "YES\n";
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