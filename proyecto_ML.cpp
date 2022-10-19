#include <iostream>
#include <string>

using namespace std;


string cadena;

bool numero_tel(string x); //Funcion que indica si el mensaje tiene un numero
bool correo(string x); //Funcion que indica si el mensaje tiene un correo
bool red_social(string y); //Funcion que indica si el mensaje tiene una red social


int main(){
    cout<<"Ingresa una cadena: ";
    getline(cin, cadena);
    //cout<<cadena;

    if(numero_tel(cadena)){
    	cout<<"Cadena invalida";
    	return 0;
	}
    if(correo(cadena)){
        cout<<"Cadena invalida";
        return 0;
    }
	else{
		cout<<"Cadena valida";
		return 0;
	}
}


bool numero_tel(string x){
    //Contador que indica cuantos numeros hay en el mensaje
	int contador = 0;
	
    //Variable que indica la posicion del primer numero
    int numero = x.find_first_of("1234567890");

    //Ciclo para contar las veces que hay un numero
    for(int i=numero; i<=x.length(); i++){
        if(x.find_first_of("1234567890", i+1) != -1){
            contador++;
        }
    }
    //Si en el mensaje hay mas de 9 numeros, se considera numero telefonico
    if(contador>=10){
    	return true;
	}
	return false;
}



bool correo(string x){

    //Correos estandars
    string correos[4];
    correos[0] = "@hotmail.com";
    correos[1] = "@gmail.com";
    correos[2] = "@outlook.com";
    correos[3] = "@uas.edu.mx";

    //Posicion cuando encuentra el primer arroba en el mensaje
    int posicion = x.find('@');

    //Ciclo donde comparara desde la posicion del arroba hasta el final de la cadena, si coincide con algun correo
    for(int i = 0; i<4; i++){
        if(x.compare(posicion, x.length()-posicion,correos[i]) == 0){
            return true;
        }
    }
    return false;
}