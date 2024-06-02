# Reconocimiento de imágenes de ropa : TP2 de Métodos Numéricos
## 2024, 1er cuatrimestre

## Instrucciones

1. Requerimientos:
- Python 3.8
- CMake 3.22.1

2. Bajarse los repositorios de `pybind` y `eigen` como submódulos

```
git submodule update --init --recursive

# Elegimos versiones de eigen y pybind
cd pybind11/ && git checkout v2.2.4 && cd ..
cd eigen && git checkout 3.3.7 && cd ..
```

3. Instalar requerimientos (*Previamente activar el entorno virtual. Ver  más abajo*)

```
pip install -r requirements.txt
```

4. Compilación

- Compilar el código C++ en un módulo de python
```
mkdir build
cd build
rm -rf *
cmake -DPYTHON_EXECUTABLE="$(which python)" -DCMAKE_BUILD_TYPE=Release ..
```
- Al ejecutar el siguiente comando se compila e instala la librería en el directorio `notebooks`
```
make install
```

- Si falla probar lo siguiente
```
sudo apt-get install python3-dev
sudo apt install cmake
sudo apt-get update && sudo apt-get install build-essential
```


```
make install
```

- Luego se podrá hacer directamente import desde Jupyter notebooks usando el nombre del módulo exportado (import metnum en este caso)


Listo.

### Otros directorios

En `src/` está el código de C++, en particular en `src/metnum.cpp` está el entry-point de pybind.


## Creación de un entorno virtual de python



### Directamente con python3
```
python3 -m venv .venv
source bin/activate
```

## Instalación de las depencias
```
pip install -r requirements.txt
```

## Correr notebooks de jupyter

```
cd notebooks
jupyter lab
```
o  notebook
```
jupyter notebook
```


