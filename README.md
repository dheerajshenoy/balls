# balls

Simulation of balls in C++.

# Demo

https://github.com/user-attachments/assets/d3ccf691-7886-46bf-8925-25b8eb24d38c

# Dependencies

SDL2

# Building

```bash
cd balls && mkdir build
cmake -Bbuild -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Debug
cd build && make -j$(nproc)
```

The binary will be produced in the `bin` directory. Enjoy playing with your balls.

# Features

Creates balls of random radius, position, velocity, mass and color, but also making sure that all the balls appears inside the simulation box a.k.a the window. Resizing the window effects the boundary collision.


# Todo
- [x] Boundary collision
- [x] Ellastic collision
- [ ] Effecient overlap detection
- [ ] Effecient vector operations
