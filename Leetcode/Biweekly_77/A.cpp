#include <bits/stdc++.h>
using namespace std;

class Solution {
	bool isPrefix(string &s, string &p)
	{
		if (s.length() < p.length())
			return false;

		for (int i = 0; i < p.length(); i++)
		{
			if (s[i] != p[i])
				return false;
		}

		return true;
	}
public:
	int countPrefixes(vector<string>& words, string s) {
		int cnt = 0;
		for (auto i : words)
			if (isPrefix(s, i))
				cnt++;
			
		return cnt;
	}
};

int main()
{

	return 0;
}