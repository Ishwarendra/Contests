#include <iostream>
using namespace std;

int max(int arr[4])
{
    int m = 0;
    for(int i = 1; i < 4; i++){
        if (arr[m] < arr[i]){
            m = i;
        }
    }
    return m;
}

int secondMax(int arr[4], int index)
{
    int m = 0;
    for (int i = 0; i < 4; i++){
        if (i != index and arr[i] > arr[m]){
            m = i;
        }
    }
    return m;
}

int main()
{
    int t;
    cin >> t;
    while (t--){
        int s[4];
        for(int i = 0; i < 4; i++){
            cin >> s[i];
        }
        int m1 = max(s);
        s[m1] = -3;
        int m2 = max(s);
        // cout << m1 << " " << m2 << "\n";
        if ((m1 == 0 or m1 == 1 or m2 == 0 or m2 == 1) and (m1 == 2 or m1 == 3 or m2 == 2 or m2 == 3))
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}