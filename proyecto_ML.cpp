#include <iostream>
//#include <conio.h>
#include <string>
#include <algorithm>

using namespace std;


string cadena;

bool numero_tel(string x); //Funcion que indica si el mensaje tiene un numero
bool correo(string x); //Funcion que indica si el mensaje tiene un correo
bool palabras_reservadas(string x); //Funcion con palabras prohibidas para el usuario
bool numeros_En_Letras(string x);//Funcion que busca numeros que se hayan ingresado como letras
bool red_social(string x);

int main(){
    cout<<"¿Cómo te puedo contactar?: ";
    getline(cin, cadena);
    cout<<endl<<endl;
    
    //Funcion que convierte a minúsculas toda la cadena que haya ingresado el usuario
    std::for_each(cadena.begin(), cadena.end(), [](char & c){
        c = ::tolower(c);
    });

    

    if(numero_tel(cadena)){
    	cout<<"No puedes ingresar datos personales";
    	return 0;
	}
    if(correo(cadena)){
        cout<<"No puedes ingresar datos personales";
        return 0;
    }
    if(palabras_reservadas(cadena)){
        cout<<"No puedes ingresar datos personales";
        return 0;
    }
    if(red_social(cadena)){
        cout<<"No puedes ingresar datos personales";
        return 0;
    }
    if(numeros_En_Letras(cadena)){
    	cout<<"No puedes ingresar datos personales";
        return 0;
	}

	cout<<"Cadena valida";
	return 0;
	
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
    if(contador>=6){
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

    if(x.find('@') != -1 && x.find(".com") != -1 )

    //Ciclo donde comparara desde la posicion del arroba hasta el final de la cadena, si coincide con algun correo
    for(int i = 0; i<4; i++){
        if(x.find_first_of(correos[i], posicion) != -1){
        	return true;
		}
    }
    return false;
}


//Funcion que verifica si existen algunas palabras, si es asi retorna true
bool palabras_reservadas(string x){
    string arreglo_palabras[9] = {"nombre","soy", "me llamo","contactarme","marcarme","marcar", "marca",".com","@"};
    for(int i = 0; i<8; i++){
        if(x.find(arreglo_palabras[i]) != -1){
            return true;
        }
    }
	
    return false;
}


//Funcion que busca numeros escritos en texto.
//si son mayores a cuatro se considera como numero telefonico por lo que retorna true
bool numeros_En_Letras(string x){
	int contador = 0;
	
	string numeros[10];
	numeros[0] = "cero";
	numeros[1] = "uno";
	numeros[2] = "dos";
	numeros[3] = "tres";
	numeros[4] = "cuatro";
	numeros[5] = "cinco";
	numeros[6] = "seis";
	numeros[7] = "siete";
	numeros[8] = "ocho";
	numeros[9] = "nueve";
	
	//Busca cada numero escrito en texto, si lo encuentra aumenta el contador
	for(int i = 0; i<10; i++){
        if(x.find(numeros[i]) != -1){
        	contador++;
		}
    }
    
    //Contador mayor o igual que 4, retorn verdadero
    if(contador >= 4)
    	return true;
    return false;
}

//Funcion que busca referencias a otras redes sociales
bool red_social(string x){
	if(x.find("snapchat") != -1){
		return true;
	}
	if(x.find("face") != -1){
		return true;
	}
	if(x.find("facebook") != -1){
		return true;
	}
	if(x.find("twitter") != -1){
		return true;
	}
	if(x.find("whatsapp") != -1){
		return true;
	}
	if(x.find("wa") != -1){
		return true;
	}
	return false;
}