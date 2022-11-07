## Design HashSet
### Illustrate
<https://leetcode.com/problems/design-hashset/>

```c
Design a HashSet without using any built-in hash table libraries.

To be specific, your design should include these functions:

add(value): Insert a value into the HashSet.
contains(value) : Return whether the value exists in the HashSet or not.
remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.
```

### Example
```c
MyHashSet hashSet = new MyHashSet();
hashSet.add(1);
hashSet.add(2);
hashSet.contains(1);    // returns true
hashSet.contains(3);    // returns false (not found)
hashSet.add(2);
hashSet.contains(2);    // returns true
hashSet.remove(2);
hashSet.contains(2);    // returns false (already removed)

Note:

All values will be in the range of [0, 1000000].
The number of operations will be in the range of [1, 10000].
Please do not use the built-in HashSet library.
```

### Using Separate Chaining Technique to simulate a real HashSet

### [find](https://en.cppreference.com/w/cpp/algorithm/find)
First Version

```cpp
template<class InputIt, class T>
constexpr InputIt find(InputIt first, InputIt last, const T& value)
{
    for (; first != last; ++first) {
        if (*first == value) {
            return first;
        }
    }
    return last;
}
```

### Code
```cpp
class MyHashSet {
public:
    MyHashSet() {
        // Choose a good prime as the bucket's number.
        buckets = 12289;
        hashSet = vector<list<int>>(buckets);
    }

    void add(int key) {
        int kIndex = hash(key);
        if (!contains(key)) {
            hashSet[kIndex].push_back(key);
        }
    }

    void remove(int key) {
        int kIndex = hash(key);
        auto iter = search(key);
        if (iter != hashSet[kIndex].end()) {
            hashSet[kIndex].erase(iter);
        }
    }

    bool contains(int key) {
        int kIndex = hash(key);
        auto iter = search(key);
        return (iter != hashSet[kIndex].end());
    }

private:
    int buckets;
    vector<list<int>> hashSet;

    int hash(int key) {
        return key % buckets;
    }

    list<int>::iterator search(int key) {
        int kIndex = hash(key);
        return find(hashSet[kIndex].begin(), hashSet[kIndex].end(), key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
```

- Here we do no need to use `find_if`

```cpp
    list<int>::iterator search(int key) {
        int kIndex = hash(key);
        auto pFunc = [&key](int p) {
            return p == key;
        };
        return find_if(hashSet[kIndex].begin(), hashSet[kIndex].end(), pFunc);
    }
```
