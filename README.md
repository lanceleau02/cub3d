<div align="center">

![](https://raw.githubusercontent.com/ayogun/42-project-badges/refs/heads/main/badges/philosopherse.png)

# **cub3d**

**My first RayCaster with miniLibX**

</div>

## Features

- Implement a 3D game engine using ray-casting.  
- Render a first-person perspective view from a 2D map.  
- Support wall textures, floor, and ceiling coloring.  
- Handle player movement and rotation.  
- Parse a configuration file (`.cub`) for map layout and settings.  
- Manage keyboard inputs for interactive gameplay.  
- Ensure proper error handling for invalid maps or configurations.  

## Installation

1. Clone the repository:

```bash
git clone https://github.com/lanceleau02/cub3d.git
```

2. Navigate to the project directory:

```bash
cd cub3d
```

3. Compile the program:

```bash
make
```

## Usage

Launch the game by specifying a valid `.cub` configuration file:

```bash
./cub3d path/to/map.cub
```

The `.cub` file must include:

- A valid 2D map surrounded by walls (`1`).
- Player start position (`N`, `S`, `E`, or `W`).
- Textures for walls and RGB values for the floor and ceiling.

Use the following keys to interact with the game:

- `W`, `A`, `S`, `D`: Move the player forward, backward, or sideways.
- Arrow keys: Rotate the player's view.
- `ESC`: Exit the game.

## License

This project is licensed under the **42 School** License.

- **Educational Use Only**: This project is intended for educational purposes at the 42 School as part of the curriculum.
- **Non-commercial Use**: The code may not be used for commercial purposes or redistributed outside of the 42 School context.
- **No Warranty**: The project is provided "as-is", without any warranty of any kind.

For more details, see the [LICENSE](https://github.com/lanceleau02/Philosophers/blob/main/LICENSE) file.

## Resources

- [Ray-Casting Tutorial (Lode Vandevenne)](https://lodev.org/cgtutor/raycasting.html)  
- [Bresenham’s Line Algorithm (GeeksforGeeks)](https://www.geeksforgeeks.org/bresenhams-line-generation-algorithm/)  
- [MinilibX Documentation (42Docs)](https://harm-smits.github.io/42docs/libs/minilibx)