import matplotlib.pyplot as plt 

# line 1 points 
x1 = [8,9,19,159] 
y1 = [0.000134,0.000141,0.000220,0.000532] 
# plotting the line 1 points 
plt.plot(x1, y1, label = "Standard Prims") 

# line 2 points 
x2 = [8,9,19,159]
y2 =  [0.000016,0.000018,0.000028,0.000052]
# plotting the line 2 points 
plt.plot(x2, y2, label = "Prims Using Binomial Heap") 


# naming the x axis 
plt.xlabel('Number of edges') 
# naming the y axis 
plt.ylabel('Time Taken in sec') 
# giving a title to my graph 
plt.title('Prims Algo Comparison') 

# show a legend on the plot 
plt.legend() 

# function to show the plot 
plt.show() 
