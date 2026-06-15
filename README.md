# University Dorms & Restaurant System "COMFORT"
**OOP Project — Year 1 | ENSIA**

## Overview
COMFORT is a C++ console application that manages a university dormitory and restaurant system, demonstrating core OOP principles.

## Build & Run
```bash
make        # compile
make run    # compile + run
make clean  # remove binaries and data/
```
Or manually:
```bash
g++ -std=c++17 -Iinclude -o UniDormSystem src/main.cpp
./UniDormSystem
```

## OOP Concepts Used
| Concept | Where |
|---|---|
| **Inheritance** | `Person → Student`, `Person → Staff` |
| **Polymorphism** | `virtual getRole()` |
| **Composition** | `Dorm` contains `Student` |
| **Exception Handling** | Invalid argument in `Administrator`, out of range in `Administrator` and `Staff` |
| **Dynamic Memory** |  |
| **Friend Classes** | `Administrator` declared as friend in `Restaurant` |

## Data Structures
- `vector` — To_Do in Staff
- `array`  — students , Rooms , staffs

## Users / Roles
- **Students** — view rooms, place orders, check balance
- **Dorms & Restaurant Administrator** — assign/vacate rooms, manage restaurant
- **Dorms & Restaurant Staff** — day-to-day operations
- **System Administrator** — full access

## Operations Supported
- **Access** / **Insert** / **Delete** / **Update** / **Search** / **Sort** on students, rooms, orders

## Storage
- Text files (CSV format) in `data/` directory:
  - `data/students.csv`
  - `data/staff.csv`
  - `data/rooms.csv`
  - `data/orders.csv`


## Project Structure
```
UniDormRestaurant/
├── include/
│   ├── Person.h
│   ├── Student.h
│   ├── Staff.h
│   ├── Room.h
│   ├── Dorm.h
│   ├── Restaurant.h   (MenuItem, Order, Restaurant)
│   ├── FileManager.h
│   └── System.h
├── src/
│   └── main.cpp
├── Makefile
└── README.md
```
