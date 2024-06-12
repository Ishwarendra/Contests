#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

char query(int i, int j, int k, int l)
{
    std::cout << "? " << i << " " << j << " " << k << " " << l << std::endl;
    char ch;
    std::cin >> ch;

    return ch;
    // int x = a[i] | a[j];
    // int y = a[k] | a[l];

    // return (x > y ? '>' : x < y ? '<' : '=');
}

void answer(int i, int j)
{
    std::cout << "! " << i << " " << j << std::endl;
}

void solve()
{  
    int n;
    std::cin >> n;

    int max_id = 0;
    for (int i = 1; i < n; i++)
    {
        auto ch = query(max_id, max_id, i, i);
        if (ch == '<')
            max_id = i;
    }

    std::vector<int> id(1);
    for (int i = 1; i < n; i++)
    {
        auto ch = query(max_id, i, max_id, id.back());
        if (ch == '>')
            id.clear();

        if (ch == '=' or ch == '>')
            id.emplace_back(i);
    }

    int min_id = id[0];
    for (int i = 1; i < std::size(id); i++)
    {
        auto ch = query(min_id, min_id, id[i], id[i]);
        if (ch == '>')
            min_id = id[i];
    }

    answer(max_id, min_id);
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