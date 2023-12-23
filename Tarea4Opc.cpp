

/*Realizar programa que realice la suma de matrices*/

#include <iostream>

using namespace std;



void mostrarResultado(int** m1, int** m2, int** m3, int f, int c){
	cout << "La suma de las matrices es:" << endl;
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++)
		{
			cout << m1[i][j] << " + " << m2[i][j] << " = " << m3[i][j] << endl;
		}
	}
}

int** sumaMatrices(int** m1, int** m2,int f,int c) {
	int** m3 = new int*[f];
	for (int i = 0; i < f; i++) m3[i] = new int[c];

	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++)
		{
			m3[i][j] = (m1[i][j]+m2[i][j]);
		}
	}
	return m3;
}

int pedirFilas() {
	int filas;
	cout << "Introduzca la cantidad de filas: ";
	cin >> filas;
	return filas;
}

int pedirColumnas() {
	int columnas;
	cout << "Introduzca la cantidad de columnas: ";
	cin >> columnas;
	return columnas;
}

int** devolverMatriz(int filas, int columnas) {
	int** matriz = new int* [filas];
	for (int i = 0; i < filas; i++) {
		matriz[i] = new int[columnas];
	}

	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++)
		{
			cout << "Introduzca el número de la fila " << (i + 1) << " y la columna " << (j + 1)<<": ";
			cin>>matriz[i][j];
		}
	}
	return matriz;
}

void liberarMemoria(int** m1, int** m2, int** m3,int f) {
	for (int i = 0; i < f; ++i) {
		delete[] m1[i];
		delete[] m2[i];
		delete[] m3[i];
	}
	delete[] m1;
	delete[] m2;
	delete[] m3;
}

int main() {
	int** m1;
	int** m2;
	int** m3;
	int f, c;

	f = pedirFilas();

	c = pedirColumnas();

	m1 = devolverMatriz(f, c);

	m2 = devolverMatriz(f, c);

	m3 = sumaMatrices(m1, m2, f, c);

	mostrarResultado(m1, m2, m3, f, c);
	
	liberarMemoria(m1,m2,m3,f);
	return 0;
}