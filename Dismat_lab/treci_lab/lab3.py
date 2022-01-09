import math
class Graph:

    def __init__(self, n, m, args):
        self.n = int(n)
        self.m = int(m)
        self.args = args.split()
        self.graph = [[0] * self.n for _ in range(self.n)]
        vrhovi = [i for i in range(1, int(n) + 1)]
        for i, vrh in enumerate(vrhovi):
            for j, vrh2 in enumerate(vrhovi):
                if str(abs(i - j)) in args:
                    self.graph[i][j] = 1
        self.color = [0 for _ in range(self.n)]        

    def validation(self, vrh, boja):
        for i in range(self.n):
            if self.graph[vrh][i] == 1 and self.color[i] == boja:
                return False
        return True

    def bojanje(self, i):
        if (i == self.n): 
            print("Kromatski broj zadanog grafa je {}".format(len(set(self.color))))
            return True 

        for boja in range(1, self.n + 1):
            if self.validation(i, boja):
                self.color[i] = boja  
                if (self.bojanje(i + 1)):
                    return True
                self.color[i] = 0
        return False

if __name__ == "__main__":
    file_name = str(input("Unesite ime datoteke: "))
    graph = Graph(*list(map(str, list(x.strip() for x in open(file_name).readlines()))))
    graph.bojanje(0)