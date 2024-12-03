#pragma once
#include "A.h"
class ListadeAs
{
private:
    A** lista;  // Puntero a un arreglo din�mico de punteros a objetos A
    int capacidad;  // Tama�o actual del arreglo
    int numElementos;  // N�mero de elementos actuales en el arreglo
	void redimensionar();  // Redimensiona el arreglo

public:

    ListadeAs(int capacidadInicial = 2);  // Constructor
	~ListadeAs();  // Destructor
	void agregar(A* a);  // Agrega un objeto A al arreglo
	void eliminar(int id);  // Elimina un objeto A del arreglo
	void eliminarUltimoElemento (); // Elimina el �ltimo elemento del arreglo
	 void mostrarA(int indice) const;  // Muestra los objetos A del arreglo, el const indica que no se modificar� el objeto q se llama
	void mostrarTodos() const;  // Muestra los objetos A del arreglo
	
};

