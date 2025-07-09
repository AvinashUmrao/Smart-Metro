# 🚇 Smart Metro 

A comprehensive C++-based **Delhi Metro Simulator** that combines **navigation**, **optimization**, and **administrative planning tools** into one interactive, modular application.

---

## 📁 Project Structure

```
Smart-Metro/
└── admin_user/
    ├── setup.h               # Trie-based metro map and route logic
    ├── project.cpp           # Metro route UI (shortest, cheapest paths)
    ├── metro.cpp             # Admin & user dashboard with 8 utilities
    ├── map.txt               # Metro map ASCII representation
    ├── home.txt              # Home screen ASCII art
    ├── exit.txt              # Exit screen ASCII art
    └── P/
        ├── 1.cpp             # Knapsack: Maximize goods transport profit
        ├── 2.cpp             # Huffman Coding: Passenger data compression
        ├── 3.cpp             # Train repair scheduling (Binary Search)
        ├── 4.cpp             # Platform allocation (Min Platforms)
        ├── 5.cpp             # SJF Scheduling for maintenance tasks
        ├── 6.cpp             # String Matching: Metro ticket verification
        ├── 7.cpp             # Ad scheduling: Maximize revenue
        └── 9.cpp             # Train flow optimization (Network Flow)
```

---

## 🔧 Features

### 🚉 User Mode

* **Metro Navigation Interface**:

  * Find **shortest** (based on distance) or **cheapest** (based on cost) paths between stations
  * Input via station names or numeric IDs
  * View station list, connections, and metro map
* **Goods Transportation (Knapsack)**:

  * Maximize profit for transporting goods with a fixed bag capacity
  * Supports both **0/1** and **Fractional Knapsack**

### 🔐 Admin Mode

Password-protected tools to simulate core metro operations:

* 📦 **Data Compression**: Huffman coding for passenger data
* 🔧 **Train Maintenance Scheduling**:

  * **SJF Algorithm** for minimizing waiting time
  * **Mechanic Assignment** using Binary Search
* 🛤️ **Platform Allocation**: Calculate minimum number of platforms
* 🎫 **Ticket Verification**: Pattern matching via KMP, Rabin-Karp, etc.
* 📺 **Advertisement Revenue Optimization**: Maximize ad slots revenue using DP
* 🚦 **Train Network Flow**: Ford-Fulkerson (Edmonds-Karp) to compute max train flow

---

## 🛠️ Technologies Used

* **Language**: C++
* **Algorithms**: Dijkstra, Trie, Greedy, Dynamic Programming, Huffman, SJF, KMP, Network Flow
* **Concepts**: Graphs, Priority Queues, Scheduling, Pattern Matching

---

## 🚀 Getting Started

### 🔄 Compile & Run

Ensure you have a C++ compiler (`g++`) installed.

1. Clone the repo:

   ```bash
   git clone https://github.com/your-username/smart-metro.git
   cd smart-metro/admin_user
   ```

2. Compile and run:

   * **User/Admin dashboard:**

     ```bash
     g++ metro.cpp -o metro
     ./metro
     ```
   * **Route Finder (only):**

     ```bash
     g++ project.cpp -o project
     ./project
     ```

> External files (`map.txt`, `home.txt`, `exit.txt`) are used for display purposes, make sure they're in the same directory.

---

## 📸 Sample Screens

You can check in ScreenShot_Output Folder 

---

## 🔐 Developer Access

To add new stations and manage the metro graph:

* Run `project.cpp`
* Select developer options (password required)
* Add new station name, colors, connected nodes, and costs

---

## 🧠 Algorithms in Action

| Feature                       | Algorithm/Approach        |
| ----------------------------- | ------------------------- |
| Cheapest/Fastest Metro Route  | Dijkstra's Algorithm      |
| Station Search                | Trie-based Search         |
| Goods Transport Optimization  | 0/1 & Fractional Knapsack |
| Passenger Data Compression    | Huffman Coding            |
| Maintenance Time Optimization | Binary Search + Greedy    |
| Platform Minimization         | Overlap Counting          |
| Task Scheduling               | Shortest Job First (SJF)  |
| Ticket Code Verification      | KMP, Rabin-Karp, etc.     |
| Advertisement Slot Scheduling | Dynamic Programming       |
| Train Scheduling / Flow       | Ford-Fulkerson Algorithm  |

---

| Feature                | Algorithm                 | File          |
| ---------------------- | ------------------------- | ------------- |
| Route Finder           | Dijkstra’s Algorithm      | `project.cpp` |
| Goods Transport        | Fractional Knapsack       | `P/1.cpp`     |
| Data Compression       | Huffman Coding            | `P/2.cpp`     |
| Mechanic Scheduling    | Binary Search             | `P/3.cpp`     |
| Platform Allocation    | Overlap Counting (Greedy) | `P/4.cpp`     |
| Maintenance Scheduling | SJF                       | `P/5.cpp`     |
| Ticket Verification    | KMP, Rabin-Karp, Naive    | `P/6.cpp`     |
| Ad Revenue             | Dynamic Programming       | `P/7.cpp`     |
| Train Flow             | Ford-Fulkerson (BFS)      | `P/9.cpp`     |

---
## 🧠 Skills Demonstrated

- Advanced C++ with modular programming
- Algorithm design & problem solving (Knapsack, Huffman, SJF, KMP, Ford-Fulkerson)
- Data structures: Graphs, Tries, Priority Queues
- Real-world application of CS fundamentals in transport systems
- CLI-based user/admin interfaces with I/O file handling


## 📄 License

This project is for academic and demonstration purposes.
For use in production, please contact the author.

---

## 👨‍💻 Author

**Avinash Umrao**
Engineering Student | C++ Developer | Passionate about Algorithms
🔗 [LinkedIn](https://www.linkedin.com/in/avinash-umrao-5184182b9/)

---

## ⭐️ Star the Repository

If you find this project helpful, feel free to ⭐️ the repository!
