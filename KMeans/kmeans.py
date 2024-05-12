import csv 
import numpy as np
import random as rd
import pandas as pd
import math as mt
import matplotlib.pyplot as plt
np.random.seed(123)

with open('observacoescluster.csv', 'r') as read_obj:

	 data = list(csv.reader(read_obj, delimiter =";"))
	 #data = [list(map(float, row)) for row in csv.reader(read_obj)]

#print(spamreader)

#data = np.genfromtxt('observacoescluster.csv', delimiter= ';')

data2 = [list(map(float, row)) for row in data]

k = 4
#b = np.zeros((2,20))
#bnovo = np.ones((20,2))
#cluster = np.zeros((40))
cluster = []
b = []
bnovo = []

# for i in range (19):
#     #cluster[i] = np.random.random()
#     print(data[i][0])

for i in range (len(data)):
	b.append(0)
	bnovo.append(1)

for i in range (0,k):
	 cluster.append(data[rd.randrange(0,len(data2))][:])

cluster2 = [list(map(float, row)) for row in cluster]

itermax=4000
iter = 0

centroide_maisproximo = 0
entrada = len(data)
eqt = []
erros = []
for j in range(0,k):
	eqt.append(0)
	erros.append([])

distancia = []

while (b!= bnovo) and (iter < itermax):

	for j in range(0,k):
		eqt[j] = 0
	b = bnovo[:]
	iter += 1
	print(iter)

	for i in range(0,entrada):
			maisproximo=1000
			for j in range (0,k):
				distancia = mt.sqrt((cluster2[j][0]- data2[i][0])**2 + ((cluster2[j][1]-data2[i][1]))**2)
				if (distancia < maisproximo):
					maisproximo=distancia
					centroide_maisproximo = j
				bnovo[i] = centroide_maisproximo
	
	for j in range (0,k):
		somax = 0
		somay = 0
		elementos = 0
		for i in range (0,entrada):
			if(bnovo[i] == j):
				distancia = mt.sqrt((cluster2[j][0]- data2[i][0])**2 + ((cluster2[j][1]-data2[i][1]))**2)
				eqt[j]+= distancia**2
				somax += data2[i][0]
				somay += data2[i][0]
				elementos += 1
		if elementos != 0:
			cluster2[j][0] = somax / elementos
			cluster2[j][1] = somay / elementos
	
	for j in range(0,k):
		erros[j].append(eqt[j])

for i in range(0,entrada):
	if bnovo[i] == 0:
		plt.scatter(data2[i][0], data2[i][1], c= "b")
	if bnovo[i] == 1:
		plt.scatter(data2[i][0], data2[i][1], c= "r")
	if bnovo[i] == 2:
		plt.scatter(data2[i][0], data2[i][1], c= "g")
	if bnovo[i] == 3:
		plt.scatter(data2[i][0], data2[i][1], c= "y")
	if bnovo[i] == 4:
		plt.scatter(data2[i][0], data2[i][1], c= "n")

for j in range (0,k):
	plt.scatter(cluster2[j][0],cluster2[j][1])





