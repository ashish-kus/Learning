# Introduction

### What is Network ?

### why Bother about Network ?

### Network VS Internet VS WWW

### Introduction: Basic terminologies

1. Network
2. Node
3. Devices
4. Firewall
5. ISP
6. Types of Network Architecture

- Client-Server
- Peer-2-Peer

1. Router
2. Hub
3. Bridge
4. switch

#### Logical Topologies: How data flows vs physical connections

### Client-Server Architecture

Client-server architecture is a network model in which two main entities — clients and servers — communicate with each other to complete specific tasks or share data.

    Client: The client initiates requests, waits for the server’s response, and displays it to the user. For example, a web browser acts as a client when it requests a website.
    Server: The server processes these requests, retrieves the relevant information, and sends it back to the client. For example, a web server responds with website data when a browser requests it.

#### Types or Architecture

1. Two Tier Client and Server.
2. Three Tire : middleware.
3. N-Tire : multi layer architecture.

[Resource](https://medium.com/nerd-for-tech/client-server-architecture-explained-with-examples-diagrams-and-real-world-applications-407e9e04e2d1)

### Peer to Peer Architecture

A peer-to-peer (P2P) architecture consists of a decentralized network of peers - nodes that are both clients and servers. P2P networks distribute the workload between peers, and all peers contribute and consume resources within the network without the need for a centralized server.
Some use of P2P: File sharing, Instant Messaging, collaboration tools, High Performance computing.

### 1.1.2 Types of Network by Scope

PAN : (Personal Area Network)
LAN : (Local Area Network)
MAN : (Metropolitan Area Network)
WAN : (Wide Area Network)

[Resource](https://www.simplilearn.com/tutorials/networking-tutorial/importance-of-types-of-networks-lan-man-wan)

### 1.1.3 Network Topology

1. Bus Topology: All devices are connected to single central cable.
2. Star Topology: All nodes are connected to a single switch or hub.
3. Ring Topology: All devices are connected in loop, each node connected to 2 other devices and data travel in one direction.
4. Mesh Topology: All devices are connected to all other devices in the network.
5. Hybrid Topology: combination of 2 or more Topology.

## 1.2 Network Models and Standards

### 1.2.1 OSI model

| Layer | Name             | DevOps-Relevant Concepts                                           |
| ----- | ---------------- | ------------------------------------------------------------------ |
| 7     | **Application**  | HTTP, SSH, FTP, DNS, APIs (curl, wget), browser tools              |
| 6     | **Presentation** | Encryption (TLS/SSL), data formats (JSON, XML)                     |
| 5     | **Session**      | Persistent connections (cookies, session timeouts)                 |
| 4     | **Transport**    | TCP/UDP, ports, firewalls, load balancers, health checks, Segments |
| 3     | **Network**      | IP addresses, routing, CIDR, subnets, ping, traceroute, packets    |
| 2     | **Data Link**    | MAC addresses, ARP, VLANs (mostly handled by sysadmins)            |
| 1     | **Physical**     | Cables, switches, NICs (rarely touched by DevOps)                  |

[Resource](https://aws.amazon.com/what-is/osi-model/)
[Response](https://www.cloudflare.com/learning/ddos/glossary/open-systems-interconnection-model-osi/)

### 1.2.2 TCP/IP model

| **TCP/IP Layer**      | **OSI Layer(s)**                   | **Function**                           | **Common Protocols/Examples**          |
| --------------------- | ---------------------------------- | -------------------------------------- | -------------------------------------- |
| **Application**       | Application, Presentation, Session | Provides services to user applications | HTTP, HTTPS, FTP, SSH, DNS, SMTP, SNMP |
| **Transport**         | Transport                          | End-to-end communication & reliability | TCP, UDP                               |
| **Internet**          | Network                            | Logical addressing and routing         | IP (IPv4/IPv6), ICMP, ARP              |
| **Network Interface** | Data Link + Physical               | Physical transmission of data          | Ethernet, Wi-Fi, PPP, Device drivers   |

![TCP/IP](https://www.ibm.com/docs/en/ssw_aix_72/network/figures/comma33.jpg)
[Resource](https://www.ibm.com/docs/en/aix/7.2.0?topic=protocol-tcpip-protocols)

### 1.2.3 Protocol Encapsulation and De-encapsulation

- How data travels down the stack (encapsulation)
- How data travels up the stack (de-encapsulation)
- Headers and trailers at each layer

## 1.3 IP Addressing Fundamentals

- **Structure**: 32-bit addresses, dotted decimal notation
- **Address Classes**:(historical context)
  - A : large network, Foirst bit is zero. 8bit Network ID
  - B : Medium Size Network, 10 as first bot of network ID, 18 bit Network ID
  - C : start with 192. , frst bit are 110, 24bit network id for small networks.
  - D : 1110 first 4 bit of NIC used for multi cast Network
  - E : start with 1111, experimental use only start with 240.0.0.0
- **Private vs Public IP Ranges**:
  - Class A: 10.0.0.0/8 (10.0.0.0 - 10.255.255.255) -> used for large organizations and data centers.
  - Class B: 172.16.0.0/12 (172.16.0.0 - 172.31.255.255) -> used bu medium size organizations.
  - Class C: 192.168.0.0/16 (192.168.0.0 - 192.168.255.255) -> used for local and small networks like home, office.
- **Special Addresses**: Loopback (127.0.0.1), broadcast, multicast

```
[Laptop]        [Phone]         [TV]
  |               |              |
192.168.0.2   192.168.0.3   192.168.0.4  <-- Private IPs
        \        |        /
         [ Home Router: 192.168.0.1 ]
                     |
             Public IP: 203.0.113.5
                     |
              [ Internet Backbone ]

```
