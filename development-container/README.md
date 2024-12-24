## Ubuntu Development Container

This Docker setup provides a lightweight Ubuntu-based container for compiling and running C/C++ code interactively.

### What's Installed
- **Ubuntu 22.04**: Base image
- **Development Tools**:
  - `gcc`, `g++`: Compilers for C and C++
  - `libomp-dev`: OpenMP library for parallel programming
  - `openmpi-bin`, `libopenmpi-dev`: Tools for distributed computing
  - `make`: Build system
  - `vim`: Text editor
- **Utilities**:
  - `findutils`: File searching tools

### How to Use
1. **Start the Container**:

   ```bash
   docker-compose up --build
   ```

2. **Access the Container**:

   ```bash
   docker exec -it concurrent-computing bash
   ```

3. **Develop and Test Code**:
   - Create source files in the `app` directory on your host machine.
   - Example:

     ```c
     // app/hello.c
     #include <stdio.h>
     int main() {
         printf("Hello, World!\n");
         return 0;
     }
     ```

   - Compile and run inside the container:

     ```bash
     gcc hello.c -o hello
     ./hello
     ```

4. **Edit Code**:
   - Use `vim` inside the container or any editor on your host machine.

### Notes
- The `app` directory is shared between your host and container (`/usr/src/app`).
- Use this container to test code, experiment with parallel programming, or build small projects.

<br>
