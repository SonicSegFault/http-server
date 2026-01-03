# Blocking HTTP Server

A simple **HTTP/1.1 server written in C++ from scratch** using POSIX sockets — no third-party libraries, no async, no frameworks.  
This project implements a basic **blocking TCP HTTP server** that can receive and parse HTTP requests (GET, POST with body) and send HTTP responses.

This project is educational and demonstrates how raw TCP, incremental parsing, and HTTP framing work without abstractions.

---

## 💡 Features

✔ Accepts multiple client connections (one at a time)  
✔ Parses HTTP/1.1 requests  
✔ Handles:
- GET requests
- POST requests with `Content-Length` body  
✔ Proper header/body separation using incremental `recv()`  
✔ Fully blocking I/O — simple, clear, and direct  
✔ Correct handling of partial network reads

---

## 🛠️ Why This Exists

Building an HTTP server from scratch is a great way to learn:
- how TCP streams work
- how HTTP framing works
- how to write a protocol parser
- how to do network I/O in POSIX

This project avoids relying on any HTTP frameworks to give you a **ground-up understanding** of how servers operate. :contentReference[oaicite:0]{index=0}

---

## 📦 Requirements

- Linux or UNIX-like OS  
- C++ compiler (GCC, Clang, etc.)  
- `make` (optional)

---

## ⚙️ How to Build

```bash
git clone https://github.com/SonicSegFault/Blocking-http-server.git
cd Blocking-http-server
g++ -std=c++17 -o server *.cpp
```
---
