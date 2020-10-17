## STM32 CubeMX + Cmake

### Introduction
On GitHub repository [stm32-cmake-blinking-led](https://github.com/gembcior/stm32-cmake-blinking-led) you can find simple example how you can use CMake with C++ for STM32 development.
The code itself doesn't do anything special, just the led blinks.
The main purpose of this example is to show how `STMCube` and `STMCubeMX` can be integrated with CMake.

### Project structure
```
📦stm32-cmake-blinking-led
 ┣━📂cmake              ─ contains all additonal CMake files neccessary to build project
 ┃ ┣━📂defaults         ─ contains file with default cache variables
 ┃ ┣━📂modules          ─ contains all CMake modules files
 ┃ ┗━📂toolchain        ─ contains toolchain file
 ┣━📂cubemx             ─ CubeMX project and all generated files
 ┣━📂source             ─ application sources divided into libraries
 ┃ ┗━📜CMakeLists.txt   ─ application CMake file
 ┣━📂utils              ─ contains some useful files for stm32 development
 ┗━📜CMakeLists.txt     ─ top level CMake file
```

### Requirements
The project is designed base on STM32 Nucleo-32 board with `STM32L432KC` microcontroller. It was developed on Linux based machine. For properly build the project you will need:
 - Linux based machine [^1],
 - CMake >= 3.16,
 - [STMCube repository for STM32L4 series](https://github.com/STMicroelectronics/STM32CubeL4),
 - [GNU Arm Embedded Toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads),
 - [STM32CubeProgrammer](https://www.st.com/en/development-tools/stm32cubeprog.html) (not required for project compilation).

In the project there is one crucial file:

```
📦stm32-cmake-blinking-led
 ┗━📂cmake
   ┗━📂defaults
     ┗━📜stm32_cache.cmake
```

There are variables that point to required tools to build the project.
It is important to set these variables correctly in order to build this project.

```cmake
set(STM32_TOOLCHAIN $ENV{HOME}/tools/toolchains/gcc-arm-none-eabi-9-2020-q2-update CACHE PATH "")
set(STM32_CUBE $ENV{HOME}/tools/STM32/STM32Cube/STM32CubeL4 CACHE PATH "")
set(STM32_CHIP "STM32L432xx" CACHE STRING "")
set(STM32_CHIP_FAMILY "STM32L4" CACHE STRING "")
set(STM32_CUBE_PROGRAMMER $ENV{HOME}/tools/STM32/STM32CubeProgrammer/bin/STM32_Programmer_CLI CACHE PATH "")
```

### STMCube integration

In the project there are a few major files responsible for `STM32Cube` and `STM32CubeMX` integration.

##### STM32CubeMX project
```
📦stm32-cmake-blinking-led
 ┗━📂cubemx
   ┣━📂Inc
   ┣━📂Src
   ┗━📜cubemx.ioc
```
There is `STM32CubeMX` project file and all generated files.
These files are copied to cubemx library in the source directory.
The main reason why these files are copied is to separate pure generated file from actual application code.

```
📦stm32-cmake-blinking-led
 ┗━📂source
   ┗━📂cubemx
```

Generated files can be use as is. The only change is in `main.h` and `main.c` file. The `main()` function was deleted and declaration of `SystemClock_Config` function was added to make it visible from other libraries.
Otherwise, the compiler will show an error that it cannot see this function.

```cpp
/* USER CODE BEGIN EFP */
void SystemClock_Config(void);
/* USER CODE END EFP */
```

##### STM32Cube HAL wrappers
```
📦stm32-cmake-blinking-led
 ┗━📂source
   ┗━📂hal
```

There is a hal library which contain C++ wrappers for STM32Cube HAL drivers.
Its purpose is to simplify usage of STM32Cube HAL with C++ language.
The idea is to make wrappers for all used STM32Cube HAL drivers and after that use these wrappers in the application code.

##### CMake find modules
```
📦stm32-cmake-blinking-led
 ┗━📂cmake
   ┗━📂modules
     ┣━📜FindCMSIS.cmake
     ┗━📜FindSTM32HAL.cmake
```

One of the most important files are CMake find modules.
These modules are responsible for finding source and header files of the CMSIS library and STM32Cube HAL drivers.

### How to build

Clone the repository and cd to project directory:

```shell
git clone https://github.com/gembcior/stm32-cmake-blinking-led.git
cd stm32-cmake-blinking-led
```

Create workspace directory for build and cd into it:

```shell
mkdir build
cd build
```

Generate CMake project:

```shell
cmake ../
```

Run build command:

```shell
cmake --build .
```

### Programming device
You can use CMake target **stm32-flash** to program application to the device over SWD interface.
<br>
Simply run:

```shell
cmake --build . --target stm32-flash
```

This requires STM32CubeProgrammer installed and properly set path to it in **stm32_cache.cmake** file.
See [Requirements](#requirements).

### Project in action

![in_action](https://mywayof.dev/assets/img/stm32_cubemx_with_cmake/in_action.webp)

---

[^1]: After some tweaks, there is a chance that this project can also be compiled on Windows based machine.
