## Vector
<http://www.cplusplus.com/reference/vector/vector/?kw=vector>

### Template
```c
template < class T, class Alloc = allocator<T> > class vector;
```

### Methods

- push_back
- reverse
- insert
- erase
- pop_back
- front
- back
- clear

##### erase
```c
iterator erase (const_iterator position);
iterator erase (const_iterator first, const_iterator last);
```

#### insert
```c
iterator insert (const_iterator position, const value_type& val);
iterator insert (const_iterator position, size_type n, const value_type& val);
template <class InputIterator>
iterator insert (const_iterator position, InputIterator first, InputIterator last);
iterator insert (const_iterator position, value_type&& val);
iterator insert (const_iterator position, initializer_list<value_type> il);
```

> insert from front

```c
vector<int> path;
path.insert(path.begin(), 3);
```