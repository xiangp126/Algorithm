## Queue
<http://www.cplusplus.com/reference/queue/queue/?kw=queue>
### Template
```c
template <class T, class Container = deque<T> > class queue;
```

### FIFO queue
queues are a type of container adaptor, specifically designed to operate in a `FIFO` context (**first-in first-out**), where elements are inserted into one end of the container and extracted from the other.

queues are implemented as containers adaptors, which are classes that use an encapsulated object of a specific container class as its underlying container, providing a specific set of member functions to access its elements. Elements are pushed into the "back" of the specific container and popped from its "front".

### Methods
> The underlying container may be one of the standard container class template or some other specifically designed container class. This underlying container shall support at least the following operations:

- back
- empty
- front
- pop
- push
- size

The standard container classes `deque` and `list` fulfill these requirements. By default, if no container class is specified for a particular `queue` class instantiation, the standard container `deque` is used.