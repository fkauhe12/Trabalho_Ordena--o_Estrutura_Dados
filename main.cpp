#include <iostream> /* biblioteca iostream */
#include <stdlib.h>
using namespace std;

int opcao = 1, x, y, z, ini = 0, fim = 0, tam = 9 , vetor[10] , valor;

int empurra(int n) {
    for (int x = tam - 1; x >= ini ; x--) {
        vetor[x + 1] = vetor[x]; 
    }
}

/* Função para consultar cadastro */
int consultar(int n) { 
    cout << "Consulta cadastro\n";
    if (fim == 0) {
        cout << "Vetor Vazio impossivel consultar\n";
    }else {
        cout << "Valores cadastrados: \n";
        for (int x = 0; x <= fim - 1; x++) {
            cout << vetor[x] << " ";
        }
        cout << "\n";
    }
    return 0;
}

/* Função para incluir */
int incluir(int n) { 
    cout << "Incluir\n";
    if (fim - ini == tam){
        cout << "Vetor Lotado impossivel incluir\n";
    }else{
        cout << "Digite o valor a ser incluido: ";
        cin >> valor;
        if ( ini - fim == tam) {
            vetor[fim] = valor;
            fim++;
        }else {
            empurra(1);
            vetor[0] = valor;
            fim++;
            
        }
        consultar(1);   
    }
    return 0;
}

/* Função para alterar */
int alterar(int n) { 
    cout << "Alterar\n";
    return 0;
}

/* Função para excluir */
int excluir(int n) { 
    cout << "Excluir\n";
    if (fim == 0) {
        cout << "Vetor Vazio impossivel excluir\n";
    }else {
        fim=fim - 1;
    }
    consultar(1);
    return 0;
}

/* Funçâo para Ordenar*/
int ordenar(int n) { 
    cout << "Ordenar\n";
    if (fim == 0) {
        cout << "Vetor Vazio impossivel ordenar\n";
    }else { 
        for (x = fim - 1; x >= 0; x--) {
            for (y = fim - 1; y >= 0; y--) {
                if (vetor[y] < vetor[y + 1]) {
                    valor = vetor[y];
                    vetor[y] = vetor[y + 1];
                    vetor[y + 1] = valor;
                }
            }
            for (z = fim - 1; z >= 0; z--) {
                cout << vetor[z] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}

int main() {
    while (opcao != 0) {
        cout << "####### CADASTRO DE CLIENTES #######\n\n";
        cout << "|||||||||||||||||||||||||||||||||||||\n\n";
        cout << "MENU\n\n";
        cout << "0 - Fim\n";
        cout << "1 - Inclui\n";
        cout << "2 - Altera\n";
        cout << "3 - Consulta\n";
        cout << "4 - Excluir\n";
        cout << "5 - Ordenar\n";
        cout << "\nOpcao: ";
        cin >> opcao;

        switch (opcao) {
            case 0:
                cout << "Fim do cadastro\n";
                break;
            case 1:
                incluir(1);
                break;
            case 2:
                alterar(1);
                break;
            case 3:
                consultar(1);
                break;
            case 4:
                excluir(1);
                break;
            case 5:
                ordenar(1);
                break;
            default:
                cout << "Opcao Invalida\n";
        }

        system("PAUSE");
        system("cls");
    }
    return 0;
}