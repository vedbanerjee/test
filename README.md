# Atlas The Game
Hi, I am Ved Banerjee. A newbie programmer from India. End of my first year at college so I decided to make a personal project using whatever knowledge I had, which amounts to not much. Anyways thats a lot about me. Lets talk about the project.

## Description

The game starts with one person giving a name of a country. The next person then gives another country beginning with the last letter of the first person's country. 
The thrid person gives another country beginning with the last letter of the second country and so on. Simple and a quite popular game.

## Features and Rules
Whatever country you give should be a real country.
```
Enter number of players: 3

Enter country player 1: fgihan

The country fgihan is not a valid country

Player 1 loses
```
The game is case sensitive so every country's name should be compulsarily in lowercase.

Avoid using short forms like "usa" or "st. lucia". Enter the full name of these countries

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
The country you enter should start with the last letter of the previous player's country.
```
Enter number of players: 3

Enter country player 1: india

Enter country player 2: afghanistan 

Well Done Player 2

Enter country player 3: russia

Last letter of afghanistan is not equal to the first letter of russia

Player 3 Loses
```

This is a multiplayer game and not a singleplayer so you need friends to play this with.

## Status 
The game works alright. 

A singleplayer mode would be useful. 

The game stops after one player loses. I figured this would ruin the fun. The game needs to continue until there is a winner. 

These are the only developments needed

## How to Use?
Download the .exe file and run it.(as per my limited knowledge this is how every c program runs)

### THANKS FOR STOPPING BY ON THIS PROJECT
