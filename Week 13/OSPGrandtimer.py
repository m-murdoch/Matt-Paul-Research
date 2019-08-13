import numpy as np
import csv
import matplotlib.pyplot as plt

if __name__ == "__main__":
    N = 23 # number of working mappings 
    d = [[] for i in range(N)]
    a = ["d_-j", "d_-j_-k", "d_j_-k", "d_-k_-j", "d_k_-j", "-i_j",
    "-i_j_k","-i_k_j", "j_d_k", "j_-i_-k", "j_-k_d",
    "j_-k_i", "d_j", "d_-j_k", "d_j_k", "d_-k_j", "d_k_j", 
    "-i_j_-k", "-i_k_-j",  "j_d_-k", "j_-i", "j_-i_k", "j_-k_-i"] # map names

    for i in range(N): # read in all the data
        print(a[i])
        f = open("/Users/paullys/Desktop/research2019/OSP/mappings/" + a[i] + "/trace.csv", "r")
        r = csv.reader(f, delimiter = ",")
        for j in r:
            d[i].append(j[1])
        f.close()
        #print(d)

    d = np.array(d, dtype = float)
    avg = [[] for i in range(N)]
    #print("D:", d)

    for i in range(9): # 1000-5000 steps of 500 (9 steps)
        build = [0 for j in range(N)] # temp variable for average
        sd = [[0,0,0,0,0] for j in range(N)] # temp variable for standard deviation
        for k in range(5): # 5 trials at each step
            for l in range(N): # 23 data sets to build averages from
                build[l] += d[l][5*i+k]
                sd[l][k] = d[l][5*i+k]
        for l in range(N): # complete averaging
            build[l] /= 5
            avg[l].append(build[l])
            if np.std(sd[l]) > 2: # data may not be tightly grouped if this flag goes off.
                print("Outlier found in " , a[l] , ", problem size: " , (500*i + 500))
        
    avg = np.array(avg, dtype = float)
    #print("A: ", avg)

    colors = ["black", "tan", "chartreuse", "darkgreen", "darkcyan", "navy", "darkorchid",
    "plum", "silver", "gold", "red", "darksalmon", "mediumspringgreen", "blue", "sandybrown", "mediumpurple", 
    "deepskyblue", "rosybrown", "darkkhaki", "paleturquoise", "darkturquoise", "sienna", "orange"]
    x = [1000,1500,2000,2500,3000,3500,4000,4500,5000] # the x axis
    Orders = [[] for i in range(N)]
    for i in range(N):
        Orders[i] = np.polyfit(np.log(x), np.log(avg[i]), 1)
        print("Order " + a[i] + "  :  ")
        print(Orders[i])
        plt.plot(x, avg[i], color = colors[i], label = a[i]) # raw exponential visualization
    plt.legend()
    plt.title("Space Time Mapping Statistics")
    plt.xlabel("Problem Size (N)")
    plt.ylabel("Average Time (Seconds)")
    plt.show()

    for i in range(N):
        plt.loglog(x, avg[i], color = colors[i], label = a[i]) # linear visualization 
    plt.legend()
    plt.title("Space Time Mapping Statistics (Log Scaling)")
    plt.xlabel("Log Problem Size (N)")
    plt.ylabel("Log Average Time (Seconds)")
    plt.show()
