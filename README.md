# Hospital Management System 


## Description

A **terminal-based Hospital Management System** built in **C++** during my **freshman year** as an Object-Oriented Programming project. The application demonstrates object-oriented design through patient management, hospital staff, wards, billing, and appointment scheduling in a modular, class-based architecture.

---

## Features

- Patient and staff management
- Multiple staff roles:
  - General Practitioner (GP)
  - Surgeon
  - Nurse
- Ward management
  - General Ward
  - ICU
  - Surgical Ward
- Patient admission and discharge
- Treatment tracking
- Billing system with operator overloading
- Appointment scheduling
- Double-booking prevention
- Revenue reporting
- Functional filtering and sorting using lambdas
- Deep copy and move semantics
- Polymorphic display of different person types

---

## Concepts Demonstrated

- Object-Oriented Programming
- Encapsulation
- Inheritance
- Polymorphism
- Abstract Classes
- Virtual Functions
- Operator Overloading
- Copy Constructor
- Move Constructor
- Dynamic Memory Management
- STL Containers
- Lambda Expressions
- Function Objects
- Modular Software Design

---

## Project Structure

```text
Hospital-Management-System/
├── codes/
│   ├── Person.h
│   ├── Person.cpp
│   ├── Patient.h
│   ├── Patient.cpp
│   ├── StaffMember.h
│   ├── StaffMember.cpp
│   ├── Ward.h
│   ├── Ward.cpp
│   ├── Treatment.h
│   ├── Bill.h
│   ├── Appointment.h
│   ├── AppointmentBook.h
│   ├── Hospital.h
│   ├── main.cpp
│   └── ...
│
├── DesignDocument/
│   ├── design.pdf
│
└── README.md
```

> *The `codes` folder contains the implementation of every class used throughout the project.*

---

## Object-Oriented Design

| Class | Responsibility |
|--------|----------------|
| `Person` | Base class representing a person in the hospital |
| `Patient` | Stores diagnosis, admission details, treatments, and billing information |
| `StaffMember` | Base class for all hospital employees |
| `GP` | General practitioner capable of consultations and prescriptions |
| `Surgeon` | Performs operations and manages surgical specializations |
| `Nurse` | Administers treatments and manages ward care |
| `Ward` | Abstract base class representing hospital wards |
| `GeneralWard` | Accepts all patients |
| `ICU` | Admits only critical patients |
| `SurgicalWard` | Admits patients scheduled for surgery |
| `Treatment` | Represents a medical treatment with cost and staff information |
| `Bill` | Calculates patient billing and overloads comparison and arithmetic operators |
| `Appointment` | Represents appointments between patients and staff |
| `AppointmentBook` | Manages appointment scheduling and conflict detection |
| `Hospital` | Coordinates hospital operations, admissions, billing, and reporting |

---

## Technologies Used

- C++
- Object-Oriented Programming
- Standard Template Library (STL)
- g++ (C++17)

---

## Building the Project

Compile using any C++17 compatible compiler.

Example using g++:

```bash
g++ codes/*.cpp -std=c++17 -o HospitalManagementSystem
```

Run:

```bash
./HospitalManagementSystem
```

---

## Demonstrated Functionalities

The project includes demonstrations of:

- Runtime polymorphism
- Operator overloading
- Deep copy implementation
- Move semantics
- Lambda-based filtering and sorting
- Billing rate polymorphism

---

## Developers

**Hassan Khan**

---

