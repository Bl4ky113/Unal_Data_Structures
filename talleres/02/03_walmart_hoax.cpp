#include <iostream>
#include <sstream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n;
    
    while (cin >> n && n != 0) {  // Leemos el número de días por caso
        long long totalCost = 0;  // Acumulador del costo total de la promoción
        
        multiset<int> billSet;  // Contenedor para almacenar los billetes
        
        // Procesamos cada día
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;  // Número de billetes para este día
            
            // Agregar los billetes al multiset
            for (int j = 0; j < k; j++) {
                int bill;
                cin >> bill;
                billSet.insert(bill);
            }
            
            // Realizamos la promoción
            if (billSet.size() >= 2) {  // Deben haber al menos dos billetes para hacer la selección
                int maxBill = *billSet.rbegin();  // El billete más grande (último elemento)
                int minBill = *billSet.begin();   // El billete más pequeño (primer elemento)

                totalCost += (maxBill - minBill);  // Cálculo del costo de la promoción
                
                // Eliminamos los billetes seleccionados
                billSet.erase(billSet.find(maxBill));
                billSet.erase(billSet.find(minBill));
            }
        }
        
        // Imprimimos el resultado para el caso actual
        cout << totalCost << endl;
    }

    return 0;
}
