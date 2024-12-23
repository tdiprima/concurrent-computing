# Compiler and flags
CC=gcc
CFLAGS=-fopenmp -O3 -Wall

# Executables
EXES=hello-openmp-1 hello-openmp-2 hello-openmp-3

# Default target
all: $(EXES)

# Individual targets
hello-openmp-1: hello-openmp-1.c
	$(CC) $(CFLAGS) -o $@ $<

hello-openmp-2: hello-openmp-2.c
	$(CC) $(CFLAGS) -o $@ $<

hello-openmp-3: hello-openmp-3.c
	$(CC) $(CFLAGS) -o $@ $<

# Clean target
clean:
	rm -f $(EXES)

# Run target (optional)
run: all
	@echo "Running hello-openmp-1:"
	./hello-openmp-1
	@echo "\nRunning hello-openmp-2:"
	./hello-openmp-2
	@echo "\nRunning hello-openmp-3:"
	./hello-openmp-3

# Phony targets
.PHONY: all clean run
