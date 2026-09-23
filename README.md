# ⚡ NetForge

> A C++ networking project built from scratch on Linux to explore how computer networks work at a lower level.

---

## 🧠 About

**NetForge** is a hands-on C++ networking project focused on:

* TCP sockets
* Concurrent clients
* Multithreading
* Synchronization
* Low-level Linux networking

The project was built incrementally, starting from a basic TCP client and server and evolving into a multi-client network application.

The primary goal was **not** to build a production-ready networking framework, but to understand how networking concepts actually work by implementing them directly in C++.

---

## 🚀 Features

* ✅ TCP client-server communication
* ✅ Multiple simultaneous client connections
* ✅ Concurrent client handling using C++ threads
* ✅ Dynamic message exchange between clients and server
* ✅ Server responses to clients
* ✅ Broadcasting messages between connected clients
* ✅ Client connection and disconnection handling
* ✅ Thread-safe management of connected clients
* ✅ Mutex-based synchronization for shared client data
* ✅ Graceful client termination
* ✅ Server-side logging
* ✅ Timestamped server events
* ✅ Linux socket programming using the POSIX socket API

---

## 🏗️ Architecture

The project is separated into components with different responsibilities:

```text
NetForge
│
├── Client
│   ├── Establishes TCP connection
│   ├── Sends messages
│   └── Receives broadcast messages
│
└── Server
    ├── Accepts client connections
    ├── Creates a thread for each client
    ├── Manages connected clients
    ├── Broadcasts messages
    ├── Handles disconnections
    └── Logs server events
```

---

## 🛠️ Building

### 1. Clone the repository

```bash
git clone https://github.com/M-Faiq-7R/net-forge.git
cd net-forge
```

### 2. Compile the server

```bash
g++ src/server/*.cpp -o server
```

### 3. Compile the client

```bash
g++ src/client/*.cpp -o client
```

---

## ▶️ Running

### Start the server

Open a terminal and run:

```bash
./server
```

### Start the client

Open another terminal and run:

```bash
./client
```

You can launch multiple clients from separate terminals to test simultaneous connections and message broadcasting.

---

## 🧪 Example

```bash
# Terminal 1
./server

# Terminal 2
./client

# Terminal 3
./client
```

Messages sent by one client can be broadcast to the other connected clients through the server.

---

## 🎯 Project Goal

NetForge is primarily a **learning project** focused on understanding networking from the ground up.

Instead of relying on high-level networking libraries, the project works directly with Linux's **POSIX socket API**, C++ threads, mutexes, and low-level networking primitives.

---

## 📚 Concepts Explored

```text
TCP/IP
  │
  ├── Socket Programming
  │
  ├── Client / Server Architecture
  │
  ├── Concurrent Connections
  │
  ├── Multithreading
  │
  ├── Mutex Synchronization
  │
  ├── Shared Client State
  │
  ├── Message Broadcasting
  │
  └── Connection Management
```

---

## 🐧 Platform

Built and tested on **Linux** using:

* C++
* POSIX Sockets
* TCP/IP
* `std::thread`
* `std::mutex`
* `g++`

---

