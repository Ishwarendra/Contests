#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

struct TrieNode
{
    TrieNode* nxt[26] {};
    int cnt[26] {};
    bool ended;

    TrieNode() : ended(false) 
    {
        std::fill(cnt, cnt + 26, 0);
        std::fill(nxt, nxt + 26, nullptr);
    }
    bool contains(char ch) { return !!nxt[ch - 'a']; }
    void put(char ch, TrieNode *a) { nxt[ch - 'a'] = a; }
    TrieNode* get(char ch) { return nxt[ch - 'a']; }
    void setTerminal() { ended = true; }
    bool isTerminal() { return ended; }
    void incrementCount(char ch) { cnt[ch - 'a']++; }
};

struct Trie
{
    TrieNode *root;
    int n;

    Trie(int n) : n(n) { root = new TrieNode(); }
    void insert(std::string s)
    {
        TrieNode *node = root;
        for (char ch : s)
        {
            if (!node->contains(ch))
                node->put(ch, new TrieNode());
            node->incrementCount(ch);
            node = node->get(ch);
        }
        node->setTerminal();
    }
    bool find(std::string s)
    {
        TrieNode *node = root;
        for (char ch : s)
        {
            if (!node->contains(ch))
                return false;
            node = node->get(ch);
        }

        return node->isTerminal();
    }
    std::vector<int> getCommon(const std::string &s)
    {
        TrieNode *node = root;
        std::vector<int> ans;
        for (char ch : s)
        {
            if (!node->contains(ch))
                return ans;
            
            ans.emplace_back(node->cnt[ch - 'a']);
            node = node->get(ch);
        }
        
        return ans;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    
    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    
    Trie trie(n);
    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto b = trie.getCommon(a[i]);
        int sz = std::size(b);
        
        for (int i = 1; i < sz; i++)
            b[i - 1] -= b[i];
        
        trie.insert(a[i]);
        for (int i = 0; i < sz; i++)
            ans += 1LL * (i + 1) * b[i];
    }
    
    std::cout << ans;

    return 0;
}