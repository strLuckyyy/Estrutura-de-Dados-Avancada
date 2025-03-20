#include <iostream>
#include <cmath>

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

void a(double n);
void b(double n);
void c(double n);
void d(double n);

int main() {
    double n;
    cout << "Digite um número: ";
    cin >> n;

    a(n);
    b(n);
    c(n);
    d(n);

    return 0;
}

void a(double n) {
    int i = 1;
    while (i < n) {
        i *= 2;
        cout << "a) complexidade: O(log n)" << endl;
        cout << i << endl;
    }    
}

void b(double n) {
    int i = n;

    while (i > 0) {
        cout << "b) complexidade: O(log n)" << endl;
        i /= 2;
    }
}

void c(double n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j < n) {
            j *= 2;
            cout << "c) complexidade: O(n log n)" << endl;
        }
    }
}

void d(double n) {
    int i = 1;
    while (i < n) {
        cout << "d) complexidade: tempo infinito" << endl;
        i = pow(i, 2);
    }
}
