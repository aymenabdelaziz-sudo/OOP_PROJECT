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
g++ -std=c++17 -Iinclude -o COMFORT src/main.cpp
./COMFORT
```

## OOP Concepts Used
| Concept | Where |
|---|---|
| **Inheritance** | `Person → Student`, `Person → Staff` , `Person → Administrator`|
| **Polymorphism** | `virtual getRole()` |
| **Exception Handling** | out of range in `Staff` |



## Data Structures
- `vector` — in Staff and Restaurant


## Users / Roles
- **Students** — reserve or unreserve meals (breakfast , lunch , dinner) , report problems to staff , view their information , view today restaurant menu , and room information if the student has one
- **Staff** — view its To do list and information and mark done the completed task 
- **Administrator** — (add , remove) student or staff (to , from) the system , (add , remove) student to the Dorm , view information of all staff and student on the system , modifey the restaurant menu and search for any day menu

## Operations Supported
- **Access** / **Insert** / **Delete** / **Sort** / **Search** / **Update**

## Storage
- Text files (CSV format) in `data/` directory:
  - `data/administrator.csv`
  - `data/restaurant.csv`
  - `data/rooms.csv`
  - `data/staff.csv`
  - `data/students.csv`
  `


## Project Structure
```
OOP_PROJECT/
├── data/
│   ├── administrator.csv
│   ├── restauarant.csv
│   ├── rooms.csv
│   ├── staff.csv
│   ├── students.csv
├── implement/
│   ├── person.cpp
│   ├── student.cpp
│   ├── staff.cpp
│   ├── administrator.cpp
│   ├── restaurant.cpp   
│   ├── FileManagement.cpp
│   └── System.cpp
├── include/
│   ├── person.h
│   ├── student.h
│   ├── staff.h
│   ├── administrator.h
│   ├── restaurant.h   
│   ├── FileManagement.h
│   └── System.h
├── src/
│   └── main.cpp
├── Makefile
└── README.md

