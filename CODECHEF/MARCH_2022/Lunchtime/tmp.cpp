#include <bits/stdc++.h>
using namespace std;

int cardPackets(vector<int> cardTypes)
{
    int n = cardTypes.size();
    
    sort(cardTypes.begin(), cardTypes.end());
    
    int ans = 0;
    int g = 0;
    
    for (int i = 0; i < n; i++)
        g = __gcd(g, cardTypes[i]);
    
    if (g != 1)
        return 0;
    
    for (int i = 0; i < n; i++)
    {
        if (cardTypes[i] % 2 == 1)
            ans++;
    }
    
    return ans;
}

int main()
{
    vector<int> a {4, 7, 5, 11, 15};
    vector<int> b {3, 6, 9, 12};
    
    cout << cardPackets(a) << " " << cardPackets(b);
    return 0; ;
}    