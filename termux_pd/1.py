#!/mingw64/bin/python

import json
import os
import random

data = "in.smf"

list0 = []
for i in range(0, 100):
    dict0 = {}
    dict0["type"] = 2
    dict0["name"] = str(i)
    dict0["password"] = str(int(random.random() * 1e10))
    list0.append(dict0)

with open(data, "w", encoding="utf-8") as f:
    json.dump(list0, f)
