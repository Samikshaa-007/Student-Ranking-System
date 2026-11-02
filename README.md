# 🎓 Student Ranking and Result Management System

A high-performance C++ console application designed to manage student academic records, calculate ranks, and perform fast $O(1)$ database lookups using core data structures.

---

## 🚀 Features

- **Fast Lookups:** Uses `std::unordered_map` for constant-time $O(1)$ student search by Roll Number.
- **Dynamic Ranking:** Implements a Max Heap using `std::priority_queue` to automatically sort and display top-performing students.
- **Interactive CLI:** Simple menu-driven console interface for adding, searching, and ranking students.

---

## 🛠️ Data Structures Used

| Feature | Data Structure / Algorithm | Time Complexity |
| :--- | :--- | :--- |
| **Student Record Search** | `std::unordered_map` | $O(1)$ Average |
| **Rank Calculation** | `std::priority_queue` (Max Heap) | $O(N \log N)$ |
| **Data Storage** | `std::vector` / Custom Struct | $O(N)$ Space |

---

## 💻 How to Run Locally

### Prerequisites
- A C++ compiler (such as `g++` / MinGW) installed on your system.

### Compilation & Execution
1. Clone the repository:
   ```bash
   git clone [https://github.com/Samikshaa-007/Student-Ranking-System](https://github.com/Samikshaa-007/Student-Ranking-System)
   cd Student-Ranking-System