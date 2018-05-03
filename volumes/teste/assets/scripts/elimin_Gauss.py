#!/usr/bin/python3.5
#coding: utf-8

#EXEMPLO PARA EXECUTAR O ARQUIVO -- ./elimin_Gauss.py 1 entrada4.txt
#1 - Significa que ele pega do arquivo
#2 - Recebe por meio de INPUTS
import sys

class CorDeFundo(object):
    vermelho = '\033[41m'
    verde = '\033[42m'
    azul = '\033[44m'
    ciano = '\033[46m'
    magenta = '\033[45m'
    amarelo = '\033[43m'
    branco = '\033[47m'
    preto = '\033[40m'

class CorDaLetra(object):
    vermelho ='\033[31m'
    verde ='\033[32m'
    azul ='\033[34m'
    ciano ='\033[36m'
    magenta ='\033[35m'
    amarelo ='\033[33m'
    preto ='\033[30m'
    branco ='\033[37m'
    original ='\033[0;0m'
    reverso ='\033[2m'
    negrito = '\033[1m'

class Matriz(object):
    def __init__(self,linEcol):
        self.linEcol = linEcol
        self.matriz = Matriz

    def Cria(self,linEcol):
        #CRIA UM ARRAY SIMPLES PREENCHIDO DE ZEROS
        Matriz = [0] * linEcol
        #CRIA AS LINHAS DA MATRIZ E PREENCHE COM ZERO
        for i in range(linEcol):
            #SOMA-SE COM MAIS UM PARA QUE A COLUNA DE SOLUÇÕES SEJA CONTEMPLADA
            Matriz[i] = [0]*(linEcol+1)
        #RETORNA A MATRIZ
        return Matriz

    def Exibe(self, Matriz, linEcol):
        # end="" SINALIZA PARA O PRINT QUE ELE NÃO DEVE QUEBRAR A LINHA
        for i in range (linEcol):
            print(CorDaLetra.vermelho,"| ",end="")
            for j in range (linEcol+1):
                if j != linEcol:
                    print (Matriz[i][j]," ",end="")
                else:
                    print (" | ",Matriz[i][j], end="")
                    print (" |",CorDaLetra.original)

    def Preenche(self, Matriz, linEcol):
    #FUNÇÃO QUE PREENCHE MANUALMENTE A MATRIZ COM OS VALORES QUE SE QUER
    #ESSA FUNÇÃO SÓ FUNCIONA SE FOR PASSADO 0 NO PRIMEIRO ARGUMENTO QUANDO
    #EXECUTAMOS O PROGRAMA
        for i in range(linEcol):
            for j in range(linEcol+1):
                print("ELEMENTO LINHA ",i," E COLUNA ",j)
                Matriz[i][j] = int(input("-->"))

    def Pivo(self, Matriz, linEcol):
        #DEFINE UMA LISTA DE VALORES QUE SÃO OBTIDOS DIVIDINDO O ELEMENTO
        #a11 PELO ELEMENTO. EX:. a21 --> a21/a11
        A = []
        k = 0
        for i in range (linEcol):
            #INICIA-SE POR 1 PARA QUE A PRIMEIRA LINHA NÃO SEJA CONSIDERADA,
            #UMA VEZ QUE O VALOR ANCORA ESTÁ NA PRIMEIRA LINHA.
            #SOMA-SE COM k PARA QUE SEJA IGNORADA A OPERAÇÃO JÁ EXECUTADA, FOR-
            #MANDO ASSIM UMA "ESCADINHA"
            for j in range (1+k,linEcol):
                if Matriz[i][i] != 0:
                    print(CorDaLetra.azul,"PRIMEIRO - ",Matriz[i][i]," SEGUNDO - ",Matriz[j][i],"\t---",Matriz[i][j]/Matriz[i][i],CorDaLetra.original)
                    A.append(Matriz[j][i]/Matriz[i][i])
            k = k+1
        print(A)

        return A


    def Gauss(self, Matriz, linEcol, pivo):
    #EXECUTA O MÉTODO
        k = 0
        q = 0
        for c in range (1,linEcol):
            print ("------------------------------------ c --> ",c )
            M.Exibe(M.matriz, M.linEcol)

            for i in range (c,linEcol):
                for j in range (k,linEcol+1):
                    print ("VALOR DE J :: ",j)
                    Matriz[i][j] = Matriz[i][j] - ( pivo[q]*Matriz[c-1][j] )
                q = q+1
            pivo = M.Pivo(M.matriz, M.linEcol)
            k = k+1


        return Matriz

    def LeArquivo(self,Matriz,nome):

        temp = []
        arq = open(nome, 'r')
        for line in arq:
            convertido = float(line)
            temp.append(convertido)
        arq.close()

        k = 0
        for i in range(linEcol):
            for j in range(linEcol+1):
                print("ELEMENTO LINHA ",i," E COLUNA ",j)
                Matriz[i][j] = temp[k]
                k = k + 1

    def EscreveArquivo(self,Matriz,linEcol):
        temp = []
        arq = open("arquivo_saida.txt", 'w')
        for i in range (linEcol):
            for j in range (linEcol+1):
                arq.write(str(Matriz[i][j]))
                arq.write("\n")
        arq.close()


#CRIAR FUNÇÃO QUE LÊ DO ARQUIVO

###___MAIN___
linEcol = int(sys.argv[1])
M = Matriz(linEcol)
print(M.linEcol)
M.matriz = M.Cria(linEcol)
M.Exibe(M.matriz, M.linEcol)

#if auto:
M.LeArquivo(M.matriz,sys.argv[2])
#else:
#M.Preenche(M.matriz, M.linEcol)

M.Exibe(M.matriz, M.linEcol)
Pivo = M.Pivo(M.matriz, M.linEcol)
M.Gauss(M.matriz, M.linEcol, Pivo)
M.Exibe(M.matriz, M.linEcol)
M.EscreveArquivo(M.matriz, M.linEcol)

#M.LeArquivo(M.matriz,"arquivo_saida.txt")
#M.Exibe(M.matriz, M.linEcol)

#tempor = []
#arquivo = open("arquivo_saida.txt", 'r')
#for line in arquivo:
#    converted = float(line)
#    tempor.append(converted)
#arquivo.close()
#print(tempor)
#print(len(tempor))

#solution = []
#solution.append(tempor[len(tempor)-1])
#print (solution)