<h1 align="center">Problem J</h1>
<h2 align="center">Jeffrey’s Ambition</h2>

<p>
  <h3>Información del problema</h3>
  El problema nons narra sobre la existencia de un hombre sospechosamente muy millonario, tanto así que tiene la capacidad de comprar todas las empresas que quiera, no 
  obstante al prueblo le parece injusto que este tipo pueda ser dueño de todo y se llega a la conclusión de que cada millonario tenga la oportunidad de crear una lista 
  de las empresas que desean adquirir, tal que de esas empresas solo puedan escoger una. 
  
  
  De esta manera cada millonario sería dueño de una empresa, no obstante se observa que puede darse el caso donde no todas las empresas existentes sean compradas y se 
  queden sin dueño. Por lo cual la tarea es minimizar la cantidad de empresas que se queden sin dueño.
  
  <h3>Interpretación</h3>
  Primero se podría pensar una solución con DP, pero una mejor solución es viendo esto como un grafo, tal vez suene raro pero esto es un problema de emparejamiento en
  grafos bitartitos, por lo cual puede resolver por medio de un algoritmo de Flujo máximo debido a que una de las aplicaciones era sobre grafos bitartitos.
  
  Para entender esta idea hay que pensar que tenemos a dos grupos.
  1. Millonarios 
  2. Empresas
  
  Tal que podemos ver que tenemos que relacionar un millonario a una sola empresa, tal que no puede existir:
  1. Un millonario con dos empresas.
  2. Una empresa con dos dueños.
  
  Entonces observamos que se debe de relacionar un grupo con otro, y esto simmplifica varias cosas debido a que el problema ahora se reduce en relacionar la mayor cantidad de millonarios con empresas tal que se cumplan las dos condiciones colocadas anteriormente, esto es un problema de emparejamiento.
  
  Ahora, ¿de dónde sale el flujo? Bueno, para esto se recuerda que existe el flujo unitario (flujo de 1) tal que en cada arista vamos a tener una capacidad de 1, es de este modo que sabemos que los millonarios es un grupo de vértices mientras que las empresas es otro grupo de vértices. Hasta el momento tenemos dos grupos de vértices los cuales serán unidos con aristas con una capacidad de flujo de 1.
  
  Lo siguiente es observar la necesidad de tener dos vértices más, source and target, estos dos vértices serán colocados en los extremos horizontales del grafo con el objetivo de emplear un algoritmo de flujo siendo un flujo que salga del source y llegue hasta el target, por lo cual con esto podemoss ver ya un grafo tal que nos interese el flujo máximo que llegue al target. Como la capacidad de flujo de cada arista es de 1 (capacidad unitaria) solo se estará sumando 1 en 1 el flujo que se vaya acumulando tal que el flujo máximo encontrado será la misma cantidad de millonarios que compraron una empresa tal que al restar la cantidad de estas relaciones con la cantidad de empresas que existen se obtiene como resultado la mínima cantidad de empresas que se quedaron sin dueño. 
  
  Es de este modo que el problema es posible resolverlo empleando flujo máximo.
  
  <hr>
  Una vez que fue entendido que el problema se puede resolver de este modo ya solo queda la implementación, para esto es posible usar el algoritmo de Dinic el cual es imprescindible a la hora de resolver problemas de flujo y es recomendable tenerlo siempre a la mano lo cual se debe a que es un algoritmo que nos permite hallar el flujo máximo en un tiempo polinomial, sin depender de la capacidad de flujo de las aristas.
</p>

### Implementación

```c++
require 'redcarpet'
markdown = Redcarpet.new("Hello World!")
puts markdown.to_html
puts markdown.to_html
```
