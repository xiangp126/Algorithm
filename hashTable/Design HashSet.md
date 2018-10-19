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

### Code - Array
_need not implement hash function_

**_use `bool` instead of `int`_**

```c
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        N = 1000001;
        hashSet = new bool[N];
        // sizeof(bool) = 1
        cout << "sizeof(bool) = " << sizeof(bool) << endl;
        memset(hashSet, false, N * sizeof(bool));
    }

    void add(int key) {
        if (key >= getSize()) {
            return;
        }
        hashSet[key] = true;
    }

    void remove(int key) {
        if (key >= getSize()) {
            return;
        }
        hashSet[key] = false;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        if (key >= getSize()) {
            return false;
        }
        return hashSet[key];
    }

    int getSize() {
        return N;
    }

private:
    bool *hashSet;
    int N;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */
```

### Code - Vector
_need not implement hash function_

**_use `bool` instead of `int`_**

```c
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {

    }

    void add(int key) {
        if (key >= hashSet.size()) {
            for (int i = hashSet.size(); i <= key; ++i)  {
                hashSet.push_back(false);
            }
        }
        hashSet[key] = true;
    }

    void remove(int key) {
        if (key >= hashSet.size()) {
            return;
        }
        hashSet[key] = false;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        if (key >= hashSet.size()) {
            return false;
        }
        return hashSet[key];
    }

private:
    vector<bool> hashSet;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */
```
