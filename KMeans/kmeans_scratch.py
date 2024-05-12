import numpy as np
import pandas as pd 
import matplotlib.pyplot as plt
from matplotlib.colors import ListedColormap
#%matplotlib inline

blobs = pd.read_csv('observacoescluster.csv')
colnames = list(blobs.columns[1:-1])
blobs.head()