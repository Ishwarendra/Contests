#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::string s;
    std::cin >> n >> s;

    std::stack<int> st;
    std::vector<int> del(n + 1);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ')' and !st.empty())
        {
            auto start = st.top();
            st.pop();
            del[start]++;
            del[i + 1]--;
        }
        else if (s[i] == '(')
            st.emplace(i);
    }

    for (int i = 1; i <= n; i++)
        del[i] += del[i - 1];

    std::string ans;
    for (int i = 0; i < n; i++)
    {
        if (del[i] == 0)
            ans += s[i];
    }

    std::cout << ans;
    
    return 0;
}