def shadows(A, T):
    s = [None]*len(A)
    # examine all points in the array
    for i in range(len(A)):
        # examine all points potentially in the shadow of i
        for j in range(i+1, len(A)):
            # is j outside the shadow of i
            if A[j] >= A[i]-T*(j-i):
                # j is in the sun and therefore casting a new shadow. j becomes the new i
                s[j] = True
                i = j
                break
            else:
                # j is in the shadow of i
                s[j] = False
    return s

def main():
    N = int(input("N: "))
    A = [0] * N
    for i in range(N):
        A[i] = float(input("A(" + str(i) +"): "))
    T = int(input("T: "))
    print(shadows(A, T))
    #print(shadows([1,2,3,4,1], 1))
if __name__ == '__main__':
   main()

