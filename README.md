# Atlas The Game

## Description

This was a beginner project I made at the end of my first year at university.

The game starts with one person giving a name of a country. The next person then gives another country beginning with the last letter of the first person's country. 
The thrid person gives another country beginning with the last letter of the second country and so on. A simple and quite popular game.

## Features and Rules

- Avoid using anything apart from numbers when asked to enter the number of players. 

- The game is case sensitive so every country's name should be compulsorily in lowercase.
```
Enter country player 2: Afghanistan

The country Afghanistan is not a valid country or used before

Player 2 loses
```
- Whatever country you give should be a real country.
```
Enter number of players: 3

Enter country player 1: fgihan

The country fgihan is not a valid country

Player 1 loses
```

- Avoid using short forms like "usa" or "st. lucia".

```c

Enter country player 1: guinea-bissau

Enter country player 2: usa

The country usa is not a valid country or used before

Player 2 loses
```

Instead,  enter the full name of these countries

```c
Enter number of players: 4

Enter country player 1: bangladesh

Enter country player 2: honduras

Well Done Player 2

Enter country player 3: saint lucia

Well Done Player 3
```
- The country you enter should start with the last letter of the previous player's country.
```
Enter number of players: 3

Enter country player 1: india

Enter country player 2: afghanistan 

Well Done Player 2

Enter country player 3: russia

Last letter of afghanistan is not equal to the first letter of russia

Player 3 Loses
```
- A country once used cannot be used again irrespective of whether it was used in the correct manner or not.
```
Enter number of players: 4

Enter country player 1: albania

Enter country player 2: afghanistan

Well Done Player 2

Enter country player 3: russia

Last letter of afghanistan is not equal to the first letter of russia

Player 3 Loses

Enter country player 4: niger

Well Done Player 4

Enter country player 1: russia

The country russia is not a valid country or used before

Player 1 loses
```
- At the end, when there is only one player left and he gives the correct country according to the rules, he wins the game.
```
Enter country player 2: albania

Well Done Player 2

Enter country player 1: aasia      

The country aasia is not a valid country or used before

Player 1 loses

Player 2 is the only player left.
If Player 2 guesses correctly, he will declared the Winner

Enter country 2: algeria

PLAYER 2 IS THE WINNER!!!!
```
If the last player fails to give a correct country,  there is no winner.
```
Enter country player 1: nigeria

Well Done Player 1

Enter country player 2: albania

Well Done Player 2

Enter country player 1: asia

The country asia is not a valid country or used before

Player 1 loses

Player 2 is the only player left.
If Player 2 guesses correctly, he will declared the Winner

Enter country 2: africa

No winner
```
- This is a multiplayer game and not a singleplayer so you need friends to play this with.

## Status 
The game works alright. 

A singleplayer mode would be useful.  

These are the only developments needed

## How to Use?
Download the .exe file. After downloading run it on an ide or any other terminal on your laptop

### THANKS FOR STOPPING BY ON THIS PROJECT
