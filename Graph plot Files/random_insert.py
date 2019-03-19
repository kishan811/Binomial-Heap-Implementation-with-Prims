import matplotlib.pyplot as plt 

# line 1 points 
x1 = [50,100,1000,10000,100000,200000,300000,500000,600000,700000,2000000] 
y1 = [0.000075,0.000132,0.000625,0.007867,0.04205,0.082,0.1289,0.207,0.365,0.297,0.811] 
# plotting the line 1 points 
plt.plot(x1, y1, label = "Binomial Heap") 

# line 2 points 
x2 = [50,100,1000,10000,100000,200000,300000,500000,600000,700000,2000000] 
y2 =  [0.000057,0.000086,0.001106,0.013926,0.1477,0.3359,0.5429,1.029,1.225,1.465,5.464]
# plotting the line 2 points 
plt.plot(x2, y2, label = "AVL tree") 

x2 = [50,100,1000,10000,100000,200000,300000,500000,600000,700000,2000000] 
y2 =  [0.000059,0.000067,0.000780,0.00782,0.091,0.239,0.338,0.656,0.794,0.9825,3.197]
# plotting the line 2 points 
plt.plot(x2, y2, label = "RB tree") 

# naming the x axis 
plt.xlabel('Input Size (n)') 
# naming the y axis 
plt.ylabel('Time Taken in sec') 
# giving a title to my graph 
plt.title('Insertion Comparison on random data set') 

# show a legend on the plot 
plt.legend() 

# function to show the plot 
plt.show() 
