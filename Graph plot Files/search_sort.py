import matplotlib.pyplot as plt 

# line 1 points 
x1 =[50,100,1000,10000,20000,40000,60000,80000,100000]
y1 = [0.000060,0.000077,0.00722,0.451,1.63,6.984,17.42,32.19,58.59] 
# plotting the line 1 points 
plt.plot(x1, y1, label = "Binomial Heap") 

# line 2 points 
x2 =[50,100,1000,10000,20000,40000,60000,80000,100000]
y2 =  [0.000033,0.000042,0.000191,0.00347,0.0049,0.0116,0.0186,0.0245,0.0333]
# plotting the line 2 points 
plt.plot(x2, y2, label = "AVL tree") 

x2 =[50,100,1000,10000,20000,40000,60000,80000,100000]
y2 =  [0.000025,0.000041,0.000385,0.00419,0.0054,0.0110,0.0164,0.0235,0.0281]
# plotting the line 2 points 
plt.plot(x2, y2, label = "RB tree") 

# naming the x axis 
plt.xlabel('Input Size (n)') 
# naming the y axis 
plt.ylabel('Time Taken in sec') 
# giving a title to my graph 
plt.title('Search Comparison on sorted data') 

# show a legend on the plot 
plt.legend() 

# function to show the plot 
plt.show() 
