## Longest Word in Dictionary
### Illustrate
<https://leetcode.com/problems/longest-word-in-dictionary>

Given a list of strings `words` representing an English Dictionary, find the longest word in `words` that can be built **one character at a time by other words in `words`**. If there is more than one possible answer, return the longest word with the smallest lexicographical `/ˌleksikəu'ɡræfikəl/
` order.

If there is no answer, return the empty string.

Note:

* All the strings in the input will only contain lowercase letters.
* The length of words will be in the range [1, 1000].
* The length of words[i] will be in the range [1, 30].

### Example

```c
Input: 
words = ["w","wo","wor","worl", "world"]
Output: "world"
Explanation: 
The word "world" can be built one jcharacter at a time by "w", "wo", "wor", and "worl".

Input: 
words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
Output: "apple"
Explanation: 
Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
```

### Concept

```c
string substr (size_t pos = 0, size_t len = npos) const;
```

### Code
```c
class Solution {
public:
    string longestWord(vector<string>& words) {
        /*
         * sort from small length to large length
         * a, ac, ae, ap
         * apa, app, appl, appe
         * apple
         */
        sort(words.begin(), words.end());
        string str;
        unordered_set<string> uSet;
        // walk through words
        for (auto word : words) {
            if (word.size() == 1 ||
                    uSet.find(word.substr(0, word.size() - 1)) != uSet.end()) {
                // only replace when size of word > (not >=) than that of str
                str = word.size() > str.size() ? word : str;
                // insert into set
                uSet.insert(word);                
            }
        }
        return str;
    }
};
```

### Debug

_for example 2, will err with `apply` rather than `apple`_

```c
str = str.size() > word.size() ? str : word;
```