def IsPrime(n):
    for i in range(2,int(n/2)):
        if n % i == 0 :
            return False
    return True

for i in range(2,100):
    if IsPrime(i):
        print(str(i))
