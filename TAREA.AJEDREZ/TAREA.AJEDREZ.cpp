
#include <iostream>
using namespace std;

class Pieza {
private:
	short fila;
	short columna;

public:
	Pieza() {
		fila = 1;
		columna = 1;
	}
	//constructor que recibe 2 parametros
	Pieza(short f, short c) {
		fila = f;
		columna = c;
	}

	//GETTERS
	short getfila() {
		return fila;
	}
	short getcolumna() {
		return columna;
	}

	//SETTERS
	void setfila(short f) {
			fila = f;
	}
	void setcolumna(short c) {
		columna = c;
	}
	
	void verInfo() {
		cout << "fila" << fila;
		cout << "columa" << columna;
	}

};
// hacer los setter(funcion que cambia del valor de atributo)

class Peon :public Pieza {

public:
	short direccion;//1 o -1 depende de si es blaco o negro
	//construcctor por defecto
	Peon() {
		direccion = 1;
	}
	Peon(short di, short f,short c):Pieza(f,c) {
		direccion = di;
		if (direccion == di && direccion == 1) {
			cout << "peon BLANCO, direccion hacia arriba";
		}
		else if (direccion == di && direccion == -1) {
			cout << "peon NEGRO, hacia abajo";
		}
	}

	

	void Avanzar() {//fila del 1 al 4 y columna del 1 a 4
		short nuevaposicion;
		nuevaposicion = getfila() + direccion;
		if ((getfila() >= 1 && getfila() <= 4) && (getcolumna() >= 1 && getcolumna() <= 4)) {
			setfila(nuevaposicion);
		}
		else {
			cout << "movimiento fuera de rango.";
		}
	}




	bool PuedoIRa(short f, short c){
		// AQUE LADO PUEDE AVANZAR el peon
		if (c == getcolumna() && (f == getfila() + direccion)) {
			return true;
		}
	    return false;
     }

};

class Tablero: public Peon {
public:
	void grafica(){
	
		cout << "---------------" << endl
			<< "|    |    |     |" << endl
			<< "--------------------" << endl
			<< "|    |    |     |" << endl
			<< "--------------------" << endl
			<< "|    |    |     |" << endl
			<< "--------------------" << endl
			<< "|    |    |  0  |" << endl
			<< "--------------------" << endl;
	}
	

};



class Torre: public Pieza{
private:
	short nroCuadros;
public:
	// construcctores
	Torre()  {
		nroCuadros = 0;
	}
	Torre(short numCu){
		nroCuadros = numCu;
	}

	Torre(short numCuc, short f, short c) : Pieza(f, c) {
		nroCuadros = numCuc;
	}
	//gettser y settsers
	short getnroCuadros() {
		return nroCuadros;
	}
	void setnroCuadros(short numCuc) {
		nroCuadros = numCuc;
	}

	void AvanzarTORRE(short f, short c) {
			if (f >= 1 && f <= 4 && c >= 1 && c <= 4) {
				if (f == getfila() || c == getcolumna()) {
					setfila(f);
					setcolumna(c);
				}
				else {
					cout << "Movimiento inválido para la torre. La torre solo se mueve en línea recta." << endl;
				}
			}
			else {
				cout << "Movimiento fuera de rango." << endl;
			}
		}
};


int main() {
	Pieza p1;
	Tablero peon;
	Torre to;
	p1.verInfo();
	Peon peo(2,2,3);
	peo.Avanzar();
    peon.grafica();
	to.AvanzarTORRE(2,0);
	return 0;
}
















