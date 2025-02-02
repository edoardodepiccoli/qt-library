#!/bin/bash

# Exit immediately if a command exits with a non-zero status
set -e

# Define the build directory
BUILD_DIR="build"

# Create the build directory if it doesn't exist
mkdir -p $BUILD_DIR

# Change to the build directory
cd $BUILD_DIR

# Run qmake to generate the Makefile
qmake ..

# Build the project using make
make

echo "Build completed successfully in $BUILD_DIR."
