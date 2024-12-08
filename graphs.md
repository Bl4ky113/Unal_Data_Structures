## Graphs
## Cormen, Wikipedia, et all

Grafos. 

Son una estructura matemática que se componene de una pareja de conjuntos V y E. 
Donde V van a ser los vertices, vertex, del grafo y E sus edges, edge o arista.

Estos edges son incidentes, o conectan dos vertices dependiendo del tipo de grafo a manejar, 
sin embargo se tiene como una pareja de dos vertices, ordenada o no. Estos vertices tambien 
se les conoce como endpoints del edge. 
De manera similar, se tiene que los vertices conectados por un edge son vertices adyacentes.
Y puede que exista el caso donde un vertice no tenga ningún vertice adyacente, sea el endpoint 
de un edge o que tenga un edge incidente a otro vertice, estos se le conocen como vertices aislados.

En algunas definiciones se tiene que algunos vertices pueden tener los mismos vertices adyacentes, 
lo cual se conoce como multigrafos.

Los grafos se pueden tener en:

### Grafos dirigidos
Cada edge es una pareja ordenada u, v in V, tal que (u, v) != (v, u) y (u,v) in E.
Y se permite que un vertice tenga como adyacente a si mismo (u, u) in E.

### Grafos no dirigidos
Cada edge es una pareja desordenada u, v in V, tal que {u, v} = {v, u} y {u,v} in E.
No se permite adyacencia propia.

