#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Arreglo
{
private:
	int t; //Variable del tamaño del arreglo
	vector<int> F;
  vector<int> aux;

public:
	Arreglo();
	Arreglo(vector<int>A);
	void lecturaDatos(string archivo);
	int busquedaSecuencial(int k);
	int busquedaBinaria(int inicio, int fin, int k);
	void selectionSort();
	void Intercambiar(int x, int y);
	void imprimeArreglo();
	void imprimeArregloM(vector<int>A);
  void mergesort(int lo, int hi);
  void merge(int lo, int mid, int hi); // Parte del mergesort
	void quickSort(int lo, int hi);
	int particion(int lo, int hi); //parte del quickSort
};

Arreglo::Arreglo()
{

}

Arreglo::Arreglo(vector<int>A)
{
	F = A;
}

void Arreglo::imprimeArreglo()
{
	int x = F.size();

	for (int i = 0; i < x; i++)
	{
		cout << F[i] << " " ;
	} cout << endl;
}

void Arreglo::imprimeArregloM(vector<int>A)
{
	int x = A.size();

	for (int i = 0; i < x; i++)
	{
		cout << A[i] << " " ;
	} cout << endl;
}

void Arreglo::lecturaDatos(string archivo) // Proporcionado por Eugenio Leal
{
	ifstream S(archivo.c_str());
	string t1;
	getline (S, t1);
	t = atoi(t1.c_str());

	for (int i = 0; i < t; i++)
	{
    int x;
    S >> x;
		F.push_back(x);
	}

  for (int i = 0; i < t ; i++)
  { aux.push_back(F[i]); }

	S.close();
}

int Arreglo::busquedaBinaria(int inicio, int fin, int k)
{
	int mid = (inicio + fin) / 2;

	if (inicio < fin)
	{

		if (F[mid] == k)
		{
			return mid;
		}
		else if (k < F[mid])
		{
			busquedaBinaria(inicio , mid, k);
		}
		else
		{
			busquedaBinaria( mid, fin, k);
		}
	}
	else
	{
		cout << "No esta el numero" << endl;
		return -1;
	}
}

int Arreglo::busquedaSecuencial(int k)
{
	int i;
	int r = -1; //suponer fracaso

	for (i = 0; i < t; i++)
	{
		if (k == F[i])
		{
			r = i; // Exito
			break;
		}
	}
	return r;
}

void Arreglo::Intercambiar(int x, int y)
{
	int aux = F[x];
	F[x] = F[y];
	F[y] = aux;
}

void Arreglo::selectionSort()
{
	int x = F.size();
	for (int i = 0; i < x; i++)
	{
		int min = i;
		for (int j = i + 1; j < x; j++)
		{
			if (F[j] < F[min])
			{
				min = j;
			}
			else{}
		}
		Intercambiar(i, min);
	}
}

void Arreglo::mergesort(int lo, int hi)
{
  if (hi<=lo) {return;}
  int mid = lo + (hi - lo)/2;
  mergesort(lo,mid);
  mergesort(mid +1, hi);
  merge(lo, mid, hi);
}

void Arreglo::merge(int lo, int mid, int hi)
{
	vector <int> I;
	vector <int> D;

	int n1 = mid - lo + 1;
  int n2 =  hi - mid;

  for (int i = 0; i < n1; i++)
  {
	  I.push_back(F[lo + i]);
	}
  for (int j = 0; j < n2; j++)
	{
    D.push_back(F[mid + 1+ j]);
	}

  int i = 0;
  int j = 0;
  int k = lo;

  while (i < n1 && j < n2)
  {
    if (I[i] <= D[j])
  	{
      F[k] = I[i];
      i++;
    }
    else
    {
      F[k] = D[j];
      j++;
    }
    k++;
  }
  while (i < n1)
  {
      F[k] = I[i];
      i++;
      k++;
  }
  while (j < n2)
  {
      F[k] = D[j];
      j++;
      k++;
  }

}

void Arreglo::quickSort(int lo, int hi)
{
	if(hi <= lo)
	{
		return;
	}

	int j = particion(lo,hi);
	quickSort(lo, j-1);
	quickSort(j+1, hi);
}

int Arreglo::particion(int lo, int hi)
{
	int i = lo + 1;
	int j = hi;
	int p = F[lo];
	while (true)
	{
		while (true)
		{
			if ( F[i] < p)
			{i++;}
			else
			{break;}
		}
		while (true)
		{
			if ( F[j] > p)
			{j--;}
			else
			{break;}
		}
		if (i>=j){break;}
		else
		{
			Intercambiar(i,j);
		}
	}
	Intercambiar(j,lo);

	return j;
}
