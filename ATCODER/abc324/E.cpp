#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

bool subseq(std::string s1, std::string s2)
{
    int n = s1.length(), m = s2.length();
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (s1[i] == s2[j])
            i++;
        j++;
    }
    return i == n;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::string t;
    std::cin >> n >> t;

    int st = std::size(t);
    std::vector<int> maxp(n, -1), maxs(n, st), m(st + 1);
    std::vector<std::string> a(n);

    for (int id = 0; id < n; id++)
    {
        std::string s;
        std::cin >> s;
        a[id] = s;

        int ss = std::size(s);

        for (int j = 0, i = 0; j < ss and i < st; j++)
        {
            if (s[j] == t[i])
                maxp[id] = i++;
        }

        for (int j = ss - 1, i = st - 1; j >= 0 and i >= 0; j--)
        {
            if (s[j] == t[i])
                maxs[id] = i--;
        }
    }

    for (int i = 0; i < n; i++)
        m[maxs[i]]++;

    for (int i = 1; i <= st; i++)
        m[i] += m[i - 1];

    i64 ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (maxp[i] + 1 == st)
            ans += n;
        else
            ans += m[maxp[i] + 1];
    }

    std::cout << ans;
    
    return 0;
}