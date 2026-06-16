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
| **Inheritance** | `Person → Student`, `Person → Staff` |
| **Polymorphism** | `virtual getRole()` |
| **Composition** | `Dorm` contains `Student` |
| **Exception Handling** | Invalid argument in `Administrator`, out of range in `Administrator` and `Staff` |
| **Dynamic Memory** | used in add functions in `Administrator` |
| **Friend Classes** | `Administrator` declared as friend in `Restaurant` |

## Data Structures
- `vector` — To_Do in Staff
- `array`  — students , Rooms , staffs in Administrator

## Users / Roles
- **Students** — reserve or unreserve meals (breakfast , lunch , dinner) , report problems to staff , view its information
- **Staff** — view its To do list and check the completed task
- **Administrator** — (add , remove) student or staff (to , from) the system , (add , remove) student to the Dorm , view information of all staff and student on the system , modifey the restaurant menu

## Operations Supported
- **Access** / **Insert** / **Delete** on students, Rooms, staffs 

## Storage
- Text files (CSV format) in `data/` directory:
  - `data/students.csv`
  - `data/staff.csv`
  - `data/rooms.csv`
  - `data/administrator.csv`


## Project Structure
```
OOP_PROJECT/
├── data/
│   ├── student.csv
│   ├── staff.csv
│   ├── rooms.csv
│   ├── administrator.csv
├── implement/
│   ├── person.cpp
│   ├── student.cpp
│   ├── staff.cpp
│   ├── administrator.cpp
│   ├── dorm.cpp
│   ├── restaurant.cpp   
│   ├── FileManagement.cpp
│   └── System.cpp
├── include/
│   ├── person.h
│   ├── student.h
│   ├── staff.h
│   ├── administrator.h
│   ├── dorm.h
│   ├── restaurant.h   
│   ├── FileManagement.h
│   └── System.h
├── src/
│   └── main.cpp
├── Makefile
└── README.md

