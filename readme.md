```
 ____  _____ _   _ ____  _____ _   _ _____    __  __  ____  __  __ _____
/ ___||_   _| | | |  _ \| ____| \ | |_   _|  |  \/  |/ ___||  \/  |_   _|
\___ \  | | | | | | | | |  _| |  \| | | |    | |\/| | |  _ | |\/| | | |
 ___) | | | | |_| | |_| | |___| |\  | | |    | |  | | |_| || |  | | | |
|____/  |_|  \___/|____/|_____|_| \_| |_|    |_|  |_|\____||_|  |_| |_|
```

**A clean, full-featured system to manage students, grades, and academic records.**

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Qt](https://img.shields.io/badge/Qt-41CD52?style=for-the-badge&logo=qt&logoColor=white)
![Status](https://img.shields.io/badge/Status-Active-4ade80?style=for-the-badge)
![License](https://img.shields.io/badge/License-Apache_2.0-f59e0b?style=for-the-badge)

---

## ◈ Overview

> A robust **Student Management System** built to streamline academic data handling — from enrollment and attendance to grades and reporting. Designed with simplicity and efficiency at its core.

---

## ◈ Features

```
┌─────────────────────────────────────────────────┐
│                                                 │
│   ✦  Add, Update & Delete Student Records       │
│   ✦  Track Attendance & Performance             │
│   ✦  Grade Management & GPA Calculation         │
│   ✦  Search & Filter Students Instantly         │
│   ✦  Clean Qt GUI Interface                     │
│                                                 │
└─────────────────────────────────────────────────┘
```

---

## ◈ Getting Started

**1 — Clone the repository**
```bash
git clone https://github.com/Sathvik33/Student-Management.git
cd Student-Management
```

**2 — Compile the project**
```bash
g++ -o student_management main.cpp -std=c++17
```

**3 — Run the application**
```bash
./student_management
```

---

## ◈ Project Structure

```
Student-Management/
│
├── 📁 include/
│   ├── student.h         # Student class declarations
│   ├── database.h        # Data layer declarations
│   └── utils.h           # Utility functions
│
├── 📁 src/
│   ├── student.cpp       # Student logic implementation
│   ├── database.cpp      # File handling & storage
│   └── utils.cpp         # Helper implementations
│
├── main.cpp              # Entry point
├── Makefile              # Build configuration
└── README.md
```

---

## ◈ Usage

| Action | Description |
|:-------|:-----------|

| `Add Student` | Register a new student with ID, name, and course |

| `View All` | Display the full student roster |

| `Update` | Modify existing student information |

| `Delete` | Remove a student record permanently |

| `Search` | Find students by name or ID |

| `Grades` | Assign and view grades per subject |

---

## ◈ Tech Stack

```
  Language  ──────────────  C++17
  Storage   ──────────────  File-based / Binary files
  Interface ──────────────  Qt (GUI)
  Compiler  ──────────────  g++ / MSVC
```

---

## ◈ Contributing

Contributions are welcome and appreciated.

```bash
# Fork → Branch → Commit → Pull Request
git checkout -b feature/your-feature-name
git commit -m "feat: add your feature"
git push origin feature/your-feature-name
```

---

## ◈ License

Distributed under the **Apache 2.0 License**. See `LICENSE` for more information.

---

*Made with care by [Sathvik33](https://github.com/Sathvik33) — "Organize knowledge. Empower learning."*