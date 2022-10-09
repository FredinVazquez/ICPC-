#include<bits/stdc++.h>
using namespace std;

// El secreto es paso por paso, siendo lineal el algoritmo O(n).

int main()
    {
        map<int,int> alturas;
        // map<altura,ocurrencias> 
        int ans =0;     // Siempre se explota el primer globo
        
        // Input
        int n; cin>>n;  vector<int> v(n);
        for(int i=0;i<n;i++)    cin>>v[i];
        
        //Process
        // Fijarse que el orden (posición) de cada globo se cuida debido a que se va uno por uno gracias
        // al vector que los contiene, entonces no se puede tener problemas como con el caso de 4 2 3.
        for(int i=0;i<n;i++)
            {
                // Se checa si existe una flecha con esa altura
                if(alturas[v[i]]==0)    // No existe
                    {
                        alturas[v[i]-1]++;    // Se añade en esa posición, pero menos uno porque explota
                        ans ++;               // el globo.
                    }
                else
                    {
                        // El globo existe
                        alturas[v[i]]--;// Disminuye la cantidad de flechas que hay ahí, en esa posición
                        alturas[v[i]-1]++;  // Ahora aumenta la cantidad de flechas disminuido porque se 
                                            // entiende que al explotar un globo la flecha baja.
                                            // Aún cuando se llega a una altura 0 pues eso ya no interesa
                    }
                
            }
        
        //Output
        cout<<ans;
        
        return 0;
    }
