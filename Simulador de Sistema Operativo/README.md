# Simulador de Sistema Operativo

Este proyecto fue desarrollado como parte de un trabajo práctico en la materia Sistemas Operativos. Se trata de la simulación de un sistema distribuido que implementa conceptos fundamentales de sistemas operativos, incluyendo planificación de procesos, manejo de memoria y sistemas de archivos.

## Descripción

El objetivo principal fue diseñar e implementar un sistema que permita:

- Planificar procesos utilizando algoritmos como FIFO, Round Robin (RR) y Virtual Round Robin (VRR).
- Administrar recursos compartidos y manejar solicitudes de entrada/salida.
- Implementar una memoria virtual basada en paginación, incluyendo la traducción de direcciones y una TLB.
- Gestionar un sistema de archivos simple (DialFS) con funcionalidades como creación, eliminación y truncamiento de archivos.
- Desplegar y coordinar múltiples módulos en un entorno distribuido mediante comunicación en red.

## Módulos Principales

- **Kernel**: Encargado de la planificación y coordinación entre CPU, memoria e interfaces de I/O.
- **CPU**: Simula el ciclo de instrucción de una CPU, incluyendo Fetch, Decode, Execute y Check Interrupt.
- **Memoria**: Implementa un esquema de paginación y maneja tablas de páginas y espacio de usuario.
- **Interfaces de I/O**: Gestiona interacciones con dispositivos simulados, como teclado, pantalla y un sistema de archivos básico.

## Habilidades Técnicas 

- **Programación en C**: Diseño modular y eficiente, uso de estructuras de datos y manejo de memoria dinámica.
- **Sistemas Distribuidos**: Comunicación entre procesos mediante sockets y sincronización multihilo.
- **Conceptos de Sistemas Operativos**: Planificación de procesos, administración de memoria y manejo de recursos.
- **Depuración y Testing**: Uso de logs detallados y pruebas en entornos distribuidos para asegurar el correcto funcionamiento.
- **Herramientas de Desarrollo**: Uso de Makefiles, configuración mediante archivos y control de versiones con Git.
- **Entornos virtualizados**: Configuración y uso de una máquina virtual para desarrollar y probar en un sistema operativo Linux, asegurando un entorno de trabajo aislado y reproducible.
