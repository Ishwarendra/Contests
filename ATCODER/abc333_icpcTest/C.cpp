#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<i64> a;
    i64 x = 0;
    int lim = 17;
    for (int i = 0; i < lim; i++)
    {
        a.emplace_back(x * 10 + 1);
        x = x * 10 + 1;
    }

    std::set<i64> s;
    for (int i = 0; i < lim; i++)
    {
        for (int j = 0; j < lim; j++)
        {
            for (int k = 0; k < lim; k++)
                s.emplace(a[i] + a[j] + a[k]);
        }
    }

    n--;
    while (n--)
        s.erase(std::begin(s));

    std::cout << *std::begin(s);
}