import matplotlib.pyplot as plt 

# line 1 points 
x1 = [50,100,1000,10000,20000,40000,60000,80000,100000] 
y1 = [0.000052,0.000059,0.00036,0.00275,0.0075,0.0124,0.0198,0.0251,0.0321] 
# plotting the line 1 points 
plt.plot(x1, y1, label = "Binomial Heap") 

# line 2 points 
x2 = [50,100,1000,10000,20000,40000,60000,80000,100000] 
y2 =  [0.000040,0.000052,0.000255,0.003952,0.00610,0.0115,0.0220,0.0253,0.0421]
# plotting the line 2 points 
plt.plot(x2, y2, label = "AVL tree") 

x2 = [50,100,1000,10000,20000,40000,60000,80000,100000] 
y2 =  [0.000049,0.000052,0.000708,0.007928,0.0056,0.0121,0.0196,0.0268,0.0343]
# plotting the line 2 points 
plt.plot(x2, y2, label = "RB tree") 

# naming the x axis 
plt.xlabel('Input Size (n)') 
# naming the y axis 
plt.ylabel('Time Taken in sec') 
# giving a title to my graph 
plt.title('Deletion Comparison on sorted data') 

# show a legend on the plot 
plt.legend() 

# function to show the plot 
plt.show() 
