import numpy as np
import pandas as pd
import csv
import matplotlib.pyplot as mp
import seaborn as sns
from scipy import stats
path=r"E:\omar\stat project\Diabetes Dataset.csv"
data=pd.read_csv(path)
dataframe=pd.DataFrame(data)

outcome=data['Outcome'].tolist()#1

age=data['Age'].tolist()#2

skin=data['SkinThickness'].tolist()#3

preg=data['Pregnancies'].tolist()#4

bp=data['BloodPressure'].tolist()#5

bmi=data['BMI'].tolist()#6

ins=data['Insulin'].tolist()#7

dpf=data['DiabetesPedigreeFunction'].tolist()#8

gul=data['Glucose'].tolist()#9

print(data)
corr=data.corr()
sns.heatmap(corr, annot=True, cmap='coolwarm', fmt='.2f', vmin=-1, vmax=1)
mp.title('Correlation Matrix Heatmap')
mp.show()

############################# ScatterPlot
mp.scatter(bp,bmi)
mp.title("ScatterPlot")
mp.xlabel("BP")
mp.ylabel("BMI")
mp.show()


###############################  Histogram
mp.hist(preg)
mp.title("pregnancies")
mp.show()
mp.hist(skin)
mp.title("SkinThickness")
mp.show()
mp.hist(age)
mp.title("Age")
mp.show()
##########################################   PieChart
ct=0
ct2=0
for i in outcome:
    if outcome[i]==1:
        ct+=1
    else:
        ct2+=1 
        

res=[ct2,ct]
label = ["Has diabeites", "Do not have diabetes"]
mp.pie(res,labels = label,autopct='%1.0f%%')
mp.show()
################################################BoxPlots

mp.boxplot(dpf) 
mp.title("DiabetesPedigreeFunction boxplot")
mp.show()
mp.boxplot(skin) 
mp.title("Skin thickness boxplot")
mp.show()
mp.boxplot(bp)
mp.title("Blood Pressure boxplot")
mp.show()

###############################################central tendencies

for r in data:
    res=np.median(data[r])#median
    print("The median of",r,"is",res)
    res=stats.mode(data[r])#mode
    print("The mode of",r,"is",res)
    res=np.mean(data[r])#mean
    print("The mean of",r,"is",res)
    res=np.var(data[r])#variance
    print("The variance of",r,"is",res)
    res=np.std(data[r])#standrad deviation
    print("The Standrad deviation of",r,"is",res)
    res=np.min(data[r])#min
    print("The min of",r,"is",res)
    res=np.max(data[r])#max
    print("The max of",r,"is",res)