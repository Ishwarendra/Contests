#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

class Solution {
public:
    std::vector<std::vector<int>> mergeSimilarItems(std::vector<std::vector<int>>& items1, std::vector<std::vector<int>>& items2) {
        
        std::map<int, int> m;
        int n = std::size(items1), m = std::size(items2);

        for (auto i : items1)
            m[i[0]] += i[1];
        for (auto i : items2)
            m[i[0]] += i[1];

        std::vector<std::vector<int>> ans;
        for (auto [num, v] : m)
            ans.push_back({num, v});

        return ans;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    
    
    return 0;
}