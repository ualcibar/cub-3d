<p align="right"><a href="README.md">English</a></p>

<h1 align="center">🎮 Cub3D</h1>
<h3 align="center">Proyecto del Common Core — 42 Urduliz</h3>

<p align="center">
  <img src="https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white" />
  <img src="https://img.shields.io/badge/MinilibX-000000?style=flat" />
  <img src="https://img.shields.io/badge/42-000000?style=flat&logo=42&logoColor=white" />
</p>

## 📖 Descripción

**Cub3D** es un proyecto del Common Core de 42 inspirado en el primer FPS de la historia. Consiste en construir, en C, un **motor de raycasting** en primera persona que renderiza una vista 3D dinámica dentro de un laberinto 2D, usando la librería gráfica **MinilibX** — sin usar ningún motor 3D ya existente.

## ✨ Funcionalidades

- **Motor de raycasting** que renderiza paredes, suelo y techo en tiempo real
- **Parser del mapa** con comprobación de errores (valida que el mapa esté correctamente cerrado)
- **Movimiento y rotación** en tiempo real (WASD + ratón/flechas)
- **Paredes texturizadas**, con textura distinta según orientación (N/S/E/O)
- **Libft propia** usada a lo largo de todo el proyecto
- Target `bonus` con funcionalidades extra (minimapa, puertas, etc., según la implementación)

## 🛠️ Tecnologías

- **Lenguaje:** C
- **Librería gráfica:** MinilibX
- **Compilación:** Makefile

## 🚀 Uso

```bash
git clone <url-del-repo>
cd cub-3d
make
./cub3d maps/<archivo_mapa>.cub
```

## ⚙️ Comandos del Makefile

| Comando | Qué hace |
|---|---|
| `make` / `make all` | Compila `libft` y MinilibX, y luego genera el binario `cub3d` |
| `make clean` | Elimina los archivos objeto (también limpia `libft` y `mlx`) |
| `make fclean` | Ejecuta `clean` y además elimina el binario `cub3d` |
| `make bonus` | Recompila el proyecto incluyendo las funcionalidades bonus |
| `make re` | Ejecuta `fclean` seguido de `all` — recompilación completa desde cero |

## 🧠 Aprendizajes

- Algoritmos de **raycasting** y proyección 3D a partir de un mapa 2D
- Parseo y validación de un **formato de mapa propio**
- Renderizado en tiempo real y **gestión de eventos** con MinilibX
- Trabajo con **texturas** y buffers de imagen píxel a píxel
- Gestión de memoria y estructura modular de un proyecto en C

## 👥 Equipo

Este proyecto lo hice junto a mi compañero **[Llopeando](https://github.com/Llopeando)**, dentro del Common Core de 42.

## 👤 Autor

**Unai Alcibar** — [42 Urduliz](https://github.com/ualcibar) · [LinkedIn](https://www.linkedin.com/in/unai-alcibar)

---

<p align="center"><i>Proyecto evaluado mediante peer-review según la metodología de 42.</i></p>
