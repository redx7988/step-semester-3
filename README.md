# STEP - Semester 3

C++ coursework for Semester 3 of the STEP program — weekly practice problems, assignments, and homework covering core C++ and object‑oriented programming concepts.

Each week's work lives on its own branch (`feature/week1` through `feature/week6`) rather than on `main`, so check out the relevant branch to see that week's code.

## Branches & Topics

| Branch | Focus | Folders |
|---|---|---|
| `feature/week1` | C++ basics (e.g. building a Rock‑Paper‑Scissors game) | `PRACTICE_PROBLEMS`, `ASSIGNMENT` |
| `feature/week2` | Strings & parsing (PIN validation, word reversal, CSV parsing) | `PRACTICE_PROBLEMS`, `ASSIGNMENT` |
| `feature/week3` | Intro to classes & constructors (`BookInventory`, `PayrollAccount`, `Employee`) | `PRACTICE_PROBLEMS`, `HOMEWORK` |
| `feature/week4` | OOP with vectors & collections (`Participant`, `Item`, `ParkingTicket`) | `PRACTICE_PROBLEMS`, `HOMEWORK` |
| `feature/week5` | Access modifiers & encapsulation (`AccessChecker`, `BookInventory`) | `PRACTICE_PROBLEMS`, `ASSIGNMET PROBLEMS` |
| `feature/week6` | Inheritance & polymorphism (`LibraryMember` hierarchy, virtual functions) | `PRACTICE PROBLEMS` |

Within each week, problems are numbered `m1.cpp` through `m5.cpp` (or `question-1.cpp`, etc.).

## Getting Started

Clone the repo and switch to the branch you want to work with:

```bash
git clone https://github.com/redx7988/step-semester-3.git
cd step-semester-3
git checkout feature/week3   # or whichever week
```

### Compiling & Running a File

Each `.cpp` file is self-contained. Compile and run any individual file with g++:

```bash
g++ -std=c++17 -o output "PRACTICE_PROBLEMS/m1.cpp"
./output
```

Adjust the folder/file path to match the branch and problem you're running.

## Requirements

- A C++ compiler supporting C++11 or later (e.g. `g++`, `clang++`)

## Repository Structure

```
step-semester-3/
├── README.md                 (this file — lives on main)
└── feature/weekN branches
    ├── PRACTICE_PROBLEMS/     # in-class / practice exercises
    └── ASSIGNMENT|HOMEWORK/  # weekly graded work
```

## License

No license specified. All rights reserved by the repository owner unless stated otherwise.
