#!/bin/sh

echo "test $#"
if [ "$#" -ne 1 ]
then
  echo "Usage: Must provide input file"
  echo "Example : [sh run.sh \"orders coding test developer.dat\"]"
  exit 1
fi

FILE=$1
BUILD_DIR="build"
mkdir ${BUILD_DIR}
cd ${BUILD_DIR}
cmake ..
make all
cd ..

./build/DaVinci "${FILE}"



