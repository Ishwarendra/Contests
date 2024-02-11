#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

vector<int> arr(1e5 + 3);
void make_arr()
{
    for(int i = 0; i < 100003; i++)
        arr[i] = i;
}

void solve()
{
    int n; cin >> n;
    if ((n/2) & 1){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    vi arr1, arr2;

    int i = 1, j = n;
    while(abs(j - i) > 1)
    {
        arr1.push_back(i), arr1.push_back(j);
        i++, j--;
        arr2.push_back(i), arr2.push_back(j);
        i++, j--;
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    for(auto i : arr1)
        cout << i << " ";
    cout << "\n";
    for(auto i : arr2)
        cout << i << " ";
    cout << "\n";
}

int main()
{
    // make_arr();
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}