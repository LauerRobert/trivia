from fileinput import close
import subprocess
from filecmp import cmp
import os

# set up paths
goldMaster = "../GoldMaster/GoldMaster.txt"
goldMasterComparator = "../GoldMaster/GoldMasterComparator.txt"
executable = "../C++/GameRunner.exe"

# run executable and accumulate output
goldMasterComparatorFile = open(goldMasterComparator, "w")
subprocess.call([executable, "0", "1", "2", "3", "5", "7", "11", "13", "17"], stdout=goldMasterComparatorFile)
goldMasterComparatorFile.close()

# check whether output matches goldMaster
result = cmp(goldMaster, goldMasterComparator)
print(result)

# clean up
if (result is True):
    os.remove(goldMasterComparator)
else:
    subprocess.call(["C:/Program Files/Beyond Compare 4/BCompare.exe", goldMaster, goldMasterComparator])
os.remove(executable)
