import math

def shadows(A, T):
    s = [True]*len(A)
    for i in range(len(A)):
        shadow = i+math.ceil(A[i]/T)
        if shadow > len(A):
            shadow = len(A)
        for j in range(i+1, shadow):
            if A[j] >= A[i]-T*(j-i):
                i = j
                break
            else:
                s[j] = False
    return s

def main():
    N = int(input("N: "))
    A = [0] * N
    for i in range(N):
        A[i] = float(input("A(" + str(i) +"): "))
    T = int(input("T: "))
    print(shadows(A, 1))

if __name__ == '__main__':
   main()