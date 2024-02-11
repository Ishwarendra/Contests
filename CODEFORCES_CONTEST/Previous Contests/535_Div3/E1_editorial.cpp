	#include <bits/stdc++.h>
	using namespace std;

	#define FIO       ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
	#define all(a)    ((a).begin()), ((a).end())
	#define printarr  (v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
	#define log(v)    for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
	#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

	using vi   =  vector<int>;
	using vvi  =  vector<vector<int>>;
	using vll  =  vector<long long>;
	using vvll =  vector<vector<long long>>;
	using ll   =  long long;
	using ld   =  long double;
	using ull  =  unsigned long long;
	using pii  =  pair<int, int>;
	using pll  =  pair<long long, long long>;

	void err(istream_iterator<string> it){};
	template <typename T, typename... Args>
	void err(istream_iterator<string> it, T a, Args... args)
	{
	    cout << a << " ";
	    err(++it, args...);
	};

	void solve()
	{
		int n, m; cin >> n >> m;

		vi a(n);
		vvi segments(m, vi(3));

		int maxi = INT_MIN, mini = INT_MAX;

		for (auto &x : a)
		{
			cin >> x;
			maxi = max(x, maxi);
			mini = min(x, mini);
		}

		for (int i = 0; i < m; i++)
		{
			cin >> segments[i][0] >> segments[i][1];
			segments[i][2] = i + 1;

			segments[i][0]--, segments[i][1]--;
		}

		int best_ans = maxi - mini;
		set<int> used_best;
		
		for(int i = 0; i < n; i++)
		{
			vi factor(n + 1);
			set<int> used_cur;
			
			for(int j = 0; j < m; j++)
			{
				int start = segments[j][0], end = segments[j][1];
				if (i < start or i > end) // maximum won't decrease
				{
					used_cur.insert(segments[j][2]);
					factor[start]--, factor[end + 1]++;
				}
			}
			
			for(int i = 1; i < n; i++)
				factor[i] += factor[i - 1];
			
			int cur_max = INT_MIN, cur_min = INT_MAX;
			
			for(int i = 0; i < n; i++)
			{
				cur_max = max(cur_max, a[i] + factor[i]);
				cur_min = min(cur_min, a[i] + factor[i]);
			}
			
			int cur_ans = cur_max - cur_min;
			
			if (cur_ans >= best_ans)
			{
				best_ans = cur_ans;
				used_best = used_cur;
			}
		}
		
		cout << best_ans << "\n" << used_best.size() << "\n";
		
		if (used_best.size())
		{
			log(used_best);
		}
		else
			cout << "\n";
	}

	int main()
	{
	    FIO;
	    int t = 1;
	    // cin >> t;
	    while(t--)
	        solve();
	}