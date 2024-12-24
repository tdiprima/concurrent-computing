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
    vim \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory in the container
WORKDIR /usr/src/app

# Start an interactive Bash shell by default
CMD ["bash"]
