'''
# Exercícios de revisão de análise de algoritmos
'''

'''
Encontre o limite superior para a função:
T(n) = 2n + 7
    2n -> O(n)

T(n) = n² + n
    n² -> O(n²)
'''

'''
Prove que:
F(n) = 2n³ - 6n != O(n²)
    n³ > n², logo não é O(n²)
    
F(n) = 20n² + 2n + 5 == O(n²)
    n² == n², logo é O(n²)
'''

'''
Encontre a complexidade de tempo dos seguintes códigos: 
'''
# a)
def a(n):
    i = 1 # O(1)
    while i < n: # O(log n) -> i dobra a cada iteração, tornando o código mais rápido do que O(n) (q seria algo como i++)
        i *= 2 # O(1) 
        print("a) complexidade: O(log n)") # O(1)
        print(i) # O(1)

def b(n):
    i = n # O(1)
    while i > 0: # O(log n) -> i reduz pela metade a cada iteração -> log2(n), logo (log n)...aparentemente
        print("b) complexidade: ",i) # O(1)
        i /= 2 # O(1)

def c(n):
    for i in range(1, n): # O(n log n) -> i vai de 1 a n, e dentro do for tem um while que é log n, somando as complexidades vira um O(n log n)
        j = i # O(1)
        while j < n: # O(log n) por causa do j *= 2
            j *= 2 # O(1)
            print("c) complexidade: O(n log n)", j) # O(1)

def d(n):
    i = 1 # O(1)
    while i < n: # infinito
        print("d) complexidade: infinita...ou até a luz acabar", i) # O(1)
        i = i ** 2 # O(1) essa operação não muda o valor de i, então o loop nunca acaba

n = 100 # O(1)

a(n) # O(log n)
b(n) # O(log n)
c(n) # O(n log n)
d(n) # tempo infinito
