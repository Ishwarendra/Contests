#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v) for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
     cout << a << " ";
     err(++it, args...);
};

void solve()
{
     int n; cin >> n;
     unordered_set<string> twoLen, threeLen;
     bool oneLen = false; 
     bool possible = false;
     for(int i = 0; i < n; i++)
     {
          string s; cin >> s;
          if (s.length() == 1)
               oneLen = true;
          else if (s.length() == 2)
          {
               // yx_
               for(int i = 97; i <= 122; i++){
                    string cur;
                    cur += s[1], cur += s[0],
                    cur += (char)i;

                    if (threeLen.find(cur) != threeLen.end())
                    {
                         possible = true;
                         break;
                    }
               }
               // yx
               string cur;
               cur += s[1], cur += s[0];
               if (twoLen.find(cur) != twoLen.end())
                    possible = true;
               
               // self-palin
               if (s[1] == s[0])
                    possible = true;

               twoLen.insert(s);
          }
          else
          {
               // zy
               string cur;
               cur += s[2], cur += s[1];
               // print(cur);
               if (twoLen.find(cur) != twoLen.end())
                    possible = true;
               
               cur += s[0];
               // zyx
               if (threeLen.find(cur) != threeLen.end())
                    possible = true;

               // self-palinf
               if (s[2] == s[0])
                    possible = true;

               threeLen.insert(s);
          }
     }

     if (possible or oneLen)
          cout << "YES\n";
     else
          cout << "NO\n";
}

int main()
{
     FIO;
     int t = 1;
     cin >> t;
     while(t--)
         solve();
     return 0;
}