#include <bits/stdc++.h> 
using namespace std; 
int s=0;
/*los rangos ordenados [bajo, medio1), [medio1, medio2) y [mid2, high) mid1 es el primer punto medio índice en el rango general para la funcion mid2 es el segundo índice de punto medio en el rango general para funcionar */
void merge(int gArray[], int low, int mid1,	int mid2, int high, int destArray[]) 
{ 
	int i = low, j = mid1, k = mid2, l = low; 

	// elegir el  más pequeño de los más pequeños en los tres rangos
	while ((i < mid1) && (j < mid2) && (k < high)) 
	{ 
		if(gArray[i] < gArray[j]) 
		{ 
			if(gArray[i] < gArray[k]) 
			{ 
				destArray[l++] = gArray[i++]; 
			} 
			else
			{ 
				destArray[l++] = gArray[k++]; 
			} 
		} 
		else
		{ 
			if(gArray[j] < gArray[k]) 
			{ 
				destArray[l++] = gArray[j++]; 
			} 
			else
			{ 
				destArray[l++] = gArray[k++]; 
			} 
		} 
	} 

	// caso donde primero y segundo rangos
	// tiene valores restantes
	while ((i < mid1) && (j < mid2)) 
	{ 
		if(gArray[i] < gArray[j]) 
		{ 
			destArray[l++] = gArray[i++]; 
		} 
		else
		{ 
			destArray[l++] = gArray[j++]; 
		} 
	} 

	// caso donde el segundo y tercer rango 
	// tiene valores restantes
	while ((j < mid2) && (k < high)) 
	{ 
		if(gArray[j] < gArray[k]) 
		{ 
			destArray[l++] = gArray[j++]; 
		} 
		else
		{ 
			destArray[l++] = gArray[k++]; 
		} 
	} 

	//caso donde el primer y tercer rango tienen
	// valores restantes
	while ((i < mid1) && (k < high)) 
	{ 
		if(gArray[i] < gArray[k]) 
		{ 
			destArray[l++] = gArray[i++]; 
		} 
		else
		{ 
			destArray[l++] = gArray[k++]; 
		} 
	} 

	// copie los valores restantes del primer rangoq
	while (i < mid1) 
		destArray[l++] = gArray[i++]; 

	// copie los valores restantes del segundo rango
	while (j < mid2) 
		destArray[l++] = gArray[j++]; 

	// copie los valores restantes del tercer rango
	while (k < high) 
		destArray[l++] = gArray[k++]; 
} 


/* Realizar el algoritmo de ordenamiento de fusión en el
matriz dada de valores en el rango de índices
[bajo, alto]. bajo es el índice mínimo, alto es
índice máximo (exclusivo)*/
void mergeSort3WayRec(int gArray[], int low, int high, int destArray[]) 
{
    
	// Si el tamaño de la matriz es 1, no hace nada
	if (high - low < 2) 
	{
	
	    if(gArray[low]%3==0)
	    {
	    	s=s+gArray[low]; // posterirmente en el main se divide entre dos porque la suma se realiza dos veces 
		}
        
		return; 
    }
	// División de matriz en 3 partes
	int mid1 = low + ((high - low) / 3); 
	int mid2 = low + 2 * ((high - low) / 3) + 1;
	

	//Ordenar 3 matrices recursivamente
	mergeSort3WayRec(destArray, low, mid1, gArray); 

	mergeSort3WayRec(destArray, mid1, mid2, gArray); 
	mergeSort3WayRec(destArray, mid2, high, gArray); 

	// combinan las matrices ordenadas 
	merge(destArray, low, mid1, mid2, high, gArray); 
} 

void mergeSort3Way(int gArray[], int n) 
{ 
	// si el tamaño de la matriz es cero, devuelve nulo
	if (n == 0) 
		return; 

	//crea duplicados de una matriz
	int fArray[n]; 

	// copia elementos de una matriz dada en
	// duplica arreglo
	for (int i = 0; i < n; i++) 
		fArray[i] = gArray[i]; 

	//  funcion sort
	mergeSort3WayRec(fArray, 0, n, gArray); 

	// copia los elementos de la matriz duplicada
	
	for (int i = 0; i < n; i++)
		gArray[i] = fArray[i]; 
} 

// la cabeza del programa 
int main() 
{ 
	int data[] = {45, -2, -45, 78, 342, 10, 19, 73, 93}; 
	mergeSort3Way(data,10); 
	cout << " solucion :"<<endl;
	for (int i = 0; i < 10; i++) 
	{ 
		cout << data[i] << " "; 
	} 
	cout<<endl<<s/2 <<" :solucion"<<endl; 
	return 0; 
}

