import pandas as pd
import matplotlib.pyplot as plt
from scipy.ndimage.filters import gaussian_filter1d

data = pd.read_csv('aware_forwardrewardhexa.csv')
#data = pd.read_csv('forwardrewardhexa_final.csv')
sf=4

       # Extract the data we're interested in
q = data['Value-eval'].quantile(0.99)
rew = data[data['Value-eval'] < q]
ite = rew['Step-eval']
rew_smooth = gaussian_filter1d(rew['Value-eval'], sigma=sf)

q1 = data['Value-eval1'].quantile(0.99)
rew1 = data[data['Value-eval1'] < q1]
ite1 = rew1['Step-eval1']
rew_smooth1 = gaussian_filter1d(rew1['Value-eval1'], sigma=sf)

q2 = data['Value-eval2'].quantile(0.99)
rew2 = data[data['Value-eval2'] < q2]
ite2 = rew2['Step-eval2']
rew_smooth2 = gaussian_filter1d(rew2['Value-eval2'], sigma=sf)

q3 = data['Value-eval3'].quantile(0.99)
rew3 = data[data['Value-eval3'] < q3]
ite3 = rew3['Step-eval3']
rew_smooth3 = gaussian_filter1d(rew3['Value-eval3'], sigma=sf)

"""
ite1, rew1 = data['Step-eval1'], data['Value-eval1']
rew1_smooth = gaussian_filter1d(rew1, sigma=sf)
ite2, rew2 = data['Step-eval2'], data['Value-eval2']
rew2_smooth = gaussian_filter1d(rew2, sigma=sf)
ite3, rew3 = data['Step-eval3'], data['Value-eval3']
rew3_smooth = gaussian_filter1d(rew3, sigma=sf)
"""
       # Scatter the points, using size and color but no label
plt.plot(ite, rew_smooth)
plt.plot(ite1, rew_smooth1)
plt.plot(ite2, rew_smooth2)
plt.plot(ite3, rew_smooth3)
plt.show()
