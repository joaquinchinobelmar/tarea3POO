# Tarea 3 Programación Orientada a Objetos

Integrantes: Benjamin Arias Vega	202230007-8

Joaquin Belmar		202330003-9


Adjunto Link de Repositorio

https://github.com/joaquinchinobelmar/tarea3POO


## Requisitos: C++ y QT

Para todas las fases de esta tarea, hay que trabajar con C++ y QT, para lo que se recomienda usar el programa que nosotros usamos, [CLion](https://www.jetbrains.com/es-es/clion/). Para ejecutar QT en Clion, se deben seguir las siguientes instrucciones:

1. Descargar [QT desde su página oficial](https://www.qt.io/download-qt-installer), se necesitará una cuenta.
2. Ejecutar el instalador e instalar la última versión de QT, asegurando que se instala QTCreator.
3. Al finalizar la instalación, se mostrará la ubicación donde se instaló QT, presione esa ubicación. Dentro de la carpeta, abra la carpeta con el número de la versión, y luego abra la carpeta de mingw_64. Copie esa dirección. Generalmente, estas ubicaciones se ven así:

```bash
  C:\Qt\6.9.1\mingw_64
```
4. Abra Clion.
5. En caso que Clion no haya detectado a QT, vaya a File > Settings.
6. Busque Build, Execution, Deployment > Toolchains
7. Asegurese que Clion detecte MinGW.
8. En Build, Execution, Deploymen, busque CMake.
9. Asegurese que en Toolchain se use MinGW.
10. Busque el espacio de CMake options.
11. Ponga el siguiente argumento:
```bash
  -DCMAKE_PREFIX_PATH=<Ruta de la carpeta>
```
En nuestro caso, quedaría así:

```bash
  -DCMAKE_PREFIX_PATH=C:\Qt\6.9.1\mingw_64
```
12. Dele click en Apply, y cierre las opciones.

Con todo verificado y configurado, ya está listo para ejecutar a través de Clion.

## Ejecución en Clion con configuración de proyecto

Para ejecutar desde este programa, tan solo hay que abrir la carpeta del repositorio clonado, y configurar el proyecto para que pueda usar QT. Para esto, se deben hacer los siguientes pasos (despúes de terminar la configuración anterior):

### Cambiar configuración del archivo principal

1. En el lado superior derecho, haga click donde se ve "Tarea3_PubSubSimulator_Etapa1", y haga click en "Edit Configurations...".
2. En la sección "Environment variables", haga click en el icono de la derecha de la barra (el que dice "Edit environment variables").
3. Agregue una variable, que tenga de nombre "Name" el nombre de PATH.
4. En la parte de Value, haga doble click, y agregue lo siguiente:

```bash
  <Ruta de la carpeta>\bin;%PATH%
```
Ergo, debe ser la carpeta de mingw copiada anteriormente, con la subcarpeta \bin, sumandole ";%PATH%". En nuestro caso, queda así:

```bash
  C:\Qt\6.9.1\mingw_64\bin;%PATH%
```
5. Presiona "Apply" y "Ok".

Y ya puede ejecutar el programa con QT con el boton "Run".

## Etapas de desarrollo

El desarrollo del simulador se realizo de forma iterativa e incremental, abordando las etapas definidas en el enunciado.

### Etapa 1: Publicador y Suscriptor de Video

1. Se implementaron las clases base:
    -"Component", "Broker", "Topic", "Publisher", "Subscriber"
2. Se crearon las clases:
    -"VideoPublisher": esta muestra un campo de texto para ingresar una URL.
    -"VideoFollower": boton que muestra el ultimo URL publicado.
3. El "VideoPublisher" publica el URL al presionar Enter.
4. El boton del "VideoFollower" se actualiza con cada nueva publicación (sin reproducir aun).
5. Se uso "Stage1.cpp" como archivo principal.

### Etapa 2: Reproducción de Video

1. Se completo la clase "VideoFollower" para que reaccione al boton.
2. Al presionar el boton, se reproduce el video correspondiente usando "QMediaPlayer" y "QVideoWidget".
3. Se utilizaron ejemplos de reproduccion proporcionados por el curso.

### Etapa 3: Publicador y Suscriptor GPS

1. Se implemento la clase "GPSCarPublisher", que permite:
    -Seleccionar un archivo ".txt" con posiciones GPS usando "QFileDialog".
    -Leer lineas del tipo "<tiempo> <x> <y>".
    -Usar "QTimer" para enviar posiciones cada segundo.
    -Interpolar posiciones intermedias entre dos tiempos para simular movimiento continuo.
2. Se implemento "GPSFollower" que muestra en una ventana separada:
    -Tiempo actual.
    -Coordenadas "(x, y)" del movil.
    -Texto que se actualiza en tiempo real.

### Etapa 4: Funcionalidades completas

1. Se integraron:
    -Publicador de video.
    -Publicador GPS.
    -Ambos suscriptores en una misma interfaz (dos a la izquierda, dos a la derecha).
2. El suscriptor GPS ahora también muestra un circulo movil usando "QPainter".
3. El sistema opera completamente con publicacion/suscripcion por topico.

### Extra-credito: Ajuste de Volumen para reproductor de Video

1. Se agregó un "QSlider" debajo del boton del "VideoFollower".
2. Permite ajustar el volumen del reproductor de video en tiempo real.

## Comentarios Finales

1. Se utilizaron C++ y la biblioteca Qt para GUI.
2. El sistema fue probado en CLion con Qt 6.9.1 y ejecutado correctamente.
3. Este archivo contiene el diagrama de clases UML solicitado en la tarea
