![Descripción](https://img.shields.io/badge/Descripción-blue?style=for-the-badge)

- Visualizador de mapas en 3D proyectados en isométrico, basado en la librería MiniLibX de 42.  
- Lee archivos de mapa (`*.fdf`) con una malla de alturas (enteros).  
- Dibuja una representación de alambre (wireframe) en ventana gráfica.  
- Permite rotar, mover y hacer zoom en tiempo real para explorar la malla.  

![Estructura](https://img.shields.io/badge/Estructura-orange?style=for-the-badge)
```text
08.FdF-main/
├── includes/           
│   └── fdf.h              # Prototipos, structs y defines
├── srcs/                
│   ├── main.c             # Punto de entrada, gestión de MLX
│   ├── parser.c           # Lectura y almacenamiento del mapa
│   ├── draw.c             # Dibujo de líneas en isométrico
│   ├── transform.c        # Cálculo de proyecciones y matrices
│   ├── hooks.c            # Manejo de teclado (rotación/zoom/movimiento)
│   ├── utils.c            # Funciones auxiliares (ft_split, ft_atoi, etc.)
│   └── …
├── maps/                 
│   └── example.fdf        # Ejemplo de mapa de prueba
├── Makefile              # Reglas de compilación y limpieza
└── fdf                   # Ejecutable resultante
```

![Compilar el proyecto](https://img.shields.io/badge/Compilar%20el%20proyecto-blue?style=for-the-badge)

&nbsp;&nbsp;&nbsp;&nbsp;make

- make all — Compila toda la fuente y genera el ejecutable fdf.

- make clean — Elimina los objetos intermedios (*.o).

- make fclean — Además de clean, elimina fdf.

- make re — Ejecuta fclean y luego all.

![Uso](https://img.shields.io/badge/Uso-blue?style=for-the-badge)

- Para ejecutar el programa principal:

  - ./fdf maps/example.fdf

- Controles por teclado:

    -  Flechas `← ↑ → ↓´ => Mover la vista.

    -  ´+ / -´ => Zoom in / out.

    -  ´W / S´ => Rotar en X.

    -  ´A / D´ => Rotar en Y.

    -  ´Q / E´ => Rotar en Z.

    -  ´R´ => Resetear vista.

    -  ´ESC´ => Cerrar la ventana y salir.


![Autor](https://img.shields.io/badge/Autor-red?style=for-the-badge)

- Roberto del Olmo Lima
- [![GitHub](https://img.shields.io/badge/GitHub-Profile-informational?style=for-the-badge&logo=github&logoColor=white&color=181717)](https://github.com/legrol)
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/roberto-del-olmo-731746245)
