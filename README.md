# NetForge

A C++ networking project built from scratch on Linux to explore how computer networks work at a lower level.

## About

**NetForge** is a hands-on C++ project focused on networking concepts, Linux, and low-level programming.

The goal is to gradually build networking functionality from the ground up instead of relying entirely on high-level tools and libraries.

## Goals

* Learn practical network programming with C++
* Understand how data moves through a network
* Work with Linux networking APIs
* Explore sockets and protocols
* Build networking utilities from scratch
* Improve C++ and systems-programming skills
* Develop a deeper understanding of networking beyond Packet Tracer

## Tech Stack

* **Language:** C++
* **OS:** Linux / Ubuntu
* **Compiler:** g++
* **Version Control:** Git & GitHub

## Project Status

🚧 **In Development**

NetForge is currently in its early development stage. Features will be added incrementally as the project grows.

## Planned Features

The exact feature set will evolve during development, but the project may eventually include:

* ✅ Basic TCP client
* ✅ Basic TCP server
* ⬜ UDP communication
* ✅ IP and port handling
* ✅ Connection management
* ⬜ Packet/data inspection
* ⬜ Network diagnostics
* ⬜ Custom networking utilities
* 🔄 Logging and debugging
* ⬜ More advanced networking functionalitys

## Current Progress
Phase 4: Client Management & Logging

* ⬜ Task 1 — Create a dedicated client information structure
* ⬜ Task 2 — Track connected clients with IP address and port
* ⬜ Task 3 — Record client connection timestamps
* ⬜ Task 4 — Implement server event logging
* ⬜ Task 5 — Log client connections and disconnections
* ⬜ Task 6 — Keep client state and logs thread-safe
* ⬜ Task 7 — Verify logs and client tracking with multiple clients
* ⬜ Task 8 — Test the complete client management system

## Installing System

```bash
git clone https://github.com/M-Faiq-7R/net-forge.git
cd net-forge
```

## Building

Compile the project using `g++`:

For Server: 

```bash
g++ src/server/*.cpp -o server
```

For Client: 

```bash
g++ src/client/*.cpp -o client
```

Run it with:

```bash
./server
```
```bash
./client
```

## Philosophy

> **Don't just use the network. Understand it.**

NetForge is primarily a learning project. Instead of immediately using existing networking tools, the project aims to recreate and understand networking concepts through implementation.

## Author

**Muhammad Faiq**

Built with C++ on Linux.
