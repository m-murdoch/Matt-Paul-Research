import numpy as np
import csv
import matplotlib.pyplot as plt
from scipy import stats

def flops(n, t):
    return (((5*(n**3))/6)/t)/(10**9)

if __name__ == "__main__":
    N = 23 # number of working mappings 
    d = [[] for i in range(N)] # data
    a = ["d_-j", "d_-j_-k", "d_j_-k", "d_-k_-j", "d_k_-j", "-i_j",
    "-i_j_k","-i_k_j", "j_d_k", "j_-i_-k", "j_-k_d",
    "j_-k_i", "d_j", "d_-j_k", "d_j_k", "d_-k_j", "d_k_j", 
    "-i_j_-k", "-i_k_-j",  "j_d_-k", "j_-i", "j_-i_k", "j_-k_-i"] # map names (23)

    for i in range(N): # read in all the data
        f = open("/Users/paullys/Desktop/research2019/OSP/mappings/" + a[i] + "/trace.csv", "r")
        r = csv.reader(f, delimiter = ",")
        for j in r:
            d[i].append(j[1])
        f.close()
       
    d = np.array(d, dtype = float) # cast data as floats
    sd = [[[0,0,0,0,0] for j in range(N)] for k in range(9)] # initalize stats table for removing outliers
    Z = [[0 for i in range(N)] for j in range(9)] # initialize z score table
    avg = [[] for i in range(N)] # initalize raw plotting data table
    avg1 = [[] for i in range(N)] # initalize "outlier removed" plotting data table
    
    for i in range(9): # 1000-5000 steps of 500 (9 steps)
        build = [0 for j in range(N)] # temp variable for average
        build2 = [0 for j in range(N)] # temp variable for outlier remover average
        for k in range(5): # 5 trials at each step
            for l in range(N): # 23 data sets to build averages from
                build[l] += d[l][5*i+k]
                sd[i][l][k] = d[l][5*i+k]
        for l in range(N): # complete averaging
            build[l] /= 5
            avg[l].append(build[l])
            for q in range(2): # remove a maximum of 2 outliers from each set
                Z[i][l] = np.abs(stats.zscore(sd[i][l])) # Z scores
                zM = np.where(Z[i][l] == max(Z[i][l]))[0][0] # max Z score
                if max(Z[i][l]) > 1: # data may not be tightly grouped if this flag goes off
                    #print("Outlier found in " , a[l] , ", problem size: " , (500*i + 1000))
                    sd[i][l].remove(sd[i][l][zM]) # remove the outlier
        for l in range(N):
            for k in range(len(sd[i][l])):
                build2[l] += sd[i][l][k]
            build2[l] /= len(sd[i][l])
            avg1[l].append(build2[l])
        
    avg = np.array(avg, dtype = float)
    avg1 = np.array(avg, dtype = float)
    
    ########## FLOPS calculations #############
    flop = [["aa", 0,0,0,0,0,0,0,0,0] for i in range(N)]
    for i in range(N):
        flop[i][0] = a[i]
        for j in range(9):
            flop[i][j+1] = flops((j*500)+1000, avg1[i][j])
    flop = sorted(flop, key = lambda x: x[1])
    fl = [["aa", 0] for i in range(N)]
    for i in range(N):
        temp = 0
        fl[i][0] = flop[i][0]
        for j in range(9):
            temp += flop[i][j+1]
        temp /= 9
        fl[i][1] = temp
    fl = sorted(fl, key = lambda x: x[1])
    fl = np.array(fl)
    np.vstack(fl)
    print(fl)
    #########################################

    colors = ["darkkhaki", "tan", "chartreuse", "darkgreen", "darkcyan", "navy", "darkorchid",
    "red", "silver", "gold", "black", "darksalmon", "mediumspringgreen", "grey", "sandybrown", "mediumpurple", 
    "deepskyblue", "rosybrown", "blue", "paleturquoise", "darkturquoise", "sienna", "orange"]
    x = [1000,1500,2000,2500,3000,3500,4000,4500,5000] # the x axis
    Orders = [[] for i in range(N)]
    Orders1 = [[] for i in range(N)]
    for i in range(N):
        Orders[i] = np.polyfit(np.log(x), np.log(avg[i]), 1)
        Orders1[i] = np.polyfit(np.log(x), np.log(avg1[i]), 1)
        #print(a[i] + "  :  ", Orders[i])
        #print("Tight Order " + a[i] + "  :  ", Orders1[i])
        if Orders[i][0] != Orders1[i][0] or Orders[i][1] != Orders1[i][1]:
            print("Tightening order changed result.")
        plt.plot(x, avg[i], color = colors[i], label = a[i]) # raw exponential visualization
    plt.legend()
    plt.title("Space Time Mapping Statistics")
    plt.xlabel("Problem Size (N)")
    plt.ylabel("Average Time (Seconds)")
    #plt.show()

    t1 = [["aa",0,0] for i in range(N)]
    for i in range(N):
        t1[i][0] = a[i]
        t1[i][1] = Orders[i][0]
        t1[i][2] = Orders[i][1]
    t1 = sorted(t1, key = lambda x: x[1])
    t1 = np.array(t1)
    np.vstack(t1)
    #print("Mapping         Log Slope              Log Intercept")
    #print(t1)

    for i in range(N):
        plt.loglog(x, avg[i], color = colors[i], label = a[i]) # linear visualization 
    plt.legend()
    plt.title("Space Time Mapping Statistics (Log Scaling)")
    plt.xlabel("Log Problem Size (N)")
    plt.ylabel("Log Average Time (Seconds)")
    #plt.show()

    plt.loglog(x, avg[7], color = "blue", label = a[7] + "  3.08")
    plt.loglog(x, avg[18], color = "red", label = a[18] + "  3.05")
    plt.loglog(x, avg[14], color = "green", label = a[14])
    plt.loglog(x, avg[11], color = "purple", label = a[11] + "  4.32")
    plt.loglog(x, avg[20], color = "gold", label = a[20])
    plt.legend()
    plt.title("Space Time Mapping Statistics (Cleaner) (Log Scaling)")
    plt.xlabel("Log Problem Size (N)")
    plt.ylabel("Log Average Time (Seconds)")
    #plt.show()
