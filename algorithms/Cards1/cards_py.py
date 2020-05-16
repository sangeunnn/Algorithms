#
#
#
#

#input 1. n 2. numbers
in = open("1.txt",'r')
in>>n
for i in range(1,n+1):
    total_sum += i
    total_mult += i*i
for i in range(0,n-2):
    in >> number
    sum += number
    mult += number*number
in.close()

#find card number
c = total_sum - sum
d = total_mult - mult
b = (c+math.sqrt(2*d-c*c))/2
a = c - b

#output
out = open("1t.txt", 'w')
if a<b:
    print(a)
    print(b)
    out
else:
    print(b)
    print(a)
