#!/bin/bash

# Function to compile all .c and .cpp files in the current folder and specified subfolders
compile() {
    echo "Compiling all .c and .cpp files in the current folder and specified subfolders..."
    # Define an array of directories to search
    directories=( "." "./hello-world-in-openmp" "./mpi-examples" "./openmp-solutions" )

    for dir in "${directories[@]}"; do
        find "$dir" -type f \( -name "*.c" -o -name "*.cpp" \) | while read -r file; do
            # Skip utility files that don't have main()
            if [[ $file == */random.c ]] || \
               [[ $file == */random_par.c ]] || \
               [[ $file == */random_seq_lcg.c ]]; then
                continue
            fi

            output="${file%.*}.out"
            if [[ $file == */pi_mc_par.c ]]; then
                # Special case for pi_mc_par.c - include random.c in compilation
                dirname=$(dirname "$file")
                mpicc -fopenmp -Wall -O2 -o "$output" "$file" "./random.c" -I"$dirname" || { echo "Failed to compile $file"; exit 1; }
            elif [[ $file == */pi_mc.c ]]; then
                # Special case for pi_mc.c - compile with random_seq_lcg.c
                mpicc -fopenmp -Wall -O2 -c "./openmp-solutions/random_seq_lcg.c" -o random_seq_lcg.o
                mpicc -fopenmp -Wall -O2 -o "$output" "$file" random_seq_lcg.o || { echo "Failed to compile $file"; exit 1; }
                rm -f random_seq_lcg.o
            elif [[ $file == *.c ]]; then
                mpicc -fopenmp -Wall -O2 -o "$output" "$file" || { echo "Failed to compile $file"; exit 1; }
            elif [[ $file == *.cpp ]]; then
                mpic++ -fopenmp -Wall -O2 -o "$output" "$file" || { echo "Failed to compile $file"; exit 1; }
            fi
            echo "Compiled $file -> $output"
        done
    done
}

# Function to clean all .out files in the current folder and specified subfolders
clean() {
    echo "Cleaning up all .out files in the current folder and specified subfolders..."
    directories=( "." "./hello-world-in-openmp" "./mpi-examples" "./openmp-solutions" )
    for dir in "${directories[@]}"; do
        find "$dir" -type f -name "*.out" -exec rm -f {} \;
        find "$dir" -type f -name "*.o" -exec rm -f {} \;
    done
    echo "Cleanup complete."
}

# Main logic for script
case "$1" in
    compile)
        compile
        ;;
    clean)
        clean
        ;;
    *)
        echo "Usage: $0 {compile|clean}"
        exit 1
        ;;
esac
