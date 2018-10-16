## Socket Intro
_Just Introduction, more on referred pages_

### Contents
- [What is the meaning of _backlog_ in `listen` ?](#listenbacklog)
- [What is the meaning of `TIME_WAIT`?](#timewait)
- [Say hwo to use `SO_REUSEADDR` and `SO_REUSEPORT`](#soreuseaddr)
- [Different of the return sockfd between `socket` and `accept`](#sockfd)
- [**Blocking** function and **Non-Blocking** function](#blocking)
- [How Linux handle Network packets](#linuxnetpackets)

<a id=listenbacklog></a>
### Listen - _backlog_
- _listen_

> `Unix Network Programming` **Chapter 4.5** _Listen Function_
<http://www.masterraghu.com/subjects/np/introduction/unix_network_programming_v1.3/ch04lev1sec5.html>

```c
int listen(int sockfd, int backlog)
```

1. When a socket is created by the `socket` function, it is assumed to be an active socket, that is, a lient socket that will issue a `connect`. The `listen` function converts an unconnected socket into a passive socket, indicating that the kernel should accept incoming connection requests directed to this socket. In terms of the TCP state transition diagram, the call to `listen` moves the socket from the `CLOSED` state to the `LISTEN` state.

2. The second argument to this function specifies the _**maximum number of connections**_ the kernel should _queue_ for this socket.

- _backlog_

    To understand the `backlog` argument, we must realize that for a given listening socket, the kernel maintains two queues:

<div align=center><img src="../res/listen_queue.png"/ width=650></div>

1. An _**incomplete connection queue**_, which contains an entry for each `SYN` that has arrived from a client for which the server is awaiting completion of the `TCP three-way handshake`. These sockets are in `SYN_RCVD` state.
2. A _**completed connection queue**_, which contains an entry for each client with whom the `TCP three-way handshake` has completed. These sockets are in the `ESTABLISHED` state.
<div align=center><img src="../res/syn_exchange.png"/ width=650></div>

- wrap for socket

    We allow the environment variable`LISTENQ ` to override the value specified by the caller.

```c
137 void
138 Listen (int fd, int backlog)
139 {
140     char    *ptr;

141         /* can override 2nd argument with environment variable */
142     if ( (ptr = getenv("LISTENQ")) != NULL)
143         backlog = atoi (ptr);

144     if (listen (fd, backlog) < 0)
145         err_sys ("listen error");
146 }
```

<a id=timewait></a>
### TIME_WAIT
- _TCP state transition graph_
<div align=center><img src="../res/tcp_state.jpg"/ width=600></div>

> `Unix Network Programming` **Chapter 2.7** _TIME\_WAIT state_
<http://www.masterraghu.com/subjects/np/introduction/unix_network_programming_v1.3/ch02lev1sec7.html><br>
<http://blog.51cto.com/yaocoder/1338567>

- There are two reasons for the `TIME_WAIT` state:
    - To implement TCP's full-duplex connection termination reliably
    - To allow old duplicate segments to expire in the network

<a id=soreuseaddr></a>
### `SO_REUSEADDR` && `SO_REUSEPORT`

> `Unix Network Programming` **Chapter 7.5** _Generic Socket Options_<br>
search `SO_REUSEADDR and SO_REUSEPORT Socket Options`<br>
<http://www.masterraghu.com/subjects/np/introduction/unix_network_programming_v1.3/ch07lev1sec5.html>
<https://stackoverflow.com/questions/14388706/socket-options-so-reuseaddr-and-so-reuseport-how-do-they-differ-do-they-mean-t><br>
allow bind to the same _IP address_ or same _IP port_<br>
 _**call `setsockopt` to set the `SO_REUSEADDR` socket option before calling `bind` in all TCP servers**_

```c
176  int usbip_net_set_reuseaddr(int sockfd)
177  {
178  	const int val = 1;
179  	int ret;
180  
181  	ret = setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
182  	if (ret < 0)
183  		dbg("setsockopt: SO_REUSEADDR");
184  
185  	return ret;
186  }
187  
```

> Definition of `setsockopt`

```c
1880  /*
1881   *	Set a socket option. Because we don't know the option lengths we have
1882   *	to pass the user mode parameter for the protocols to sort out.
1883   */
1884  
1885  SYSCALL_DEFINE5(setsockopt, int, fd, int, level, int, optname,
1886  		char __user *, optval, int, optlen)
1887  {
1888  	int err, fput_needed;
1889  	struct socket *sock;
1890  
1891  	if (optlen < 0)
1892  		return -EINVAL;
1893  
1894  	sock = sockfd_lookup_light(fd, &err, &fput_needed);
1895  	if (sock != NULL) {
1896  		err = security_socket_setsockopt(sock, level, optname);
1897  		if (err)
1898  			goto out_put;
1899  
1900  		if (level == SOL_SOCKET)
1901  			err =
1902  			    sock_setsockopt(sock, level, optname, optval,
1903  					    optlen);
1904  		else
1905  			err =
1906  			    sock->ops->setsockopt(sock, level, optname, optval,
1907  						  optlen);
1908  out_put:
1909  		fput_light(sock->file, fput_needed);
1910  	}
1911  	return err;
1912  }
1913   
```

_then come to `sock_setsockopt` when `level` == `SOL_SOCKET`_

```c
618  /*
619   *	This is meant for all protocols to use and covers goings on
620   *	at the socket level. Everything here is generic.
621   */
622  
623  int sock_setsockopt(struct socket *sock, int level, int optname,
624  		    char __user *optval, unsigned int optlen)
625  {
626  	struct sock *sk = sock->sk;
627  	int val;
628  	int valbool;
629  	struct linger ling;
630  	int ret = 0;
631  
632  	/*
633  	 *	Options without arguments
634  	 */
635  
636  	if (optname == SO_BINDTODEVICE)
637  		return sock_setbindtodevice(sk, optval, optlen);
638  
639  	if (optlen < sizeof(int))
640  		return -EINVAL;
641  
642  	if (get_user(val, (int __user *)optval))
643  		return -EFAULT;
644  
645  	valbool = val ? 1 : 0;
646  
647  	lock_sock(sk);
648  
649  	switch (optname) {
650  	case SO_DEBUG:
651  		if (val && !capable(CAP_NET_ADMIN))
652  			ret = -EACCES;
653  		else
654  			sock_valbool_flag(sk, SOCK_DBG, valbool);
655  		break;
656  	case SO_REUSEADDR:
657  		sk->sk_reuse = (valbool ? SK_CAN_REUSE : SK_NO_REUSE);
658  		break;
659  	case SO_REUSEPORT:
660  		sk->sk_reuseport = valbool;
661  		break;

... ...

```

<a id=sockfd></a>
### Listening socket && connected socket

- accept

> `accept` is called by a TCP server to return the next completed connection from the front of the _**completed connection queue**_ (Figure 4.7). If the completed connection queue is empty, the process is put to sleep (assuming the default of a blocking socket).

```c
#include <sys/socket.h>

int accept (int sockfd, struct sockaddr *cliaddr, socklen_t *addrlen);
```

1. If `accept` is successful, its return value is a **brand-new descriptor** automatically created by the kernel.
2. This new descriptor refers to the TCP connection with the client.

> When discussing `accept`, we call the first argument to accept _**the listening socket**_ (the descriptor created by socket and then used as the first argument to both `bind` and `listen`), and we call the return value from `accept` _**the connected socket**_.

#### _It is important to differentiate between these two sockets_
  
1. A given server normally creates only one _**listening socket**_, which then exists for the lifetime of the server.<br>
2. The kernel creates one _**connected socket**_ for each client connection that is accepted (i.e., for which the TCP `three-way handshake` completes). When the server is finished serving a given client, the _**connected socket**_ is closed.

### Blcoking Function

<a id=linuxnetpackets></a>
### Linux Handle Network Packets
<https://segmentfault.com/a/1190000008836467>