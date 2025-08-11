# Computer Networks for DevOps - Detailed Syllabus

## 📚 Course Structure: 7 Modules (12 Weeks)

---

## 📖 **Module 1: Networking Fundamentals**

_Duration: Week 1-2_

### **Chapter 1.1: Introduction to Computer Networks**

- **1.1.1** What is a Computer Network?
  - Definition and purpose
  - Network vs Internet vs World Wide Web
  - Client-server vs peer-to-peer models
- **1.1.2** Types of Networks by Scope
  - **PAN (Personal Area Network)**: Bluetooth, USB connections
  - **LAN (Local Area Network)**: Home/office networks, switches
  - **MAN (Metropolitan Area Network)**: City-wide networks, cable TV
  - **WAN (Wide Area Network)**: Internet, corporate networks
- **1.1.3** Network Topologies
  - **Physical Topologies**: Star, bus, ring, mesh, hybrid
  - **Logical Topologies**: How data flows vs physical connections
  - **DevOps Relevance**: Data center network design, redundancy planning

### **Chapter 1.2: Network Models and Standards**

- **1.2.1** OSI 7-Layer Model (Conceptual Framework)
  - **Layer 1 - Physical**: Cables, signals, hubs, repeaters
  - **Layer 2 - Data Link**: MAC addresses, switches, frames, Ethernet
  - **Layer 3 - Network**: IP addresses, routers, routing, packets
  - **Layer 4 - Transport**: TCP/UDP, ports, segments, reliability
  - **Layer 5 - Session**: Session management, NetBIOS, SQL sessions
  - **Layer 6 - Presentation**: Encryption, compression, data formats
  - **Layer 7 - Application**: HTTP, FTP, SSH, DNS, applications
- **1.2.2** TCP/IP Model (Practical Implementation)
  - **Network Interface Layer**: Ethernet, WiFi, device drivers
  - **Internet Layer**: IP (IPv4/IPv6), ICMP, ARP, routing
  - **Transport Layer**: TCP, UDP, port numbers
  - **Application Layer**: HTTP, SSH, FTP, DNS, SMTP
- **1.2.3** Protocol Encapsulation and De-encapsulation
  - How data travels down the stack (encapsulation)
  - How data travels up the stack (de-encapsulation)
  - Headers and trailers at each layer

### **Chapter 1.3: IP Addressing Fundamentals**

- **1.3.1** IPv4 Addressing
  - **Structure**: 32-bit addresses, dotted decimal notation
  - **Address Classes**: Class A, B, C, D, E (historical context)
  - **Private vs Public IP Ranges**:
    - Class A: 10.0.0.0/8 (10.0.0.0 - 10.255.255.255)
    - Class B: 172.16.0.0/12 (172.16.0.0 - 172.31.255.255)
    - Class C: 192.168.0.0/16 (192.168.0.0 - 192.168.255.255)
  - **Special Addresses**: Loopback (127.0.0.1), broadcast, multicast
- **1.3.2** Subnetting and CIDR
  - **Subnet Masks**: Purpose and calculation
  - **CIDR Notation**: /24, /16, /8 prefixes
  - **Subnetting Examples**:
    - 192.168.1.0/24 = 254 usable hosts
    - 192.168.1.0/25 = 126 usable hosts (2 subnets)
    - 192.168.1.0/26 = 62 usable hosts (4 subnets)
  - **VLSM (Variable Length Subnet Masking)**: Efficient IP allocation
- **1.3.3** IPv6 Addressinc
  c **Structure**: 128-bit addresses, hexadecimal notation
  - **Address Types**: Unicast, multicast, anycast
  - **Special Addresses**: Loopback (::1), link-local (fe80::/10)
  - **IPv6 vs IPv4**: Comparison and migration strategies

### **Chapter 1.4: Core Network Services**

- **1.4.1** DNS (Domain Name System)
  - **Purpose**: Human-readable names to IP addresses
  - **DNS Hierarchy**: Root servers, TLD servers, authoritative servers
  - **Record Types**:
    - **A Record**: Maps domain to IPv4 address
    - **AAAA Record**: Maps domain to IPv6 address
    - **CNAME Record**: Alias for another domain
    - **MX Record**: Mail exchange servers
    - **TXT Record**: Text information, SPF, DKIM
    - **NS Record**: Name server records
  - **DNS Resolution Process**: Recursive vs iterative queries
  - **DNS Caching**: TTL, local caches, performance impact
- **1.4.2** DHCP (Dynamic Host Configuration Protocol)
  - **Purpose**: Automatic IP address assignment
  - **DHCP Process**: DORA (Discover, Offer, Request, Acknowledge)
  - **DHCP Options**: Default gateway, DNS servers, NTP servers
  - **Reservations**: MAC-based IP assignment
  - **DHCP Relay**: Cross-subnet DHCP service
- **1.4.3** ARP (Address Resolution Protocol)
  - **Purpose**: IP to MAC address mapping
  - **ARP Process**: Request and reply mechanism
  - **ARP Table**: Local cache of IP-MAC mappings
  - **ARP Spoofing**: Security implications

### **Chapter 1.5: Network Hardware and Infrastructure**

- **1.5.1** Physical Layer Devices
  - **Cables**: Ethernet (Cat5e, Cat6), fiber optic, coaxial
  - **Hubs**: Collision domains, half-duplex communication
  - **Repeaters**: Signal amplification and regeneration
- **1.5.2** Data Link Layer Devices
  - **Switches**: MAC address tables, full-duplex, VLANs
  - **Bridges**: Segment networks, reduce collision domains
  - **Access Points**: Wireless connectivity, SSID, security
- **1.5.3** Network Layer Devices
  - **Routers**: Routing tables, inter-network communication
  - **Layer 3 Switches**: Routing + switching capabilities
  - **Default Gateway**: Router interface for subnet egress
- **1.5.4** Advanced Network Devices
  - **Firewalls**: Packet filtering, stateful inspection, NAT
  - **Load Balancers**: Traffic distribution, health checks
  - **Proxy Servers**: Forward/reverse proxy, content filtering

### **Chapter 1.6: Network Address Translation (NAT)**

- **1.6.1** NAT Concepts
  - **Purpose**: Private to public IP translation, IPv4 conservation
  - **NAT Types**: Static NAT, dynamic NAT, PAT (Port Address Translation)
- **1.6.2** Port Forwarding
  - **Concept**: External port to internal service mapping
  - **Use Cases**: Web servers, SSH access, gaming
  - **Security Implications**: Exposing internal services

---

## 📖 **Module 2: Protocol Deep Dive**

_Duration: Week 3-4_

### **Chapter 2.1: Transport Layer Protocols**

- **2.1.1** TCP (Transmission Control Protocol)
  - **Characteristics**: Connection-oriented, reliable, ordered delivery
  - **TCP Header Structure**: Sequence numbers, acknowledgments, flags
  - **3-Way Handshake**: SYN, SYN-ACK, ACK connection establishment
  - **4-Way Handshake**: Connection termination process
  - **Flow Control**: Window size, congestion control
  - **Error Detection and Recovery**: Checksums, retransmission
- **2.1.2** UDP (User Datagram Protocol)
  - **Characteristics**: Connectionless, unreliable, fast
  - **UDP Header Structure**: Source/destination ports, length, checksum
  - **Use Cases**: DNS, DHCP, streaming media, gaming
- **2.1.3** Port Numbers and Well-Known Services
  - **Port Ranges**: Well-known (0-1023), registered (1024-49151), dynamic (49152-65535)
  - **Common Ports**:
    - HTTP (80), HTTPS (443), SSH (22), FTP (20/21)
    - DNS (53), DHCP (67/68), SMTP (25), POP3 (110), IMAP (143)
    - Telnet (23), SNMP (161), NTP (123), LDAP (389)

### **Chapter 2.2: Application Layer Protocols**

- **2.2.1** HTTP (HyperText Transfer Protocol)
  - **HTTP Methods**: GET, POST, PUT, DELETE, PATCH, HEAD, OPTIONS
  - **HTTP Headers**: Content-Type, Authorization, User-Agent, Accept
  - **Status Codes**:
    - **1xx**: Informational responses
    - **2xx**: Success (200 OK, 201 Created, 204 No Content)
    - **3xx**: Redirection (301 Moved, 302 Found, 304 Not Modified)
    - **4xx**: Client errors (400 Bad Request, 401 Unauthorized, 404 Not Found)
    - **5xx**: Server errors (500 Internal Error, 502 Bad Gateway, 503 Service Unavailable)
  - **HTTP/1.1 vs HTTP/2 vs HTTP/3**: Protocol evolution
- **2.2.2** HTTPS (HTTP Secure)
  - **TLS/SSL Handshake**: Certificate exchange, encryption negotiation
  - **Certificate Validation**: CA trust chain, certificate expiration
  - **Encryption Methods**: Symmetric vs asymmetric encryption
- **2.2.3** SSH (Secure Shell)
  - **SSH Protocol**: Authentication, encryption, port forwarding
  - **Key-Based Authentication**: Public/private key pairs, ssh-agent
  - **SSH Tunneling**: Local, remote, and dynamic port forwarding
  - **SCP/SFTP**: Secure file transfer protocols

### **Chapter 2.3: Network Control and Management Protocols**

- **2.3.1** ICMP (Internet Control Message Protocol)
  - **Purpose**: Error reporting and network diagnostics
  - **ICMP Message Types**: Echo request/reply, destination unreachable, time exceeded
  - **Tools Using ICMP**: ping, traceroute, pathping
- **2.3.2** SNMP (Simple Network Management Protocol)
  - **SNMP Components**: Manager, agent, MIB (Management Information Base)
  - **SNMP Operations**: GET, SET, TRAP notifications
  - **SNMP Versions**: v1, v2c, v3 (security improvements)
- **2.3.3** NTP (Network Time Protocol)
  - **Time Synchronization**: Importance in distributed systems
  - **NTP Hierarchy**: Stratum levels, reference clocks
  - **Time Accuracy**: Precision, accuracy, stability

---

## 📖 **Module 3: Linux Network Configuration & Troubleshooting**

_Duration: Week 5-6_

### **Chapter 3.1: Linux Network Interfaces**

- **3.1.1** Network Interface Management
  - **Interface Types**: Ethernet (eth0, enp0s3), loopback (lo), wireless (wlan0)
  - **Interface States**: UP/DOWN, configuration persistence
  - **Network Manager**: nmcli, systemd-networkd, traditional ifconfig
- **3.1.2** IP Configuration Commands\*\*
  - **ip command suite**: Modern Linux networking tool
  - **Interface Configuration**: `ip addr`, `ip link`, `ip route`
  - **Legacy Commands**: ifconfig, route (deprecated but still used)
- **3.1.3** Network Namespaces\*\*
  - **Concept**: Network isolation within single kernel
  - **Use Cases**: Container networking, network testing
  - **Management**: Creating, deleting, executing in namespaces

### **Chapter 3.2: Routing and Gateway Configuration**

- **3.2.1** Routing Table Management\*\*
  - **Default Gateway**: 0.0.0.0/0 route configuration
  - **Static Routes**: Persistent route configuration
  - **Route Metrics**: Priority and path selection
- **3.2.2** Advanced Routing Concepts\*\*
  - **Policy-Based Routing**: Multiple routing tables
  - **Source-Based Routing**: Route selection based on source
  - **Load Balancing**: Multi-path routing

### **Chapter 3.3: DNS Configuration and Troubleshooting**

- **3.3.1** DNS Client Configuration\*\*
  - **/etc/resolv.conf**: DNS server configuration
  - **systemd-resolved**: Modern DNS resolver
  - **DNS Search Domains**: Automatic domain completion
- **3.3.2** Local DNS Resolution\*\*
  - **/etc/hosts**: Local hostname resolution
  - **Host Resolution Order**: /etc/nsswitch.conf configuration
  - **DNS Caching**: Local cache management

---

## 📖 **Module 4: Network Security and Firewalls**

_Duration: Week 7-8_

### **Chapter 4.1: Linux Firewall Systems**

- **4.1.1** iptables Fundamentals\*\*
  - **Tables**: filter, nat, mangle, raw
  - **Chains**: INPUT, OUTPUT, FORWARD, PREROUTING, POSTROUTING
  - **Targets**: ACCEPT, DROP, REJECT, LOG, MASQUERADE
  - **Rule Structure**: Match criteria and actions
- **4.1.2** Common Firewall Rules\*\*
  - **Allow SSH**: Secure remote access rules
  - **Web Server Rules**: HTTP/HTTPS access
  - **NAT Configuration**: Internet sharing, port forwarding
- **4.1.3** Advanced Firewall Features\*\*
  - **Stateful Tracking**: Connection state monitoring
  - **Rate Limiting**: DDoS protection, connection limits
  - **Logging**: Security event logging and analysis

### **Chapter 4.2: Network Security Scanning**

- **4.2.1** Port Scanning with nmap\*\*
  - **Scan Types**: TCP SYN, TCP connect, UDP scans
  - **Host Discovery**: Network reconnaissance
  - **Service Detection**: Version and OS fingerprinting
- **4.2.2** Vulnerability Assessment\*\*
  - **Security Auditing**: Identifying open services
  - **Compliance Checking**: Security policy enforcement
  - **Penetration Testing**: Authorized security testing

---

## 📖 **Module 5: Cloud and DevOps Networking**

_Duration: Week 9-10_

### **Chapter 5.1: Virtual Private Clouds (VPC)**

- **5.1.1** VPC Architecture Design\*\*
  - **Subnets**: Public vs private subnet strategies
  - **Availability Zones**: Multi-AZ deployment patterns
  - **Route Tables**: Traffic flow control
- **5.1.2** Internet Connectivity\*\*
  - **Internet Gateways**: Public subnet internet access
  - **NAT Gateways**: Private subnet internet access
  - **Elastic IPs**: Static public IP addressing

### **Chapter 5.2** Load Balancing and High Availability\*\*

- **5.2.1** Load Balancer Types\*\*
  - **Layer 4 (Network) Load Balancers**: Transport layer balancing
  - **Layer 7 (Application) Load Balancers**: HTTP/HTTPS balancing
  - **Global Load Balancing**: Multi-region traffic distribution
- **5.2.2** Health Checks and Failover\*\*
  - **Health Check Configuration**: Monitoring backend services
  - **Auto Scaling Integration**: Dynamic capacity management
  - **Disaster Recovery**: Multi-region failover strategies

### **Chapter 5.3: Cloud Security**

- **5.3.1** Security Groups\*\*
  - **Stateful Firewalls**: Instance-level access control
  - **Rule Configuration**: Protocol, port, source specifications
  - **Best Practices**: Least privilege principle
- **5.3.2** Network Access Control Lists (NACLs)\*\*
  - **Stateless Filtering**: Subnet-level access control
  - **Rule Evaluation**: Numbered rule processing
  - **Security Groups vs NACLs**: When to use each

---

## 📖 **Module 6: Container and Kubernetes Networking**

_Duration: Week 11_

### **Chapter 6.1: Docker Networking**

- **6.1.1** Docker Network Drivers\*\*
  - **Bridge Network**: Default container networking
  - **Host Network**: Direct host network access
  - **Overlay Network**: Multi-host container networking
  - **None Network**: Isolated containers
- **6.1.2** Container Communication\*\*
  - **Port Mapping**: Exposing container services
  - **Inter-Container Communication**: Same host vs cross-host
  - **Docker Compose Networking**: Multi-container applications

### **Chapter 6.2: Kubernetes Networking Model**

- **6.2.1** Pod Networking\*\*
  - **Flat Network Architecture**: Pod-to-pod communication
  - **CNI (Container Network Interface)**: Network plugin standard
  - **Popular CNI Plugins**: Calico, Flannel, Cilium, Weave Net
- **6.2.2** Kubernetes Services\*\*
  - **ClusterIP**: Internal cluster communication
  - **NodePort**: External access via node ports
  - **LoadBalancer**: Cloud provider integration
  - **ExternalName**: External service mapping
- **6.2.3** Ingress Controllers\*\*
  - **HTTP/HTTPS Routing**: Path and hostname-based routing
  - **TLS Termination**: SSL certificate management
  - **Popular Controllers**: Nginx, Traefik, HAProxy, Istio Gateway

---

## 📖 **Module 7: Monitoring and Observability**

_Duration: Week 12_

### **Chapter 7.1: Network Monitoring Fundamentals**

- **7.1.1** Key Network Metrics\*\*
  - **Bandwidth Utilization**: Interface capacity monitoring
  - **Latency**: Round-trip time measurement
  - **Packet Loss**: Network reliability metrics
  - **Connection States**: TCP connection monitoring
- **7.1.2** Monitoring Tools\*\*
  - **Command Line**: iftop, vnstat, netstat, ss
  - **Real-time Monitoring**: netdata, htop network section
  - **Historical Analysis**: RRDtool, InfluxDB time series

### **Chapter 7.2: Prometheus and Grafana**

- **7.2.1** Metrics Collection\*\*
  - **Node Exporter**: System and network metrics
  - **Custom Metrics**: Application-specific monitoring
  - **Service Discovery**: Dynamic target configuration
- **7.2.2** Visualization and Alerting\*\*
  - **Grafana Dashboards**: Network performance visualization
  - **Alert Rules**: Proactive issue detection
  - **Notification Channels**: Slack, email, PagerDuty integration

### **Chapter 7.3: Log Analysis**

- **7.3.1** Network Log Sources\*\*
  - **System Logs**: /var/log/messages, syslog
  - **Application Logs**: Web server, database logs
  - **Security Logs**: Authentication, firewall logs
- **7.3.2** Log Aggregation\*\*
  - **ELK Stack**: Elasticsearch, Logstash, Kibana
  - **Loki + Grafana**: Lightweight log aggregation
  - **Centralized Logging**: Multi-host log collection

---

## 🎯 **Learning Outcomes by Module**

### **Module 1 Outcomes**

- Configure IP addressing and subnetting schemes
- Understand network device roles and placement
- Troubleshoot basic connectivity issues
- Design simple network topologies

### **Module 2 Outcomes**

- Analyze network protocols using packet capture
- Configure secure communication channels
- Troubleshoot application-layer connectivity
- Implement HTTP-based services

### **Module 3 Outcomes**

- Configure Linux network interfaces and routing
- Manage network namespaces for isolation
- Troubleshoot DNS resolution issues
- Implement network redundancy

### **Module 4 Outcomes**

- Configure comprehensive firewall rules
- Perform network security assessments
- Implement access control policies
- Respond to security incidents

### **Module 5 Outcomes**

- Design scalable cloud network architectures
- Implement load balancing and failover
- Configure cloud security controls
- Integrate hybrid cloud connectivity

### **Module 6 Outcomes**

- Deploy containerized applications with proper networking
- Configure Kubernetes cluster networking
- Implement service discovery and load balancing
- Secure container communications

### **Module 7 Outcomes**

- Implement comprehensive network monitoring
- Create actionable dashboards and alerts
- Analyze network performance trends
- Optimize network infrastructure

---

## 📋 **Assessment Methods**

### **Practical Labs (60%)**

- Hands-on configuration exercises
- Troubleshooting scenarios
- Real-world problem solving

### **Theory Examinations (25%)**

- Concept understanding tests
- Protocol knowledge assessment
- Architecture design questions

### **Projects (15%)**

- End-to-end network implementation
- Documentation and presentation
- Peer review and feedback

---

## 📚 **Required Resources**

### **Software/Tools**

- Linux virtual machines (Ubuntu/CentOS)
- Cisco Packet Tracer or GNS3
- Wireshark packet analyzer
- Cloud account (AWS/Azure/GCP free tier)
- Docker and Kubernetes (minikube)

### **Hardware Requirements**

- Computer with virtualization support
- Minimum 8GB RAM, 100GB storage
- Reliable internet connection
- Optional: Raspberry Pi for physical networking labs**Remember**: Networking is the foundation of DevOps. Master these concepts, and you'll be able to design, deploy, and troubleshoot any modern infrastructure! 🌟
