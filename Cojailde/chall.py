#!/user/bin/env python3

blacklist = ['write','open','pty','from','sys','platform','type', 'ls', 'cat', 'flag', 'head', 'tail', 'print']
import os

# Have to read flag.txt

while True:
	cmd = input(">>> ")
	if any([x in cmd  for x in blacklist]):
		print ("Did not pass filter")
	else:
		try:
			print(cmd)
			exec(cmd)
		except Exception as e :
			print(f"Error running command\n{e}")
