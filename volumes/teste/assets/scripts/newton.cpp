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
		cout<<"\nUso: ./netwon [OPÇÕES]\n\nOPÇÕES:\n\n -o [Arquivo]       Arquivo de saída.\n\n                        Ex.: -o ./diretorio/saida.csv\n\n -b [Base] 	    Define a base.\n\n                        Ex.: -b 10\n\n -p [Precisão]      Define a precisão.\n\n                        Ex.: -i 3\n\n -l [LimInferior]   Define o limite inferior.\n\n                        Ex.: -l -3\n\n -u [LimSuperior]   Define o limite superior.\n\n                        Ex.: -u 3\n\n -h      Mostra esta tela de ajuda e sai\n -v      Mostra a versão do programa e sai\n\n\nExemplo completo de uso:\n\n./float-point -o ./diretorio/saida.csv -b 10 -p 3 -l -3 -u 3\n\n";
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

// Funcao(progamacao) que deriva a funcao(matematica)
double derivFunc(double x)
{
    double barril;
    barril = ((func(x+EPSILON) - func(x))/EPSILON); // calcula a derivada, lembra quando a gente calculava derivada pelo limite em calculo 1?
    return barril;
}


void newtonRaphson(string saida, double x)
{

    ofstream output;
    output.open(saida.c_str());

    double h = func(x) / derivFunc(x); // variavel h apenas para facilitar a visualizacao ( nao fui eu que fiz essa porra )
    int c=1;

    while (abs(h) >= EPSILON) // LAÇO DE REPETIÇÃO, CONDIÇÃO DE PARADA,:o valor de h seja menor que o epsilon...
    {
        h = func(x)/derivFunc(x);

        // x(i+1) = x(i) - f(x) / f'(x) <--- formula de Newton Raphson
        x = x - h;
        // Aumentei a precisao do x ( setprecision() ) para ter uma visao mais nitida da diferenca da raiz nas ultimas iteraçoes...
        output << "Iteracao numero: " << c << " | Raiz aproximada: " << setprecision(15)<< x << endl;
        c++;
    }

    output.close();

}

int main(int argc, char *argv[])
{
    mensagem exibir;

    int numParametros = argc;

    string  nomePrograma=argv[0], arquivoSaida;

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

    } else if ( numParametros == 5 ){

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

                            default:
                                cout << "Arquivo saida: " << arquivoSaida << endl;
                                cout << "A: " << a << endl;

                                exibir.erro();
                                return 1;
                        }
                    }
                }
            }

        // EXECUTION PROGRAM

        newtonRaphson(arquivoSaida, a);

    } else {

        exibir.erro();
        return 1;
    
    }

    return 0;

}
