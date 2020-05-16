# hw_1
# 학번 : 201645615  이름 : 박상은
# solving 5 queens problem by genetic algorithm

import random

def chromo(size): #making random chromosomes 
    return [ random.randint(1, n) for _ in range(n) ]

#fitness evaluation
#충돌횟수로 fitness를 판단한다.
def evaluation(chromosome):
    # 가로, 세로방향의 충돌횟수
    collisions = sum([chromosome.count(queen)-1 for queen in chromosome])/2
    # 대각선 방향의 충돌횟수
    diag_collisions = 0

    n = len(chromosome)
    left = [0] * 2*n    # 왼쪽 대각선방향 충돌을 저장하는 배열
    right = [0] * 2*n   # 오른쪽 대각선방향 충돌을 저장하는 배열
    
    #i번째 퀸의 위치의 대각선방향에 1의 가중치를 준다
    for i in range(n):
        left[i + chromosome[i] - 1] += 1
        right[len(chromosome) - i + chromosome[i] - 2] += 1
    
    #대각선방향 충돌횟수를 확인한다.
    diag_collisions = 0
    for i in range(2*n-1):
        count = 0
        if left[i] > 1:
            count += left[i]-1
        if right[i] > 1:
            count += right[i]-1
        diag_collisions += count / (n-abs(i-n+1))   
    return int(total_Fitness - (collisions + diag_collisions))

def probability(chromosome, evaluation):
    return evaluation(chromosome) / total_Fitness
#
def randomchoose(chromosomes, prob):
    Probabilty = zip(chromosomes, prob)
    total = sum(i for d, i in Probabilty)
    n = random.uniform(0, total)
    until = 0
    for d, i in zip(chromosomes, prob):
        if until + i >= n:
            return d
        until += i
    assert False, "--XXXXXXX--"
        
def crossover(a, b): #doing cross_over between two chromosomes
    n = len(a)
    p = random.randint(0, n - 1)
    return a[0:p] + b[p:n]

def mutate(a):  #randomly changing the value of a random index of a chromosome
    n = len(a)
    p = random.randint(0, n - 1)
    k = random.randint(1, n)
    a[p] = k
    return a

def generation_succession(chromosomes, evaluation):
    mutation = 0.03
    new_chromo = []
    #chromosome집단중 하나를 선택했을때 적합한 해가 될 확률을 구한다.
    probabilities = [probability(n, evaluation) for n in chromosomes]
    for i in range(len(chromosomes)):
        x = randomchoose(chromosomes, probabilities) #best chromosome 1
        y = randomchoose(chromosomes, probabilities) #best chromosome 2
        child = crossover(x, y) #creating two new chromosomes from the best 2 chromosomes
         
        if random.random() < mutation:
            child = mutate(child)   #mutation
        print_chromo(child)
        new_chromo.append(child)
        
        if evaluation(child) == total_Fitness: break
    return new_chromo

def print_chromo(chrom):
    print("Chromosome = {},  evaluation = {}"
        .format(str(chrom), evaluation(chrom)))

if __name__ == "__main__":
   
    # Initialization
    n = 5 #say N = 5 ,SOLVING 5 QUEENS
    total_Fitness = (n*(n-1))/2  # 5*4/2 = 10
    chromosomes = [chromo(n) for _ in range(100)]
    
    # Genaration initial
    gene = 1

    # finess evaluation & generate new generation
    # get result
    while not total_Fitness in [evaluation(chrom) for chrom in chromosomes]:
        print("=== Generation {} ===".format(gene))
        chromosomes = generation_succession(chromosomes, evaluation)
        print("")
        print("entire Fitness = {}".format(max([evaluation(n) for n in chromosomes])))
        gene += 1
    chrom_out = []
    print("Solved in Generation {}!".format(gene-1))
    for chrom in chromosomes:
        if evaluation(chrom) == total_Fitness:
            print("");
            print("One of the solutions: ")
            chrom_out = chrom
            print_chromo(chrom)
            
    a = []

    for x in range(n):
        a.append(["x"] * n)
        
    for i in range(n):
        a[n-chrom_out[i]][i]="Q"
            

    def board(board):
        for row in a:
            print (" ".join(row))
            
    print()
    board(a)
            
