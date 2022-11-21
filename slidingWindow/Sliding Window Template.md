## Sliding Window Template

### Reference
[我写了首诗，把滑动窗口算法变成了默写题](https://labuladong.github.io/algo/1/12/)

### Template
```cpp
size_t left = 0, right = 0;

while (right < s.size()) {
    // expand the window
    window.insert(s[right]);
    ++right;

    while (window needs shrink) {
        // shrink the window
        window.erase(s[left]);
        ++left;
    }
}
```
