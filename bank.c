#include <stdio.h>
#include <stdlib.h>

int main() {
    int pin = 1234, enteredPin, oldPin, newPin, choice, attempts = 0;
    float balance = 50000.0; // Initial balance
    float amount;

    printf("********* Welcome to ATM Simulator *********\n");

    // PIN authentication with 3 attempts
    while (attempts < 3) {
        printf("Enter your 4-digit PIN: ");
        scanf("%d", &enteredPin);

        if (enteredPin == pin) {
            printf("PIN accepted!\n");
            break;  // Exit loop if correct PIN
        } else {
            attempts++;
            printf("Incorrect PIN! Attempts left: %d\n", 3 - attempts);
        }

        if (attempts == 3) {
            printf("Your card has been blocked due to 3 incorrect attempts.\n");
            return 0; // Exit program
        }
    }

    // ATM Menu
    do {
        printf("\n===== ATM Menu =====\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4.Change Pin")
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nYour Current Balance: ₹%.2f\n", balance);
                break;

            case 2:
                printf("\nEnter amount to deposit: ₹");
                scanf("%f", &amount);
                if (amount > 0) {
                    balance += amount;
                    printf("₹%.2f deposited successfully!\n", amount);
                } else {
                    printf("Invalid amount!\n");
                }
                break;

            case 3:
                printf("\nEnter amount to withdraw: ₹");
                scanf("%f", &amount);
                if (amount > balance) {
                    printf("Insufficient Balance!\n");
                } else if (amount <= 0) {
                    printf("Invalid amount!\n");
                } else {
                    balance -= amount;
                    printf("₹%.2f withdrawn successfully!\n", amount);
                }
                break;

            case 4:   
                printf("\nEnter Your Current PIN: ");
                scanf("%d", &oldPin);
                if (oldPin == pin)
                {
                    printf("\nEnter new 4-digit PIN: ");
                    scanf("%d", &newPin);
                    pin = newPin;
                    printf("PIN changed successfully!\n");
                }
                else
                {
                    printf("New PIN cannot be the same as the old PIN!\n");
                }
                break;

            case 5:
                printf("\nThank you for using the ATM. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while(choice != 4);

    return 0;
}

