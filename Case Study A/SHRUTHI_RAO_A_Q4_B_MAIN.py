import numpy as np
import scipy as sp
from scipy.stats import norm
sigma = 0.3
T = 1
r = 0.12
K = 50
t = float(input())
St = np.array(range(1,150))
d1 = (np.log(St/K) + (r + (sigma*sigma)/2)*(T-t))/(sigma*np.sqrt(T-t))
d2 = d1 - sigma*np.sqrt(T-t)
N_d1 =  sp.stats.norm.cdf(d1)
N_d2 =  sp.stats.norm.cdf(d2)
C = N_d1*St - N_d2*K*np.exp(-r*(T-t))
P = K*np.exp(-r*(T-t)) - St + C
print('When t =', t)
print('Delta for call option from the graph =', np.gradient(C)[124])
print('Delta for put option from the graph =', np.gradient(P)[124])