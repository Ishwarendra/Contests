import requests
import json

# url1 = "https://jsonmock.hackerrank.com/api/football_matches?year=" + str(2020); # + "&team1=" + "2"


def getDiscount(barcode):
    url = f"https://jsonmock.hackerrank.com/api/inventory?barcode={barcode}"
    response = requests.get(url)
    result = json.loads(response.content)

    data = result['data']
    if len(data) == 0:
        return -1

    price = data[0]['price']
    discount = data[0]['discount']

    return price - (price * discount) // 100

print(getDiscount(74002314))