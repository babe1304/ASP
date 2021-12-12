from itertools import permutations

class Graph:
    def __init__(self, n, a, b):
        self.n = n
        self.a = a
        self.b = b
        self.list = [[0] * n for i in range(n)]
        for i in range(self.n):
            for j in range(self.n):
                if i == j:
                    continue
                elif i < j:
                    self.list[i][j] = ((i + 1) * self.a + (j + 1) * self.b) ** 2 + 1
                else: 
                    self.list[i][j] = self.list[j][i]

    def greedy_alg(self):
        vrh_lista = []
        minimum = float("inf")
        prvi_cvor = 1
        drugi_cvor = 1
        for i in range(len(self.list)):
            for j in range(i, len(self.list[i])):
                if self.list[i][j] < minimum and self.list[i][j] != 0:
                    minimum = self.list[i][j]
                    prvi_cvor = i + 1
                    drugi_cvor = j + 1

        vrh_lista.append(prvi_cvor)
        vrh_lista.append(drugi_cvor)
        prvi_pocetni = True
        najblizi_cvor = prvi_cvor
        ukupna_tezina = minimum

        while len(vrh_lista) < self.n:
            sljedeca_tezina = float("inf")
            for i in range(self.n):
                if self.list[prvi_cvor - 1][i] != 0 and (i + 1) not in vrh_lista and self.list[prvi_cvor - 1][i] < sljedeca_tezina:
                    sljedeca_tezina = self.list[prvi_cvor - 1][i] 
                    najblizi_cvor = i + 1
                    prvi_pocetni = True
            
                if self.list[drugi_cvor - 1][i] != 0 and (i + 1) not in vrh_lista and self.list[drugi_cvor - 1][i] < sljedeca_tezina:
                    sljedeca_tezina = self.list[drugi_cvor - 1][i]
                    najblizi_cvor = i + 1
                    prvi_pocetni = False

            ukupna_tezina += sljedeca_tezina 
            prvi_cvor = najblizi_cvor if prvi_pocetni else prvi_cvor
            drugi_cvor = najblizi_cvor if not prvi_pocetni else drugi_cvor
            vrh_lista.append(najblizi_cvor)
        ukupna_tezina += self.list[prvi_cvor - 1][drugi_cvor - 1]
        return ukupna_tezina

    def iscrpni(self):
        lista_suma = []
        for perm in permutations(x for x in range(2, self.n + 1)):
            perm = (1,) + perm
            suma = 0
            for i in range(len(perm)):
                trenutni = perm[i] 
                sljedeci = perm[i + 1] if i != len(perm) - 1 else perm[0]
                suma += int(self.list[trenutni - 1][sljedeci - 1]) 
            lista_suma.append(suma)
        return min(lista_suma)

graph = Graph(*list(map(int, input("Unesite redom, odvojene razmakom, parametre n, a i b: ").split())))
if (graph.n <= 2 or graph.n >= 12):
    print("Premaleni" if graph.n <= 2 else "Preveliki", "n si upisao!")
else:
    iscrpno = graph.iscrpni()
    print(f"Pohlepni algoritam nalazi ciklus duljine {graph.greedy_alg()}")
    print(f"Iscrpni algoritam nalazi ciklus duljine {iscrpno}")
    print("Pohlepni algoritam na ovom grafu", "ne" if iscrpno < graph.greedy_alg() else "","daje optimalno rješenje!")