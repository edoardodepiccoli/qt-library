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

# Move the compiled application to the parent directory
mv qt-library.app ..

# Clean up the build directory, leaving only the Makefile
find . -not -name 'Makefile' -type f -exec rm -f {} +

# Change back to the parent directory
cd ..

# Optionally, remove the build directory if you don't need the Makefile
rm -rf $BUILD_DIR

echo "Build completed successfully."