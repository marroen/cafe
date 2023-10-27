#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void order(char* order);
void take_order();
int confirm_order(char* order);
void process_order();

int main(int argc, char* argv[]) {
  switch (argc) {
    case 1:
      printf("Please enter your order!\n");
      return EXIT_FAILURE;
    case 2:
      order(argv[1]);
      return EXIT_SUCCESS;
    default:
      printf("One order at a time!\n");
      return EXIT_FAILURE;
  }
}

void order(char* order) {
  int flag = 1;
  while (flag) {
    switch (confirm_order(order)) {
      case 1:
        process_order();
        flag = 0;
        break;
      case 0:
        take_order(order);
        break;
      default:
        break;
    } 
  }
}

void take_order(char* order) {
  scanf("%19s", order);
}

int confirm_order(char* order) {
  char input;

  printf("One %s? (y/n)\n", order);

  while (1) {
    scanf(" %c", &input);

    switch (input) {
      case 'y':
        return 1;
      case 'n':
        printf("Enter your order: \n");
        return 0;
      default:
        printf("(y/n)\n");
        break;
    }
  }

}

// could add more ASCII art per case
void process_order() {
  printf("\n\
                          (\n\
                            )     (\n\
                     ___...(-------)-....___\n\
                 .-''       )    (          ''-.\n\
           .-'``'|-._             )         _.-|\n\
          /  .--.|   `''---...........---''`   |\n\
         /  /    |                             |\n\
         |  |    |                             |\n\
          \\  \\   |                             |\n\
             `\\ `|                             |\n\
             _/ /\\                             /\n\
            (__/  \\                           /\n\
         _..---''` \\                         /`''---.._\n\
      .-'           \\                       /          '-.\n\
     :               `-.__             __.-'              :\n\
     :                  ) ''---...---'' (                 :\n\
      '._               `'--...___...--'`              _.'\n\
         \\'--..__                              __..--'''/ \n\
         '._     ''''----.....______.....----'''     _.'\n\
            `''--..,,_____            _____,,..--''`\n\
                          `'''----'''`\n\
  \n");
}

