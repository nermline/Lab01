import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("output2.csv", names=["cell", "count"])
ax = df.plot(kind="bar", x="cell", y="count", legend=False)
ax.set_xticks([])  
ax.set_xlabel("Cell")
ax.set_ylabel("Hits count")
plt.show()