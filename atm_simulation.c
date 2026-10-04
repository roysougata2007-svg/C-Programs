#include <stdio.h>

// Function Declarations
void Menu();
void CheckBalance(float balance);
float deposit(float balance);
float withdraw(float balance);
int changedpin(int pin);

int main() {
    int pin = 1234;
    int enteredpin;
    int newpin;
    int choice;
    int attempts = 0;
    float balance = 10000.0;
    float amount;

    printf("===== ATM Machine =====\n");

    // PIN Authentication (Max 3 attempts)
    while (attempts < 3) {
        printf("Enter your PIN: ");
        scanf("%d", &enteredpin);

        if (enteredpin == pin) {
            printf("Login Successfully\n");
            break;
        }

        attempts++;
        printf("Incorrect PIN\n");
        printf("Attempts remaining: %d\n", 3 - attempts);

        if (attempts == 3) {
            printf("Too many incorrect attempts.\n");
            printf("Account temporarily blocked.\n");
            return 0; // Terminate if account gets blocked
        }
    }

    // Main Transaction Menu Loop
    do {
        Menu();
        printf("Enter your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                CheckBalance(balance);
                break;

            case 2:
                balance = deposit(balance);
                break;

            case 3:
                balance = withdraw(balance);
                break;

            case 4:
                newpin = changedpin(pin);
                if (newpin != pin) {
                    pin = newpin;
                }
                break;

            case 5:
                printf("Thank You for using the ATM.\n");
                printf("Have a nice day\n");
                break;

            default:
                printf("Invalid Choice! Please try again\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

// Display Menu Options
void Menu() {
    printf("----- Menu -----\n");
    printf("1. Check Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Change PIN\n");
    printf("5. Exit\n");
}

// Balance Inquiry
void CheckBalance(float balance) {
    printf("Current Balance: %.2f\n", balance);
}

// Deposit Amount
float deposit(float balance) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount\n");
    } else {
        balance += amount;
        printf("%.2f deposited successfully.\n", amount);
        printf("New Balance: %.2f\n", balance);
    }
    return balance;
}

// Withdraw Amount
float withdraw(float balance) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount\n");
    } else if (amount > balance) {
        printf("Insufficient balance\n");
    } else {
        balance -= amount;
        printf("Please collect your Cash.\n");
        printf("%.2f withdraw successfully\n", amount);
        printf("Remaining Balance: %.2f\n", balance);
    }
    return balance;
}

// Change ATM PIN
int changedpin(int pin) {
    int currentpin;
    int newpin;

    printf("Enter your current PIN: ");
    scanf("%d", &currentpin);

    if (currentpin != pin) {
        printf("Incorrect PIN\n");
        return pin;
    }

    printf("Enter your new 4-digit PIN: ");
    scanf("%d", &newpin);

    if (newpin >= 1000 && newpin <= 9999) {
        printf("PIN changed successfully\n");
        return newpin;
    } else {
        printf("PIN must contain exactly 4 digits.\n");
        return pin;
    }
}