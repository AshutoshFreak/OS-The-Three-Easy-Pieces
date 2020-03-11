from bs4 import BeautifulSoup
import requests
import multiprocessing


main_page_url = 'http://pages.cs.wisc.edu/~remzi/OSTEP/'  # Trailing '/' reqd.
response = requests.get(main_page_url)
response.raise_for_status()
raw_html = response.text
soup = BeautifulSoup(raw_html, 'lxml')

table = soup.find_all(name='table')[4]

li = table.find_all(name='tr')
header_row = li[0]
body_rows = li[1:]

jobs = []
counter = 99901
for row in body_rows:
    for cell in row.find_all('td'):
        li = cell.find_all(name='a')
        if not li:
            continue
        x = li[0]
        file_url = main_page_url + x['href'].strip()
        file_name = x.text.strip()
        file_chap_num = cell.find(name='small')
        if file_chap_num:
            file_chap_num = file_chap_num.text.strip()
        else:
            file_chap_num = counter
            counter += 1
        file_name = f"{file_chap_num:0>2} - {file_name.replace('/', '_')}.pdf"
        jobs.append((file_url, file_name))

for job in jobs:
    print(job[0], ' ==== ', job[1])

print('\n\n', 'CONTINUE? (Press Ctrl+C to stop now, Press Enter continue...)')
try:
    input()
except KeyboardInterrupt:
    print('\n\nAborted.')
    exit(0)

print('\n\n', 'Downlaoding...')

def download(job):
    response = requests.get(job[0])
    response.raise_for_status()
    with open(job[1], 'wb') as file:
        file.write(response.content)

with multiprocessing.Pool() as pool:
    pool.map(download, jobs)

print('\n\n', 'Done.')
