#!/usr/bin/env python
import matplotlib.pyplot as plt 

#x1 = [9679,23114533,19319,39769,9999999967,99999999999899999,1049179854847,799333555511111,50256041046881,7942297991, 9999999929, 999998727899999, 999983]
#y1 =  [1.6,0.00,2,15,71,21780,250,14355,2601,3,186,7016,3]
#plt.plot(x1, y1, label = "Pollard Rho")
  
x2 = [7,97,997,9973,99929,999983,9999991,999999937,1235944327,261628321,8609513413,982451653,999416681,99999989]
y2 = [3,3,3,3,9,8,3,3,2,3,24,609,259,1498]
plt.plot(x2, y2, label = "Pollard p-1")
  

#x3 = [1,4,16,64] 
#y3 =  [286,1449,896464,5218045] 
#plt.plot(x3, y3, label = "Quadratic Sieve")
  
# naming the x axis 
plt.xlabel('N')
# naming the y axis 
plt.ylabel('Running Time')
# giving a title to my graph 
plt.title('Value of N vs Running time')
  
# show a legend on the plot 
plt.legend() 
  
# function to show the plot 
plt.show()

