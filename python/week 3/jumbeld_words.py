import random

def get_word():
    words = ["Candle", "Bicycle", "Symphony", "Mango", "Telescope", "Ocean", "Castle", "Umbrella", "Whisper", "Mountain", "Envelope", "Galaxy", "Lemon", "Rainbow", "Dragon", "Piano", "Tiger", "Marshmallow", "Forest", "Anchor", "Feather", "Chocolate", "Satellite", "Jellyfish", "Diamond", "Starfish", "Potion", "Lantern", "Penguin", "Robot", "Dinosaur", "Moonlight", "Firefly", "Puzzle", "Lighthouse", "Guitar", "Thunderstorm", "Pineapple", "Parrot", "Carousel", "Bridge", "Wizard", "Bubble", "Coral", "Treasure", "Galaxy", "Serenade", "Zephyr", "Quicksilver", "Nebula"]
    word = random.choice(words)
    return word

def jumble_word(word):
    word = "".join(random.sample(word, len(word)))
    return word

def thank(p1n,p2n,p1,p2):
    print(p1n," your score is ", p1)
    print(p2n," your score is ", p2)
    print("Thanks For Playing")
        

def game():

    ply1 = input("Enter player 1 name: ")
    ply2 = input("Enter player 2 name: ")
    sc1 = 0
    sc2 = 0
    turn = 0
    while(1):
        word = get_word()
        j_word = jumble_word(word)
        print (j_word)

        if turn % 2 == 0:
            print(ply1," Its Your Turn")
        else:
            print(ply2," Its Your Turn")

        ans = input("Guess the Word: ")
        
        if ans == word:
            if turn % 2 == 0:
                sc1 = sc1 + 1
                print(ply1, " Your score is ", sc1,"\n")
            else:
                sc2 = sc2 + 1
                print(ply2, " Your score is", sc2,"\n")
        else:
            print("Better Luck Next Time\nThe Correct Word is ", word)
        c = input("\nDo you want to continue (y/n) : ")
        if c =="n":
                thank(ply1,ply2,sc1,sc2)                
                return
        turn = turn + 1


game()

