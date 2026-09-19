import numpy as np
import pandas as pd
import json

df=pd.read_csv(r'DATA\kolkata_west_bengal_dijkstra_routes.csv')


# To gate the station number and load the station with number
s=set()
count=0
for i,row in df.iterrows():
    if row['Source'] in s:
        continue
    l=row['Source'].split()
    key="_".join(l)
    s.add(row['Source'])
    print(f'stations["{key}"]={count};')
    count+=1
    


# # To gate edge info with destination
# stations={}
# count=0
# s=set()
# for i,row in df.iterrows():
#     if row['Source'] in s:
#         continue
#     s.add(row['Source'])
#     stations[row['Source']]=count
#     count+=1

# # print(json.dumps(stations))

# for i,row in df.iterrows():
#     # print(f"{row['Source']},{row['Destination']},{row['Distance_km']},{row['Travel_Time_min']}")
#     print(f'g.addEdge({stations[row["Source"]]},{stations[row["Destination"]]},{row['Distance_km']},{row['Travel_Time_min']});')







# print(f"Index: {i}-->Source:{row['Source']},Destination:{row['Destination']},Distance_km:{row['Distance_km']},Travel_Time_min:{row['Travel_Time_min']}")

