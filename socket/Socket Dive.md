## Socket Dive

### Contents
- [what is the meaning of backlog in _listen_ ?](#listenbacklog)
- [what is TIME_WAIT and what to do with it ?](#timewait)
- [different of the return sockfd between `socket` and `accept`](#sockfd)

<a id=listenbacklog></a>
### Listen - _backlog_

> `Unix Network Programming` Chapter 4.5 Listen Function

```c
int listen(int sockfd, int backlog)
```

1. when a socket is created by the `socket` function, it is assumed to be an active socket, that is, a lient socket that will issue a `connect`. The `listen` function converts an unconnected socket into a passive socket, indicating that the kernel should accept incoming connection requests directed to this socket. In terms of the TCP state transition diagram, the call to `listen` moves the socket from the `CLOSED` state to the `LISTEN` state.

2. The second argument to this function specifies the _**maximum number of connections**_ the kernel should _queue_ for this socket.

<a id=timewait></a>
### TIME_WAIT
<http://blog.51cto.com/yaocoder/1338567>

- _TCP state transition graph_
<div align=center><img src="../res/tcp_state.jpg"/ width=700></div>

<a id=sockfd></a>
### Socket Fd Difference