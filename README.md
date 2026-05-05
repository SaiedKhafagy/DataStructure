# 🏥 Hospital Triage System (Data Structures Project)

## 📌 Overview

This project simulates a simple **hospital triage system** using fundamental data structures implemented manually (without STL).

The system prioritizes patients based on urgency:

* Emergency cases are handled first
* Normal patients are handled in arrival order
* All processed patients are stored in a history log

---

## ⚙️ Data Structures Used

### 1. Queue (Normal Patients)

* Implements FIFO (First In First Out)
* Stores regular patients waiting for treatment
* Operations:

  * `enqueue()` → Add patient
  * `dequeue()` → Process patient

---

### 2. Stack (Emergency Cases)

* Implements LIFO (Last In First Out)
* Used for critical cases that must be handled immediately
* Operations:

  * `push()` → Add emergency patient
  * `pop()` → Process emergency case

---

### 3. Linked List (Discharged Patients)

* Stores processed patients permanently
* Used for hospital records and tracking
* Operations:

  * `addRecord()` → Save patient after processing
  * `display()` → Show all discharged patients

---

## 🔁 System Logic

1. Emergency patients are always treated first
2. If no emergency exists → normal queue is processed
3. Every processed patient is saved in history
4. System runs continuously until exit

---

## 🖥️ Menu Options

```
1. Add Normal Patient
2. Add Emergency Case
3. Process Next Patient
4. View Discharged Records
5. Exit
```

---

## 🚀 How to Run

1. Compile the code:

```
g++ main.cpp -o hospital
```

2. Run the program:

```
./hospital
```

---

## 📊 Example Scenario

* Add normal patients: 101, 102
* Add emergency patient: 999

Processing order will be:

```
Emergency: 999
Normal: 101
Normal: 102
```

---

## 🎯 Key Concepts Demonstrated

* Manual implementation of:

  * Queue using Linked List
  * Stack using Linked List
  * Linked List traversal
* Memory management using `new` and `delete`
* Real-world simulation of triage systems
* Priority handling logic

---

## ⚠️ Notes

* No STL (like `queue`, `stack`, `list`) is used
* All structures are implemented from scratch
* IDs are integers only
* No input validation for invalid data types

---

## 💡 Possible Improvements

* Add patient names and severity levels
* Use priority queue instead of stack for emergencies
* Add GUI interface
* Store data in file instead of memory

---

## 👨‍💻 Author

Developed as a Data Structures practice project.
