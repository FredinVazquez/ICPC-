<h1 align="center">Problem K</h1>
<h2 align="center">Kilo Waste</h2>

<p>
  <h3>Información del problema</h3>
  El problema se trata sobre optimizar, de forma resumida se sabe que se requiere comprar una cierta cantidad de kilos de arroz para la cena, no obstante en la tienda 
  donde se hace la compra solo ofrece bolsas de arroz con una determinada cantidad de kilos de arroz. Esto trae un problema debido a que no siempre vamos a poder comprar
  la cantidad exacta de kilos de arroz que necesitamos puesto que las presentaciones de bolsas de arroz puede variar a cuanto la cantidad de kilos que contienen, entonces
  habrá ocasiones donde se tenga que comprar arroz extra, por lo cual o deseado es que esta cantidad de arroz sobrante sea la mínima o directamente no exista.
  
  <h3>Interpretación</h3>
  Ahora, viendo el problema se cae en la cuenta que se puede tratar de un problema de knapsack pero repetidos N veces, debido a que tenemos una cantidad deseada de arroz
  a querer comprar, pero tenemos pesos determinados, así que se quiere minimizar. 
  Una solución sería simplemente hacer tal cual la implementación de knapsack problem y repetirlo, pero esto resulta no tan viable, otra opción sería conseguir todas 
  las sumas de los pesos de arroz que sea posible conseguir para después buscar la cantidad deseada por medio de una búsqueda binaria, se estaría buscando el número
  más cercano al valor buscado por el refugio.
  
  Entonces, tenemos que idear una forma de generar todas las sumas posibles dado los kilos de arroz que tiene cada bolsa, para esto se tendrá que observar los rangos de pesos que puede llegar a necesitar el refugio y es de 5x10^4 además de que las bolsas de arroz van de 1 a 100, entonces solo nos debemos de preocupar con el refugio
  debido a que esto nos hace saber que la suma máxima que se podría llegar a solicitar es de 5x10^4, así que al momento de generar todas las sumas nos vamos a poder 
  limitar hasta 5x10^4, ya que no tendría sentido generar sumas mayores ya que nunca nos van a preguntar por eso.
  
  En este momento ya sabemos hasta dónde parar, ahora ya queda ver la manera de generar estas sumas, y lo que podemos hacer es por medio de un ciclo for tal que se esté tomando en cuenta tanto  
</p>



### Implementación

```c++
require 'redcarpet'
markdown = Redcarpet.new("Hello World!")
puts markdown.to_html
puts markdown.to_html
```
