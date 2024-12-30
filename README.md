# cppcrate

`cppcrate` is a lightweight tool for initializing C++ projects, inspired by Rust's `cargo`. The project is still in its early stages, with basic functionality to create a standard project directory structure and starting files.

---

## Features

- **Project Initialization**:
  - Automatically generates a C++ project directory structure.
  - Creates essential starting files, including:
    - `main.cpp`
    - `test_main.cpp`
    - `cppcrate.toml`
    - `Makefile`

---

## Current Functionality

Running `cppcrate new <project_name>` creates the following directory structure:
```
<project_name>/
├── include/
├── src/
│   └── main.cpp
├── tests/
│   └── test_main.cpp
├── cppcrate.toml
└── Makefile
```

---

## Installation

### Prerequisites

- C++17 or later
- Boost Filesystem Library

### Build Instructions

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/cppcrate.git
   cd cppcrate
   ```

2. Build the project:
   ```bash
   make
   ```

---

## Usage

To initialize a new project, run:
```bash
./main new <project_name>
```

This creates the project directory and populates it with the starting files.

---

## Status

`cppcrate` is in its early stages of development. Current progress includes:
- Generating the initial project directory structure.
- Creating predefined starting files.

Stay tuned for updates as we expand its functionality!

---
