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
  
  En este momento ya sabemos hasta dónde parar, ahora ya queda ver la manera de generar estas sumas, y lo que podemos hacer es por medio de un ciclo for donde se esté manipulando un arreglo donde se esté almacenando esta suma, por lo cual en este arreglo lo que se puede hacer es tomar en cuenta tanto el valor actual como el valor anterior, es aquí donde podemos ver el siguiente ejemplo para dar entender la idea:
  
  2 15 7
  
  Este son los pesos de arroz que nos dan en un input, se observa que estaríamos empezando con 2, aunque no resulta necesario empezar con el menor. Por lo cual se tendrá en la primera posición 2:
  
  arreglo[0] = 2
  
  Ahora, se hace otra iteración y en esa iteración será necesario tomar en cuenta el anterior valor que tenemos:
  
  arreglo[0] + arreglo[1]
  
  2 + 2
  
  4
  
  De igual forma, para la siguiente iteración es necesario tomar en cuenta el valor anterior
  
  4 + 2
  
  6
  
  Así sucesivamente podemos ir construyendo el arreglo que contenga todas las sumas. Ahora se debe de pensar en la forma de buscar dichos números, y es que al generar las sumas de esta manera se tendrá un problema y es la posición de los números debido a que no se estaría llevando un orden y para aplicar una búsqueda será necesario tener que ordenar el arreglo tal que nos llevaría una complejidad de O(nlog(n)), lo cual estaría resultando algo muy ineficiente, así que lo mejor sería trabajar sobre los índices, o sea usar los indices para generar todas las sumas posibles tal que después se deposita los índices en otro arreglo y ya tendríamos todos las sumas en un arreglo y ya estaría ordenado, siendo que en lugar de tener una complejidad de O(nlog(n)) se tiene ya una complejidad lineal.
</p>



### Implementación

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	// Suma máxima a realizar 5 × 10^4, no nos van a pedir una suma mayor
	int k,p; cin>>k>>p;
	int dp[50005];  // Se podría usar un bool, pero para evitar errores sobre la inicialización
	int numer;
	
	// Caso base es querer 0 kilos y sería simplemente no comprar nada
	dp[0] = 1;
	
	for(int i=0;i<p;i++)
	    {
	         cin>>numer;
	         dp[numer] = 1;
	         
	         for(int j=numer;j<50005;j++){
	            
	            if(dp[j-numer] == 1)
	                {
	                    //cout<<"Se hizo: "<<j<<endl;
	                    dp[j] = 1;
	                }
	                
	         }
	    }
	
	// Vaciando los índices en un arreglo
	vector<int> v;
	
	for(int i=0;i<50005;i++)
	    {
	        if(dp[i] == 1){
	            v.push_back(i);
	        }
	    }
	
	// Aplicando búsqueda binaria, por las condiciones a cumplir se necesitaría encontrar un valor igual o que
	// sea el más próximo al buscado, siendo el próximo mayor para poder cubrir la solicitud y que sobre arroz
	// Estas características cumple lower_bound.
	int value;
	vector<int>::iterator ans;
	for(int i=0;i<k;i++)
	    {
	        cin>>value;
	        ans = lower_bound(v.begin(), v.end(), value);
	        cout<<abs(value-(*ans))<<endl;
	    }
	
	
	return 0;
}

```

### Referencias:
<a href="https://www.geeksforgeeks.org/lower_bound-in-cpp/#:~:text=The%20lower_bound()%20method%20in,or%20equal%20to%20that%20number.">Lower_bound C++</a>
