import os
import time
import sys


child_number = 0
input('Hello! I am the parent process. My PID is ' + str(os.getpid()) + '. \nYou can attach me to strace now. Press Enter when you are done.')
new_fork = os.fork()
if new_fork == 0:
    print('\n\nHello! I am the child. ' + 'My PID is ' + str(os.getpid()))
    time.sleep(5)
    print('\nWriting to file "123temp.txt". This file will be deleted before my parent process terminates.')
    f = open('123temp.txt', 'w')
    f.write('Hi there! This is just a test content. If this file exists for more than 1 second, it means that there was some problem with the executing process.')
    time.sleep(5)
    print("\nWritten. Now I will exit! Bye!")
    sys.exit(0)
os.waitpid(new_fork, 0)
time.sleep(5)
print("\nI am the parent process. Looks like my child has created some garbage file into your computer. I am reading the file contents now.")
f = open('123temp.txt', 'r')
f.read()
time.sleep(8)
print('\nRead. I will be deleting what my mischievous child created.')
os.remove('123temp.txt')
time.sleep(5)
print('\nDeleted. Now I will be exiting too! Have a great day!')
time.sleep(3)

