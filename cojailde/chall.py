#!/user/bin/env python3

# Have to read flag.txt

blacklist = ['write','open','pty','from','sys','platform','type', 'ls', 'cat', 'flag', 'head', 'tail', 'print']
import os


cmd = input(">>> ")
if any([x in cmd  for x in blacklist]):
	print ("did not pass filter")
else:
	try:
		print(cmd)
		exec(cmd)
	except Exception as e :
		print(f"error running command\n{e}")
