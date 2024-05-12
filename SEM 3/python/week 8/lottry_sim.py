import random
import numpy
import matplotlib.pyplot as plt

tickets =100

def RanBetAmt(players):
    i = 0
    bet_amt = 0 
    while i < players:
        bet_amt += random.randint(1, 100) 
        i += 1
    return bet_amt

#bet = int(input("Enter Your Bet from 1 to 10 : "))
#test = int(input("Enter Number of test cases : "))
#plays = int(input("Enter Number of Plays : "))
test = 10
plays = 365
x = []
results = [] 
t = 0
win = 0
loss = 0

while t< test: 
    x.append(t+1)
    players = random.randint(1, tickets)
    i = 0
    account = 100
    y = []
    z = []
    while i < plays:
        z.append(i+1)
        bet = random.randint(1, 10)
        bet = 1
        #print("Your Bet : ", bet)
        player_bet_amt = random.randint(1, 100)
        #print("Player Bet Amount : ", player_bet_amt)
        total_pool = RanBetAmt(players) + player_bet_amt
        #print("Total Pool : ", total_pool)
        lucky_draw = random.randint(1, players)
        #print("Lucky Draw : ", lucky_draw)
        if bet == lucky_draw:
            account = account + total_pool - player_bet_amt
        else:
            account = account - player_bet_amt
        #print("Your Balance : ", account)
        #print("")
        i = i + 1
        y.append(account)
    plt.plot(z, y)
    plt.show()
    t += 1
    results.append(account)
    if(account > 0):
        win += 1
    else : 
        loss += 1
print("Avarage of all tests is : ",numpy.average(results))
print("No. of wins : ",win,"\nNo. of loss : ",loss)
print("Win ratio : ",win/test,"\nLoss ratio : ", loss/test)

plt.plot(x, results)
plt.show()
