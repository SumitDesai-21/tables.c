# 📊 Student Grade Analysis System — `tables.c`

A **C-based grade analysis system** that processes student data from CSV files to calculate grades, compute CGPA, identify toppers, and detect failed subjects.
This project emphasizes **core logic-building skills** by avoiding built-in string functions like `strtok`, instead using **custom parsing methods** for enhanced modularity and learning.

---

## 🚀 Project Overview

This program simulates a **student grade analysis system** that:

* Reads data from three CSV files:

  * `subjects.csv` — Subject details
  * `grades.csv` — Grade mappings
  * `marks.csv` — Students' marks
* Processes the data to:

  * Calculate individual grades and overall CGPA.
  * Identify subject toppers and semester toppers.
  * Detect subjects where students have failed.

It’s designed for **students and developers** looking to strengthen their C programming skills through **file handling**, **data processing**, and **modular design**.

---

## 🛠️ Features

* ✅ **Grade Calculation:** Computes grades and CGPA for every student.
* ✅ **Topper Identification:** Detects both subject-wise and semester-wise toppers.
* ✅ **Failure Detection:** Lists failed subjects for each student.
* ✅ **Modular Structure:** Built with **custom functions** for clean, maintainable code.
* ✅ **Pure C Logic:** No use of functions like `strtok`—all string parsing is done manually for deep learning.

---

## 📂 File Structure

```
.
├── tables.c              # Main C source file with all logic
├── subjects.csv          # CSV containing subject codes and names
├── grades.csv            # CSV mapping marks to grades and grade points
├── marks.csv             # CSV with students' marks
└── README.md             # Project documentation
```

---

## 📄 CSV File Descriptions

### `subjects.csv`

| Subject Name       | Credits      | Semester     |
| ------------------ | ------------ | ------------ |
| PSPP               | 3            | 1            |
| CL                 | 1            | 1            |

### `grades.csv`

| Min Marks | Max Marks | Grade | Grade Point |
| --------- | --------- | ----- | ----------- |
| 77        | 88        | AA    | 10          |
| 60        | 77        | AB    | 9           |

### `marks.csv`

|  MIS NO.  | PSPP      | CL    | PPL   |  DSA   | OS    |  CN   |  TOC  |
|  -------  | --------- | ----- | ----- |------- | ------| ----- | ----- |
| 612303001 | 82        | 85    | 90    | 67     | 68    |  85   |  90   |

--- 

## ⚙️ How to Run

### 1. Clone the Repository

```bash
git clone https://github.com/SumitDesai-21/grade_analysis_system.git
cd grade_analysis_system
```

### 2. Compile the Program

Use `gcc` to compile the project:

```bash
gcc tables.c -o t
```

### 3. Run the Program

```bash
./t
```

### ✅ Prerequisites:

* GCC compiler installed (`sudo apt install gcc` on Linux Terminal).
* All CSV files (`subjects.csv`, `grades.csv`, `marks.csv`) must be in the **same directory** as `tables.c`.

---

## 🏧 Key Concepts Used

* File I/O in C (`fopen`, `fgets`, etc.)
* Manual string parsing
* Data structures (arrays - 1D and 2D, structs)
* Custom functions for modularity and reusability
* Error handling for file operations

---

## 📈 Learning Objectives

* Master **file operations** and **data parsing** in C.
* Enhance **problem-solving** by writing manual string parsers.
* Understand how to design modular, scalable C projects.

---

## 🌟 Future Enhancements

* Support for dynamic data (currently limited by static array sizes).
* Improved UI/UX for terminal output.
* Export analysis reports to new CSV files.

---

## 🤝 Contributions

Contributions, suggestions, and improvements are welcome!
Feel free to fork this repository, raise an issue, or submit a pull request.

---

## 📄 License

This project is licensed under the **MIT License**.

---

## 👨‍💻 Author

**Sumit Desai**
*Passionate about C programming, problem-solving, and building efficient solutions.*
