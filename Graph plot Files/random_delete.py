import matplotlib.pyplot as plt 

# line 1 points 
x1 = [50,100,1000,10000,20000,40000,60000,80000,100000] 
y1 = [0.000063,0.000152,0.001885,0.03588,0.0573,0.343,1.071,2.909,3.886] 
# plotting the line 1 points 
plt.plot(x1, y1, label = "Binomial Heap") 

# line 2 points 
x2 = [50,100,1000,10000,20000,40000,60000,80000,100000] 
y2 =  [0.000038,0.000061,0.000920,0.008507,0.0165,0.037,0.066,0.083,0.1351]
# plotting the line 2 points 
plt.plot(x2, y2, label = "AVL tree") 

x2 = [50,100,1000,10000,20000,40000,60000,80000,100000] 
y2 =  [0.000049,0.000052,0.000708,0.007928,0.0111,0.024,0.040,0.057,0.098]
# plotting the line 2 points 
plt.plot(x2, y2, label = "RB tree") 

# naming the x axis 
plt.xlabel('Input Size (n)') 
# naming the y axis 
plt.ylabel('Time Taken in sec') 
# giving a title to my graph 
plt.title('Deletion Comparison on random data') 

# show a legend on the plot 
plt.legend() 

# function to show the plot 
plt.show() 
