#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s;
    std::cin >> s;

    int n =s.size();
    std::vector<long long> pref(n);
    pref[0] = s[0] - '0';

    for (int i = 1; i < n; i++)
        pref[i] += pref[i - 1] + (s[i] - '0');

    std::string ans;
    long long carry = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        long long sum = pref[i] + carry;
        ans += std::to_string(sum % 10);
        carry = sum / 10;
    }

    if (carry != 0)
        ans += std::to_string(carry);

    std::reverse(ans.begin(), ans.end());

    std::cout << ans << "\n";
    
    return 0;
}