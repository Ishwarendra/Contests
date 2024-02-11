#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;
using namespace std;

string solve(string num, int k) {
    string str = "";
    for (char x : num) {
        while (str.length() && str.back() > x && k) {
            str.pop_back();  k--;
        }

        if (str.length() || x != '0') {str.push_back(x);}
    }

    while (str.length() && k--) { str.pop_back(); }
    if (str.empty()) {return "0";}
    return str;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::cout << (solve(s, n));

    return 0;
}