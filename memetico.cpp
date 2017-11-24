#include <iostream>

using namespace std;

class Passageiro {
	public:
		double tarifa, tempo;
		int origem, destino;
		Passageiro() {}
		Passageiro(double tarifa, int origem, int destino, int tempo) {
			this->tarifa = tarifa;
			this->origem = origem;
			this->destino = destino;
			this->tempo = tempo;
		}
};

int main(int argc, char const *argv[]) {
	int N, P, R;

	cin >> N >> P >> R;

	double **c = new double*[N];
	for (int i = 0; i < N; ++i)
		c[i] = new double[N];

	double **y = new double*[N];
	for (int i = 0; i < N; ++i)
		y[i] = new double[N];

	//double c[N][N]; // Matriz de custos
	//double y[N][N]; // Matriz de tempos
	double t[P]; // tarifa máxima do passageiro
	double w[P]; // tempo máximo do passageiro
	int o[P]; // Origem do passageiro
	int d[P]; // Destino do passageiro
	double b[N]; // Lista de bonus
	double g[N]; // Delay dos vértices
	double Q; // Quota mínima
	int start = 0; // Vértice inicial

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int aux;
			cin >> aux;
			c[i][j] = aux;
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int aux;
			cin >> aux;
			y[i][j] = aux;
		}
	}

	Passageiro *passageiro = new Passageiro[P];
	for (int i = 0; i < P; ++i) {
		double tarifa, tempo;
		int origem, destino;
		cin >> tarifa >> origem >> destino >> tempo;
		t[i] = tarifa;
		o[i] = origem;
		d[i] = destino;
		w[i] = tempo;
		passageiro[i] = Passageiro(tarifa, origem, destino, tempo);
	}

	for (int i = 0; i < N; ++i) {
		b[i] = 0;
		g[i] = 0;
	}

	cin >> Q;

	for (int i = 0; i < N; ++i) {
		int vertice; double bonus_value, delay;
		cin >> vertice >> bonus_value >> delay;
		b[vertice] = bonus_value;
		g[vertice] = delay;
	}
}