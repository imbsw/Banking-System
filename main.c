#include <stdio.h>
#include <stdlib.h>

void create_new();
void deposit_money();
void withdraw_money();
void display_acc();
void display_all();
void close();

int decision;

struct
{
    char cus_name[20];
    int accNo;
    char nic[11];
    char accType[2];
    float balance;
} create,tocheck,deposit,withdraw;

int main()
{
    int option;

    printf("\n\n\t\t\t\t               ABC BANKING SYSTEM");
    printf("\n\n\t\t\t ==============WELCOME TO THE MAIN MENU============== ");

    do
    {

        printf("\n \nPress 1 to add a new customer to the bank.");
        printf("\nPress 2 to Deposit Money.");
        printf("\nPress 3 to Withdraw Money.");
        printf("\nPress 4 to display account Details");
        printf("\nPress 5 to Display sorted customer details according to the account type:");
        printf("\nPress 0 to Exit The Program:\n");

        scanf("%d",&option);

        switch(option)
        {

        case 0:
            close();
            break;
        case 1:
            create_new();
            break;
        case 2:
            deposit_money();
            break;
        case 3:
            withdraw_money();
            break;
        case 4:
            display_acc();
            break;
        case 5:
            display_all();
            break;


        }

    }

    while(option !=0);

    return 0;
}

void create_new()
{
    FILE *fpointer;
    fpointer=fopen("customer.txt","a+");
add_account:
    printf("\nEnter Account Number:");
    scanf("%d",&tocheck.accNo);
    while(fscanf(fpointer,"%d %s %s %s %f \n",&create.accNo,create.accType,create.cus_name,create.nic,&create.balance)!=EOF)
    {
        if(tocheck.accNo==create.accNo)
        {
            printf("Account Number is Already in use");
            goto add_account;
        }
    }
    create.accNo=tocheck.accNo;
    printf("\nEnter The Name:");
    scanf("%s",create.cus_name);

    printf("\nEnter The NIC:");
    scanf("%s",create.nic);

    printf("\nEnter The Amount That You Deposite:");
    scanf("%f",&create.balance);

    printf("Type Your Account Type\n for Normal type N\n for 18 + Type E\n For Rankakulu Type R\n For Wanitha Type W\n");
    scanf("%s",create.accType);

    fprintf(fpointer,"%d %s %s %s %f\n",create.accNo,create.accType,create.cus_name,create.nic,create.balance);
    fclose(fpointer);
    printf("\nSuccesful!");

    printf("\n\n\n\tPress 1 to add a another account or press 0 to go to the main menu:");
    scanf("%d",&decision);
    if(decision==0)
        main();
    else if(decision==1)
        create_new();
    else
        main();

}
void deposit_money()
{
    int run=0;

    FILE *oldData,*newData;
    oldData=fopen("customer.txt","r");
    newData=fopen("newCus.txt","w");

    printf("Enter The Account Number of The Customer:");
    scanf("%d",&deposit.accNo);

    while(fscanf(oldData,"%d %s %s %s %f \n",&create.accNo,create.accType,create.cus_name,create.nic,&create.balance)!=EOF)
    {
        if(deposit.accNo==create.accNo)
        {
            run=1;
            printf("Enter The Amount That You want To Deposit:");
            scanf("%f",&deposit.balance);
            create.balance+=deposit.balance;
            fprintf(newData,"%d %s %s %s %f\n",create.accNo,create.accType,create.cus_name,create.nic,create.balance);
            printf("Deposited Succesfully!");

        }

    }
    fclose(oldData);
    fclose(newData);
    remove("customer.txt");
    rename("newCus.txt","customer.txt");

            if(run!=1)
        {
            printf("Account does not Exists\nto retry press 1\npress 0 to go to the main menu:\n");
            scanf("%d",&decision);
            if(decision==0)
                main();
            else if(decision==1)
                deposit_money();
            else
                main();

        }

}
void withdraw_money()
{
    int run=0;

    FILE *oldData1,*newData1;
    oldData1=fopen("customer.txt","r");
    newData1=fopen("newCus.txt","w");

    printf("Enter The Account Number of The Customer:");
    scanf("%d",&withdraw.accNo);

    while(fscanf(oldData1,"%d %s %s %s %f \n",&create.accNo,create.accType,create.cus_name,create.nic,&create.balance)!=EOF)
    {
        if(create.accNo==withdraw.accNo)
        {
            run=1;
            printf("Enter the amount that you want to withdraw:");
            scanf("%f",&withdraw.balance);

            if(strcmpi(create.accType,"N")==0)
            {
                printf("\n\tMinimum Balance Should be Rs 500.00");
                create.balance-=withdraw.balance;

                if(create.balance < 500)
                {
                    printf("\n\t Account Balance Is Not Sufficient:");
                    create.balance+=withdraw.balance;
                    fprintf(newData1,"%d %s %s %s %f\n",create.accNo,create.accType,create.cus_name,create.nic,create.balance);

                    main();

                }
                else
                {
                    fprintf(newData1,"%d %s %s %s %f\n",create.accNo,create.accType,create.cus_name,create.nic,create.balance);
                    printf("\n\tWithdrawn succesfully");
                    printf("\n\tYour Current Balance is Rs%f",create.balance);
                }
                if(strcmpi(create.accType,"E")==0)
                {
                    printf("\n\tMinimum Balance Should be Rs 1000.00");
                    create.balance-=withdraw.balance;

                    if(create.balance < 1000)
                    {
                        printf("\n\t Account Balance Is Not Sufficient:");
                        create.balance+=withdraw.balance;
                        fprintf(newData1,"%d %s %s %s %f\n",create.accNo,create.accType,create.cus_name,create.nic,create.balance);

                        main();

                    }
                    else
                    {
                        fprintf(newData1,"%d %s %s %s %f\n",create.accNo,create.accType,create.cus_name,create.nic,create.balance);
                        printf("\n\tWithdrawn succesfully");
                        printf("\n\tYour Current Balance is Rs%f",create.balance);
                    }
                }
                if(strcmpi(create.accType,"R")==0)
                {

                    printf("\n\tMinimum Balance Should be Rs 1500.00");
                    create.balance-=withdraw.balance;

                    if(create.balance < 1500)
                    {
                        printf("\n\t Account Balance Is Not Sufficient:");
                        create.balance+=withdraw.balance;
                        fprintf(newData1,"%d %s %s %s %f\n",create.accNo,create.accType,create.cus_name,create.nic,create.balance);

                        main();

                    }
                    else
                    {
                        fprintf(newData1,"%d %s %s %s %f\n",create.accNo,create.accType,create.cus_name,create.nic,create.balance);
                        printf("\n\tWithdrawn succesfully");
                        printf("\n\tYour Current Balance is Rs%f",create.balance);
                    }

                }
                if(strcmpi(create.accType,"W")==0)
                {

                    printf("\n\tMinimum Balance Should be Rs 1000.00");
                    create.balance-=withdraw.balance;

                    if(create.balance < 1000)
                    {
                        printf("\n\t Account Balance Is Not Sufficient:");
                        create.balance+=withdraw.balance;
                        fprintf(newData1,"%d %s %s %s %f\n",create.accNo,create.accType,create.cus_name,create.nic,create.balance);

                        main();

                    }
                    else
                    {
                        fprintf(newData1,"%d %s %s %s %f\n",create.accNo,create.accType,create.cus_name,create.nic,create.balance);
                        printf("\n\tWithdrawn succesfully");
                        printf("\n\tYour Current Balance is Rs%f",create.balance);
                    }

                }
            }

        }
    }
    fclose(oldData1);
    fclose(newData1);
    remove("customer.txt");
    rename("newCus.txt","customer.txt");

            if(run!=1)
        {
            printf("Account does not Exists\nto retry press 1\npress 0 to go to the main menu:\n");
            scanf("%d",&decision);
            if(decision==0)
                main();
            else if(decision==1)
                deposit_money();
            else
                main();

        }
}
void display_acc()
{  int run=0;

    printf("Enter The Account Number That You want to check:");
    scanf("%d",&tocheck.accNo);

    FILE *view;
    view=fopen("customer.txt","r");

    while(fscanf(view,"%d %s %s %s %f \n",&create.accNo,create.accType,create.cus_name,create.nic,&create.balance)!=EOF)
    {
        if(tocheck.accNo==create.accNo)
            {
                printf("\n%d \t\n%s \t\n%s \t\n%s \t\n%.2f",create.accNo,create.accType,create.cus_name,create.nic,create.balance);
                run=1;
            }
    }

    if(run!=1)
        {
            printf("Account You Entered does not exists");
            printf("\n\n\n\tPress 1 to check a another account or press 0 to go to the main menu:");
            scanf("%d",&decision);
            if(decision==0)
                main();
            else if(decision==1)
                display_acc();
            else
                main();
        }


}
void display_all()
{
    int run=0;

    FILE *view1;

    view1=fopen("customer.txt","r");

    printf("Enter the account Type that tou want to display:");
    scanf("%s",tocheck.accType);
    while(fscanf(view1,"%d %s %s %s %f \n",&create.accNo,create.accType,create.cus_name,create.nic,&create.balance)!=EOF)
    {
        if(strcmpi(create.accType,tocheck.accType)==0)
            {
                printf("\n%d \t\n%s \t\n%s \t\n%s \t\n%.2f\n\n",create.accNo,create.accType,create.cus_name,create.nic,create.balance);
                run=1;
            }
    }

    if(run!=1)
        {
            printf("Entered Account Type Does Not exists");
            printf("\n\n\n\tPress 1 to view all the accounts according account type or press 0 to go to the main menu:");
            scanf("%d",&decision);
            if(decision==0)
                main();
            else if(decision==1)
                display_all();
            else
                main();
        }
}
void close()
{
    system("cls");
    printf("Thank You");

}
