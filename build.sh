#!/bin/bash

cmake -DTERM_COLORS=ON -GNinja -B build/
cmake --build build/

sandbox/shaders/build_shaders.sh sandbox/shaders

