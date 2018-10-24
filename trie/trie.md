## Trie

<https://www.hackerearth.com/zh/practice/data-structures/advanced-data-structures/trie-keyword-tree/tutorial/>

### Pronunciation
Tries are an extremely special and useful data-structure that are based on the `prefix of a string`. They are used to represent the **Retrieval** of data and thus the name Trie.

`/ˈtriː/` (as "tree") tree or `Pre-fix Tree`

### Property

<div align=center><img src=../res/trie.png width=70%></div>

* 根节点不包含字符，除根节点外每一个节点都只包含一个字符。
* 从根节点到某一节点，路径上经过的字符连接起来，为该节点对应的字符串。
* 每个节点的所有子节点包含的字符都不相同。

### Advantages

_As a replacement for other data structures_

> As discussed below, a trie has a number of advantages over binary search trees. A trie can also be used to replace a `hash table`, over which it has the following advantages:

* Looking up data in a trie is faster in the worst case, **O(m)** time (where m is the length of a search string), compared to an imperfect hash table.An imperfect hash table can have `key collisions`. A key collision is the hash function mapping of different keys to the same position in a hash table.The worst-case lookup speed in an imperfect hash table is O(N) time, but far more typically is O(1), with O(m) time spent evaluating the hash.
* There are no collisions of different keys in a trie.
* Buckets in a trie, which are analogous to hash table buckets that store key collisions, are necessary only if a single key is associated with more than one value.
* There is no need to provide a hash function or to change hash functions as more keys are added to a trie.
* A trie can provide an **alphabetical ordering** of the entries by key.

### Drawbacks
> Tries do have some drawbacks as well:

* Trie lookup can be slower in some cases than hash tables, especially if the data is directly accessed on a hard disk drive or some other secondary storage device where the random-access time is high compared to main memory.
* Some keys, such as **floating point numbers**, can lead to long chains and prefixes that are not particularly meaningful. Nevertheless, a bitwise trie can handle standard IEEE single and double format floating point numbers.
* Some tries can require more space than a hash table, as memory may be allocated for each character in the search string, rather than a single chunk of memory for the whole entry, as in most hash tables.