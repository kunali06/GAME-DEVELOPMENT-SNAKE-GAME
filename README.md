# GAME-DEVELOPMENT-SNAKE-GAME

COMPANY: CODTECH IT SOLUTIONS

NAME: KUNALI BHAVARTHE

INTERN ID: CT2MTXEI

DOMAIN: C++ PROGRAMMING

DURATION: 8 WEEEKS

MENTOR: NEELA SANTHOSH

## 🪟 For Windows (with Code::Blocks or Visual Studio)

### 🔧 Option A: Using Code::Blocks

1. **Download SFML**
   - Go to: [https://www.sfml-dev.org/download.php](https://www.sfml-dev.org/download.php)
   - Choose **"GCC 7.3.0 MinGW (DW2) - 32-bit"** or a version that matches your compiler.
   - Extract the zip file (e.g., `C:\SFML`)

2. **Configure Code::Blocks**
   - Open Code::Blocks, go to **Settings > Compiler > Search directories**
     - Add `C:\SFML\include` under **Compiler**
     - Add `C:\SFML\lib` under **Linker**
   - Then go to **Project > Build options > Linker Settings**
     - Add these SFML libraries:
       ```
       sfml-graphics
       sfml-window
       sfml-system
       ```
   - Copy DLL files from `C:\SFML\bin` to your project folder (where your `.exe` is).

---

### 🔧 Option B: Using Visual Studio

1. **Download SFML for Visual C++**
   - Download the **Visual C++ 15 (2017) - 32-bit or 64-bit** version.
   - Extract it, e.g., `C:\SFML`

2. **Configure Visual Studio Project**
   - Right-click your project > Properties
   - Under **C/C++ > General > Additional Include Directories**:
     ```
     C:\SFML\include
     ```
   - Under **Linker > General > Additional Library Directories**:
     ```
     C:\SFML\lib
     ```
   - Under **Linker > Input > Additional Dependencies**:
     ```
     sfml-graphics.lib
     sfml-window.lib
     sfml-system.lib
     ```

3. **Copy DLLs**
   - From `C:\SFML\bin`, copy these to your build folder:
     ```
     sfml-graphics-2.dll
     sfml-window-2.dll
     sfml-system-2.dll
     ```

---

## 🍎 For macOS (with Homebrew)

### 🛠️ Steps:

1. Install SFML using Homebrew:
   ```bash
   brew install sfml
   ```

2. When compiling your code, link SFML like this:
   ```bash
   g++ -std=c++11 main.cpp -o Snake -lsfml-graphics -lsfml-window -lsfml-system
   ```

---

## 🐧 For Linux (Ubuntu/Debian)

### 🛠️ Install via apt:
```bash
sudo apt update
sudo apt install libsfml-dev
```

### 🛠️ Compile your project:
```bash
g++ -std=c++11 main.cpp -o Snake -lsfml-graphics -lsfml-window -lsfml-system
```

---

## ✅ Check Installation

To make sure SFML is working:
1. Try compiling a simple “Hello SFML” window.
2. Run your Snake game code.



#output
![Image](https://github.com/user-attachments/assets/8b589d99-13d1-46a2-9e75-f113646d3be6)
![Image](https://github.com/user-attachments/assets/5ce3c612-777d-420c-b836-8d7792a43b95)
![Image](https://github.com/user-attachments/assets/ab2173f2-52ce-41f6-bee3-8090627cb59e)
![Image](https://github.com/user-attachments/assets/ed04e5cc-26c1-4f66-acd0-9df25a9ed4dd)
