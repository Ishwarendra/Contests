#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using namespace std;

class Solution 
{
public:
    int countCompleteSubstrings(string s, int k) {
        int n = std::size(s);

        auto check = [&](int len)
        {
            char prev = s[0];
            std::array<int, 26> f{};

            int ans = 0;
            for (int i = 0, j = 0; i <= n - len and j <= n;)
            {
                int ok = 1;
                if (j == n and j - i != len)
                    break;

                if (j - i < len)
                {
                    if (std::abs(s[j] - prev) > 2)
                    {
                        i = j;
                        std::fill(std::begin(f), std::end(f), 0);
                        f[s[i] - 'a']++;
                        prev = s[i];
                        j++;
                    }
                    else
                    {
                        f[s[j] - 'a']++;
                        if (f[s[j] - 'a'] > k)
                        {
                            while (f[s[j] - 'a'] > k)
                            {
                                f[s[i] - 'a']--;
                                i++;
                            }

                            prev = s[j];                         
                            j++;
                            continue;
                        }

                        prev = s[j];
                        j++;
                    }
                }
                else
                {
                    for (int x : f)
                    {
                        if (x != 0 && x != k) 
                        {
                            ok = 0;
                            break;
                        }
                    }

                    ans += ok;
                    f[s[i] - 'a']--;
                    i++;
                }
            }

            return ans;
        };

        int ans = 0;
        for (int i = k; i <= std::min(n, 26 * k); i += k)
            ans += check(i);

        return ans;
    }
};

int main()
{
    int k; cin >> k;
    std::string s;
    std::cin >> s;

    Solution so;
    print(so.countCompleteSubstrings(s,k));
    return 0;
}