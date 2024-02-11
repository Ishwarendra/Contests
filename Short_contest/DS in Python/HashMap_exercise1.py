with open("nyc_weather.csv") as f:
    arr = []; arr_data = []
    for line in f:
        data = line.split(",")
        data[1] = data[1].replace("\n", "")
        if data[0] == "date":
            arr.append([data[0], data[1]])
            continue
        arr.append([data[0], float(data[1])])
        arr_data.append(float(data[1]))
sum = 0
for i in range(7):
    sum += arr_data[i]
print(f"Average of the first week is {sum/7}")