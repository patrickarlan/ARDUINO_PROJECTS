# PlatformIO Arduino Projects

This project demonstrates different approaches for managing multiple Arduino projects in PlatformIO.

## Current Setup

This workspace contains multiple environments configured in `platformio.ini`:

### Environments:
- **`uno`** - Compiles all `.cpp` files for Arduino Uno
- **`project2_nano`** - Compiles all `.cpp` files for Arduino Nano  
- **`relay_project`** - Compiles **only** `relay.cpp` for Arduino Uno

### Source Files:
- `src/main.cpp` - Main Arduino project
- `src/relay.cpp` - Relay control project

## Building & Uploading

### Build All Environments:
```bash
pio run
```

### Build Specific Environment:
```bash
# Build main project for Uno
pio run -e uno

# Build relay project only
pio run -e relay_project

# Build for Nano
pio run -e project2_nano
```

### Upload to Board:
```bash
# Upload relay project
pio run -e relay_project --target upload

# Upload main project
pio run -e uno --target upload

# Upload to Nano
pio run -e project2_nano --target upload
```

### Other Useful PlatformIO Commands:
```bash
# Clean build files
pio run --target clean

# Monitor serial output
pio device monitor

# List connected devices
pio device list

# Build with verbose output
pio run -v -e relay_project

# Check project configuration
pio project config

# Install library
pio lib install "library_name"
```

## Approach 1: Single Project with Multiple Environments (Current Setup)

**When to use:** Testing the same code on different boards, or related projects that share some code.

### Adding New Environment:
1. Add new environment in `platformio.ini`:
```ini
[env:new_project]
platform = atmelavr
board = uno
framework = arduino
src_filter = -<*> +<new_project.cpp>  ; Compile only this file
```

2. Create `src/new_project.cpp` file

### Source Filter Options:
```ini
src_filter = -<*> +<file.cpp>        # Only compile file.cpp
src_filter = +<file.cpp>             # Compile all files + file.cpp  
src_filter = -<main.cpp>             # Compile all except main.cpp
```

## Approach 2: Separate Project Folders (Recommended for Different Projects)

**When to use:** Completely different, unrelated Arduino projects.

### Folder Structure:
```
ARDUINO_PROJECTS/
├── PROJECT_1/
│   ├── platformio.ini
│   ├── src/
│   │   └── main.cpp
│   ├── lib/
│   └── include/
├── PROJECT_2/
│   ├── platformio.ini
│   ├── src/
│   │   └── main.cpp
│   ├── lib/
│   └── include/
└── PROJECT_3/
    ├── platformio.ini
    ├── src/
    │   └── main.cpp
    ├── lib/
    └── include/
```

### Creating New Separate Project:

1. **Create new project folder:**
```bash
cd c:\Users\HP\Documents\ARDUINO_PROJECTS
mkdir NEW_PROJECT
cd NEW_PROJECT
```

2. **Initialize PlatformIO project:**
```bash
pio project init --board uno
```

3. **Or manually create structure:**
```
NEW_PROJECT/
├── platformio.ini
├── src/
├── lib/
├── include/
└── test/
```

4. **Create `platformio.ini`:**
```ini
[env:uno]
platform = atmelavr
board = uno
framework = arduino
```

5. **Create `src/main.cpp`:**
```cpp
#include <Arduino.h>

void setup() {
  // Your setup code
}

void loop() {
  // Your main code
}
```

### Opening Separate Projects in VS Code:
- **Option A:** Open each project folder individually
- **Option B:** Use VS Code workspace file to manage multiple projects:
  - File → Add Folder to Workspace
  - Save as `.code-workspace` file

## Common Arduino Boards:
- `uno` - Arduino Uno
- `nanoatmega328` - Arduino Nano
- `megaatmega2560` - Arduino Mega  
- `leonardo` - Arduino Leonardo
- `pro16MHzatmega328` - Arduino Pro Mini
- `esp32dev` - ESP32
- `nodemcuv2` - NodeMCU ESP8266

## Tips:
- Use **single project** (current setup) for related projects or testing same code on different boards
- Use **separate projects** for completely different, unrelated Arduino projects  
- Keep source filters simple: `-<*> +<file.cpp>` for exclusive compilation
- Each environment can have different libraries, build flags, and upload settings

## Resources:
- [PlatformIO Documentation](https://docs.platformio.org/)
- [platformio.ini Reference](https://docs.platformio.org/page/projectconf.html)