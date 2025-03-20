#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/*
Exercícios de revisão de análise de algoritmos

Encontre o limite superior para a função:
T(n) = 2n + 7
    2n -> O(n)

T(n) = n² + n
    n² -> O(n²)

    -------
Prove que:
F(n) = 2n³ - 6n != O(n²)
    n³ > n², logo não é O(n²)
    
F(n) = 20n² + 2n + 5 == O(n²)
    n² == n², logo é O(n²)
    
    -------

Encontre a complexidade de tempo dos seguintes códigos:
*/

void menu(double n);
void a(double n);
void b(double n);
void c(double n);
void d(double n);

int main() {
    double n = 100;

    menu(n);

    return 0;
}

void menu(double n) {
    cout << "Qual Algorítmo vc quer rodar?\n" << endl;
    cout << "A) Complexidade O(log n)" << endl;
    cout << "B) Complexidade O(log n)" << endl;
    cout << "C) Complexidade O(n log n)" << endl;
    cout << "D) Tempo infinito" << endl;
    cout << "Digite a letra correspondente: ";
    
    string op;
    getline(cin, op);

    switch(op[0]) 
    {
        case 'A' | 'a':
            a(n);
            break;
        case 'B' | 'b':
            b(n);
            break;
        case 'C' | 'c':
            c(n);
            break;
        case 'D' | 'd':
            d(n);
            break;
        default:
            cout << "Opção inválida" << endl;
            return menu(n);
    }

    cout << "Deseja rodar outro algorítmo? (s/n)" << endl;
    string resp;
    getline(cin, resp);

    if (resp[0] == 's' || resp[0] == 'S') {
        return menu(n);
    }
}

void a(double n) {
    int i = 1;
    while (i < n) {
        i *= 2;
        cout << "a) I = " << i << "; Complexidade: O(log n)" << endl;
    }
}

void b(double n) {
    int i = n;

    while (i > 0) {
        cout << "b) I = " << i << "; Complexidade: O(log n)" << endl;
        i /= 2;
    }
}

void c(double n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j < n) {
            j *= 2;
            cout << "c) I = " << i << "; J = " << j << "; Complexidade: O(n log n)" << endl;
        }
    }
}

void d(double n) {
    int i = 1;
    while (i < n) {
        cout << "d) I = " << i << "; Complexidade: tempo infinito" << endl;
        i = pow(i, 2);
    }
}
