//Azra-Karin-Yilmaz-
#include <stdio.h>
#include <string.h>

#define M 101

struct Bank{
    char name[M];
    int account_num;
    float balance;
};

void displayMenu();
int getUserInput();
void createAccount(struct Bank[],int*);
void depositMoney(struct Bank[],int);
void withdrawMoney(struct Bank[],int);
void checkBalance(struct Bank[],int);

int main() {
    struct Bank account[M];
    int count=0; //this will count how many account created so we can print real results
    int option; //this users menu choice that will lead them to do whatever function they want
    printf("\nWelcome to the Simple Banking System Designed by METU-NCC Student!");
    do{ //i putted in do-while loop because even the inout is wrong it will display it at least 1
        displayMenu();
        printf("\nEnter your choice:");
        option= getUserInput(); //getting option in the getUserInput() so i equal it to option
        switch(option){
            case 1:
                createAccount(account,&count);
                break;
            case 2:
                depositMoney(account,count);
                break;
            case 3:
                withdrawMoney(account,count);
                break;
            case 4:
                checkBalance(account,count);
                break;
            case 5:
                printf("\n\nThank you for using our Simple Banking System\nGoodbye!");
                break;
            default: //if something entered instead 1,2,3,4,5 it will give this error and re ask user to enter
                printf("Invalid Value, you should enter betweeen 1-5:");
                break;
        }

    }while(option!=5);



    return 0;
}

void displayMenu(){ //printing menu
    printf("\n\n1. Create New Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Check Balance\n");
    printf("5. Quit\n");

}

int getUserInput(){ //getting input for what to do in menu
    int option;
    scanf("%d",&option);
    return option;
}

void createAccount(struct Bank account[],int *count){ //because i said count=0 in main we start from first element in our account[] array
    getchar(); //used this for to refresh the newline in input buffer
    printf("\nEnter your name:");
    fgets(account[*count].name,100,stdin); //i prefered fgets instead gets because it was safer and my clion was saying using gets for this string may occur problem in yellow warning
    account[*count].name[strcspn(account[*count].name,"\n")]=0;//this delete the extra line at the end of the text


    printf("Enter initial deposit:");
    scanf("%f",&account[*count].balance);//getting balance for the account[] elements balance

    account[*count].account_num=1001+*count; //i did 1001+*count because question says account number is starting from 1001 ALSO our array elements start from 0 so,
    //                                         for our first element which is account[0], account number=1001
    //                                         for our second element which is account[1], account number=1002.. and it goes like this


    printf("Account created successfully!\n");
    printf("Account Holder name is %s\n",account[*count].name);
    printf("Account number is %d\n",account[*count].account_num);

    (*count)++; //everytime this function used count will be +1 because we will pass the next element in account[] array
    //also i used pointer in here because they are used when nwe want the change variables and it wouldnt be correct if i didnt used pointers nothing else fit
}


void depositMoney(struct Bank account[],int count){
    int entered_acc; //entering acc number to see if its fits one of our account numbers
    float new_deposit[M];
    printf("\nEnter account number:");
    scanf( "%d",&entered_acc);

    for(int i=0;i<count;i++){//chechking all the created accounts
        if(entered_acc==account[i].account_num){ //if entered account number is founded:
            printf("Enter deposit amount:");
            scanf("%f",&new_deposit[i]);
            account[i].balance=account[i].balance+new_deposit[i];//entered depoist added to the account balance
            printf("Deposit successful!New balance:%.0f",account[i].balance);
        }else{
            printf("No account founded\n");//if account number is NOT founded
        }
    }
}

void withdrawMoney(struct Bank account[],int count){
    int entered_acc;
    float withdraw_amount[M];
    printf("\nEnter account number:");
    scanf("%d",&entered_acc);

    for(int i=0;i<count;i++){//chechking all the created accounts
        if(entered_acc==account[i].account_num){
            printf("Enter withdrawal amount:");
            scanf("%f",&withdraw_amount[i]);
            account[i].balance=account[i].balance-withdraw_amount[i];//entered withdraw amount took away from to the account balance
            printf("Withdrawal sucessful!New balance: %.0f",account[i].balance);
        }else{
            printf("No account founded\n");//if account number is NOT founded
        }
    }
}

void checkBalance(struct Bank account[],int count){
    int entered_acc;
    printf("Enter account number:");
    scanf("%d",&entered_acc);

    for(int i=0;i<count;i++){//chechking all the created accounts
        if(entered_acc==account[i].account_num){
            printf("Current Balance: %.0f",account[i].balance);//if account founded printing it
        }else{
            printf("No account founded\n");//if account number is NOT founded
        }
    }
}