## STL - Priority Queue

> Priority queues are a type of container adaptors, specifically designed such that its first element is always the **greatest** of the elements it contains, according to some strict weak ordering criterion.

_Default **Max-Peak** Heap_

- empty
- size
- top
- push
- pop

### Template
    template <class T, class Container = vector<T>,
    class Compare = less<typename Container::value_type> > class priority_queue;

### Sample    
```c
priority_queue<int> que;
que.push(3);

while (!que.empty()) {
    cout << que.top();
    que.pop();
}
```