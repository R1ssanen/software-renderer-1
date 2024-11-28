#!/bin/bash

SHADER_SYS_NAME="rohan_shaders"

if [[ $# != 1 ]]; then
    echo "[$SHADER_SYS_NAME] Invalid arguments."
    exit 1
fi

# cd to shader directory
SHADER_DIR=$1
cd $SHADER_DIR

for file in ./*.c 
do
    name=$(basename -s .c $file)
    echo "[$SHADER_SYS_NAME] Compiling shader '$name'..."
    gcc -c -Wall -Werror -fpic $file 
    gcc -shared -o lib$name.so $name.o
done

rm ./*.o
cd -

echo "[$SHADER_SYS_NAME] Shaders compiled."
exit 0

