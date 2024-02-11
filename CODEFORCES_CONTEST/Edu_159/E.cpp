#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

struct TrieNode
{
    bool flag;
    TrieNode * links[26]{};
    int f;

    TrieNode() { flag = false; f = 0; }
    bool containsKey(char ch) { return links[ch - 'a']; }
    void put(char ch, TrieNode *a) { links[ch - 'a'] = a; }
    TrieNode *get(char ch) { return links[ch - 'a']; }
    void setTerminal() { flag = true; }
};

struct Trie 
{
    TrieNode *root;
    Trie() { root = new TrieNode(); }

    void insert(const std::string &word)
    {
        TrieNode* node = root;

        for (char ch : word)
        {
            if (!node->containsKey(ch))
                node->put(ch, new TrieNode());
            node = node->get(ch);
            node->f++;
        }

        node->setTerminal();
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::string> a(n);
    Trie trie;

    i64 tot = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        trie.insert(a[i]);
        tot += std::size(a[i]);
    }

    for (int i = 0; i < n; i++)
        ans += 1LL * n * std::size(a[i]) + tot;

    for (auto &s : a)
    {
        std::reverse(std::begin(s), std::end(s));
        TrieNode *node = trie.root;
        for (auto &ch : s)
        {
            if (node->containsKey(ch))
            {
                node = node->get(ch);
                ans -= (node->f) * 2LL;
            }
            else
                break;
        }
    }

    std::cout << ans;

    return 0;
}