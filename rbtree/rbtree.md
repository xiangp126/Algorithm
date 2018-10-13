## Red-Black Tree
### Property
> In addition to the requirements imposed on a binary search tree
the following must be satisfied by a red–black tree:

- each node is either red or black.
- the root is black. This rule is sometimes omitted.
- all leaves (_`NIL`_) are black.
- if a node is red, then both its children are black.
- every path from a given node to any of its descendant _`NIL`_ nodes contains the same number of black nodes.

### Routine Result
```c
RB-Tree Size: 1000000

RB-Tree Height: 24

Insert Time Elapsed: 4370 ms 846 us

Search Time Elapsed: 0 ms 4 us
Node key = 16623759665, data = River872339
```

### License
The [MIT](./LICENSE.txt) License (MIT)