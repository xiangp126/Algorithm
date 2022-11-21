## Design HashMap
### Illustrate
<https://leetcode.com/problems/design-hashmap/><br>
<https://soulmachine.gitbooks.io/system-design/content/cn/hashmap.html>

```
Design a HashMap without using any built-in hash table libraries.

To be specific, your design should include these functions:

put(key, value) : Insert a (key, value) pair into the HashMap. If the value already exists in the HashMap, update the value.
get(key): Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
remove(key) : Remove the mapping for the value key if this map contains the mapping for the key.
```

### Example
```c
MyHashMap hashMap = new MyHashMap();
hashMap.put(1, 1);
hashMap.put(2, 2);
hashMap.get(1);            // returns 1
hashMap.get(3);            // returns -1 (not found)
hashMap.put(2, 1);          // update the existing value
hashMap.get(2);            // returns 1
hashMap.remove(2);          // remove the mapping for 2
hashMap.get(2);            // returns -1 (not found)

Note:

All keys and values will be in the range of [0, 1000000].
The number of operations will be in the range of [1, 10000].
Please do not use the built-in HashMap library.
```

### Using Separate Chaining Technique to simulate a real Hashmap
[Why is it best to use a prime number as a mod in a hashing function?](https://cs.stackexchange.com/questions/11029/why-is-it-best-to-use-a-prime-number-as-a-mod-in-a-hashing-function)<br>
[good hash table primes](https://planetmath.org/goodhashtableprimes)<br>
<https://github.com/Mohammed-Shoaib/Coding-Problems/blob/master/LeetCode/Solutions/LC0706.cpp>

#### [find_if](https://en.cppreference.com/w/cpp/algorithm/find)
The third version

```cpp
template<class InputIt, class UnaryPredicate>
constexpr InputIt find_if(InputIt first, InputIt last, UnaryPredicate p)
{
    for (; first != last; ++first) {
        if (p(*first)) {
            return first;
        }
    }
    return last;
}
```

#### [Lambda Expression](https://en.cppreference.com/w/cpp/language/lambda)
#### [C++ 中的 Lambda 表达式](https://learn.microsoft.com/zh-cn/cpp/cpp/lambda-expressions-in-cpp?view=msvc-170)
Constructs a closure: an unnamed function object capable of capturing variables in scope.

```cpp
[&key](pair<int, int>& p) {
    return p.first == key;
});
```

This Lambda Expression will act as the `UnaryPredicate` passed into `find_if`.

### Code

```cpp
class MyHashMap {
public:
    MyHashMap() {
        // Choose a good prime as the number of the buckets.
        N = 12289;
        // Bug Point: Initialize the hashtable.
        hashtable.resize(N);
    }

    ~MyHashMap() {

    }

    void put(int key, int value) {
        int keyHash = hash(key);
        auto iter = search(key);
        if (iter != hashtable[keyHash].end()) {
            // Update the value as the description requires.
            iter->second = value;
        } else {
            hashtable[keyHash].push_back(make_pair(key, value));
        }
    }

    int get(int key) {
        int keyHash = hash(key);
        auto iter = search(key);
        if (iter != hashtable[keyHash].end()) {
            return iter->second;
        } else {
            return -1;
        }
    }

    void remove(int key) {
        int keyHash = hash(key);
        auto iter = search(key);
        if (iter != hashtable[keyHash].end()) {
            hashtable[keyHash].erase(iter);
        }
    }

private:
    // number of buckets.
    int N;
    vector<list<pair<int, int> > > hashtable;

    // A function defined in the body of a class declaration
    // is implicitly an inline function.
    int hash(int key) {
        return key % N;
    }

    list<pair<int, int> >::iterator search(int key) {
        int keyHash = hash(key);
        return find_if(hashtable[keyHash].begin(), hashtable[keyHash].end(),
                       [&key](pair<int, int> &p) { return p.first == key; });
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
```

or you can use an named variable to represent the lambda function to make it more clearly.

```cpp
    list<pair<int, int>>::iterator search(int key) {
        int kIndex = hash(key);
        # Take care of the ; at the end of a Lamda Expression.
        auto jFunc = [&key](pair<int, int> &pair) {
            return pair.first == key;
        };
        return find_if(hashMap[kIndex].begin(), hashMap[kIndex].end(), jFunc);
    }
```

Or even you may use the following block of code to replace the Lambda expression.

```cpp
    list<pair<int, int> >::iterator search(int key) {
        int keyHash = hash(key);
        auto iter = hashtable[keyHash].begin();
        while (iter != hashtable[keyHash].end()) {
            if (iter->first == key) {
                return iter;
            }
            ++iter;
        }
        return iter;
    }
```
