#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <fstream>

using namespace std;

// CLASSE MENSAGEM
class mensagem {
public:

	void versao(){
		cout<<"Versão 0.001"<<endl<<endl;
	}

	void ajuda(){
		cout<<"\nUso: ./float-point [OPÇÕES]\n\nOPÇÕES:\n\n -o [Arquivo]       Arquivo de saída.\n\n                        Ex.: -o ./diretorio/saida.csv\n\n -b [Base] 	    Define a base.\n\n                        Ex.: -b 10\n\n -p [Precisão]      Define a precisão.\n\n                        Ex.: -i 3\n\n -l [LimInferior]   Define o limite inferior.\n\n                        Ex.: -l -3\n\n -u [LimSuperior]   Define o limite superior.\n\n                        Ex.: -u 3\n\n -h      Mostra esta tela de ajuda e sai\n -v      Mostra a versão do programa e sai\n\n\nExemplo completo de uso:\n\n./float-point -o ./diretorio/saida.csv -b 10 -p 3 -l -3 -u 3\n\n";
	}

	void erro(){
		cout<<"Opção inválida, tente novamente. Use -h para ajuda."<<endl<<endl;
    }

};


void SistemaDeAritimeticaDePontoFlutuante(string saida, int BASE, int precisao, int limLower, int limUpper){

	ofstream output;
	output.open(saida.c_str());

	int maxValores = 2*( (BASE-1) * (pow(BASE,(precisao-1))) * (limUpper-limLower+1) ) + 1 ;

	cout << "Valores Máximos: " << maxValores << endl;

	float arrayValores[ maxValores ];
	
	stringstream arrayConcat[ maxValores ];

	string arrayString[ maxValores ];

	int indice = 0;


	if ( precisao == 1 ) {

		for( int i = 1 ; i <= 9 ; i++ ){

			for( int z = limLower ; z <= limUpper ; z++ ){

				// CONCATENA OS VALORES NO ARRAY
				arrayConcat[indice] << i;

				// ESCREVE VALORES EM UM ARRAY DE STRING
				arrayString[indice] = arrayConcat[indice].str();

				// CONVERTE VALOR DO ARRAY DE STRING EM INT E ESCREVE NO ARRAY DE FLOAT
				arrayValores[indice] = atoi( arrayString[indice].c_str() );

				// COMPUTA O VALOR FINAL E ESCREVE NO ARRAY DE FLOAT
				arrayValores[indice] = ((arrayValores[indice])/1000) * (pow(10,z)) ;

				// ESCREVE NO ARQUIVO
				output << arrayValores[indice] << ";0.0" << endl;

				// INCREMETA O INDICE
				indice++;

			}

		}

	}

	if ( precisao == 2 ) {

		for( int i = 1 ; i <= 9 ; i++ ){

			for( int j = 0 ; j <= 9 ; j++ ){

				for( int z = limLower ; z <= limUpper ; z++ ){

					// CONCATENA OS VALORES NO ARRAY
					arrayConcat[indice] << i << j;

					// ESCREVE VALORES EM UM ARRAY DE STRING
					arrayString[indice] = arrayConcat[indice].str();

					// CONVERTE VALOR DO ARRAY DE STRING EM INT E ESCREVE NO ARRAY DE FLOAT
					arrayValores[indice] = atoi( arrayString[indice].c_str() );

					// COMPUTA O VALOR FINAL E ESCREVE NO ARRAY DE FLOAT
					arrayValores[indice] = ((arrayValores[indice])/1000) * (pow(10,z)) ;

					// ESCREVE NO ARQUIVO
					output << arrayValores[indice] << ";0.0" << endl;

					// INCREMETA O INDICE
					indice++;

				}

			}

		}

	}	

	if ( precisao == 3 ) {

		for( int i = 1 ; i <= 9 ; i++ ){

			for( int j = 0 ; j <= 9 ; j++ ){

				for( int k = 0 ; k <= 9 ; k++ ){

					for( int z = limLower ; z <= limUpper ; z++ ){

						// CONCATENA OS VALORES NO ARRAY
						arrayConcat[indice] << i << j << k;

						// ESCREVE VALORES EM UM ARRAY DE STRING
						arrayString[indice] = arrayConcat[indice].str();

						// CONVERTE VALOR DO ARRAY DE STRING EM INT E ESCREVE NO ARRAY DE FLOAT
						arrayValores[indice] = atoi( arrayString[indice].c_str() );

						// COMPUTA O VALOR FINAL E ESCREVE NO ARRAY DE FLOAT
						arrayValores[indice] = ((arrayValores[indice])/1000) * (pow(10,z)) ;

						// ESCREVE NO ARQUIVO
						output << arrayValores[indice] << ";0.0" << endl;

						// INCREMETA O INDICE
						indice++;

					}

				}

			}

		}

	}

	output.close();

}


int main(int argc, char *argv[]){

	mensagem exibir;

	int numParametros = argc, precisao, limLower, limUpper, base;

	string	nomePrograma=argv[0], arquivoSaida;


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

	} else if ( numParametros == 11 ){

			int i = 0;

			while ((++argv)[0]){

				// TESTA APENAS PARAMETROS IMPARES, PARA NAO ELIMINAR VALORES COM MENOS NA FRENTE, NO CASO DE NUMEROS NEGATIVOS (EXEMPLO: -3)
				if ( ((++i)%2) ) {
				
					if (argv[0][0] == '-' ){

						switch(argv[0][1]){
		
							case 'o':
								arquivoSaida = argv[1];
								break;

							case 'b':
								base = atoi(argv[1]);
								break;

							case 'p':
								precisao = atoi(argv[1]);
								break;

							case 'l':
								limLower = atoi(argv[1]);
								break;

							case 'u':
								limUpper = atoi(argv[1]);
								break;

							default:
								cout << "Arquivo saida: " << arquivoSaida << endl;
								cout << "Base: " << base << endl;
								cout << "Precisao: " << precisao << endl;
								cout << "LimLower: " << limLower << endl;
								cout << "limUpper: " << limUpper << endl;

								exibir.erro();
								return 1;
						}
					}
				}
			}

		// EXECUTION PROGRAM

		SistemaDeAritimeticaDePontoFlutuante(arquivoSaida, base, precisao, limLower, limUpper);

	} else {

		exibir.erro();
		return 1;
	
	}

	return 0;
}
