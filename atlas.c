#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 195
// Global variable 'countries' containing list of all the countries
char *countries[MAX] = {"afghanistan", "albania", "algeria", "andorra", "angola", "antigua and deps", "argentina", "armenia", "australia", "austria", "azerbaijan", "bahamas", "bahrain", "bangladesh", "barbados", "belarus", "belgium", "belize", "benin", "bhutan", "bolivia", "bosnia herzegovina", "botswana", "brazil", "brunei", "bulgaria", "burkina", "burundi", "cambodia", "cameroon", "canada", "cape verde", "central african republic", "chad", "chile", "china", "colombia", "comoros", "congo", "costa rica", "croatia", "cuba", "cyprus", "czech republic", "denmark", "djibouti", "dominica", "dominican republic", "east timor", "ecuador", "egypt", "el salvador", "equatorial guinea", "eritrea", "estonia", "ethiopia", "fiji", "finland", "france", "gabon", "gambia", "georgia", "germany", "ghana", "greece", "grenada", "guatemala", "guinea", "guinea-bissau", "guyana", "haiti", "honduras", "hungary", "iceland", "india", "indonesia", "iran", "iraq", "ireland", "israel", "italy", "ivory coast", "jamaica", "japan", "jordan", "kazakhstan", "kenya", "kiribati", "north korea", "south korea", "kosovo", "kuwait", "kyrgyzstan", "laos", "latvia", "lebanon", "lesotho", "liberia", "libya", "liechtenstein", "lithuania", "luxembourg", "macedonia", "madagascar", "malawi", "malaysia", "maldives", "mali", "malta", "marshall islands", "mauritania", "mauritius", "mexico", "micronesia", "moldova", "monaco", "mongolia", "montenegro", "morocco", "mozambique", "myanmar", "namibia", "nauru", "nepal", "netherlands", "new zealand", "nicaragua", "niger", "nigeria", "norway", "oman", "pakistan", "palau", "panama", "papua new guinea", "paraguay", "peru", "philippines", "poland", "portugal", "qatar", "romania", "russia", "rwanda", "saint kitts and nevis", "saint lucia", "saint vincent and the grenadines", "samoa", "san marino", "sao tome and principe", "saudi arabia", "senegal", "serbia", "seychelles", "sierra leone", "singapore", "slovakia", "slovenia", "solomon islands", "somalia", "south africa", "south sudan", "spain", "sri lanka", "sudan", "suriname", "swaziland", "sweden", "switzerland", "syria", "taiwan", "tajikistan", "tanzania", "thailand", "togo", "tonga", "trinidad and tobago", "tunisia", "turkey", "turkmenistan", "tuvalu", "uganda", "ukraine", "united arab emirates", "united kingdom", "united states of america", "uruguay", "uzbekistan", "vanuatu", "vatican city", "venezuela", "vietnam", "yemen", "zambia", "zimbabwe"};

int is_present(char *country)
{ // Checks if the country is in the list of all countries
    for (int i = 0; i < MAX; i++)
    {
        if (strcmp(country, countries[i]) == 0)
        {
            countries[i] = "\0";
            return 1;
        }
    }
    return 0;
}

void reset(int *player_count, int num_of_players)
{ // After the last player's turn, this makes sure the next turn is of the first player
    if (*player_count == (num_of_players) + 1)
    {
        *player_count = 1;
    }
}
int win(char *ctr1, char *ctr2, int num_of_players, int lost_players[]);
int main(void)
{
    int player_count = 1;
    int num_of_players = 0;
    while (num_of_players <= 1)
    {
        printf("Enter number of players: ");
        scanf("%d", &num_of_players);
    }
    char waste; // Stores the '\n' after scanning num_of_players
    scanf("%c", &waste);

    int lost_players[num_of_players];
    int players_remaining = num_of_players;
    char *ctr1 = (char *)malloc(64 * sizeof(char));
    printf("Enter country player %d: ", player_count);
    gets(ctr1);
    while (!is_present(ctr1))
    { // If ctr1 is invalid
        printf("The country %s is not a valid country\n", ctr1);
        printf("Player %d loses\n", player_count);
        lost_players[player_count - 1] = -1;
        player_count += 1;
        players_remaining -= 1;
        if (players_remaining < 1)
        { // If all players give wrong answers on their first turn
            printf("No winner\n");
            return 0;
        }
        printf("Enter country player %d: ", player_count);
        gets(ctr1);
    }
    if (players_remaining == 1)
    {
        goto win;
    }
    player_count += 1;
    reset(&player_count, num_of_players);
    char *ctr2 = malloc(64 * sizeof(char));
    int c;
    do
    {
        c = 0;
        while (lost_players[player_count - 1] == -1)
        {
            player_count += 1;
            c = 1;
            reset(&player_count, num_of_players);
        }
        printf("Enter country player %d: ", player_count);
        gets(ctr2);
        if (!is_present(ctr2))
        { // Checks if ctr2 is valid
            printf("The country %s is not a valid country or used before\n", ctr2);
            printf("Player %d loses\n", player_count);
            lost_players[player_count - 1] = -1;
            players_remaining -= 1;
        }
        else if (ctr1[strlen(ctr1) - 1] == ctr2[0])
        {
            printf("Well Done Player %d\n", player_count);
            char *temp = ctr1; // Swapping the pointers
            ctr1 = ctr2;
            ctr2 = temp;
        }
        else
        {
            printf("Last letter of %s is not equal to the first letter of %s\n", ctr1, ctr2);
            printf("Player %d Loses\n", player_count);
            lost_players[player_count - 1] = -1;
            players_remaining -= 1;
        }
        player_count += 1;
        reset(&player_count, num_of_players);
    } while (players_remaining > 1);
    int winner;
win:
    winner = win(ctr1, ctr2, num_of_players, lost_players);
    if (winner != 0)
    {
        printf("\nPLAYER %d IS THE WINNER!!!!\n", winner);
    }
    else
    {
        printf("No winner\n");
    }
    free(ctr1);
    free(ctr2);
    return 0;
}

int win(char *ctr1, char *ctr2, int num_of_players, int lost_players[])
{ // When only one player is left in the game
    int winner;
    for (int i = 0; i < num_of_players; i++)
    { // Checking for which player is left
        if (lost_players[i] != -1)
        {
            winner = i + 1;
            break;
        }
    }
    printf("\nPlayer %d is the only player left.\nIf Player %d guesses correctly, he will declared the Winner\n\n", winner, winner);
    printf("Enter country %d: ", winner);
    gets(ctr2);
    if (is_present(ctr2) && ctr1[strlen(ctr1) - 1] == ctr2[0])
    { // If he gives a correct country according to the rules
        return winner;
    }
    else
    {
        return 0;
    }
}
