import matplotlib.pyplot as plt 

# line 1 points 
x1 =[50,100,1000,10000,20000,40000,60000,80000,100000]
y1 = [0.000050,0.000121,0.00805,0.457,1.68,6.93,16.35,30.83,54.16] 
# plotting the line 1 points 
plt.plot(x1, y1, label = "Binomial Heap") 

# line 2 points 
x2 =[50,100,1000,10000,20000,40000,60000,80000,100000]
y2 =  [0.000032,0.000080,0.000515,0.0043,0.0058,0.01296,0.0192,0.0281,0.0365]
# plotting the line 2 points 
plt.plot(x2, y2, label = "AVL tree") 

x2 =[50,100,1000,10000,20000,40000,60000,80000,100000]
y2 =  [0.000031,0.000050,0.000481,0.0028,0.0056,0.0118,0.0176,0.0256,0.03215]
# plotting the line 2 points 
plt.plot(x2, y2, label = "RB tree") 

# naming the x axis 
plt.xlabel('Input Size (n)') 
# naming the y axis 
plt.ylabel('Time Taken in sec') 
# giving a title to my graph 
plt.title('Search Comparison on reverse sorted data') 

# show a legend on the plot 
plt.legend() 

# function to show the plot 
plt.show() 
