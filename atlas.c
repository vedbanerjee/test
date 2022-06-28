#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 195
// Global variable 'countries' containing list of all the countries
char *countries[MAX] = {"afghanistan", "albania", "algeria", "andorra", "angola", "antigua and deps", "argentina", "armenia", "australia", "austria", "azerbaijan", "bahamas", "bahrain", "bangladesh", "barbados", "belarus", "belgium", "belize", "benin", "bhutan", "bolivia", "bosnia herzegovina", "botswana", "brazil", "brunei", "bulgaria", "burkina", "burundi", "cambodia", "cameroon", "canada", "cape verde", "central african republic", "chad", "chile", "china", "colombia", "comoros", "congo", "costa rica", "croatia", "cuba", "cyprus", "czech republic", "denmark", "djibouti", "dominica", "dominican republic", "east timor", "ecuador", "egypt", "el salvador", "equatorial guinea", "eritrea", "estonia", "ethiopia", "fiji", "finland", "france", "gabon", "gambia", "georgia", "germany", "ghana", "greece", "grenada", "guatemala", "guinea", "guinea-bissau", "guyana", "haiti", "honduras", "hungary", "iceland", "india", "indonesia", "iran", "iraq", "ireland", "israel", "italy", "ivory coast", "jamaica", "japan", "jordan", "kazakhstan", "kenya", "kiribati", "north korea", "south korea", "kosovo", "kuwait", "kyrgyzstan", "laos", "latvia", "lebanon", "lesotho", "liberia", "libya", "liechtenstein", "lithuania", "luxembourg", "macedonia", "madagascar", "malawi", "malaysia", "maldives", "mali", "malta", "marshall islands", "mauritania", "mauritius", "mexico", "micronesia", "moldova", "monaco", "mongolia", "montenegro", "morocco", "mozambique", "myanmar", "namibia", "nauru", "nepal", "netherlands", "new zealand", "nicaragua", "niger", "nigeria", "norway", "oman", "pakistan", "palau", "panama", "papua new guinea", "paraguay", "peru", "philippines", "poland", "portugal", "qatar", "romania", "russia", "rwanda", "saint kitts and nevis", "saint lucia", "saint vincent and the grenadines", "samoa", "san marino", "sao tome and principe", "saudi arabia", "senegal", "serbia", "seychelles", "sierra leone", "singapore", "slovakia", "slovenia", "solomon islands", "somalia", "south africa", "south sudan", "spain", "sri lanka", "sudan", "suriname", "swaziland", "sweden", "switzerland", "syria", "taiwan", "tajikistan", "tanzania", "thailand", "togo", "tonga", "trinidad and tobago", "tunisia", "turkey", "turkmenistan", "tuvalu", "uganda", "ukraine", "united arab emirates", "united kingdom", "united states of america", "uruguay", "uzbekistan", "vanuatu", "vatican city", "venezuela", "vietnam", "yemen", "zambia", "zimbabwe"};
    
int is_present(char *country){ // Checks if the country is in the list of all countries
    for(int i =0;i<MAX;i++){
        if(strcmp(country,countries[i])==0){
            countries[i]="\0";
            return 1;
        }
    }
    return 0;
}

int main(void)
{
    int player_count=1;
    int num_of_players=0;
    while(num_of_players<=1){
        printf("Enter number of players: ");
        scanf("%d", &num_of_players);
    }
    char waste; // Stores the '\n' after scanning num_of_players
    scanf("%c",&waste);
    char *ctr1=(char *)malloc(64*sizeof(char));
    printf("Enter country player %d: ",player_count);
    gets(ctr1);
    int c=0;
    if(!is_present(ctr1)){// Checks if ctr1 is valid
        printf("The country %s is not a valid country\n",ctr1);
        printf("Player %d loses\n",player_count); 
        free(ctr1); // Returns 0 and ends the program if the country given is not valid
        return 0;
    }
    player_count+=1;
    do{
        char *ctr2=malloc(64*sizeof(char));
        printf("Enter country player %d: ",player_count);
        gets(ctr2);
        if(!is_present(ctr2)){// Checks if ctr2 is valid
            printf("The country %s is not a valid country or used before\n",ctr2);
            printf("Player %d loses\n",player_count);
            free(ctr1);
            free(ctr2); // Returns 0 and ends the program if the country is not valid
            return 0;
        }
        if(ctr1[strlen(ctr1)-1]==ctr2[0]){ // player_count goes back to one after each player's turn
            printf("Well Done Player %d\n",player_count);
            player_count+=1;
            if(player_count==(num_of_players)+1){
                player_count=1;
            }
            char *temp=ctr1; //Swapping the pointers
            ctr1=ctr2;
            ctr2=temp;
            ctr1=realloc(ctr1,(strlen(ctr1)+1)*sizeof(char));
            ctr2=realloc(ctr2,(strlen(ctr2)+1)*sizeof(char));
            c=1;
        }
        else{
            printf("Last letter of %s is not equal to the first letter of %s\n",ctr1,ctr2);
            printf("Player %d Loses",player_count);
            c=0;
            free(ctr1);
            free(ctr2);
        }
    }while(c>0);
    return 0;
}