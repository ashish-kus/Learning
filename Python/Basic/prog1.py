def get_choices():
    player_choice = input("ENTER the choice ( rock, paper, scissors)")
    computer_choice = "Paper"
    ch={"player":player_choice,"computer_choice":computer_choice}
    return ch

choices = get_choices()
print(choices)

