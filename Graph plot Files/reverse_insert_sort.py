import matplotlib.pyplot as plt 

# line 1 points 
x1 = [50,100,1000,10000,100000,300000,500000,1000000,2000000] 
y1 = [0.000103,0.000113,0.000866,0.00671,0.041,0.119,0.192,0.387,0.759] 
# plotting the line 1 points 
plt.plot(x1, y1, label = "Binomial Heap") 

# line 2 points 
x2 = [50,100,1000,10000,100000,300000,500000,1000000,2000000]  
y2 =  [0.000078,0.000131,0.001157,0.0104,0.091,0.280,0.499,1.021,2.164]
# plotting the line 2 points 
plt.plot(x2, y2, label = "AVL tree") 

x2 = [50,100,1000,10000,100000,300000,500000,1000000,2000000] 
y2 =  [0.000074,0.000116,0.000786,0.0096,0.058,0.1925,0.318,0.674,1.47]
# plotting the line 2 points 
plt.plot(x2, y2, label = "RB tree") 

# naming the x axis 
plt.xlabel('Input Size (n)') 
# naming the y axis 
plt.ylabel('Time Taken in sec') 
# giving a title to my graph 
plt.title('Insertion Comparison on reverse sorted data') 

# show a legend on the plot 
plt.legend() 

# function to show the plot 
plt.show() 
