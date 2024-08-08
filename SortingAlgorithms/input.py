#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# To generate a text file containing numbers in descending order
n=50000
fp = open("descending_"+str(n)+".txt","w") 
fp.write(str(n)+" ")
for i in range(n-1,1,-1): # n = 10000, 9999, 9998, ---- 1 
    fp.write(str(i)+" ")
fp.write(str(1))
fp.close()

# To generate a text file containing numbers in ascending order
# #!/usr/bin/env python3
# # -*- coding: utf-8 -*-
# n=60000
# fp = open("ascending_"+str(n)+".txt","w") #fp.write(str(n)+" ")
# for i in range(1,n): # 1 to n-1
# #ascending_60000.txt
#     fp.write(str(i)+" ") # 1 2 3 4 ... 10 11 12 fp.write(str(n))
# fp.close()

# To generate a text file containing numbers in random order
# #!/usr/bin/env python3 
# # -*- coding: utf-8 -*- 
# import random
# n = 50000
# fp = open("random_"+str(n)+".txt","w") 
# fp.write(str(n)+" ")
# for i in range(1,n):
#     x = random.random()
# #random_50000.txt
#     fp.write(str(int(x*n))+" ")
# x = random.random()
# fp.write(str(int(x*n))+" ")
# fp.close()
    