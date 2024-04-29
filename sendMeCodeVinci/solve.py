import requests

url = 'http://localhost:5000/'

headers = {'Content-Type': 'application/json'}
response = requests.request('CODEVINCI', url, headers=headers)

print(response.text)
