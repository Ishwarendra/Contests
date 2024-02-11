#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

class TrieNode 
{
    bool flag;
    TrieNode* links[26]{};
    std::array<int, 26> cnt{};
public:
    TrieNode()
    {
        flag = false;
    }
    
    bool containsKey(char ch)
    {
        return links[ch - 'a'];
    }
    
    void put(char ch, TrieNode *a)
    {
        links[ch - 'a'] = a;
        cnt[ch - 'a']++;
    }
    
    TrieNode* get(char ch)
    {
        return links[ch - 'a'];
    }
    
    void setTerminal()
    {
        flag = true;
    }
    
    bool isTerminal()
    {
        return flag;
    }

    int getCount(char ch)
    {
        return cnt[ch - 'a'];
    }

    void incCount(char ch)
    {
        cnt[ch - 'a']++;
    }
};

class Trie {
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() 
    {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(std::string word) 
    {
        TrieNode* node = root;
        
        for (char ch : word)
        {
            if (!node->containsKey(ch))
                node->put(ch, new TrieNode());
            else
                node->incCount(ch);
            
            node = node->get(ch);
        }
        
        node->setTerminal();
    }

    int maxPrefix(std::string &t)
    {
        int ans = 0;
        TrieNode *node = root;
        for (char ch : t)
        {
            if (!node->containsKey(ch))
                break;
            else
            {
                int cnt = node->getCount(ch);
                if (cnt > 1)
                    ans++;
                else
                    break;
            }

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

    Trie* trie = new Trie();
    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        trie->insert(a[i]);
    }
    
    for (int i = 0; i < n; i++)
        std::cout << trie->maxPrefix(a[i]) << "\n";
    
    return 0;
}