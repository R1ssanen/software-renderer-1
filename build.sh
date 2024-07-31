#! bin/bash

cmake -DCMAKE_BUILD_TYPE=Release -DTERM_COLORS=OFF -GNinja -S corelib/ -B corelib/build/
cmake --build corelib/build/

cmake -DCMAKE_BUILD_TYPE=Release -GNinja -S testing/ -B testing/build/
cmake --build testing/build/
