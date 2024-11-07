# Data Structures 
# Universidad Nacional de Colombia
# Edwin Niño

## ArrayzzzzZzzZzZzZZzzzzzZZZZz

Estructura de dato lineal en la memoria, homogenio. Es decir, almacenando un solo tipo de dato. 
Bastante básica, con métodos sencillos.

Generalmente hecho usando allocadores de memoria como malloc.
Vamos a definir el tamaño o largo de la estructura como L.

Estas estrucutra tiene un tiempo de acceso alateoreo de O(1).
Si necesitamos acceder o buscar un elemento vamos a tener O-(L).

## Matrix

Estructura de datos básica basada generalmente en Arrays que nos pemite poder almacenar información semi-homogenia
en el formato de fila/columna. Donde generalmente siempre se tiene que definir el tamaño o número de filas, sin embargo,
el número de columnas puede variar de fila a fila.

Su tiempo de acceso alateoreo es de O(1).

## Análisis de Algoritmos

Se va a basar en el añalisis asintótico de las funciones. El cual ya se ha visto anteriormente, 
aunque en esta ocación se hace principal enfoque a el tiempo de ejecución.

En general se tiene un número de entradas, valores o pasos generales de ejecución en función del tiempo de ejecución.
Para poder hacer un análisis a un algoritmo podemos tomar un módelo de maquina que nos permite poder tener en cuenta 
acciones o pasos bases de un algoritmo.

Vamos a mirar un modelo de maquina abstracta conocido como Random Access Machine o RAM.

### Random Access - Machine Model




### O, Theta and Omega notation
This is a simple notation that can be used to determine the running time of an algorithm. 
Afther doing the analisys of an algorithm with an abstract machine, we get the polynomial of a function.
With this we can see if the function is contained in a set of functions, such like:

Let f and g be functions, f(n) and g(n) the polynomial result of the function for a given n. Generaly, n tends to be infinite, or at least greater 
or equal to 0. Then, f will be a member of a set defined by g and the required notation if:

- O-notation: 
    f(n) will be in O(g(n)) or f(n) in O(g(n)) or f(n) = O(g(n)),
    if exists a Real postive constant C such that, 
    0 <= f(n) <= C * g(n); for all n >= 0
- Theta-notation: 
    f(n) will be in Theta(g(n)) or f(n) in Theta(g(n)),
    if there's an Real K, L > 0 such that,
    0 <= K * g(n) <= f(n) <= L * g(n); for all n >= 0
- Omega-notation:
    f(n) will be in Omega(g(n)) or f(n) in O(g(n)),
    if there's a Real C > 0 such that,
    0 <= C * g(n) <= f(n); for all n >= 0

There's also the non-incluve version of some notations:
- o-notation:
    ... f(n) in o(g(n)),
    if ... C > 0,
    0 <= f(n) < C * o(g(n))
- omega-notation:
    ... f(n) in omega(g(n)),
    if ... C > 0,
    0 <= C *o(g(n)) < f(n)

