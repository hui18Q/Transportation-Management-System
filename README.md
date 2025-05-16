# Transportation-Management-System
An object-oriented system for managing various types of vehicles efficiently.

## **Table of Contents**
- [Overview](#overview)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Object-Oriented Concepts](#object-oriented-concepts)
- [Contributors](#contributors)
- [License](#license)

## **Overview**  
This program simplifies vehicle management using **object-oriented programming (OOP)** principles. It supports different transportation types—**Air, Land, and Sea**—allowing users to add, edit, delete, search, and display vehicles.

## **Features**  
- **Vehicle Management**
  - Add new vehicles with detailed attributes.
  - Modify vehicle information.
  - Remove vehicles from the database.
  - Search by name or filter by type.
- **Transportation Types**
  - **Air Vehicles** (e.g., planes, helicopters)
  - **Land Vehicles** (e.g., cars, bikes)
  - **Sea Vehicles** (e.g., ships, boats)
- **File Handling**
  - Read/write vehicle data from files.
- **User-Friendly Menu**
  - Console-based interface with interactive options.

## **Installation**  
To set up and run the project:  
1. **Clone the repository:**  
   ```bash
   git clone <repository-url>
   cd TransportationManagement
   ```
2. **Compile the program:**  
   ```bash
   g++ main.cpp -o TransportManager
   ```
3. **Run the executable:**  
   ```bash
   ./TransportManager   # Linux/macOS
   TransportManager.exe # Windows
   ```

## **Usage**  
- Start the program and **follow the menu prompts**.
- Choose options like adding, editing, deleting, or searching for vehicles.

## **Object-Oriented Concepts Used**  
- **Classes & Inheritance**: `Vehicle` is the base class, with `AirVehicle`, `LandVehicle`, and `SeaVehicle` as subclasses.
- **Encapsulation**: Attributes like `name`, `year`, and `engineType` are protected, ensuring controlled access.
- **Polymorphism**: The `display()` function is overridden for different vehicle types.
- **Operator Overloading**: Allows formatted output using `std::cout`.

## **Contributors**  
**Group 5 - Multimedia University**  
- Chin Wen Hui  
- Aw Kak Yi  
- Muhammad Aiman Danish bin Ahmad Amri  
- Muhammad Danish bin Zulkipli  

## **License**  
This project is intended for academic use and licensed under **[MIT License](LICENSE)**.
