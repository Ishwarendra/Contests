#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string ray, ben, kevin;
    std::cin >> ray;

    int n = ray.length();

    std::vector<char> suff_min(n);
    suff_min.back() = ray.back();

    for (int i = n - 2; i >= 0; i--)
        suff_min[i] = std::min(suff_min[i + 1], ray[i]);

    for (int i = 0; i < n; i++)
    {
        while (ben.size() and ben.back() <= suff_min[i])
            kevin += ben.back(), ben.pop_back();
        if (suff_min[i] == ray[i])
            kevin += ray[i];
        else
            ben += ray[i];
    }

    while (!ben.empty())
    {
        kevin += ben.back();
        ben.pop_back();
    }

    std::cout << kevin << "\n";

    return 0;
}