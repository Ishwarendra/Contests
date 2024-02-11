#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

pair<int, int> get_val(int x)
{
    if (x == 1)
        return {2, 0};
    if (x == 2 or x == 3)
        return {1, 1};
    else    
        return {0, 2};
}

int main()
{
    int open = 0, close = 0;
    vi v(4);
    for(int i = 0; i < 4; i++)
        cin >> v[i];
            
    if ((v[2] > 0 and v[0] == 0) or (v[0] != v[3]))
    {
        cout << false;
        return 0;
    }
    // cout << open <<' ' << close << ' ';
    (open == close) ? (cout << true) : (cout << false);

    return 0;
}