#include "aula4.h"

using namespace std;

Aula4::Aula4()
{
    cout << "Aula 4 : 18/03 \nÁrvores Binárias." << endl;
}

/*Exercício 1: Crie uma árvore binária de pesquisa
inserindo as chaves conforme a ordem abaixo:
g, d, a, c, m, o, b, d, a, l, p, q

Exercício 2: Suponha que temos números entre 1 e 1000 em
uma BST e queremos procurar pelo número 363. Qual(is) das
sequências a seguir NÃO poderia(m) ser a(s) sequência(s) de
nós examinados?
a) 2, 252, 401, 398, 330, 344, 397, 363.
b) 924, 220, 911, 244, 898, 258, 362, 363.
c) 925, 202, 911, 240, 912, 245, 363.
d) 2, 399, 387, 219, 266, 382, 381, 278, 363.
e) 935, 278, 347, 621, 299, 392, 358, 363.

Exercício 3: O professor Bunyan pensa ter descoberto uma
importante propriedade de BST. Suponha que a pesquisa da
chave k em uma BST termine em uma folha. Considere três
conjuntos: A, as chaves à esquerda do caminho de pesquisa; B, as
chaves no caminho de pesquisa; e C, as chaves à direita do
caminho de pesquisa. O professor afirma que três chaves
quaisquer a  A, b  B e c  C devem satisfazer a a  b  c.
Forneça um contraexemplo mínimo possível para a afirmação do
professor.

Exercício 4. Desenhe uma árvore de pesquisa com a inserção dos elementos na seguinte
ordem: K G G B L O C P A U D. Apresente os quatro percursos estudados!

Exercício 5. Desenhe uma árvore de pesquisa com a inserção dos elementos na seguinte
ordem: 20 10 5 8 12 3 14 23 28 30 100 e 99.

Exercício 6. Apresente o percurso pós-ordem para a árvore abaixo.
         /----- 8
         |       \----- 7
 /----- 6
4
 |       /----- 3
 \----- 2
         \----- 1

Exercício 7. A partir da árvore abaixo, aplique as seguintes técnicas de
exclusão (use a árvore resultante e não a original):
a) Exclusão por fusão da chave 12
b) Exclusão por cópia da chave 36
c) Exclusão da chave 8
d) Exclusão da chave 6

                 /----- 54
         /----- 51
         |       \----- 45
 /----- 36
 |       |       /----- 30
 |       \----- 24
 |               \----- 22
20
 |               /----- 18
 |       /----- 17
 |       |       \----- 15
 \----- 12
         |       /----- 10
         \----- 8
                 \----- 6


Exercício 8. A árvore abaixo é:
a) Estritamente binária? Justifique sua resposta.
b) Completa? Justifique sua resposta.
c) Cheia? Justifique sua resposta.

                 /----- 180
         /----- 100
         |       \----- 90
 /----- 80
37
 |       /----- 30
 \----- 20
         \----- 10
                 \----- 5

*/

void Aula4::Exe1()
{
    cout << "Exercício 1: Crie uma árvore binária de pesquisa\n"
            "inserindo as chaves conforme a ordem abaixo:\n"
            "g, d, a, c, m, o, b, d, a, l, p, q" << endl;
}

void Aula4::Exe2()
{
    cout << "Exercício 2: Suponha que temos números entre 1 e 1000 em\n"
            "uma BST e queremos procurar pelo número 363. Qual(is) das\n"
            "sequências a seguir NÃO poderia(m) ser a(s) sequência(s) de\n"
            "nós examinados?" << endl;
}

void Aula4::Exe3()
{
    cout << "Exercício 3: O professor Bunyan pensa ter descoberto uma\n"
            "importante propriedade de BST. Suponha que a pesquisa da\n"
            "chave k em uma BST termine em uma folha. Considere três\n"
            "conjuntos: A, as chaves à esquerda do caminho de pesquisa; B, as\n"
            "chaves no caminho de pesquisa; e C, as chaves à direita do\n"
            "caminho de pesquisa. O professor afirma que três chaves\n"
            "quaisquer a contem A, b contem B e c contem C devem satisfazer a a <= b <= c.\n"
            "Forneça um contraexemplo mínimo possível para a afirmação do\n"
            "professor." << endl;
}

void Aula4::Exe4()
{
    cout << "Exercício 4. Desenhe uma árvore de pesquisa com a inserção dos elementos na seguinte\n"
            "ordem: K G G B L O C P A U D. Apresente os quatro percursos estudados!" << endl;
}

void Aula4::Exe5()
{
    cout << "Exercício 5. Desenhe uma árvore de pesquisa com a inserção dos elementos na seguinte\n"
            "ordem: 20 10 5 8 12 3 14 23 28 30 100 e 99." << endl;
}

void Aula4::Exe6()
{
    cout << "Exercício 6. Apresente o percurso pós-ordem para a árvore abaixo.\n"
            "         /----- 8\n"
            "         |       \\----- 7\n"
            " /----- 6\n"
            "4\n"
            " |       /----- 3\n"
            " \\----- 2\n"
            "         \\----- 1" << endl;
}

void Aula4::Exe7()
{
    cout << "Exercício 7. A partir da árvore abaixo, aplique as seguintes técnicas de\n"
            "exclusão (use a árvore resultante e não a original):\n"
            "a) Exclusão por fusão da chave 12\n"
            "b) Exclusão por cópia da chave 36\n"
            "c) Exclusão da chave 8\n"
            "d) Exclusão da chave 6" << endl;
}

void Aula4::Exe8()
{
    cout << "Exercício 8. A árvore abaixo é:\n"
            "a) Estritamente binária? Justifique sua resposta.\n"
            "b) Completa? Justifique sua resposta.\n"
            "c) Cheia? Justifique sua resposta." << endl;
}
