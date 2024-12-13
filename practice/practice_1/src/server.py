import random

options = ["stone", "scissor", "paper"]

for i in range(1,1001):
	server_choice = random.choice(options)

	print(f"=====Round {i}/1000=====")
	print(f"Server choosed {server_choice}!")
	print("Enter your choice: ")
	player_choice = str(input().strip().lower())

	if player_choice not in options:
		print("Invalid Choice")
		exit(1)
	else:
		if player_choice == server_choice:
			print("Draw")
			exit(1)
		elif (player_choice == "stone" and server_choice == "scissor") or \
			(player_choice == "scissor" and server_choice == "paper") or \
			(player_choice == "paper" and server_choice == "stone"):
			print("You win!")
		else:
			print("You Lose")
			exit(1)

print("Congrats for wining 1000 round!")
print("FLAG{la7e_thr0w}")