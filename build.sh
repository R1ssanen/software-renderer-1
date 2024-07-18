#! bin/bash

cmake -DCMAKE_BUILD_TYPE=Debug -DTERM_COLORS=OFF -GNinja -S core/ -B core/build/
cmake --build core/build/

cmake -DCMAKE_BUILD_TYPE=Debug -GNinja -S testing/ -B testing/build/
cmake --build testing/build/
