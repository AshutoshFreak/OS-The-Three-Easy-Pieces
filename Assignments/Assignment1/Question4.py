import subprocess
import sys
import pathlib
import time

python = sys.executable
self_name = pathlib.Path(sys.argv[0]).resolve()
requested_children = int(sys.argv[1])

if requested_children:
    subprocess.check_call([python, self_name, str(requested_children-1)])
else:
    time.sleep(30)
