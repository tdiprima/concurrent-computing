# OpenMP-C-Docker Setup

This repository contains multiple C and C++ files utilizing OpenMP for parallel programming. The setup includes a Docker container with all required tools to compile and run these files.

## Prerequisites

- Docker installed on your system.
- Basic familiarity with terminal commands.

## Setting Up the Docker Container

1. Build the Docker image:

   ```sh
   docker build -t openmp-c-container .
   ```

2. Run the container interactively:

   ```sh
   docker run --rm -it -v $(pwd):/usr/src/app openmp-c-container bash
   ```

   The `-v $(pwd):/usr/src/app` flag mounts the current directory into the container so that changes persist.

## Compiling the Files

Inside the container:

1. Compile all source files using the Makefile:

   ```bash
   make
   ```

2. To clean compiled files:

   ```bash
   make clean
   ```

## Running the Executables

After compilation, each `.c` or `.cpp` file will have a corresponding `.out` executable. Run them using:

```bash
./<filename>.out
```

For example, if you have a file named `program.c`, compile and run it as follows:

```bash
./program.out
```

## Using OpenMP

OpenMP is enabled by the `-fopenmp` flag in the compilation settings. Ensure that any `#pragma omp` directives in your source files are correctly formatted and placed.

## Notes

- Edit the source files on your host system, and they will be reflected inside the container due to the mounted volume.
- Make sure to add new `.c` or `.cpp` files in the repository and rerun `make` to compile them.

Enjoy experimenting with OpenMP and Docker!
```

### Verification Steps
- Place all `.c` and `.cpp` files in the same directory as the Dockerfile and Makefile.
- Build and run the container using the instructions provided.
- Ensure the Makefile compiles all source files correctly, and executables run without errors.

<br>
