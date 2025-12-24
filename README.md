# Student Grading System

## Author  
Ugochukwu Erick Nwahiri

---

## Project Description

This project is a **Student Grading System** implemented in **C++**, developed incrementally through multiple tasks.  
The application reads student data, calculates final grades using **average or median**, sorts students, divides students into **passed** and **failed** groups, and performs **performance analysis** using different STL containers.

The project demonstrates:
- Object-Oriented Programming
- Rule of Three
- STL containers (`vector`, `list`, `deque`)
- Algorithm optimization using `<algorithm>`
- File input/output
- Performance benchmarking
- Cross-platform build systems (Make & CMake)

---

## Final Grade Calculation Formula

Final grade is calculated using the formula:

Final = 0.4 × Homework + 0.6 × Exam

Homework result can be calculated using either:
- **Average**
- **Median**

The user can choose the calculation method.

---

## Release History

### v0.1 — Initial Implementation (Task 1)

- Implemented `Person` class containing:
  - First name and surname
  - Homework and exam results
  - Final grade
- Implemented the **Rule of Three**:
  - Copy constructor
  - Assignment operator
  - Destructor
- Overloaded input/output operators (`>>`, `<<`)
- Used `std::vector` for homework storage
- Implemented final grade calculation using:
  - Average
  - Median
- Added support for random generation of homework and exam scores
- Implemented reading student data from file
- Sorted students by name or surname
- Created **Release v0.1**

---

### v0.2 — Refactoring & Performance Measurement (Task 2)

- Refactored code into multiple `.cpp` and `.h` files
- Introduced utility modules and timer for performance measurement
- Implemented exception handling for:
  - File opening errors
  - Invalid data access
- Generated large student datasets:
  - 1,000
  - 10,000
  - 100,000
  - 1,000,000 records
- Split students into:
  - **Passed** (final grade ≥ 5.0)
  - **Failed** (final grade < 5.0)
- Output results into separate files
- Measured execution time for:
  - File reading
  - Sorting
  - Splitting
  - File output
- Created **Release v0.2**

---

### v0.25 — Container Comparison

- Implemented the same logic using:
  - `std::vector`
  - `std::list`
  - `std::deque`
- Compared performance of different STL containers
- Measured execution time for each container type
- Created **Release v0.25**

---

### v1.0 — Final Optimization (Task 3)

- Optimized implementation of version v0.25
- Implemented two student splitting strategies:

**Strategy 1 — Copy Strategy**
- Students are copied into two new containers:
  - Passed
  - Failed
- Original container remains unchanged
- Higher memory usage

**Strategy 2 — Move & Erase Strategy**
- Failed students are moved into a new container
- Removed from the base container
- Remaining students are passed
- More memory efficient

- Refactored logic using `<algorithm>`:
  - `std::copy_if`
  - `std::remove_if`
  - `std::partition`
  - `std::stable_partition`
- Compared performance for:
  - Vector, List, Deque
  - Strategy 1 and Strategy 2
- Added **Makefile** and **CMakeLists.txt**
- Created **Final Release v1.0**

- ## Note on Large Data Files

Due to GitHub file size limitations, very large generated data files 
(e.g., students1000000.txt and larger) are not included in the repository.
These files are generated and used locally for performance testing.


---

## Project Structure

