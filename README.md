[![wakatime](https://wakatime.com/badge/github/AlexPT2k22/Projecto_POO.svg)](https://wakatime.com/badge/github/AlexPT2k22/Projecto_POO) ![Language](https://img.shields.io/badge/language-C++-blue) ![Documentation](https://img.shields.io/badge/documentation-Doxygen-brightgreen) ![Status](https://img.shields.io/badge/status-Done-brightgreen) ![License](https://img.shields.io/badge/license-MIT-blue)

# 🇵🇹 THIS PROJECT IS IN PORTUGUESE

# 📚 Library Management System

This project implements a comprehensive library management system in C++. It facilitates the administration of books, readers, reservations, and loans, with advanced features like exporting and importing data in CSV format. The system uses inheritance and polymorphism to model different types of books and readers.

## ✨ Features

### 1. **Book Management**
- **Supported book types**:
  - Scientific Books
  - Educational Books
  - Fiction Books
  - Magazines
  - Newspapers
- **Available actions**:
  - Add new books.
  - Update book information.
  - Register loans and returns.
  - Reserve books.
  - And more.

### 2. **Reader Management**
- **Supported reader types**:
  - Common Reader
  - Student
  - Professor
  - Senior Reader
- **Available actions**:
  - Register readers.
  - Log loans for readers.
  - View detailed reader information.
  - And more.

### 3. **Loans and Reservations**
- Log loans with loan and return dates.
- Manage book reservations.
- Automatically update book copy availability.
- And more.

### 4. **Data Export and Import**
- **Supported file format**: CSV.
- Export detailed information about books, readers, reservations, and loans.
- Import data to restore library state.

## 🛠️ Technologies Used
- **Language**: C++.
- **Paradigm**: Object-Oriented Programming (OOP).
  - Classes and objects for data modeling.
  - Inheritance to represent specialized types of books and readers.
  - Polymorphism for dynamic behaviors.
- **Input and Output**:
  - CSV file manipulation.
  - Terminal interaction for data input.
 
## Prerequisites

- **Compiler:** GCC or any C++11 compliant compiler.
- **Tools:** Doxygen (for documentation generation), Makefile (if configured for automated builds).

## Installation and Usage

1. **Clone the Repository**
   ```bash
   git clone https://github.com/AlexPT2k22/Projecto_POO.git
   cd Projecto_POO.git
   ```

2. **Build the Project Compile all .cpp files**
   ```bash
   g++ -o biblioteca.exe main.cpp src\*.cpp -I include
   ```
   
3. **Run the Application**
    ```bash
      ./library_management
4. **Generate Documentation (Optional) If Doxygen is installed:**
   ```bash
     doxygen Doxyfile
   ```

# License
This project is licensed under the MIT License - see the LICENSE file for details.
