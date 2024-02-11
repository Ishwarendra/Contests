#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)  
        std::cin >> a[i];

    std::vector<int> tested(n);

    auto good = [&n, &a, &tested](int mid, int q)
    {
        std::fill(std::begin(tested), std::end(tested), 0);
        int ans = 0;

        // leave last mid element
        for (int i = 0; i < n - mid; i++)
        {
            // free to do
            if (a[i] <= q)
            {
                tested[i] = 1;
                ans++;
            }
        }

        for (int i = n - mid; i < n; i++)
        {
            if (a[i] <= q)
                tested[i] = 1, ans++;
            else
                q--, tested[i] = 1, ans++;

            if (q < 0)
                return 0;
        }

        return ans;
    };

    int left = 1, right = n, ans = -1;
    std::string todo;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        int cur_ans = good(mid, q);
        if (cur_ans)
        {
            left = mid + 1;
            if (cur_ans >= ans)
            {
                ans = cur_ans;
                todo.clear();
                
                for (int i = 0; i < n; ++i)
                    todo += char(tested[i] + '0');
            }
        }
        else
            right = mid - 1;
    }

    std::cout << todo << "\n";
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