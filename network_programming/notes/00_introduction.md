# Chapter 1 — Introduction

**UNIX Network Programming (Vol. 1)**

---

## 1.1 Introduction — Big Picture

Network programs communicate according to a **protocol**, which defines how messages are exchanged.
Before specifying message formats or system calls, the first design decision is **who initiates communication and how interactions are sequenced**.

Most applications adopt the **client/server model** because it simplifies both protocol logic and implementation.

---

## Client / Server Model

* **Server**

  * Long-running process (daemon)
  * Passively waits for requests
  * Responds to incoming messages

* **Client**

  * Actively initiates communication
  * Sends requests and receives responses

### Basic interaction

```
Client                    Server
  | ---- request ------->   |
  | <--- response --------  |
```

This request/response structure is simple, predictable, and widely used.

---

## Asynchronous Communication (Less Common)

Some applications require **server-initiated messages** (callbacks, push models):

* WebSockets
* Webhooks
* Streaming systems

These increase complexity (state, failures, ordering), so most systems still prefer the basic client/server approach.

---

## Client and Server Scale

* A **client** usually talks to one server at a time
* A **server** commonly serves many clients simultaneously

```
        Client A
           |
Client B --|--> Server
           |
        Client C
```

Handling multiple clients efficiently is a central problem in network programming.

---

## Layered Network Architecture

Applications do not communicate directly; data flows through **protocol layers**.
This book focuses on the **TCP/IP protocol suite**.

### Simplified protocol stack

```
Application   (HTTP, FTP, custom protocols)
-------------------------------------------
Transport     (TCP / UDP)
-------------------------------------------
Network       (IP: IPv4 / IPv6)
-------------------------------------------
Data Link     (Ethernet, Wi-Fi)
```

### Data flow

```
Client app
   ↓
Protocol stack
   ↓
Network
   ↓
Protocol stack
   ↓
Server app
```

* Applications run in **user space**
* TCP/IP is mostly implemented in the **kernel**

---

## Transport and Network Protocols

* **TCP**: reliable, connection-oriented
* **UDP**: unreliable, connectionless
* **IPv4**: long-standing Internet protocol
* **IPv6**: newer version designed to replace IPv4

Both TCP/UDP and IPv4/IPv6 are used throughout the book.

---

## Network Scope

Clients and servers may be:

* On the same **LAN**
* On different networks connected by **routers** and **WANs**

```
Client -- LAN -- Router -- WAN -- Router -- LAN -- Server
```

The Internet is the largest WAN.

---

## What Chapter 1 Covers (Roadmap)

Chapter 1 prepares the foundation for the rest of the book:

### Section Overview

* **1.1 Introduction**
  Core networking concepts and the client/server model

* **1.2 A Simple Daytime Client**
  First complete TCP client example (IPv4)

* **1.3 Protocol Independence**
  Writing clients/servers that work with both IPv4 and IPv6

* **1.4 Error Handling: Wrapper Functions**
  Simplifying system call usage and error checking

* **1.5 A Simple Daytime Server**
  Companion server implementation

* **1.6 Roadmap to Client/Server Examples**
  How examples evolve throughout the book

* **1.7 OSI Model**
  Conceptual reference model for layered networking

* **1.8 BSD Networking History**
  Origins of Unix networking APIs

* **1.9 Test Networks and Hosts**
  Environment used for examples (hosts, routers, OSes)

* **1.10 Unix Standards**
  POSIX and its impact on networking APIs

* **1.11 64-Bit Architectures**
  Data models and portability concerns

* **1.12 Summary**
  Key ideas recap

* **Exercises**
  Reinforce concepts through practice

---

## Key Takeaways

* Network programming starts with **protocol design**
* The **client/server model** dominates because it is simple and robust
* Servers must handle **multiple concurrent clients**
* Communication relies on **layered protocols (TCP/IP)**
* Applications run in user space; networking is largely kernel-managed
* The chapter sets up both **practical code examples** and **theoretical context**


