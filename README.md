# Algoritmos-EstructuraDatos

## Algoritmos y Estructura de Datos

### Autor

* __@00santiagob__

## Resumen

En este repositorio se haran los codigos de distintos algoritmos de nuestro interes como los de ordenamiento, los arboles binarios, y los grafos. Ademas se hara uso de estructuras de datos.

### Temario

   1. Algoritmos de busqueda:
      * Linear search
      * Binary search
   2. Algoritmos de ordenamiento:
      * Selection sort (Ordenamiento por seleccion)
      * Insertion sort (Ordenamiento por insercion)
      * Quick sort (Ordenamiento rapido)
      * Permutation sort (Ordenamiento por permutacion)
      * Merge sort (Ordenamiento por intercalacion)
      * Heap sort (Ordenamiento por )
   3. Tipos de datos concretos:
      * Listas
      * Tuplas
   4. Tipos de datos abstractos (TAD):
      * Queue (Cola)
      * Stack (Pila)

## Requisitos

Tener instalado *__Git__* y  *__GCC__* o *___CCLANG__*, ademas tambien nos interesa tener *__Make__*, *__GDB__* y *__Valgrind__*.

> **Nota:** mas abajo se dara algunas instrucciones para ayudarlos a installar algunos programas.

## Instrucciones

Primero descargar el repositorio __Algoritmos-EstructuraDatos__:

1) Abrir una terminal:

        git clone https://github.com/00santiagob/Algoritmos-EstructuraDatos.git

2) Para correr los programas se hara usa de un Makefile en cada seccion del repositorio y alguno de los archivos en inputs.
   * **make** compila el programa.
   * **make run ./input/nombre-de-archivo.in** ejecuta el programa.
   * **make valgrind ./input/nombre-de-archivo.in** ejecuta los test con valgrind.
   * **make debug ./input/nombre-de-archivo.in** ejecuta el programa con gdb.
   * **make clean** elimina los archivos objetos ejecutables.

### Como Instalar

Hara falta tener instalado Git en su dispositivo, pero no es parte de este repositorio enseñarles a hacerlo, asi que queda en sus manos hacerlo.

#### Para Windows

Para Windows pueden utilizar [_chocolatey_](https://jcutrer.com/windows/install-chocolatey-choco-windows10).
Abrir powershell en modo administrador y correr los siguientes comandos:

        choco install make
        choco install 

#### Para Ubuntu

Abrir la terminal y correr el siguiente comando:

        sudo apt install gcc
        sudo apt install gpp
        sudo apt install gdb
        sudo apt install valgrind
        sudo apt install make
        sudo apt update && sudo apt upgrade

#### Para ALGUN-OTRO-OS

Queda pendiente. Si sos usuario de algun sistema operativo distinto a los anteriormente mencionados, te pido que ayudes a completar este instructivo.

#### Evitar errores

**Cualquier error se agradece que lo comenten abriendo una issue nueva.**

Gracias y disfruten
