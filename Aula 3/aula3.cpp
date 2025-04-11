
#include "aula3.h"

using namespace std;

Aula3::Aula3()
{
    cout << "Aula 3 : 11/03 \nRevisão: Análise de Algoritmos. \nÁrvores." << endl;
}

void Aula3::ShowInfo()
{
    string info = ("Aula 3 : Atividades\n\n",
                   "Exercícios de revisão de análise de algoritmos\n",
                    "1. Encontre o limite superior para a função:\n",
                        "T(n) = 2n + 7\n",
                        "T(n) = n² + n\n",
                    "2. Prove que:\n",
                        "F(n) = 2n³ - 6n != O(n²)\n",
                        "F(n) = 20n² + 2n + 5 == O(n²)\n\n",
                    "3. Encontre a complexidade de tempo dos seguintes códigos:\n",
                    "a) for (int i = 0; i < n; i++)\n",
                        "   for (int j = 0; j < n; j++)\n",
                            "       printf(\"%d\", i + j);\n",
                    "b) for (int i = 0; i < n; i++)\n",
                        "   for (int j = 0; j < n; j++)\n",
                            "       for (int k = 0; k < n; k++)\n",
                                "           printf(\"%d\", i + j + k);\n",
                    "c) for (int i = 0; i < n; i++)\n",
                        "   for (int j = 0; j < n; j++)\n",
                            "       for (int k = 0; k < n; k++)\n",
                                "           for (int l = 0; l < n; l++)\n",
                                    "               printf(\"%d\", i + j + k + l);\n",
                    "d) for (int i = 0; i < n; i++)\n",
                        "   for (int j = 0; j < n; j++)\n",
                            "       for (int k = 0; k < n; k++)\n",
                                "           for (int l = 0; l < n; l++)\n",
                                    "               for (int m = 0; m < n; m++)\n",
                                        "                   printf(\"%d\", i + j + k + l + m);\n");
    
    cout << info << endl;
}

void Aula3::A(double n)
{
    int i = 1;
    while (i < n) {
        i *= 2;
        cout << "a) complexidade: O(log n)" << endl;
        cout << i << endl;
    }
}

void Aula3::B(double n)
{
    int i = n;

    while (i > 0) {
        cout << "b) complexidade: O(log n)" << endl;
        i /= 2;
    }
}

void Aula3::C(double n)
{
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j < n) {
            j *= 2;
            cout << "c) complexidade: O(n log n)" << endl;
        }
    }
}

void Aula3::D(double n)
{
    int i = 1;
    while (i < n) {
        cout << "d) complexidade: tempo infinito" << endl;
        i = pow(i, 2);
    }
}
