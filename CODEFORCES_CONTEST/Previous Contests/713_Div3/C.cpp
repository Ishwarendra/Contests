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
    int a, b;
    std::string s;

    std::cin >> a >> b >> s;
    std::swap(a, b);

    int n = std::size(s);

    int one = std::count(std::begin(s), std::end(s), '1');
    int zero = std::count(std::begin(s), std::end(s), '0');
    int quest = n - one - zero;

    if (one > a or zero > b)
    {
        std::cout << "-1\n";
        return;
    }

    std::vector<int> need {b - zero, a - one};

    int i = -1, j = n;

    while (i < j)
    {
        i++, j--;
        if (s[i] == '?' and s[j] == '?')
            continue;

        if (s[j] == '?')
            s[j] = s[i], need[s[i] - '0']--;
        else if (s[i] == '?')
            s[i] = s[j], need[s[j] - '0']--;

        if (need[0] < 0 or need[1] < 0 or abs(s[i] - s[j]) == 1)
        {
            std::cout << "-1\n";
            return;
        }

        if (need[0] < 0 or need[1] < 0)
        {
            std::cout << "-1\n";
            return;
        }
    }

    i = 0, j = n - 1;
    while (i < j)
    {
        if (s[i] == s[j] and s[i] != '?')
        {
            i++, j--;
            continue;
        }

        if (s[i] == '?' or s[j] == '?')
        {
            if (s[i] != '?')
                s[j] = s[i], need[s[i] - '0']--;
            else if (s[j] != '?')
                s[i] = s[j], need[s[j] - '0']--;
            else
            {
                if (need[0] >= 2)
                    s[i] = s[j] = '0', need[0] -= 2;
                else if (need[1] >= 2)
                    s[i] = s[j] = '1', need[1] -= 2;
                else
                {
                    std::cout << "-1\n";
                    return;
                }
            }

            i++, j--;

            if (need[0] < 0 or need[1] < 0)
            {
                std::cout << "-1\n";
                return;
            }
        }
        else
        {
            std::cout << "-1\n";
            return;
        }
    }

    if (s[n / 2] == '?')
    {
        if (need[0])
            s[n / 2] = '0';
        else if (need[1])
            s[n / 2] = '1';
        else
        {
            std::cout << "-1\n";
            return;
        }
    }

    std::cout << s << "\n";
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