from fileinput import close
import subprocess
from filecmp import cmp
import os

goldMaster = "../GoldMaster/GoldMaster.txt"
goldMasterComparator = "../GoldMaster/GoldMasterComparator.txt"

goldMasterComparatorFile = open(goldMasterComparator, "w")
subprocess.call(["../C++/GameRunner.exe", "0", "1", "2", "3", "5", "7", "11", "13", "17"], stdout=goldMasterComparatorFile)
goldMasterComparatorFile.close()

result = cmp(goldMaster, goldMasterComparator)
print(result)

if (result is True):
    os.remove(goldMasterComparator)
else:
    subprocess.call(["C:/Program Files/Beyond Compare 4/BCompare.exe", goldMaster, goldMasterComparator])
