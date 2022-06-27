#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 100

class MatrizGraf {
private:
	char MNodo[MAX];
	int NumNodos;
	int NumAristas;
	int MatrizA[MAX][MAX];

public:

	MatrizGraf();
	MatrizGraf(char Nodos[], int NNodos, char Aristas[][2], int NAristas);
	void print();

private:
	
	int getPosition(char ch);
};

MatrizGraf::MatrizGraf()
{

}


MatrizGraf::MatrizGraf(char Nodos[], int NNodos, char Aristas[][2], int NAristas)
{
	int i, p1, p2;
	
	
	NumNodos = NNodos;
	NumAristas = NAristas;

	for (i = 0; i < NumNodos; i++)
		MNodo[i] = Nodos[i];
	
	
	for (i = 0; i < NumAristas; i++)
	{
	
		p1 = getPosition(Aristas[i][0]);
		p2 = getPosition(Aristas[i][1]);
		
		MatrizA[p1][p2] = 1;
		MatrizA[p2][p1] = 1;
	}
}

int MatrizGraf::getPosition(char ch)
{
	int i;
	for(i=0; i<NumNodos; i++)
		if(MNodo[i]==ch)
		return i;
	return -1;
}

void MatrizGraf::print()
{
	int i,j;
	
	cout << "Martix Graph:" << endl;
	for (i = 0; i < NumNodos; i++)
	{
		for (j = 0; j < NumNodos; j++){
			cout << MatrizA[i][j] << " ";
		}
		cout<<endl;
	}
}

int main()
{
	int n;
	cout<<"Que cantidad de nodos desea ingresar? ";
	cin>>n;
	int a;
	cout<<"Que cantidad de aristas desea ingresar? ";
	cin>>a;
	
	char Nodos[n];
	for (int i = 0; i < n; i++){
		cout<<"Ingrese un nodo: ";
		cin>>Nodos[i];
	}
	
	char Aristas[a][2];
	
	for (int i = 0; i < a; i++){
		cout<<"Ingrese el primer nodo: ";
		cin>>Aristas[i][0];
		cout<<"ingrese el segundo nodo: ";
		cin>>Aristas[i][1];
	}
	
	int NNodos = sizeof(Nodos)/sizeof(Nodos[0]);
	int NAristas = sizeof(Aristas)/sizeof(Aristas[0]);
	MatrizGraf* pG;
	
	cout<<"Esto tiene"<<Nodos<<endl;
	cout<<"Esto tiene"<<Nodos[0]<<endl;

	pG = new MatrizGraf(Nodos, NNodos, Aristas, NAristas);
	
	pG->print();   
	
	cout<<endl;
	
	for(int i = 0; i < a; i++){

		if(Aristas[i][0] != Aristas[i-1][0]){
			cout<<endl;
		}
		cout<<Aristas[i][0]<<"->"<<Aristas[i][1]<<" ";
	}
	
	return 0;
}
