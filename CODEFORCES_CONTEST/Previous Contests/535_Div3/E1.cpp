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

void err(istream_iterator<string> it) {};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
	cout << a << " ";
	err(++it, args...);
};
/*
 ----------------------------------------------------
 ----------------------------------------------------
 ------ ---------- DOESN'T WORK ------------ --------
 ----------------------------------------------------
 ---------------------------------------------------- 
*/

int get_min(vi &a)
{
	return *min_element(all(a));
}

int get_max(vi &a)
{
	return *(max_element(all(a)));
}

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
	if (m == 0)
	{
		cout << best_ans << "\n0\n";
		return;
	}


	set<int> used_best;

	vi original = a;

	for (int i = 0; i < m; i++)
	{
		set<int> used_cur;

		int start = segments[i][0], end = segments[i][1];

		int cur_ans = get_max(a) - get_min(a);
		
		for (int idx = start; idx <= end; idx++)
			a[idx]--;
		
		used_cur.insert(segments[i][2]);
		int tmp_ans = get_max(a) - get_min(a);
			
		if (cur_ans <= tmp_ans)
			cur_ans = tmp_ans;
		else
		{
			for(int id = start; id <= end; id++)
				a[id]++;
			used_cur.erase(segments[i][2]);
			continue;
		}

		// Find which segments are good for ith one
		for (int j = 0; j < m; j++)
		{
			if (i == j)
				continue;
			
			vi tmp = a;
			
			// Try this segment
			start = segments[j][0], end = end = segments[j][1];

			for (int idx = start; idx <= end; idx++)
				a[idx]--;

			int now = get_max(a) - get_min(a);

			if (cur_ans < now) // No harm
			{
				cur_ans = now;
				used_cur.insert(segments[j][2]);
			}
			else // go back to prev state
				a = tmp;
		}
		
		// Found all goodie seg for i
		if (best_ans < cur_ans)
		{
			best_ans = cur_ans;
			used_best = used_cur;
		}
		
		// revert a
		a = original;
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
	while (t--)
		solve();
}