import random

def get_choices():
     player_choice=input("Enter Your choice ")
     options = ["Rock","Paper", "Scissors"]
     computer_choice=random.choice(options)
     hoices={"player":player_choice, "computer": computer_choice}
     return hoices

def check_win(player,computer):
    print(f"player: {player} and computer: {computer}")
    if player == computer:
        return "It's A tie"
    elif player == "Rock":
        if computer == "Paper":
            print(f"computer Won ")
            return 
        if computer == "Scissors":
            print(f"Computer Won ")
            return
    elif player == "Paper":
         if computer == "Scissors":
            print(f"computer Won ")
            return 
         if computer == "Rock":
            print(f"Player Won ")
            return
    elif player == "Scissors":
         if computer == "Rock":
            print(f"computer Won ")
            return 
         if computer == "Paper":
            print(f"Player Won ")
            return


fchoices=get_choices()
result=check_win(fchoices["player"],fchoices["computer"])

print(result)
