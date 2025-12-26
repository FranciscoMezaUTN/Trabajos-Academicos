# Aplicación Web de Gestión y Visualización de Hechos Geolocalizados

Este proyecto fue desarrollado como parte de un trabajo práctico para la materia Diseño de Sistemas de Información. Se trata de una aplicación web full-stack orientada a microservicios, diseñada para la recolección, publicación y visualización interactiva de hechos geolocalizados en tiempo real.

## Descripción

El objetivo principal fue diseñar e implementar un sistema distribuido que permita:

- Publicar y gestionar hechos/eventos vinculados a coordenadas geográficas específicas.
- Visualizar datos en un mapa interactivo con filtros dinámicos por categorías, fechas y fuentes.
- Implementar una arquitectura orientada a microservicios para separar la lógica de agregación de datos de la interfaz de usuario.
- Consumir APIs externas y servicios internos mediante comunicación asíncrona y reactiva.
- Garantizar la integridad y persistencia de grandes volúmenes de datos geográficos.

## Módulos Principales

- **Fuente Estática**: Encargada de la extracción y procesamiento de datos desde orígenes persistentes y locales (como archivos CSV o bases de datos internas) para alimentar el sistema con información histórica o base.
- **Fuente Dinámica**: Responsable de la obtención de información en tiempo real mediante aportes de los usuarios, permitiendo la actualización constante de los hechos geolocalizados.
- **Fuente Proxy**: Actúa como un componente intermediario que estandariza la comunicación con servicios de terceros, gestionando la transformación de datos externos a un formato compatible con el sistema interno.
- **Servicio Agregador**: El núcleo del back-end; centraliza la información proveniente de todas las fuentes, aplica filtros de lógica de negocio y expone una API unificada para la visualización de los hechos.
- **Servicio de Estadísticas**:  Módulo especializado en el procesamiento analítico de los datos recolectados para generar métricas, tendencias y reportes sobre la actividad en el sistema.
- **Gestión de Usuarios**: Administra la seguridad del sistema, manejando la autenticación, autorización y perfiles de usuario, asegurando que el acceso a las funciones de administración esté debidamente protegido.

## Habilidades Técnicas 

- **Back-end Development**: Implementación de servicios con Java y Spring Boot, creación de APIs REST y uso de WebClient para comunicación entre servicios.
- **Persistencia de Datos**: Gestión de bases de datos con MySQL, modelado de entidades complejas y optimización de consultas gracias a Hibernate. 
- **Front-end Development**: Creación de interfaces dinámicas utilizando JavaScript, HTML, CSS, y Thymeleaf con integración de librerías de mapas y manejo de formularios estáticos y asíncronos.
- **Arquitectura y Calidad**: Diseño de sistemas basados en Microservicios y aplicación de estándares de calidad ISO 25000 para asegurar un código mantenible y eficiente.
- **Cloud & DevOps**: Colaboración en el despliegue de la infraestructura utilizando servicios de nube de AWS y control de versiones con GitHub.
- **Herramientas de Desarrollo**: Gestión de dependencias con Maven, configuración de entornos distribuidos y depuración técnica mediante logs de servidor.

