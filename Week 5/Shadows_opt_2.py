def shadows(A, T):
    S = [True]
    caster = 0
    # examine all points potentially in the cast shadow
    for i in range(caster+1, len(A)):
        # is i outside the shadow of the caster
        if A[i] >= A[caster]-T*(i-caster):
            # i is in the sun and therefore casting a new shadow. i becomes the new caster
            S.append(True)
            caster = i
        else:
            # i is in the shadow of caster
            S.append(False)
    return S

def main():
    N = int(input("N: "))
    A = []
    for i in range(N):
        A.append(float(input("A(" + str(i) +"): ")))
    T = float(input("T: "))
    print(shadows(A, T))

if __name__ == '__main__':
   main()
