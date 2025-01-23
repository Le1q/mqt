REM clean build
cmake --build build --target clean

cmake -DCMAKE_PREFIX_PATH=C:\Qt\6.5.3\msvc2019_64 -S . -B build
cmake --build build --config Debug