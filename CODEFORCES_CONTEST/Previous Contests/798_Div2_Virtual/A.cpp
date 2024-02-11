#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
    int n, m, k;
    std::string a, b;
    std::cin >> n >> m >> k >> a >> b;

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    std::string c;
    bool turn_a = 1;
    int op_left = k;

    int i, j;

    for (i = 0, j = 0; i < n and j < m;)
    {
        if (a[i] < b[j])
        {
            if (turn_a and op_left > 0)
                c += a[i++], op_left--;
            else if (turn_a and op_left <= 0)
                c += b[j++], turn_a = 0, op_left = k - 1;
            else if (!turn_a)
            {
                op_left = k - 1;
                c += a[i++];
                turn_a = 1;
            }
        }
        else
        {
            if (!turn_a and op_left > 0)
                c += b[j++], op_left--;
            else if (!turn_a and op_left <= 0)
                c += a[i++], turn_a = 1, op_left = k - 1;
            else if (turn_a)
            {
                op_left = k - 1;
                c += b[j++];
                turn_a = 0;
            }
        }
        // std::cout << c << "\n";
    }  

    std::cout << c << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while(t--)
        solve();
    
    return 0;
}