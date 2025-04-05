/*
Criar em memória uma representação para cada uma das 52 cartas de um baralho 
(x 2 baralhos) para serem utilizadas em um jogo de Buraco.

O programa deverá "distribuir" aleatoriamente as cartas (11 cartas para cada um 
dos 4 jogadores participantes). Encerra a proposta com a apresentação das "mãos" 
de cada jogador.

Notação para a identificação da carta:

N-99-B = Onde:
N  -> Naipe (1-Copas / 2-Paus / 3-Ouro / 4-Espada)
99 -> Número da carta (01-Ás / 13-Rei)
B  -> Baralho (1 ou 2)
Exemplo: 4-10-2  ->  10 de espada do baralho 2
baralho[n][c]
n = 0..1
c = 0..51
baralho[0][1] = "1021"
baralho[0][2] = "1031"
baralho[0][0] = "1011"
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <time.h>
#include <sstream> 
#include <string>
#include <set>
#include <utility>
using namespace std;

#define LIN 2
#define COL 52
#define TOTAL 104

void exibirMao(string **c) {
	srand(time(0));
	set<pair<int, int> > cartaSorteada;

	for (int jogadores = 0; jogadores < 4; jogadores++) {
		cout << "Mão do Jogador " << (jogadores + 1) << endl;

		int cartas = 0;

		while (cartas < 11) {
			int rl = rand() % LIN;
			int rc = rand() % COL;
			pair<int, int> pos(rl, rc);

			if (cartaSorteada.find(pos) == cartaSorteada.end()) { //para previnir repitida
				cartaSorteada.insert(pos);
				cout << "Carta nº " << (cartas + 1) << ": " << c[rl][rc] << endl;
				cartas++;
			}
		}
		cout << endl;
	}
}

int main(int argc, char** argv)
{
	int opcao;
	string **mat;
	
	mat = new string*[LIN];
	
    for (int i = 0; i < LIN; ++i) 
    {
        mat[i] = new string[COL];
    }
	
    for (int baralho = 0; baralho < 2; baralho++) {
    	int posicao=0;
	    for (int naipe = 0; naipe < 4; naipe++) {
	        for (int numero = 1; numero <= 13; numero++) {
	        	stringstream ss;
	            ss << (naipe+1)<<"-"<<(numero <10 ? "0" : "") << numero << "-" << (baralho+1); // usando condicional ternário para simplificar 
				mat[baralho][posicao] = ss.str();
				ss.str(""); // limpa
				ss.clear(); // reseta flags
				posicao++;
	        }
	    }
	}
	
	do{
    cout << "Menu de opções" << endl
                   << "0.	Finalizar" << endl
                   << "1.	iniciar jogo" << endl
                   <<"escolhe a opção que deseja: ";
	cin >> opcao;

switch (opcao) {
    case 0:
        break;
    case 1:
        exibirMao(mat);
        break;
    default:
        cout<<"Ocorreu um erro, verifique se digitou corretamente"<< endl;
        break;
        
        }
    }while(opcao !=0);
    
        return 0;;
}