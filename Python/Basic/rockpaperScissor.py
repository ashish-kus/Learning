import random

def get_choices():
    player_choice = input("ENTER the choice ( rock, paper, scissors)")
    option=["rock", "paper", "scissor"]
    computer_choice = random.choice(option)
    ch={"player":player_choice,"computer_choice":computer_choice}
    return ch



def check_win(player, computer):
    print(f"you : {player} , Computer : {computer}")
    if player== computer:
        return "its a tie"
    elif player=="rock":
        if computer == "scissor":
            return "rock smashes scissors"
        else:
            return "paper cover rock you lose."
    
    elif player=="paper":
        if computer == "rock":
            return "you win"
        else:
            return "you lose. scissor will cut you"
    elif player=="scissor":
        if computer == "rock":
            return "cant cut rock, you lose."
        else:
            return "paper is so weak, you lose."
    else:
        return "you did somthing that was not ment to be done"

choices=get_choices()

result = check_win(choices["player"], choices["computer_choice"])
print(result)
