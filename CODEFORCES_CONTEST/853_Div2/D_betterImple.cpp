#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::string a, b;
    std::cin >> n >> a >> b;

    std::vector<int> A(n), B(n);
    for (int i = 0; i < n; i++)
        A[i] = a[i] - '0', B[i] = b[i] - '0';

    if (A == B)
    {
        std::cout << "0\n";
        return;
    }

    auto shift = [&](int k)
    {
        assert(k != 0);
        if (k > 0)
        {
            for (int i = 0; i < n - k; i++)
                A[i] ^= A[i + k];
        }
        else
        {
            k *= -1;
            for (int i = n - k - 1; i >= 0; i--)
                A[i + k] ^= A[i];
        }
    };

    int x = std::find(std::begin(A), std::end(A), 1) - std::begin(A);
    int y = std::find(std::begin(B), std::end(B), 1) - std::begin(B);

    if (x == n or y == n)
    {
        std::cout << "-1\n";
        return;
    }

    std::vector<int> ans;
    if (x > y)
    {
        ans.emplace_back(x - y);
        shift(ans.back());
        x = y;
    }

    for (int i = x + 1; i < n; i++)
    {
        if (A[i] != B[i])
        {
            ans.emplace_back(x - i);
            shift(ans.back());
        }
    }

    int end = n - 1;
    while (end >= 0 and A[end] == 0)
        end--;

    for (int i = x; i >= 0; i--)
    {
        if (A[i] != B[i])
        {
            ans.emplace_back(end - i);
            shift(ans.back());
        }
    }

    assert(A == B and std::ssize(ans) <= n);
    
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