import matplotlib.pyplot as pyp 
import numpy as np
#f = open("data_time","r")
f = open("data_space","r")
x_t = []
y_t = []

for line in f.readlines():
	x_t.append(line.split()[2])
	y_t.append(line.split()[5])

print(x_t,y_t)
pyp.scatter(x_t,y_t)
pyp.show()
