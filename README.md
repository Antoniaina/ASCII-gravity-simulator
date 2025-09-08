### Gravity Simulator (Terminal)

Simple 2D gravity simulation rendered in the terminal with ANSI colors. A single ball moves inside a bounded area, bounces elastically on the walls, and a HUD displays live values (time, velocity, position, gravity, restitution).

### How it works
- **Physics**: Semi-implicit Euler integration. Vertical velocity increases by gravity, position updates, and collisions against the box invert velocity with a restitution factor.
- **Engine**: Holds simulation state (time and balls) and updates all balls each frame.
- **Renderer**: Draws a HUD and the simulation area using ANSI escape codes. Only changed cells are reprinted for efficiency.

### Project structure
- `include/`
  - `physics.h`: `Ball` struct and physics update API
  - `engine.h`: `Engine` struct and engine update API
  - `render.h`: Rendering types, constants, and API
- `src/`
  - `physics.c`: `updateBall` (gravity + wall collisions)
  - `engine.c`: `initEngine`, `updateEngine`
  - `render.c`: Screen buffer, HUD, and diff-based frame rendering
  - `main.c`: Simulation loop, parameters, and per-frame rendering

### Build
Requirements: a C11 compiler and a terminal that supports ANSI escape sequences.

Windows (MinGW-w64):
```bash
gcc -std=c11 -O2 -Iinclude src/*.c -o sim.exe -lwinpthread
```

Linux/macOS:
```bash
gcc -std=c11 -O2 -Iinclude src/*.c -o sim
```

Notes:
- On Windows, use Windows Terminal or a recent PowerShell/Terminal with ANSI enabled. The provided `sim.exe` may already run without building.
- Terminal size should be at least `TOTAL_WIDTH x TOTAL_HEIGHT` from `include/render.h`.

### Run
Windows:
```bash
./sim.exe
```

Linux/macOS:
```bash
./sim
```

Press Ctrl+C to quit.

### Configure / tweak
- Gravity and restitution: edit `GRAVITY` and `RESTITUTION` in `src/main.c`.
- Initial position/velocity and number of balls: edit `initEngine` in `src/engine.c` (default uses one ball).
- Render dimensions and HUD layout: edit constants in `include/render.h`.

### Limitations
- Single-ball simulation by default (expandable up to `MAX_BALLS`).
- No user input or persistence; parameters are compile-time constants.

