# OSI model

what is OSI ? how it is related to others.
Open Systems Interconnection model, is a conceptual framework that standardizes the functions of a telecommunication or computing system into seven layers.

#### Layer 1

- Modem:
- Hub:

#### Layer 2

- Switch: ASCI chip,
- WAP:

#### Layer 3

- Multilayer Switch:
- Router:

#### Security devices

- Firewall: (software or hardware );
  - Stateless Inspection
  - Stateful Inspection
- IVS: Intrusion Detection Systems
  Do not prevent but alerts
  - Signature Based
  - Anomaly Based
  - Policy based
- IPS: Intrusion Prevention Systems
  Try to stop a breach or attack, First active response.
  - Signature Based
  - Anomaly Based
  - Policy based
- VPN Constrator :
  - work on L1, L2, L3, L7:

#### Optimization and Performance devices

- Load balancer
- Proxy Server: filtering, caching, un-auth accesses, etc.

### VPN: Virtual Private Network

Types of VPN

- Site to Site
- remote-accesses
- Host-to-host ( SSL/TLS VPN )

### Protocols used by VPN

- IPsec
  - AH
  - ESP
    mode: Transparent
    : Tunnel
  - GRE : also encrypt 1 to many cast and broadcast transimition as IPsec cant
  - Point to point.
  - TLS: replace SSL
  - SSL:

### Network Accesses devices

- NIC:
- Radius: Remote authentication, AAA,

#### other survices and application

- RAS: Remote Accesses Service
- Web Services : Creating means across cross comm
- Voice over IP

### DHCP

what is IP, Who gives it IP ?

- Static IP : Admin gives subnet mask, gateway, DNS server location,
- DHCP server: listen for request

  - DHCP working.
    Upon boot system request of Discovery packet at 255.255.255.255.67 UDP.
    DHCP response an offer packet at 68.
    Acknowledgement packet is sent to DHCP.
    DHCP on receives this acknowledgement packet it sends requester another acknowledgement package with IP and other important stuffs.
    PC then updates its IP and reflects IP information.

  - Components and processes of DHCP: - port used - Address Scope ( rules for static ip addresses, range etc) - Leases - options DNS, Time Server, default gateway,
    NOTE: DHCP relay, and IP helper

### DNS Server

Domain Name System, Maps human names to IP addresses, Fully qualified Domain.

- Levels of DNS

  - Local DNS Server
  - Top Level Domain ( .com, .edu, .io etc),
  - Root Server ( super server having all dns info to give it to all TLD servers.)

- Server Types

  - Authoritative Servers: ( actual server that is configured to hold that record )
  - Non-Authoritative Servers: ( 2nd 3rd record not original but have record copy )

- Types of DNS Records.

  - A ( hostnames to ipv4 )
  - AAAA ( host name to ipv6 )
  - CNAME ( alias like .edu, .in, .org to same )
  - PTR ( point to caninocal name)
  - MX ( maps the email server to email server, how transmission take place.)

- Dynamic DNS
- DDNS : updates updated ip to Domain name. Read more about this

### Network Addresses Translation

Routing non-routabel addresses, used to reserve ipv4, route with nat enabled.

- Working
  Static: assign local and public IP
  Dynamic: used reusable Pool.

#### Port Addresses Translation

solving problem in above, ip addresses are avalable and used now we can use port numbers to firther change what is communicatoin to whome.

#### NAT Terminalogs

- Inside local addresses.
- inside global addresses.
- Outside global addresses.
- Outside local addresses.

### WAN Technologies

What is WAN and LAN ?

Legacy

- Public Switch Telephone Network
- Dial Up ( P2P wired connection )
- ISDN ( P2P wireless connection )
  Digital
- xDSL ( digital Wan Technologies using PSTIN )
- SDSL ( same upload and download speed )
- ADSL ( slow upload but high download )
- VDSL ( high bit rate and is very fast )
  Broadband
- Coaxial cable Network: TV cables connection.
- Fiver optics ( uses light to communicate SONET standards, multiplexing, increase bandwidth.)
  Witeless
- GSM/CDMA WAN ( cellular networking, 1G, 2G, 3G: starting WAN, 4G(LTE , WiMAX) )
- WiMAX Connection

WiMAX WAN Connection: Uses Microwave for communication, need Line of site. 4G compatable and LTE
Satellite WAN Connection: Uses Microwave radio relay. Latency issue.
