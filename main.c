#include <stdio.h>
#include <string.h>
#include <stdbool.h>


// Function declarations so C is happy! (I believe it's the compiler that's happy, lol)
void isHighestSale(int *saleAmount, int *highestSale, char greatestEarner[][2], char *salesPerson);
bool compareInput(char *humanInput, char *uppercase, char *lowercase);
void getSaleAmount(int *saleAmount, char *salesPerson);
void getSalesperson(char *humanInput);


int main(void) {
  // Variables for checking stuff and everything else!
  char allowedCharacters[6][2] = {"D", "d", "E", "e", "F", "f"};
  char greatestEarner[1][2];
  int highestSale = 0;
  int grandTotal = 0;
  int i;
 // The arrays for the Salesperson and their sales.
  char salesPerson[3][2] = {"D", "E", "F"};
  int sales[3] = {0, 0, 0};
  // Define variables that are used for inputting data.
  char humanInput[2];
  int saleAmount;

  // Prompt the user (who's hopefully a human) <--- This is priming input!
  getSalesperson(&humanInput);

  while (strcmp(humanInput, "Z") != 0) { 
    // Corresponds to Danielle.
    if (compareInput(&humanInput, &allowedCharacters[0], &allowedCharacters[1])) {
      getSaleAmount(&saleAmount, &humanInput);
      isHighestSale(&saleAmount, &highestSale, &greatestEarner, &salesPerson[0]);
      sales[0] = saleAmount;
      grandTotal += saleAmount;
    }
    // Corresponds to Edward.
    else if (compareInput(&humanInput, &allowedCharacters[2], &allowedCharacters[3])) {
      getSaleAmount(&saleAmount, &humanInput);
      isHighestSale(&saleAmount, &highestSale, &greatestEarner, &salesPerson[1]);
      sales[1] = saleAmount;
      grandTotal += saleAmount;
    }
    // Corresponds to Francis.
    else if (compareInput(&humanInput, &allowedCharacters[4], &allowedCharacters[5])) {
      getSaleAmount(&saleAmount, &humanInput);
      isHighestSale(&saleAmount, &highestSale, &greatestEarner, &salesPerson[2]);
      sales[2] = saleAmount;
      grandTotal += saleAmount;
    }
    // NOBODY BY THAT NAME WORKS HERE; NOW LEAVE ME ALONE.
    // "IS THIS THE KRUSTY KRAB?" -> "NO, THIS IS PATRICK."
    else {
      printf("\nError, invalid salesperson selected, please try again.\n");
    }

    // Are we entering more, or are we breaking free of the loop?
    getSalesperson(&humanInput);
  }
  
  // JOB DONE!
  printf("\n\n<!>----------< PROGRAM END >----------<!>\n\n");
  printf("->>> Grand Total: %d\n", grandTotal);
  printf("->>> Highest Sale: %s", greatestEarner);
}


// Compare the user's input with two letters (we could use || but this is reader friendly!)
bool compareInput(char *humanInput, char *uppercase, char *lowercase) {
  if (strcmp(humanInput, uppercase) == 0) {
    printf("\n YARR, THIS BE THE INPUT: %s, AND THIS BE THE UPPERCASE: %s", humanInput, uppercase);
    return true; 
  }
  else if (strcmp(humanInput, lowercase) == 0) {
    printf("\n YARR, THIS BE THE INPUT: %s, AND THIS BE THE LOWERCASE: %s", humanInput, lowercase);
    return true; 
  }
  else {
    return false;
  }
}

// Prompt the user for the Salesperson and get their input.
void getSalesperson(char *humanInput) {
  printf("\n<@>----------< USING: SALESPERSON INPUT >----------<@>\n\n");
  printf("-->> Input Salesperson's initial, or input 'Z' to quit: ");
  scanf("%s", humanInput);
}

// Prompt the user for the sale amount and get their input.
void getSaleAmount(int *saleAmount, char *salesPerson) {
  printf("\n<$>----------< USING: SALE-AMOUNT INPUT >----------<$>\n\n");
  printf("--> Input the sale amount for Salesperson %s: ", salesPerson);
  scanf("%d", saleAmount);
}

// Checks the old largest sale against any new sales to see if they're larger!
void isHighestSale(int *saleAmount, int *highestSale, char greatestEarner[][2], char *salesPerson) {
  if (*saleAmount > *highestSale) {
    strcpy(greatestEarner[0], salesPerson);
  }
}