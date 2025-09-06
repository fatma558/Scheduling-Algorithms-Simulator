# Scheduling Algorithms Simulator

The **Scheduling Algorithms Simulator** is a console-based C++ application designed to model and analyze various CPU scheduling techniques used in operating systems. It provides an educational and practical platform to visualize how different algorithms manage processes and optimize CPU utilization.

---

## ✨ Features

### 🔹 Algorithm Implementation
- Supports multiple scheduling algorithms:
  - First-Come-First-Serve (FCFS)
  - Shortest Job First (SJF)
  - Round Robin (RR)
  - Priority Scheduling
  - Non-Preemptive Priority
- Accurately simulates process execution order and scheduling decisions.

### 🔹 Performance Analysis
- Calculates **Waiting Time**, **Turnaround Time**, and **Average Times** for all processes.
- Allows comparison between algorithms to highlight trade-offs in **efficiency**, and **throughput**.

### 🔹 Flexible Input Handling
- Accepts process data directly from file input.
- File input allows automated testing with larger datasets.
- Easily replicate scenarios and validate scheduling outcomes.

### 🔹 Interactive Simulation
- Console interface for entering or loading process details:
  - Arrival time
  - Burst time
  - Priority
- Displays results in a clean **tabular format**.

---

## ⚙️ Technical Highlights
- **Modular Design** → separated source and header files for algorithm logic, data handling, and UI.
- **STL Utilization** → uses vectors, queues, and priority queues to manage scheduling.
- **Custom Comparison Functions & Hash Tables** → implement advanced scheduling logic.
- **File I/O** → load process data from files and export results for deeper analysis.
- **OS Concepts in Action** → hands-on reinforcement of CPU scheduling theory.

---

## 🚀 Future Improvements
- Add **preemptive scheduling** (Preemptive SJF, Preemptive Priority).
- Visualize results with **Gantt charts**.
- Support **multi-core scheduling simulations**.
- (Optional) Export results to **CSV/JSON** for further processing.

---

