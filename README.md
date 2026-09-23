# ⚡ NetForge

> A C++ networking project built from scratch on Linux to explore computer networking at a lower level.

---

## 🧠 About

**NetForge** is a hands-on C++ networking project focused on TCP sockets, concurrent clients, multithreading, synchronization, and Linux socket programming.

The project was built incrementally from a basic TCP client-server application into a multi-client network application.

The goal was not to create a production-ready networking framework, but to understand how networking concepts work by implementing them directly in C++ using the Linux socket API.

---

## 🚀 Features

* ✅ TCP client-server communication
* ✅ Multiple simultaneous client connections
* ✅ Concurrent client handling using C++ threads
* ✅ Dynamic message exchange between clients and server
* ✅ Server responses to clients
* ✅ Client connection and disconnection handling
* ✅ Thread-safe management of connected clients
* ✅ Mutex-based synchronization for shared client data
* ✅ Graceful client termination
* ✅ Server-side event logging
* ✅ Timestamped server events
* ✅ Linux socket programming using the POSIX socket API

---

## 🏗️ Architecture

The project is organized into separate client and server components:

```text
NetForge
│
├── Client
│   ├── Establishes TCP connection
│   ├── Sends messages
│   └── Receives server responses
│
└── Server
    ├── Accepts client connections
    ├── Creates a thread for each client
    ├── Tracks connected clients
    ├── Handles client disconnections
    └── Logs server events
```

---

## 🛠️ Building

### Clone the repository

```bash
git clone https://github.com/M-Faiq-7R/net-forge.git
cd net-forge
```

### Compile the server

```bash
g++ src/server/*.cpp -o server
```

### Compile the client

```bash
g++ src/client/*.cpp -o client
```

---

## ▶️ Running

Start the server:

```bash
./server
```

Then open another terminal and start a client:

```bash
./client
```

Multiple clients can be launched from separate terminals to test simultaneous connections:

```bash
# Terminal 1
./server

# Terminal 2
./client

# Terminal 3
./client
```

---

## 📚 Concepts Explored

```text
TCP/IP
  │
  ├── Socket Programming
  ├── Client / Server Architecture
  ├── IPv4 Addressing
  ├── TCP Connections
  ├── Concurrent Connections
  ├── Multithreading
  ├── Mutex Synchronization
  ├── Shared Client State
  ├── Connection Management
  └── Graceful Disconnection
```

---

## 🧰 Technologies

* **C++**
* **Linux**
* **POSIX Socket API**
* **TCP/IP**
* **IPv4**
* **std::thread**
* **std::mutex**
* **g++**

---

## 🎯 Project Outcome

NetForge was completed as a hands-on learning project focused on understanding:

* How TCP client-server communication works
* How Linux sockets are created and managed
* How multiple clients can be handled concurrently
* How threads interact with shared data
* Why synchronization is necessary in concurrent programs
* How client connections and disconnections are managed

The project provided practical experience with **C++ networking, Linux, multithreading, and synchronization** at a lower level.
