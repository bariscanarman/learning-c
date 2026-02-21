#include <stdio.h>

int  main(){

  char operation;
  double num1, num2, result;

  // The condition '1' means the loop will run infinitely
  while(1){

  // Get the operation type from the user
  printf("Select the process you wanna use (+, -, *, /,%%)\n");
  printf("Or press 'q' to quit the calculator.\n");
  scanf(" %c", &operation);

  // Exit Condition: If the user inputs 'q' or 'Q' we break the loop
  if(operation == 'q' || operation == 'Q'){
    printf("Exiting the calculator.Goodbye!\n");
    break; // This command immediately stops and exits the while loop.
  }

   // This runs if the user enters a character other than +,-,*,/
   if(operation != '+' && operation != '-' && operation != '*' && operation != '/' && operation != '%'){

    printf("Error: Invalid process Selected.Exiting...\n");
    // continue skips the rest of the loop and starts from the beginning of the while loop
    continue;
    
    return 1;

   }

  // Get the numbers from the user
  printf("Enter two numbers (seperated by a space): \n");
  scanf(" %lf %lf", &num1, &num2);

  // Perform the operation based on the input
  switch (operation){

    // +
    case '+':
     result = num1 + num2;
     printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
     break;

    // -
    case '-':
     result = num1 - num2;
     printf("%.2lf - %.2lf =%.2lf\n", num1, num2, result);
     break;

    // *
    case '*':
     result = num1 * num2;
     printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
     break;

    // /
    case '/':
     // Error handling for preventing division by zero
     if(num2 != 0.0){
        result = num1 / num2;
        printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
    }
     else {
        printf("Error: Division by zero is not allowed!\n");
    }
     break;

    // %
    case '%':
     if((int)num2 != 0){
        int mod_result = (int)num1 % (int)num2;
        printf("%d %% %d = %d\n", (int)num1, (int)num2, mod_result);
     }
     else {
        printf("Error: Modulo by zero is not allowed!\n");
     }
     break;
    

    /* Can use default too but seeing your mistake earlier is better.

    This runs if the user enters a character other than +,-,*,/
    default:
    printf("Error: Invalid process selected.\n"); */
  }
} // End of the while loop

    return 0;

}