# ORUCEXE_SLC

ORUCEXE_SLC is a Qt/C++ application designed to help locate Minecraft strongholds using only **2 Ender Eyes**.

> **Note:** This application was developed for experimental and educational purposes in a short, amateur timeframe.

## Features
- Amateur Qt interface
- Input validation for coordinates and angles
- Real-time calculation
- Accuracy rate ~90% based on our tests
- Works using the **triangulation method**
- The more blocks you move away in the second step as shown in the app, the higher the accuracy

### Tutorials & References
- To learn how to use the app, watch this [video](your-video-link)  

---

## Getting Started

### 1. Run Prebuilt Windows Version
- Navigate to the `bin` folder.
- Download `ORUCEXE_SLC_Windows.zip`.
- Extract and run `ORUCEXE_SLC.exe`.
- Users can run it directly without installing Qt or any dependencies.

### 2. Build from Source
**Requirements:**
- Qt 6.x
- CMake 3.16 or higher
- C++17 compiler

**Steps:**
```bash
git clone https://github.com/username/ORUCEXE_SLC.git
cd ORUCEXE_SLC
mkdir build && cd build
cmake .. -G "MinGW Makefiles"
cmake --build . --config Release
