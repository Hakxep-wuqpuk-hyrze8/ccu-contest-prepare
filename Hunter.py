from bs4 import BeautifulSoup
import requests

response = requests.get('https://www.yda.gov.tw/')
soup = BeautifulSoup(response.content, 'lxml')
dates = soup.find_all("small", class_="date")
for date in dates:
    date_text = date.text.replace(' ', '').replace('\n', '')
    print(date_text)
