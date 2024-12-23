# Use an official lightweight Linux distribution
FROM ubuntu:22.04

# Set the maintainer
LABEL maintainer="Tammy DiPrima <tammy.diprima@stonybrook.edu>"

# Update the package manager and install necessary tools
RUN apt-get update && apt-get install -y \
    build-essential \
    gcc \
    g++ \
    libomp-dev \
    openmpi-bin \
    libopenmpi-dev \
    make \
    findutils \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory in the container
WORKDIR /usr/src/app

# Copy the current directory and all subdirectories to the container
COPY . .

# Add a script for compiling and cleaning files recursively
COPY compile_and_clean.sh /usr/src/app/compile_and_clean.sh
RUN chmod +x /usr/src/app/compile_and_clean.sh

# Compile all files in the main and subdirectories by default
RUN ./compile_and_clean.sh compile

# Default command to list compiled executables
CMD ["find", ".", "-name", "*.out"]
