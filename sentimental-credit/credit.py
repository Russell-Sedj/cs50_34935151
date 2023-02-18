# TODO
from cs50 import get_int
from sys import exit

card = -1
while card < 0:
    card = get_int("Number: ")

ccn = card
lenght = 0
while ccn > 0:
    ccn //= 10
    lenght += 1

ccn = card
sum = 0
i = 0
while ccn > 0:
    if i % 2 == 0:
        sum += ccn % 10
    else:
        x = 2 * (ccn % 10)
        sum += (x // 10) + (x % 10)
    i += 1
    ccn //= 10
if (sum % 10) != 0:
    print("INVALID")
    exit()

if (lenght == 15 and (card // 10000000000000 == 34 or card // 10000000000000 == 37)):
    print("AMEX")
elif (lenght == 16 and (card // 100000000000000 == 51 or card // 100000000000000 == 52 or card // 100000000000000 == 53 or card // 100000000000000 == 54 or card // 100000000000000 == 55)):
    print("MASTERCARD")
elif((lenght == 13 and card // 1000000000000 == 4) or (lenght == 16 and card // 1000000000000000 == 4)):
    print("VISA")
else:
    print("INVALID")