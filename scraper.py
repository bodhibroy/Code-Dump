#!/usr/bin/python
# This program scrapes all links from a URL, and downloads them
# Replace pdf with some other extension
import urllib2
import os
import string
from BeautifulSoup import BeautifulSoup

url="http://www.comp.nus.edu.sg/~sanjay/cs4232.html"
page=urllib2.urlopen(url)
soup=BeautifulSoup(page)
links=soup.findAll('a')
for each in links:
    if each['href'].find("pdf")!=-1:
        val="wget "+ each['href']
        print val
        os.system(val)
