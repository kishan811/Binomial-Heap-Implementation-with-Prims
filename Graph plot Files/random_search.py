import matplotlib.pyplot as plt 

# line 1 points 
x1 = [50,100,1000,10000,20000,40000,60000,80000,100000] 
y1 = [0.000052,0.000215,0.006542,0.4430,1.77,7.184,18.47,37.60,64.909] 
# plotting the line 1 points 
plt.plot(x1, y1, label = "Binomial Heap") 

# line 2 points 
x2 = [50,100,1000,10000,100000] 
y2 =  [0.000028,0.000042,0.000516,0.004879,0.0767]
# plotting the line 2 points 
plt.plot(x2, y2, label = "AVL tree") 

x2 = [50,100,1000,10000,100000] 
y2 =  [0.000033,0.000032,0.000533,0.00613,0.075]
# plotting the line 2 points 
plt.plot(x2, y2, label = "RB tree") 

# naming the x axis 
plt.xlabel('Input Size (n)') 
# naming the y axis 
plt.ylabel('Time Taken in sec') 
# giving a title to my graph 
plt.title('Search Comparison on random data') 

# show a legend on the plot 
plt.legend() 

# function to show the plot 
plt.show() 
