#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    std::set<char> vowel {'a', 'e', 'i', 'o', 'u'};
    std::vector<int> pos;

    for (int i = n - 1; i >= 0; --i)
    {
        if (vowel.count(s[i]))
        {
            pos.push_back(i);
            break;
        }
    }

    if (pos.empty())
    {
        std::cout << s << "\n";
        return;
    }

    int m = std::size(pos);
    std::vector<std::string> strings;

    std::string last, have;

    for (int i = 0; i < n; i++)
    {
        if (vowel.count(s[i]))
        {
            strings.push_back(have);
            have = std::string(1, s[i]);
        }
        else
            have += s[i];
    }

    // print(strings)

    for (int i = pos.back(); i < n and i >= 0; i++)
        last += s[i];

    pos.pop_back();

    m = std::size(strings);
    int eve = m % 2 == 0;

    for (int i = m - 1; i >= 0; i -= 2)
        pos.push_back(i);

    for (int i = 1 - eve; i < m; i += 2)
        pos.push_back(i);

    assert(pos.size() == m);
    // print(strings, index, pos)
    std::string ans;
    int parity = (int)std::size(pos) % 2;
    parity = 1 - parity;

    for (int i : pos)
    {
        assert(i < std::size(strings) and i >= 0);
        if (i % 2 == parity)
            std::reverse(std::begin(strings[i]), std::end(strings[i]));

        ans += strings[i];
    }

    ans += last;
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