#include <iostream>
#include <stdlib.h>
using namespace std;

int opcao = 1, x, y, z, ini = 0, fim = 0, tam = 10, vetor[10], valor, flag, meio, f_ini, f_fim;

int empurra(int n) {
    // Empurrar elementos para a direita
    for (int i = fim - 1; i >= ini; i--) {
        vetor[i + 1] = vetor[i];
    }
}

int consultar(int n) {
    cout << "Consulta cadastro\n";
    if (fim == 0) {
        cout << "Vetor Vazio impossivel consultar\n";
    } else {
        cout << "Valores cadastrados: \n";
        for (int i = 0; i < fim; i++) {
            cout << vetor[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

int incluir(int n) {
    cout << "Incluir\n";
    if (fim == tam) {
        cout << "Vetor Lotado impossivel incluir\n";
    } else {
        cout << "Digite o valor a ser incluido: ";
        cin >> valor;

        if (fim == 0) {  // Se o vetor estiver vazio, insere diretamente
            vetor[fim] = valor;
            fim++;
        } else {  // Caso contrário, empurra os elementos e insere na posição inicial
            empurra(1);
            vetor[0] = valor;
            fim++;
        }
        consultar(1);
    }
    return 0;
}

int alterar(int n) {
    cout << "Alterar\n";
    return 0;
}

int excluir(int n) {
    cout << "Excluir\n";
    if (fim == 0) {
        cout << "Vetor Vazio impossivel excluir\n";
    } else {
        fim--;
    }
    consultar(1);
    return 0;
}

int ordenar(int n) {
    cout << "Ordenar\n";
    if (fim == 0) {
        cout << "Vetor Vazio impossivel ordenar\n";
    } else {
        // Algoritmo de ordenação bolha (Bubble Sort)
        for (x = 0; x < fim - 1; x++) {
            for (y = 0; y < fim - 1 - x; y++) {
                if (vetor[y] > vetor[y + 1]) {
                    valor = vetor[y];
                    vetor[y] = vetor[y + 1];
                    vetor[y + 1] = valor;
                }
            }
        }
        cout << "Vetor ordenado: ";
        for (x = 0; x < fim; x++) {
            cout << vetor[x] << " ";
        }
        cout << "\n";
    }
    return 0;
}

int buscaSimples(int n) {
    cout << "Busca Simples\n";
    if (fim == 0) {
        cout << "Vetor Vazio impossivel buscar\n";
    } else {
        cout << "Digite o valor a ser buscado: ";
        cin >> valor;
        for (x = 0; x < fim; x++) {
            if (vetor[x] == valor) {
                cout << "Valor encontrado na posicao: " << x << "\n";
                flag = 0;
            }
        }
        if (flag == 1) {
            cout << "Valor nao encontrado\n";
        }
    }
    return 0;
}

int buscaBinaria(int n) {
    cout << "Busca Binaria\n";
    if (fim == 0) {
        cout << "Vetor Vazio impossivel buscar\n";
    } else {
        ordenar(1);
        cout << "Digite o valor a ser buscado: ";
        cin >> valor;

        f_ini = 0;
        f_fim = fim - 1;
        flag = 1;

        while (f_ini <= f_fim) {
            meio = (f_ini + f_fim) / 2;
            if (vetor[meio] == valor) {
                cout << "Valor encontrado na posicao: " << meio << "\n";
                flag = 0;
                break;
            } else if (vetor[meio] < valor) {
                f_ini = meio + 1;
            } else {
                f_fim = meio - 1;
            }
        }
        if (flag == 1) {
            cout << "Valor nao encontrado\n";
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
        cout << "6 - Busca Simples\n";
        cout << "7 - Busca Binaria\n";
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
            case 6:
                buscaSimples(1);
                break;
            case 7:
                buscaBinaria(1);
                break;
            default:
                cout << "Opcao Invalida\n";
        }

        system("PAUSE");
        system("cls");
    }
    return 0;
}
