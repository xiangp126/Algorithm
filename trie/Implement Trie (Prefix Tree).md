## Implement Trie (Prefix Tree)
### Illustrate
<https://leetcode.com/problems/implement-trie-prefix-tree>

Implement a trie with `insert`, `search`, and `startsWith` methods.

Note:

* You may assume that all inputs are consist of lowercase letters `a-z`.
* All inputs are guaranteed to be non-empty strings.

### Example

```c
Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");
trie.search("app");     // returns true
```

### Simplest Trie Node
```c
class TrieNode {
public:
    TrieNode *child[26];
    bool isEndWord;
    // init Trie Node
    TrieNode() : isEndWord(false) {
        for (auto &ch : child) {
            ch = NULL;
        }
    }
};
```

### Code - _Simplest Trie Node_

_simple but easy to understand_

```c
class TrieNode {
public:
    TrieNode *child[26];
    bool isEndWord;
    // init Trie Node
    TrieNode() {
        isEndWord = false;
        for (auto &ch : child) {
            ch = NULL;
        }
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        // Another pointer points to root
        TrieNode *ptr = root;
        // walk through word
        for (auto ch : word) {
            if (ptr->child[ch - 'a'] == NULL) {
                TrieNode *node = new TrieNode();
                ptr->child[ch - 'a'] = node;
            }
            ptr = ptr->child[ch - 'a'];
        }
        // put end of word flag
        ptr->isEndWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *ptr = root;
        // walk through word
        for (auto ch : word) {
            if (ptr->child[ch - 'a'] != NULL) {
                ptr = ptr->child[ch - 'a'];
            } else {
                return false;
            }
        }
        // check if this char was end of word
        return ptr->isEndWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *ptr = root;
        // walk through word
        for (auto ch : prefix) {
            if (ptr->child[ch - 'a'] != NULL) {
                ptr = ptr->child[ch - 'a'];
            } else {
                return false;
            }
        }
        return true;
    }

private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
```
