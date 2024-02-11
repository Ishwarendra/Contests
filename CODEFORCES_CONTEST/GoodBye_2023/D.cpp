#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

std::string multiply(std::string num1, std::string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
        return "0";

    std::vector<int> result(len1 + len2, 0);
    int i_n1 = 0;
    int i_n2 = 0;

    for (int i = len1 - 1; i >= 0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';

        i_n2 = 0;
        for (int j = len2 - 1; j >= 0; j--)
        {
            int n2 = num2[j] - '0';
            int sum = n1 * n2 + result[i_n1 + i_n2] + carry;
            carry = sum / 10;

            result[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }

        if (carry > 0)
            result[i_n1 + i_n2] += carry;
        i_n1++;
    }

    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0)
        i--;

    if (i == -1)
        return "0";

    std::string s;

    while (i >= 0)
        s += std::to_string(result[i--]);

    return s;
}

void solve()
{
    int n;
    std::cin >> n;

    if (n == 1)
        std::cout << "1\n";
    else if (n == 3)
        std::cout << "169\n196\n961\n";
    else if (n == 5)
        std::cout << "16384\n31684\n36481\n38416\n43681\n";
    else if (n == 7)
        std::cout << "1046529\n1695204\n1946025\n4052169\n5294601\n6215049\n9641025\n";
    else
    {
        int siz = (n + 1) / 2;
        std::vector<std::string> ans;
        std::string s = "1" + std::string(siz - 2, '0') + "8";
        int j = siz - 1;
        while (j > 1)
        {
            ans.emplace_back(s);
            std::swap(s[j - 1], s[j]);
            j--;
        }

        s = "2" + std::string(siz - 2, '0') + "4";
        j = siz - 1;
        while (j > 1)
        {
            ans.emplace_back(s);
            std::swap(s[j - 1], s[j]);
            j--;
        }

        assert(n - std::size(ans) <= 3);

        if (std::size(ans) < n)
            ans.emplace_back("129" + std::string(siz - 3, '0'));
        if (std::size(ans) < n)
            ans.emplace_back("24699" + std::string(siz - 5, '0'));
        if (std::size(ans) < n)
            ans.emplace_back("2571" + std::string(siz - 4, '0'));

        assert(std::size(ans) == n);
        for (auto x : ans)
            std::cout << multiply(x, x) << "\n";
    }
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