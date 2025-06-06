# 🧠 TCP Client-Server in C

This project demonstrates a simple TCP-based client-server communication in C using the Berkeley sockets API. The client sends a specified number of messages to the server, and the server prints each one as it arrives.

---

## 🛠 Features

- TCP communication over `localhost` (`127.0.0.1`)
- Server accepts one client and continuously receives messages
- Client sends a fixed number of user-entered messages
- Uses modern `inet_pton()` for address conversion
- Graceful error handling and connection cleanup

---

## ⚙️ Requirements

- GCC or any C compiler  
- Linux/Unix system  
- Basic terminal usage

---

## 🔧 Configuration

In both `server.c` and `client.c`:

```c
#define PORT 8080

🚀 How to Compile & Run

    Compile Both Programs

        Compile Both Programs

gcc server.c -o server
gcc client.c -o client

    Start the Server

./server

You should see:

socket() worked
bind success!!
listeningg...
accepted

    In a New Terminal, Start the Client

./client

You'll be prompted to enter the number of messages:

Enter no of messages to send: 3
Enter text: Hello
Enter text: From
Enter text: Client

Server will print:

Recieved message: Hello
Recieved message: From
Recieved message: Client


🧠 How It Works

Server (server.c)

    Creates and binds a TCP socket to 127.0.0.1:8080

    Listens for one client

    Accepts the connection and continuously reads messages using recv()

    Prints each message received

Client (client.c)

    Creates a TCP socket and connects to 127.0.0.1:8080

    Prompts user for number of messages

    Sends each message using send()

🧩 Possible Improvements

    Support multiple clients (via fork(), select(), or threads)

    Allow multi-word messages (use fgets() instead of scanf())

    Add message acknowledgments from server

    Handle connection drop or timeout gracefully

🔐 Security Note

This is a basic educational example. It does not implement:

    Authentication

    Message integrity

    TLS encryption

Use with caution if modifying for network use.
