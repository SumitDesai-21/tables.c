<p align="center">
  <img src="https://img.icons8.com/external-tal-revivo-regular-tal-revivo/96/external-readme-is-a-easy-to-build-a-developer-hub-that-adapts-to-the-user-logo-regular-tal-revivo.png" width="100" />
</p>
<p align="center">
    <h1 align="center">Student Grade Analysis System</h1>
</p>
<p align="center">
	<img src="https://img.shields.io/github/last-commit/SumitDesai-21/tables.c?style=flat&logo=git&logoColor=white&color=0080ff" alt="last-commit">
	<img src="https://img.shields.io/github/languages/top/SumitDesai-21/tables.c?style=flat&color=0080ff" alt="repo-top-language">
	<img src="https://img.shields.io/github/languages/count/SumitDesai-21/tables.c?style=flat&color=0080ff" alt="repo-language-count">
<p>
<p align="center">
		<em>Developed with: </em>
</p>
<p align="center">
	<img src="https://img.shields.io/badge/C-A8B9CC.svg?style=flat&logo=C&logoColor=black" alt="C">
</p>
<hr>

### Project Overview

A **C-based grade analysis system** that processes student data from CSV files to calculate grades, compute CGPA, identify toppers, and detect failed subjects.
This project emphasizes **core logic-building skills** by avoiding built-in string functions like `strtok`, instead using **custom parsing methods** for enhanced modularity and learning.

This program simulates a **student grade analysis system** that:

* Reads data from three CSV files:

  * `subjects.csv` — Subject details
  * `grades.csv` — Grade mappings
  * `marks.csv` — Students' marks
* Processes the data to:

  * Calculate individual grades and overall CGPA.
  * Identify subject toppers and semester toppers.
  * Detect subjects where students have failed.

It’s designed for **Students and Programmers** looking to strengthen their C programming skills through **file handling**, **data processing**, and **modular design**.

### Features

* **Grade Calculation:** Computes grades and CGPA for every student.
* **Topper Identification:** Detects both subject-wise and semester-wise toppers.
* **Failure Detection:** Lists failed subjects for each student.
* **Modular Structure:** Built with **custom functions** for clean, maintainable code.
* **Pure C Logic:** No use of functions like `strtok`—all string parsing is done manually for deep learning.

### File Structure
```
.
├── tables.c              # Main C source file with all logic
├── subjects.csv          # CSV containing subject codes and names
├── grades.csv            # CSV mapping marks to grades and grade points
├── marks.csv             # CSV with students' marks
└── README.md             # Project documentation
```

### CSV File Descriptions

#### `subjects.csv`

| Subject Name       | Credits      | Semester     |
| ------------------ | ------------ | ------------ |
| PSPP               | 3            | 1            |
| CL                 | 1            | 1            |

#### `grades.csv`

| Min Marks | Max Marks | Grade | Grade Point |
| --------- | --------- | ----- | ----------- |
| 77        | 88        | AA    | 10          |
| 60        | 77        | AB    | 9           |

#### `marks.csv`

|  MIS NO.  | PSPP      | CL    | PPL   |  DSA   | OS    |  CN   |  TOC  |
|  -------  | --------- | ----- | ----- |------- | ------| ----- | ----- |
| 612303001 | 82        | 85    | 90    | 67     | 68    |  85   |  90   |

### How to Run

#### 1. Clone the Repository

```bash
git clone https://github.com/SumitDesai-21/grade_analysis_system.git
cd grade_analysis_system
```

#### 2. Compile the Program

Use `gcc` to compile the project:

```bash
gcc tables.c -o t
```

#### 3. Run the Program

```bash
./t
```

#### Prerequisites:

* GCC compiler installed (`sudo apt install gcc` on Linux Terminal).
* All CSV files (`subjects.csv`, `grades.csv`, `marks.csv`) must be in the **same directory** as `tables.c`.

### Key Concepts Used

* File I/O in C (`fopen`, `fgets`, etc.)
* Manual string parsing
* Data structures (arrays - 1D and 2D, structs)
* Custom functions for modularity and reusability
* Error handling for file operations

### Learning Objectives

* Master **file operations** and **data parsing** in C.
* Enhance **problem-solving** by writing manual string parsers.
* Understand how to design modular, scalable C projects.

### Contributions

Contributions, suggestions, and improvements are welcome!
Feel free to fork this repository, raise an issue, or submit a pull request.

### About the Author
 - **LinkedIn**: [Sumit Desai](https://linkedin.com/in/sumit-v-d-3b6a9632a)
 - **GitHub**: [Sumit Desai](https://github.com/SumitDesai-21)
 
Happy Coding! :heart:
