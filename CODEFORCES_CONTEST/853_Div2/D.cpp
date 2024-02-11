#include "bits/stdc++.h"

// #undef LOCAL

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::string operator<<(std::string &s, int k);
std::string operator>>(std::string &s, int k)
{
    if (k < 0)
        return (s << (-k));

    int n = std::size(s);
    auto t = std::string(n, '0');

    for (int i = 0; i < n - k; i++)
        t[i + k] = s[i];

    return t;
};

std::string operator<<(std::string &s, int k)
{
    if (k < 0)
        return (s >> (-k));

    int n = std::size(s);
    auto t = std::string(n, '0');

    for (int i = 0; i < n - k; i++)
        t[i] = s[i + k];

    return t;
}

std::string operator^(std::string a, std::string b)
{
    std::string ans;
    for (int i = 0; i < std::size(a); i++)
    {
        if (a[i] == b[i])
            ans += '0';
        else
            ans += '1';
    }

    return ans;
}

auto lowestBit(std::string &s)
{
    int n = std::size(s);
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '1')
            return i;
    }

    return -1;
}

auto highestBit(std::string &s)
{
    for (int i = 0; i < std::size(s); i++)
    {
        if (s[i] == '1')
            return i;
    }

    return -1;
}

void solve()
{
    int n;
    std::string a, b;
    std::cin >> n >> a >> b;  

    auto zero = [&](std::string &s)
    {
        return std::count(std::begin(s), std::end(s), '1') == 0;
    };

    if ((zero(a) and !zero(b)) || (!zero(a) and zero(b)))
    {
        std::cout << "-1\n";
        return;
    }

    std::vector<int> ans;
    int hba = highestBit(a), hbb = highestBit(b);
    if (hba > hbb)
    {
        ans.emplace_back(hba - hbb);
        a = a ^ (a << ans.back());
        hba = hbb;
    }

    for (int i = hba + 1; i < n; i++)
    {
        if (a[i] != b[i])
        {
            ans.emplace_back(hba - i);
            a = a ^ (a << ans.back());
        }
    }

    int end = n - 1;
    while (end >= 0 and a[end] == '0')
        end--;

    for (int i = hba; i >= 0; i--)
    {
        if (a[i] != b[i])
        {
            ans.emplace_back(end - i);
            a = a ^ (a << ans.back());
        }
    }
        
    // print(a, b)
    assert(a == b and std::ssize(ans) <= n);
    std::cout << std::size(ans) << "\n";
    for (int i = 0; i < std::ssize(ans); i++)
        std::cout << ans[i] << " \n"[i == std::ssize(ans) - 1];
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