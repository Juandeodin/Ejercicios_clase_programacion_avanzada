#include<iostream>
#define TAM 10

/*
   Recorre un laberinto buscando el tesoro. 
	-Si lo encuentra muestra el recorrido seguido hasta encontrarlo
	-Si no lo encuentra indica que es inalcanzable
   Precondición: array no está vacío
   Complejidad Temporal O(n^2) (Es difícil de calcular ya que no sabemos cuando acaba pero se podría recorrer todo el laberinto si estuviera vacío)
   Complejidad Espacial O(1)
*/

using namespace std;

void imprimirLaberinto(char laberinto[][TAM])
{
  for(int i=0;i<TAM;i++)
    {
    for(int j=0;j<TAM;j++)
      cout<<laberinto[i][j];
    cout<<endl;
    }
}

bool buscarTesoro(char laberinto[][TAM],int x,int y,int &tesoro_x,int &tesoro_y)
{
  if(x>=TAM || x <0 || y<0 || y>=TAM || laberinto[x][y]=='X' || laberinto[x][y]=='*')
    return false;
  

  if(laberinto[x][y]=='T')
    {
      imprimirLaberinto(laberinto); //T(n)=No lo tenemos en cuenta
      tesoro_x=x;
      tesoro_y=y;
      return true;
    }
  

  
  laberinto[x][y]='X';
  bool encontrado=buscarTesoro(laberinto,x-1,y,tesoro_x,tesoro_y) ||
    buscarTesoro(laberinto,x,y+1,tesoro_x,tesoro_y) ||
    buscarTesoro(laberinto,x+1,y,tesoro_x,tesoro_y) ||
    buscarTesoro(laberinto,x,y-1,tesoro_x,tesoro_y);
  if(!encontrado)
    laberinto[x][y]='.';
  return(encontrado);   
}

main()
{
  int i,j;
  int sol_x,sol_y;
  char laberinto[TAM][TAM];

  for(i=0;i<TAM;i++)
    for(j=0;j<TAM;j++)
      cin>>laberinto[i][j];

  if(buscarTesoro(laberinto,0,0,sol_x,sol_y))
    {
      cout<<"ENCONTRADO "<<sol_x<<" "<<sol_y<<endl;
    }
  else
    cout<<"INALCANZABLE"<<endl;
  
  
}
