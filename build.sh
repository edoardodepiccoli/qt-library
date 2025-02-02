#!/bin/bash

# Exit immediately if a command exits with a non-zero status
set -e

# Define the build directory
BUILD_DIR="build"

# Delete the build directory if it exists
if [ -d "$BUILD_DIR" ]; then
    rm -rf $BUILD_DIR
fi

# Create the build directory
mkdir -p $BUILD_DIR

# Change to the build directory
cd $BUILD_DIR

# Run qmake to generate the Makefile
qmake ..

# Build the project using make
make

echo "Build completed successfully in $BUILD_DIR."

# Run the application
cd ..

echo "Running the application..."

echo -e "\n####################################################################################################\n"

./build/qt-library
