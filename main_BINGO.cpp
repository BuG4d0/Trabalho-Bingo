#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

#define TAM 5

using namespace std;

void clrscr() {
	cout << "\033[2J\033[H";
	cout.flush();
}

void pausar() {
	//if (cin.rdbuf()->in_avail() > 0)
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
}

void InsertionSort(int vetor[], int contador) { //InsertionSort para os elementos do vetor
	int atual = contador;
	int chave = vetor[atual];
	while (atual > 0 && vetor[atual-1] > chave) {
		vetor[atual] = vetor[atual-1];
		atual--;
	}
	vetor[atual] = chave;
}

void PreencherVetor(int vetor[75], int contador) {
	int aux = rand()%75+1;
	for (int i = 0; i <= contador; i++) {
		if (vetor[i] == aux) {
			aux = rand()%75+1;
			i = -1;
		}
	}
	vetor[contador] = aux;
}

void exibirVetor(int vetor[75], int ultimo, int contador) { //Exibe o ultimo elemento em verde
	for (int i = 0; i <= contador; i++) {
		if (i % 18 == 0) cout << endl;
		if (vetor[i] == ultimo) {
			cout << "\033[32m" << vetor[i] << "\033[0m\t";
		} else {
			cout << vetor[i] << "\t";
		}
	}
}

void ZerarVetor(int vetor[75]){
    for (int i = 0; i < 75; i++){
        vetor[i] = 0;
    }
}

void InsertionSortPreencher(int vetor[], int atual) { //InsertionSort para as colunas da Cartela (sem o static)
	int chave = vetor[atual];
	while (atual > 0 && vetor[atual-1] > chave) {
		vetor[atual] = vetor[atual-1];
		atual--;
	}
	vetor[atual] = chave;
}

int VerificaNumero(int vetor[], int tamanho, int numero) { //Verifica se o numero ja existe no vetor
	for (int i = 0; i < tamanho; i++) {
		if (numero == vetor[i]) {
			return 1;
		}
	}
	return 0;
}

int ComparaMatriz(int PrimeiraMatriz[][TAM], int SegundaMatriz[][TAM]) {
	for (int i = 0; i < TAM; i++) {
		for (int j = 0; j < TAM; j++) {
			if (PrimeiraMatriz[i][j] != SegundaMatriz[i][j]) {
				return 0;
			}
		}
	}
	return 1;
}

void PrencherMatriz(int matriz[][TAM]) {
	int vetor[TAM] = {};
	for(int i = 0; i < TAM; i++) {
		for(int j = 0; j < TAM; j++) {
			if (i == 0) {
				do {
					vetor[j] = rand() % 15 + 1 + i*15;
				} while (VerificaNumero(vetor, j, vetor[j]) != 0);
				InsertionSortPreencher(vetor, j);
				for (int x = 0; x <= j; x++) {
					matriz[i][x] = vetor[x];
				}
			} else if (i == 1) {
				do {
					vetor[j] = rand() % 15 + 1 + i*15;
				} while (VerificaNumero(vetor, j, vetor[j]) != 0);
				InsertionSortPreencher(vetor, j);
				for (int x = 0; x <= j; x++) {
					matriz[i][x] = vetor[x];
				}
			} else if (i == 2) {
				do {
					vetor[j] = rand() % 15 + 1 + i*15;
				} while (VerificaNumero(vetor, j, vetor[j]) != 0);
				InsertionSortPreencher(vetor, j);
				for (int x = 0; x <= j; x++) {
					matriz[i][x] = vetor[x];
				}
			} else if (i == 3) {
				do {
					vetor[j] = rand() % 15 + 1 + i*15;
				} while (VerificaNumero(vetor, j, vetor[j]) != 0);
				InsertionSortPreencher(vetor, j);
				for (int x = 0; x <= j; x++) {
					matriz[i][x] = vetor[x];
				}
			} else if (i == 4) {
				do {
					vetor[j] = rand() % 15 + 1 + i*15;
				} while (VerificaNumero(vetor, j, vetor[j]) != 0);
				InsertionSortPreencher(vetor, j);
				for (int x = 0; x <= j; x++) {
					matriz[i][x] = vetor[x];
				}
			}
		}
	}
}


void Impressao(int matriz[][TAM]) {
	for (int i = 0; i < TAM; i++) {
		for(int j = 0; j < TAM; j++) {
			cout << matriz[i][j] << "\t";
		}
		cout << "\n";
	}
}

void ImprimirCartela(int Cartela[TAM][TAM], int vetor[], int qtdSorteados, int ultimo) { //Imprime a Cartela com cores
	for(int i = 0; i < TAM; i++) {
		for(int j = 0; j < TAM; j++) {
			int saiu = VerificaNumero(vetor, qtdSorteados, Cartela[i][j]);
			if (Cartela[i][j] == ultimo && saiu) {
				cout << "\t\033[32m"<< Cartela[i][j]<<"\033[0m";
			} else if (saiu) {
				cout<<"\t\033[31m"<< Cartela[i][j]<<"\033[0m";
			} else {
				cout << "\t"<< Cartela[i][j]<<"";
			}
		}
		cout<<"\n";
	}
}

int VerificarBingo(int Cartela[TAM][TAM], int vetor[], int qtdSorteados) {
	int Marcador[TAM][TAM];
	for (int i = 0; i < TAM; i++) {
		for (int j = 0; j < TAM; j++) {
			Marcador[i][j] = VerificaNumero(vetor, qtdSorteados, Cartela[i][j]);
		}
	}

	for (int i = 0; i < TAM; i++) { //Verifica as linhas e colunas
		int somaLinha = 0, somaColuna = 0;
		for (int j = 0; j < TAM; j++) {
			somaLinha += Marcador[i][j];
			somaColuna += Marcador[j][i];
		}
		if (somaLinha == TAM || somaColuna == TAM) {
			return 1;
		}
	}

	int diag1 = 1, diag2 = 1; //Verifica as diagonais principais e secundarias
	for (int i = 0; i < TAM; i++) {
		if (Marcador[i][i] == 0) {
			diag1 = 0;
		}
		if (Marcador[i][TAM-1-i] == 0) {
			diag2 = 0;
		}
	}
	if (diag1 == 1 || diag2 == 1) {
		return 1;
	}
	return 0;
}

void UmVencedor(int A, int idA, string jogador1, int B, int idB, string jogador2, int C, int idC, string jogador3,
                int D, int idD, string jogador4, int E, int idE, string jogador5) {
	if (A == 1) {
		cout << "Parabéns! A Cartela ganhadora foi " << idA << " e o ganhador foi " << jogador1;
	} else if (B == 1) {
		cout << "Parabéns! A Cartela ganhadora foi " << idB << " e o ganhador foi " << jogador2;
	} else if (C == 1) {
		cout << "Parabéns! A Cartela ganhadora foi " << idC << " e o ganhador foi " << jogador3;
	} else if (D == 1) {
		cout << "Parabéns! A Cartela ganhadora foi " << idD << " e o ganhador foi " << jogador4;
	} else if (E == 1) {
		cout << "Parabéns! A Cartela ganhadora foi " << idE << " e o ganhador foi " << jogador5;
	}
}

void DoisVencedores(int A, int idA, string jogador1, int B, int idB, string jogador2, int C, int idC, string jogador3,
                    int D, int idD, string jogador4, int E, int idE, string jogador5) {
	if (A == 1 && B == 1) {
		cout << "Empate entre " << jogador1 << " (ID " << idA << ") e " << jogador2 << " (ID " << idB << ")";
	} else if (A == 1 && C == 1) {
		cout << "Empate entre " << jogador1 << " (ID " << idA << ") e " << jogador3 << " (ID " << idC << ")";
	} else if (A == 1 && D == 1) {
		cout << "Empate entre " << jogador1 << " (ID " << idA << ") e " << jogador4 << " (ID " << idD << ")";
	} else if (A == 1 && E == 1) {
		cout << "Empate entre " << jogador1 << " (ID " << idA << ") e " << jogador5 << " (ID " << idE << ")";
	} else if (B == 1 && C == 1) {
		cout << "Empate entre " << jogador2 << " (ID " << idB << ") e " << jogador3 << " (ID " << idC << ")";
	} else if (B == 1 && D == 1) {
		cout << "Empate entre " << jogador2 << " (ID " << idB << ") e " << jogador4 << " (ID " << idD << ")";
	} else if (B == 1 && E == 1) {
		cout << "Empate entre " << jogador2 << " (ID " << idB << ") e " << jogador5 << " (ID " << idE << ")";
	} else if (C == 1 && D == 1) {
		cout << "Empate entre " << jogador3 << " (ID " << idC << ") e " << jogador4 << " (ID " << idD << ")";
	} else if (C == 1 && E == 1) {
		cout << "Empate entre " << jogador3 << " (ID " << idC << ") e " << jogador5 << " (ID " << idE << ")";
	} else if (D == 1 && E == 1) {
		cout << "Empate entre " << jogador4 << " (ID " << idD << ") e " << jogador5 << " (ID " << idE << ")";
	}
}

void TresVencedores(int A, int idA, string jogador1, int B, int idB, string jogador2, int C, int idC, string jogador3,
                    int D, int idD, string jogador4, int E, int idE, string jogador5) {
	if (A == 1 && B == 1 && C == 1) {
		cout << "Empate entre " << jogador1 << ", " << jogador2 << " e " << jogador3;
	} else if (A == 1 && B == 1 && D == 1) {
		cout << "Empate entre " << jogador1 << ", " << jogador2 << " e " << jogador4;
	} else if (A == 1 && B == 1 && E == 1) {
		cout << "Empate entre " << jogador1 << ", " << jogador2 << " e " << jogador5;
	} else if (A == 1 && C == 1 && D == 1) {
		cout << "Empate entre " << jogador1 << ", " << jogador3 << " e " << jogador4;
	} else if (A == 1 && C == 1 && E == 1) {
		cout << "Empate entre " << jogador1 << ", " << jogador3 << " e " << jogador5;
	} else if (A == 1 && D == 1 && E == 1) {
		cout << "Empate entre " << jogador1 << ", " << jogador4 << " e " << jogador5;
	} else if (B == 1 && C == 1 && D == 1) {
		cout << "Empate entre " << jogador2 << ", " << jogador3 << " e " << jogador4;
	} else if (B == 1 && C == 1 && E == 1) {
		cout << "Empate entre " << jogador2 << ", " << jogador3 << " e " << jogador5;
	} else if (B == 1 && D == 1 && E == 1) {
		cout << "Empate entre " << jogador2 << ", " << jogador4 << " e " << jogador5;
	} else if (C == 1 && D == 1 && E == 1) {
		cout << "Empate entre " << jogador3 << ", " << jogador4 << " e " << jogador5;
	}
}

void QuatroVencedores(int A, int idA, string jogador1, int B, int idB, string jogador2, int C, int idC, string jogador3,
                      int D, int idD, string jogador4, int E, int idE, string jogador5) {
	if (A == 0) {
		cout << "Empate entre " << jogador2 << ", " << jogador3 << ", " << jogador4 << " e " << jogador5;
	} else if (B == 0) {
		cout << "Empate entre " << jogador1 << ", " << jogador3 << ", " << jogador4 << " e " << jogador5;
	} else if (C == 0) {
		cout << "Empate entre " << jogador1 << ", " << jogador2 << ", " << jogador4 << " e " << jogador5;
	} else if (D == 0) {
		cout << "Empate entre " << jogador1 << ", " << jogador2 << ", " << jogador3 << " e " << jogador5;
	} else if (E == 0) {
		cout << "Empate entre " << jogador1 << ", " << jogador2 << ", " << jogador3 << " e " << jogador4;
	}
}

int main() {
	srand(time(nullptr));
	string jogador1, jogador2, jogador3, jogador4, jogador5;
	int CartelaA[TAM][TAM] = {}, CartelaB[TAM][TAM] = {}, CartelaC[TAM][TAM] = {}, CartelaD[TAM][TAM] = {}, CartelaE[TAM][TAM] = {};
	int vetor[75], ultimo,idA, idB, idC, idD, idE, i = 0;
	int opcao, loop = 0,  vencedor = 0;
	do {
		clrscr();
		cout << "\tMENU PRINCIPAL\n";
		cout << "1. Jogar\n";
		cout << "2. Sobre\n";
		cout << "3. Sair\n";
		cout << "Escolha uma opcao: ";

		if (!(cin >> opcao)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout.flush();
			opcao = 0;
		} else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		switch (opcao) {
		case 1: {
			clrscr();
			cout << "Insira os nomes dos jogadores:\n";
			cout << "Qual o nome do jogador 1: ";
			cin >> jogador1;
			cout << "Qual o nome do jogador 2: ";
			cin >> jogador2;
			cout << "Qual o nome do jogador 3: ";
			cin >> jogador3;
			cout << "Qual o nome do jogador 4: ";
			cin >> jogador4;
			cout << "Qual o nome do jogador 5: ";
			cin >> jogador5;

			do { //Preencimento das Cartelas e verificacao se tem alguma repetida
				PrencherMatriz(CartelaA); 
				PrencherMatriz(CartelaB);
				PrencherMatriz(CartelaC);
				PrencherMatriz(CartelaD);
				PrencherMatriz(CartelaE);
			} while(ComparaMatriz(CartelaA, CartelaB) == 1 || ComparaMatriz(CartelaA, CartelaC) == 1 || ComparaMatriz(CartelaA, CartelaD) == 1 ||
			        ComparaMatriz(CartelaA, CartelaE) == 1 || ComparaMatriz(CartelaB, CartelaC) == 1 || ComparaMatriz(CartelaB, CartelaD) == 1 ||
			        ComparaMatriz(CartelaB, CartelaE) == 1 || ComparaMatriz(CartelaC, CartelaD) == 1 || ComparaMatriz(CartelaC, CartelaE) == 1 ||
			        ComparaMatriz(CartelaD, CartelaE) == 1);
			idA = 1 + loop * 5;
			idB = 2 + loop * 5;
			idC = 3 + loop * 5;
			idD = 4 + loop * 5;
			idE = 5 + loop * 5;
			cout << "Essas são suas cartelas:\n";
			clrscr();
			cout << "Cartela de ID: " << idA << "\tJogador: " << jogador1 << endl;
			Impressao(CartelaA);
			cout << "Cartela de ID: " << idB << "\tJogador: " << jogador2 << endl;
			Impressao(CartelaB);
			cout << "Cartela de ID: " << idC << "\tJogador: " << jogador3 << endl;
			Impressao(CartelaC);
			cout << "Cartela de ID: " << idD << "\tJogador: " << jogador4 << endl;
			Impressao(CartelaD);
			cout << "Cartela de ID: " << idE << "\tJogador: " << jogador5 << endl;
			Impressao(CartelaE);
			pausar();
			cout << "\nPrecione Enter para começar o jogo!";
			pausar();
			i = 0;
			vencedor = 0;
			do {
				clrscr();
				PreencherVetor(vetor, i);
				ultimo = vetor[i];
				InsertionSort(vetor, i);
				cout << "Cartela de ID: " << idA << "\tJogador: " << jogador1 << endl;
				ImprimirCartela(CartelaA, vetor, i + 1, ultimo);
				cout << "Cartela de ID: " << idB << "\tJogador: " << jogador2 << endl;
				ImprimirCartela(CartelaB, vetor, i + 1, ultimo);
				cout << "Cartela de ID: " << idC << "\tJogador: " << jogador3 << endl;
				ImprimirCartela(CartelaC, vetor, i + 1, ultimo);
				cout << "Cartela de ID: " << idD << "\tJogador: " << jogador4 << endl;
				ImprimirCartela(CartelaD, vetor, i + 1, ultimo);
				cout << "Cartela de ID: " << idE << "\tJogador: " << jogador5 << endl;
				ImprimirCartela(CartelaE, vetor, i + 1, ultimo);
				cout << "\nValores ja sorteados:\n";
				exibirVetor(vetor, ultimo, i);

				vencedor = VerificarBingo(CartelaA, vetor, i + 1) + VerificarBingo(CartelaB, vetor, i + 1) +
				           VerificarBingo(CartelaC, vetor, i + 1) + VerificarBingo(CartelaD, vetor, i + 1) +
				           VerificarBingo(CartelaE, vetor, i + 1);

				cout << "\n\nPrecione Enter para continuar!";
				pausar();
				i++;
			} while (vencedor < 1);

			int A = VerificarBingo(CartelaA, vetor, i); //Transformacao da funcao das cartelas em um numero para ficar mais facil de manipular com ifs
			int B = VerificarBingo(CartelaB, vetor, i);
			int C = VerificarBingo(CartelaC, vetor, i);
			int D = VerificarBingo(CartelaD, vetor, i);
			int E = VerificarBingo(CartelaE, vetor, i);

			if (vencedor == 1) {
				UmVencedor(A, idA, jogador1, B, idB, jogador2, C, idC, jogador3, D, idD, jogador4, E, idE, jogador5);
			}
			else if (vencedor == 2) {
				DoisVencedores(A, idA, jogador1, B, idB, jogador2, C, idC, jogador3, D, idD, jogador4, E, idE, jogador5);
			}
			else if (vencedor == 3) {
				TresVencedores(A, idA, jogador1, B, idB, jogador2, C, idC, jogador3, D, idD, jogador4, E, idE, jogador5);
			}
			else if (vencedor == 4) {
				QuatroVencedores(A, idA, jogador1, B, idB, jogador2, C, idC, jogador3, D, idD, jogador4, E, idE, jogador5);
			}
			else if (vencedor == 5) {
				cout << "Todos os Jogadores empataram";
			}
			pausar();
			loop++;

			break;
		}
		case 2: {
			clrscr();
			cout << "\tSobre:\n";
			cout << "Equipe:Henrique dos Santos Waschburger, Giovanne Bressanini Palaci, Joao Vitor Moura Coelho, Lucca Danna Katcharowski e Matheus Adriano Senczkowski.\n";
			cout << "Mes/Ano:Setembro/2026.\n";
			cout << "Disciplina:Algoritmos e Programação II.\n";
			cout << "Professor:Rafael Martins.\n";
			pausar();
			break;
		}
		case 3: {
			clrscr();
			cout << "Encerrando o programa.\n";
			break;
		}
		default:
			clrscr();
			cout << "Opcao invalida! Escolha uma opcao entre 1 e 3.\n\n";
			pausar();
		}
	} while (opcao != 3);

	return 0;
}