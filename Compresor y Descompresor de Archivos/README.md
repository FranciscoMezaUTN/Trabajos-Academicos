# Compresor y Descompresor de Archivos - Método Huffman

## Descripción
Este trabajo implementa un compresor y descompresor de archivos de texto e imágenes en formato .bmp basado en el algoritmo de Huffman, logrando una reducción significativa en el tamaño de los archivos. Fue desarrollado en el marco de la materia Algoritmos y Estructuras de Datos.

## Tecnologías Utilizadas
- Lenguaje: C++
- Entorno de desarrollo: Eclipse

## Estructura del Trabajo
├── src/

│   ├── principal.cpp:        Archivo principal que ejecuta el programa

│   ├── auxiliar.hpp:         Funciones auxiliares para apoyar la lógica principal

│   ├── biblioteca/

│   |   ├── funciones/

│   |   │   ├── arrays.hpp:   Manejo de arreglos

│   |   │   ├── files.hpp:    Operaciones sobre archivos

│   |   │   ├── lists.hpp:    Manipulación de listas

│   |   │   ├── strings.hpp:  Procesamiento de cadenas de texto

│   |   │   ├── tokens.hpp:   Manejo de tokens en cadenas

│   |   ├── tads/

│   |   |   ├── Array.hpp:    Implementación de arreglos

│   |   |   ├── Coll.hpp:     Implementación de colecciones

│   |   |   ├── List.hpp:     Implementación de listas

│   |   |   ├── Map.hpp:      Implementación de mapas

│   |   |   ├── Queue.hpp:    Implementación de colas

│   |   |   ├── Stack.hpp:    Implementación de pilas

│   |   |   ├── huffman/

│   |   |   |   ├── BitReader.hpp:     Lectura de datos a nivel de bits

│   |   |   |   ├── BitWriter.hpp:     Escritura de datos a nivel de bits

│   |   |   |   ├── HuffmanSetup.hpp:  Configuración del algoritmo de Huffman

│   |   |   |   ├── Progress.hpp:      Seguimiento del progreso en las operaciones

├── example.bmp:              Archivo de ejemplo para probar el programa

├── README.md:                Documentación del proyecto
