#include <iostream>
#include <string>
using namespace std;

class Pieza {
protected:
	short filas;
	short columnas;
public:
	Pieza(short f = 8, short c = 8) : filas(f), columnas(c) {}
	
	virtual ~Pieza() {}
	
	short getFilas() const {
		return filas;
	}
	
	short getColumnas() const {
		return columnas;
	}
	
	virtual bool movimientoValido(int xInicial, int yInicial, int xFinal, int yFinal) = 0;
};

class Peon : public Pieza {
public:
	Peon() : Pieza() {}
	
	bool movimientoValido(int xInicial, int yInicial, int xFinal, int yFinal) override {
		return (xFinal == xInicial + 1 && yFinal == yInicial);
	}
};

class Tablero {
private:
	Pieza* casillas[8][8];
	
public:
	Tablero() {
		
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				casillas[i][j] = nullptr;
			}
		}
		casillas[1][0] = new Peon();
	}
	
	~Tablero() {
		
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				delete casillas[i][j];
			}
		}
	}
	
	bool moverPieza(int xInicial, int yInicial, int xFinal, int yFinal) {
		Pieza* pieza = casillas[xInicial][yInicial];
		
		if (pieza != nullptr && pieza->movimientoValido(xInicial, yInicial, xFinal, yFinal)) {
			casillas[xFinal][yFinal] = pieza;
			casillas[xInicial][yInicial] = nullptr;
			return true;
		}
		
		cout << "Movimiento inválido." << endl;
		return false;
	}
};

int main() {
	Tablero tablero;
	int xInicial, yInicial, xFinal, yFinal;
	
	cout << "Jugador uno, ingrese el movimiento de su pieza (ej. 2 0 3 0): ";
	cin >> xInicial >> yInicial >> xFinal >> yFinal;
	
	if (tablero.moverPieza(xInicial, yInicial, xFinal, yFinal)) {
		cout << "Movimiento realizado con éxito." << endl;
	}
	
	cout << "Jugador dos, ingrese el movimiento de su pieza (ej. 2 1 3 1): ";
	cin >> xInicial >> yInicial >> xFinal >> yFinal;
	
	if (tablero.moverPieza(xInicial, yInicial, xFinal, yFinal)) {
		cout << "Movimiento realizado con éxito." << endl;
	}
	
	return 0;
}

