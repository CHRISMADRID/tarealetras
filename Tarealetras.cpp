#include <iostream>
using namespace std;

int main()
{

char letra;

cout <<"ingrese una letra de las siguientes(R,Y,B,W,K,C,G): ";
cin >> letra;

switch (letra)

{
 case 'R':
 cout << "Rojo";
 break;
case 'r':
 cout << "Rojo";
 break;
case 'Y':
 cout << "Amarillo";
 break;
case 'y':
 cout << "Amarillo";
 break;
case 'B':
 cout << "Azul";
 break;
case 'b':
 cout << "Azul";
 break;
case 'W':
 cout << "Blanco";
 break;
case 'w':
 cout << "Blanco";
 break;
case 'K':
 cout << "Negro";
 break;
case 'k':
 cout << "Negro";
 break;
case 'C':
 cout << "Cian";
 break;
case 'c':
 cout<< "Cian";
 break;
case 'G':
 cout << "Verde";
 break;
case 'g':
 cout << "Verde";
 break;

cout << "letra incorrecta";
break;
 
}
return 0;

}