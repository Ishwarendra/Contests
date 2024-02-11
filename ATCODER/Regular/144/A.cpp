#include <bits/stdc++.h>

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

    int n;
    std::cin >> n;

    std::string ans;
    int take = -1;
    for (int i = 1; i < 5; i++)
    {
        if (n % i == 0)
        {
            take = i;
            break;
        }
    }

    std::cout << 2 * n << "\n";
    int sz = n / take;

    while (sz--)
        ans += std::to_string(take);

    n = std::size(ans);
    std::string real;

    for (int i = n - 1; i >= 0;)
    {
        int num = 0;
        if (i == 0)
        {
            if (ans.size())
                real += ans.front();
            
            break;
        }

        while (i > 0 and num < 5)
        {
            char dig1 = ans[i], dig2 = ans[i - 1];
            i--;

            if (dig1 + dig2 - 2 * '0' >= 5)
                break;

            ans.pop_back();
            ans.pop_back();

            num = dig1 + dig2 - 2 * '0';
            ans += std::to_string(num);
        }

        real += std::to_string(num);
        ans.pop_back();
    }

    std::reverse(std::begin(real), std::end(real));
    std::cout << real << "\n";

    return 0;
}