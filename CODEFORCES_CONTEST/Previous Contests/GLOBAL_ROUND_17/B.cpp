#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

/*
** find the smallest i for which a[i] != a[n - i - 1] (0-based)
** if we remove all instance of a[i] or a[n - i - 1] then does it become palindrome if no then answer is NO
** why check only these two??
** if suppose we delete x (!= a[i] or a[n - i - 1]) and a becomes palindrome
** then a[i] must be equal a[n - i - 1] but this is against our assumption
** Thus, if deleting a[i] and a[n - i -1] doesn't make a palindrome then it won't ever become one 
*/

// 1, 4, 3, 4, 1, 1
bool ignore_k_palin(vector<int> &a, int k)
{
    int start = 0, end = a.size() - 1;
    while(start <= end)
    {
        while (a[start] == k) start++;
        while (a[end] == k) end--;

        if (start <= end and a[start] != a[end])
            return false;
        start++, end--;
    }   

    return true;
}

void solve()
{
    int n; cin >> n;
    vi a(n);
    for(int &x: a)
        cin >> x;
    
    int start = 0, end = n - 1;

    while(start <= end)
    {
        if (a[start] != a[end])
            break;
        start++, end--;
    } 

    if (start > end)
    {
        cout << "YES\n";
    }
    else if (ignore_k_palin(a, a[start]) or ignore_k_palin(a, a[end]))
        cout << "YES\n";
    else 
        cout << "NO\n";
}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
    // vector<int> a {1, 4, 3, 4, 1, 1};
    // cout << ignore_k_palin(a, 1);
}