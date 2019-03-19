import matplotlib.pyplot as plt 

# line 1 points 
x1 = [50,100,1000,10000,20000,40000,60000,80000,100000] 
y1 = [0.000076,0.000133,0.0013,0.015,0.031,0.097,0.113,0.188,0.218] 
# plotting the line 1 points 
plt.plot(x1, y1, label = "Binomial Heap") 

# line 2 points 
x2 = [50,100,1000,10000,20000,40000,60000,80000,100000] 
y2 =  [0.000040,0.000089,0.000596,0.0045,0.00600,0.0127,0.0231,0.0262,0.044]
# plotting the line 2 points 
plt.plot(x2, y2, label = "AVL tree") 

x2 = [50,100,1000,10000,20000,40000,60000,80000,100000] 
y2 =  [0.000051,0.000074,0.000684,0.0044,0.0063,0.0157,0.0215,0.0289,0.034]
# plotting the line 2 points 
plt.plot(x2, y2, label = "RB tree") 

# naming the x axis 
plt.xlabel('Input Size (n)') 
# naming the y axis 
plt.ylabel('Time Taken in sec') 
# giving a title to my graph 
plt.title('Deletion Comparison on descending sorted data') 

# show a legend on the plot 
plt.legend() 

# function to show the plot 
plt.show() 
