#include <bits/stdc++.h>

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

    int n;
    std::string s;
    std::cin >> n >> s;

    std::map<char, int> m;
    for (int i = 0; i < n; ++i)
        m[s[i]]++;

    int need = n / 3;
    std::vector<int> cnt(3);

    for (int i = 0; i < n; ++i)
    {
        if (m[s[i]] <= need)
            continue;

        if (s[i] == '0')
        {
            if (cnt[0] != need)
                cnt[0]++;
            else
            {
                if (m['1'] < need)
                    m['1']++, m['0']--, s[i] = '1';
                else if (m['2'] < need)
                    m['2']++, m['0']--, s[i] = '2';
            }
        }
        else if (s[i] == '1')
        {
            if (m['0'] < need)
                s[i] = '0', m['0']++, m['1']--;
            else if (m['2'] < need) 
            {
                if (cnt[1] != need)
                    cnt[1]++;
                else
                    s[i] = '2', m['2']++, m['1']--;
            }
        }
        else
        {
            for (char ch : {'0', '1'})
            {
                if (m[ch] < need)
                {
                    s[i] = ch, m[ch]++, m['2']--;
                    break;
                }
            }
        }
    }

    std::cout << s;

    return 0;
}