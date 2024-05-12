import csv 
import numpy as np
import random as rd
import math as mt
import matplotlib.pyplot as plt
np.random.seed(123)

with open('observacoescluster.csv', 'r') as read_obj:

	 data = list(csv.reader(read_obj, delimiter =";"))

data2 = [list(map(float, row)) for row in data]

k = 4
cluster = []
b = []
bnovo = []

for i in range (len(data)):
	b.append(0)
	bnovo.append(1)

for i in range (0,k-1):
	 cluster.append(data[rd.randrange(0,len(data2))][:])

cluster2 = [list(map(float, row)) for row in cluster]

itermax=4000
iter = 0

centroide_maisproximo = 0
entrada = len(data)
eqt = []
erros = []
for j in range(0,k-1):
	eqt.append(0)
	erros.append([])

distancia = []

while (b!= bnovo) and (iter < itermax):

	for j in range(0,k-1):
		eqt[j] = 0
	b = bnovo[:]
	iter += 1
	print(iter)

	for i in range(0,entrada):
			maisproximo=1000
			for j in range (0,k-1):
				distancia = mt.sqrt((cluster2[j][0]- data2[i][0])**2 + ((cluster2[j][1]-data2[i][1]))**2)
				if (distancia < maisproximo):
					maisproximo=distancia
					centroide_maisproximo = j
				bnovo[i] = centroide_maisproximo
	
	for j in range (0,k-1):
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
	
	for j in range(0,k-1):
		erros[j].append(eqt[j])



for i in range(0,entrada):
	if bnovo[i] == 0:
		plt.scatter(data2[i][0], data2[i][1], c= "b", marker= '.')
	if bnovo[i] == 1:
		plt.scatter(data2[i][0], data2[i][1], c= "r", marker= '.')
	if bnovo[i] == 2:
		plt.scatter(data2[i][0], data2[i][1], c= "g", marker= '.')
	if bnovo[i] == 3:
		plt.scatter(data2[i][0], data2[i][1], c= "y", marker= '.')
	if bnovo[i] == 4:
		plt.scatter(data2[i][0], data2[i][1], c= "n", marker= '.')

for j in range (0,k-1):
	plt.scatter(cluster2[j][0],cluster2[j][1])

plt.show()


