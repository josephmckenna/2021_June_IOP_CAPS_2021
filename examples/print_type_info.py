import sys

def PrintTypeInfoTitle():
    print("Name\tBytes\tmin\tmax\n")

def PrintTypeInfo(T):
    print((type(T).__name__) + "\t" + str(sys.getsizeof(T)))

PrintTypeInfo(True)
PrintTypeInfo('a')
PrintTypeInfo(123)
PrintTypeInfo(12345)
PrintTypeInfo(2* 10**307)