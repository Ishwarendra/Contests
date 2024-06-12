#include <iostream>
#include <set>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    int n = std::size(s);

    std::set<std::string> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
            ans.emplace(s.substr(i, j - i + 1));
    }

    std::cout << std::size(ans);
}
