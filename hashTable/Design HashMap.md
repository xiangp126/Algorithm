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

### Code - Array
_need not implement hash function_

```c
class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        N = 1000001;
        hashMap = new int[N];
        // sizeof(hashMap) = 8
        // cout << "sizeof(hashMap) = " << sizeof(hashMap) << endl;
        // all initialized to -1
        memset(hashMap, -1, N * sizeof(int));
    }

    ~MyHashMap() {
        delete [] hashMap;
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        if (key >= getSize()) {
            return;
        }
        hashMap[key] = value;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        if (key >= getSize()) {
            return -1;
        }
        return hashMap[key];
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        if (key >= getSize()) {
            return;
        }
        hashMap[key] = -1;
    }

    int getSize() {
        return N;
    }

private:
    // index starts from 0
    int *hashMap;
    int N;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
```

### Code - Vector
_need not implement hash function_

```c
class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {

    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        if (key >= hashMap.size()) {
            for (int i = hashMap.size(); i <= key; ++i) {
                hashMap.push_back(-1);
            }
        }
        hashMap[key] = value;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        if (key >= hashMap.size()) {
            return -1;
        }
        return hashMap[key];
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        if (key >= hashMap.size()) {
            return;
        }
        hashMap[key] = -1;
    }

private:
    vector<int> hashMap;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
```
