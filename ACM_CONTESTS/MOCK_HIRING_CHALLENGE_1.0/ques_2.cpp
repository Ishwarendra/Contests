#include <bits/stdc++.h>
using namespace std;
#define long long int

int convert(string &s)
{
     int hours = (s[0] - '0') * 10 + (s[1] - '0');
     int minutes = (s[2] - '0') * 10 + (s[3] - '0');
     return hours * 60 + minutes;
}

int32_t main()
{
     ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
     int tt;
     cin >> tt;
     while (tt--)
     {
          int n;
          cin >> n;
          vector<int> arrival(n), departure(n);
          for (int &x : arrival)
          {
               string s;
               cin >> s;
               x = convert(s);
          }
          for (int &x : departure)
          {
               string s;
               cin >> s;
               x = convert(s);
          }

          sort(arrival.begin(), arrival.end());
          sort(departure.begin(), departure.end());

          int i = 0, j = 0, cur_platforms = 0, min_platforms = 0;
          while (i < n and j < n)
          {
               if (arrival[i] <= departure[j])
                    cur_platforms++,
                    i++;

               else
                    cur_platforms--, j++;

               min_platforms = max(min_platforms, cur_platforms);
          }

          cout << min_platforms << "\n";
     }
     return 0;
}