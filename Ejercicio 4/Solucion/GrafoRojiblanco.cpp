#include<iostream>
#include <queue> 
using namespace std;

int color_nodo[100];
bool aristas[100][100];
int n_nodos;
int n_aristas;

bool ColorearGrafo(int origen)
{
  queue<int> cola;

  for(int i = 0; i< n_nodos; i++)
    color_nodo[i]=-1;

  color_nodo[origen] = 0;
  
  cola.push(origen);
  while(!cola.empty())
    {
      origen = cola.front();
      cola.pop();
     
      for(int destino=0;destino<n_nodos;destino++)
	{
	  if(aristas[origen][destino])
	    {
	      if(color_nodo[destino]==-1)
		{
		  color_nodo[destino] = 1 - color_nodo[origen];
		  cola.push(destino);
		}
	      else if (color_nodo[destino] == color_nodo[origen])
		{
		  return false;	     		  
		}
	    }
	}
    }
  return true;
}

int main()
{
  int a,b;
  while(1)
    {
      cin>>n_nodos;
      if(n_nodos<=0)
	break;
      cin>>n_aristas;
      
      for(int i=0;i<n_nodos;i++)
	{
	  for(int j=0;j<n_nodos;j++)
	    aristas[i][j]=false;
	}
      
      for(int i=0;i<n_aristas;i++)
	{
	  cin>>a;
	  cin>>b;
	  aristas[a][b]=true;
	  aristas[b][a]=true;
	}

      bool es_bipartito = true;
      int inicio = 0;
      while(es_bipartito && inicio<n_nodos)
	{
	  es_bipartito = ColorearGrafo(inicio);
	  inicio++;
	}
      if(es_bipartito)
	cout<<"SI"<<endl;
      else
	cout<<"NO"<<endl;
      
    }
}
