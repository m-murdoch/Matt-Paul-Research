import math

def shadows(A, T):
    # we assume all points are in the sun to start
    s = [True]*len(A)
    for i in range(len(A)):
        # shadow is the end point of i's shadow
        shadow = i+math.floor(A[i]/T)
        if shadow > len(A):
            # avoids out of bounds errors
            shadow = len(A)
        # examine all points within i's shadow
        for j in range(i+1, shadow):
            # is A[j] outside the shadow
            if A[j] >= A[i]-T*(j-i):
                # j is now the point casting shadows and becomes i
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
    print(shadows(A, T))

if __name__ == '__main__':
   main()
