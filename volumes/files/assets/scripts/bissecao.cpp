#include <bits/stdc++.h> // DAQUI A GENTE USA A FUNÇAO ABS() QUE DÁ O VALOR ABSOLUTO DO NUMERO... ( linha 30 )
#include <cmath> // PARA MAIS INFORMAÇOES, CONSULTE: http://www.cplusplus.com/reference/cmath/
#define EPSILON 0.0000000000001 // APROXIMACAO SUFICIENTE
#define PI 3.14159

using namespace std;

// CLASSE MENSAGEM
class mensagem {
public:

	void versao(){
		cout<<"Versão 0.001"<<endl<<endl;
	}

	void ajuda(){
		cout<<"\nUso: ./bissecao [OPÇÕES]\n\nOPÇÕES:\n\n -o [Arquivo]       Arquivo de saída.\n\n                        Ex.: -o ./diretorio/saida.csv\n\n -b [Base] 	    Define a base.\n\n                        Ex.: -b 10\n\n -p [Precisão]      Define a precisão.\n\n                        Ex.: -i 3\n\n -l [LimInferior]   Define o limite inferior.\n\n                        Ex.: -l -3\n\n -u [LimSuperior]   Define o limite superior.\n\n                        Ex.: -u 3\n\n -h      Mostra esta tela de ajuda e sai\n -v      Mostra a versão do programa e sai\n\n\nExemplo completo de uso:\n\n./double-point -o ./diretorio/saida.csv -b 10 -p 3 -l -3 -u 3\n\n";
	}

	void erro(){
		cout<<"Opção inválida, tente novamente. Use -h para ajuda."<<endl<<endl;
    }

};

double func(double x)
{
    // aqui tu define a função, vai ter q receber do usuario pelo site la, a biblioteca cmath tem a porra toda (exponencial,cosseno,logaritmo,etc..)
    //return (pow(x,3) - pow(x,2) -1);
    return ((0.3*PI*pow(x,2)*(9-x))-1); // funcao que caiu na prova..
}

void bissecao(string saida, double a, double b)
{

	ofstream output;
	output.open(saida.c_str());

    int count =1; // contador para contar iteraçoes
    // verifica se o intervalo inserido é valido, para ser valido essa multiplicacao tem que dar menor que 0;
    if ((func(a) * func(b)) >= 0)
    {
        cout << "Interalo invalido, nao temos raizes no intervalo ou podemos ter mais de uma raiz e isso causou um problema!.\n";
        return;
    }

    double c = a; // esse c é o intervalo de cima, vulgo a aproximacao da raiz..
    while ((b-a) >= EPSILON) // condicao de parada...
    {

        c = (a+b)/2; // pega o valor medio


        if (func(c) == 0.0) // verifica se é zero, se for zero já achou a raiz..
            break;


        else if (func(c)*func(a) < 0) // aqui faz a nova verificao para determinar o novo intervalo..
            b = c;
        else
            a = c;

    output << "Iteracaoo numero: " << count << " | Raiz aproximada: " << setprecision(15) << c << endl;
    count++;
    }

	output.close();

}


int main(int argc, char *argv[])
{
	mensagem exibir;

	int numParametros = argc;

	string	nomePrograma=argv[0], arquivoSaida;

    double a, b; // aqui é definido os intervalos a e b, isso aqui tu pega do usuario..

    if ( numParametros == 2 ){

		if (argv[1][0] == '-' ){

			switch(argv[1][1]){

				case 'v':
				case 'V':
					exibir.versao();
					return 0;
					break;

				case 'h':
				case 'H':
					exibir.ajuda();
					return 0;
					break;

				default:
					exibir.erro();
					return 1;
			}

		}

	} else if ( numParametros == 7 ){

			int i = 0;

			while ((++argv)[0]){

				// TESTA APENAS PARAMETROS IMPARES, PARA NAO ELIMINAR VALORES COM MENOS NA FRENTE, NO CASO DE NUMEROS NEGATIVOS (EXEMPLO: -3)
				if ( ((++i)%2) ) {
				
					if (argv[0][0] == '-' ){

						switch(argv[0][1]){

							case 'o':
								arquivoSaida = argv[1];
								break;
		
							case 'a':
								a = atof(argv[1]);
								break;

							case 'b':
								b = atof(argv[1]);
								break;

							default:
								cout << "Arquivo saida: " << arquivoSaida << endl;
								cout << "A: " << a << endl;
								cout << "B: " << b << endl;

								exibir.erro();
								return 1;
						}
					}
				}
			}

		// EXECUTION PROGRAM

		bissecao(arquivoSaida, a, b);

	} else {

		exibir.erro();
		return 1;
	
	}

	return 0;

}
