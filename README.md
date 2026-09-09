<p align="right"><a href="README.es.md">Español</a></p>

<h1 align="center">🎮 Cub3D</h1>
<h3 align="center">42 Common Core project — 42 Urduliz</h3>

<p align="center">
  <img src="https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white" />
  <img src="https://img.shields.io/badge/MinilibX-000000?style=flat" />
  <img src="https://img.shields.io/badge/42-000000?style=flat&logo=42&logoColor=white" />
</p>

## 📖 Description

**Cub3D** is a 42 Common Core project inspired by the first FPS ever made. It consists of building, in C, a first-person **raycasting engine** that renders a dynamic 3D view inside a 2D maze, using the **MinilibX** graphics library — no existing 3D engine allowed.

## ✨ Features

- **Raycasting engine** rendering walls, floor and ceiling in real time
- Custom **map parser** with error checking (validates the map is properly closed)
- Real-time **movement and rotation** (WASD + mouse/arrow look)
- **Textured walls**, with a different texture per orientation (N/S/E/W)
- Custom **libft** used throughout the project
- `bonus` target with extra features (minimap, doors, etc., depending on the implementation)

## 🛠️ Tech stack

- **Language:** C
- **Graphics library:** MinilibX
- **Build:** Makefile

## 🚀 Usage

```bash
git clone <repo-url>
cd cub-3d
make
./cub3d maps/<map_file>.cub
```

## ⚙️ Makefile commands

| Command | What it does |
|---|---|
| `make` / `make all` | Compiles `libft` and MinilibX, then builds the `cub3d` binary |
| `make clean` | Removes object files (also cleans `libft` and `mlx`) |
| `make fclean` | Runs `clean` and also removes the `cub3d` binary |
| `make bonus` | Rebuilds the project including the bonus features |
| `make re` | Runs `fclean` followed by `all` — full rebuild from scratch |

## 🧠 What I learned

- **Raycasting** algorithms and 3D projection from a 2D map
- Parsing and validating a **custom map format**
- Real-time rendering and **event handling** with MinilibX
- Working with **textures** and per-pixel image buffers
- Memory management and modular C project structure

## 👥 Team

This project was built together with my teammate **[Llopeando](https://github.com/Llopeando)** as part of the 42 Common Core.

## 👤 Author

**Unai Alcibar** — [42 Urduliz](https://github.com/ualcibar) · [LinkedIn](https://www.linkedin.com/in/unai-alcibar)

---

<p align="center"><i>Project evaluated through peer-review, following 42's methodology.</i></p>
