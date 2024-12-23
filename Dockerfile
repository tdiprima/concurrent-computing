# Use an official lightweight Linux distribution
FROM ubuntu:22.04

# Set the maintainer
LABEL maintainer="Your Name <your_email@example.com>"

# Update the package manager and install necessary tools
RUN apt-get update && apt-get install -y \
    build-essential \
    gcc \
    g++ \
    libomp-dev \
    make \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory in the container
WORKDIR /usr/src/app

# Copy source files to the container
COPY . .

# Default command to list available source files
CMD ["ls", "-l"]
