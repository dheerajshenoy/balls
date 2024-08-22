# balls

Simulation of balls in C++

# Dependencies

SDL2

# Building

```bash
cd balls && mkdir build
cmake -Bbuild -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Debug
cd build && make -j$(nproc)
```

The binary will be produced in the `bin` directory. Enjoy playing with your balls.

# Todo

[ ] Effecient overlap detection
[ ] Effecient vector operations
