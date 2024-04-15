import random

upper_bound = random.randint(100000000, 1000000000)
ans = random.randint(0, upper_bound)

print(f'Guess a number between 0 and {upper_bound}!')

while True:
	data = int(input())
	if(data == ans):
		print("FLAG{pwwwwntooool!}")
	elif(data < ans):
		print("Higher!")
	elif(data > ans):
		print("Lower!")