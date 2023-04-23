"""
def op():
    n, h = map(int, input().split())
    a = [int(i) for i in input().split()]
    a.sort()
    ans = (h//n)-1
    run = True
    m = n
    H = h
    while run:
        m = n
        ans+=1
        b = [a[n-1]]
        for i in range(n-2, -1, -1):
            if a[i]+ans>=a[i+1]:
                h-=a[i+1]-a[i]
                m-=1
            else:
                b.append(a[i])
        ans = max(ans, h//m-1)
        if (h-m*ans)<=0:
            run = False
        h = H
    print(ans)
for i in range(int(input())):
    op()
"""

 
def calcula_k():
 
    n, h = map(int, input().split())
    ataques = list( map(int, input().split()) ) #lista de INSTANTES do ataque i: ataques[i]
 
    if n >= h:
        print("1")
        return
    else:
        # busca binaria
        inicio = 1 # comeca do minimo possivel de dano
        fim = h # terminamos caso em algum momento k chegue ao valor de h, nosso maximo
        meio = 0
 
        intervalos = {}
        for i in range(n-1):
            intervalos[i] = ataques[i+1] - ataques[i] # "timedelta" entre cada ataque consecutivo
        
        while inicio <= fim:
            meio = (inicio + fim) // 2
            dano_causado = meio
            for i in range(n-1):
                delta = intervalos.get(i)
                if delta < meio:
                    dano_causado += delta
                else:
                    dano_causado += meio
            if dano_causado < h:
                inicio = meio + 1
            else:
                fim = meio - 1
        
        print(fim + 1) # correção pela iteração final em que inicio ultrapassa fim
    #pass
 
 
n_testes = int(input())
for i in range(n_testes):
    calcula_k()
