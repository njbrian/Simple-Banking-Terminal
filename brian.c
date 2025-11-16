#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char name[100];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Account limit reached.\n");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = 1000 + accountCount;
    printf("Enter name: ");
    scanf(" %[^\n]", newAccount.name);
    newAccount.balance = 0.0;

    accounts[accountCount++] = newAccount;
    printf("Account created successfully. Account Number: %d\n", newAccount.accountNumber);
}

void deposit() {
    int accNum;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNum);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accNum) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Deposited successfully. New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw() {
    int accNum;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNum);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accNum) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful. New balance: %.2f\n", accounts[i].balance);
            } else {
                printf("Insufficient balance.\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void checkBalance() {
    int accNum;
    printf("Enter account number: ");
    scanf("%d", &accNum);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accNum) {
            printf("Account Holder: %s\n", accounts[i].name);
            printf("Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

int main() {
    int choice;
    do {
        printf("\n--- Simple NJ Banking System Menu ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: checkBalance(); break;
            case 5: printf("Exiting program.\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
