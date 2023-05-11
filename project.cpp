#include <iostream>
#include <windows.h>

using namespace std;

//*************************declaring all variables*******************

string name;
int ch, qty;
int item_id[10];
int quantity[10];
int rate[10];
string item_name[10];
int total_price;
float tax_price;
float tax;
int choice;
int admin_choice;
string item[5];
int ad_price[5];
int sizes;
int siz;
string u_name, pass;

// color function
void changeColor(int desiredColor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}

//*********************************Main class**********************
class CCD
{
public:
    void drawLine() // draw vertical line function
    {
        for (int i = 1; i < 70; i++)
            cout << "=";
        cout << endl;
    }

    // *************************Welcome and Animation function*********************
    void animation()
    {

        system("COLOR 0e");
        system("cls");
        drawLine();
        drawLine();
        cout << "\t!!! --Welcome to CCD-- !!! " << endl;
        drawLine();
        drawLine();

        cout << ("\e[?25l");

        SetConsoleCP(437);
        SetConsoleOutputCP(437);
        int bar1 = 177, bar2 = 219;

        cout<< "\n\n\tLoading...";
        cout << "\n\n\t";

        for (int i = 0; i < 25; i++)
        {
            cout << (char)bar1;
        }

        cout << "\r";
        cout << "\t";

        for (int i = 0; i < 25; i++)
        {
            cout <<(char)bar2;
            Sleep(130);
        }
    }

    //********************login function**************************
    void login()
    {
        drawLine();
        cout << "\t!! Welcome ADMIN please Authenticate yourself !!\n";
        drawLine();

        cout << "Enter Your |USERNAME| : ";
        cin >> u_name;
        cout << "Enter Your |PASSWORD| : ";
        cin >> pass;
    }

    //******************authentication function***********************
    void auth()
    {
        changeColor(3);
        login();
        if (u_name == "admin" && pass == "admin")
        {
            admin();
        }
        else
        {
            cout << "!! -----Wrong Password or Username------ !!\n";
            auth();
        }
    }

    void upmenu()
    {
        for (int i = 0; i < siz; i++)
        {
            cout << i + 6 << ". " << item[i] << "\t\t" << ad_price[i] << endl;
        }
    }

    //******************Starting page function****************************
    void index()
    {
        system("cls");
        drawLine();
        cout << "\t\t!! Welcome to CCD !!\n";
        drawLine();
        cout << "1. Admin Login \n";
        cout << "2. Let's go to Shop->\n";
        drawLine();
        cout << "Enter your choice (no.) : ";
        cin >> choice;

        if (choice == 1)
        {
            system("cls");
            auth();
        }
        else
        {
            system("cls");
            e_name();
            howmany();
            menu();
            order();
        }
    }

    //*******************admin function***********************
    void admin()
    {
        system("cls");
        drawLine();
        cout << "\t\t\t!! WELCOME Admin !!\n";
        drawLine();
        cout << "1. Add Items\n";
        cout << "2. View Order\n";
        cout << "3. Back to Main Menu\n";
        drawLine();
        cout << "Enter your choice (no.) : ";
        cin >> admin_choice;

        if (admin_choice == 3)
        {
            index();
        }
        else if (admin_choice == 2)
        {
            system("cls");
            showbill();
        }
        else
        {

            additem();
        }
    }

    //****************add item function*************************
    void additem()
    {

        cout << "How many Items do you want to Add : ";
        cin >> siz;

        for (int i = 0; i < siz; i++)
        {
            cout << "Enter " << i + 1 << " Item Name : ";
            cin >> item[i];
            cout << "Enter " << i + 1 << " Item Prize : ";
            cin >> ad_price[i];
        }
         cout << "!! Items were Added |Sucessfully| !!\n";
        admin(); 
        drawLine();
        drawLine();
    }

    //***************SHOW BILL Function*********************

    void showbill()
    {
        system("cls");
        changeColor(2);

        char men;
        drawLine();
        cout << "     || Bill ||    |  Thanks '" << name << "' for Visiting Our Shop |\n";
        drawLine();
        cout << "NO:\t\tOrder ID\tItem name\tQuantity\tRate\n";
        drawLine();

        for (int i = 0; i < sizes; i++)
        {
            cout << i + 1 << "\t\t" << item_id[i] << "\t\t" << item_name[i] << "\t\t" << quantity[i] << "\t\t" << rate[i] << endl;
            total_price += rate[i];
        }

        tax = (0.18 * total_price);
        tax_price = total_price + tax;

        drawLine();
        cout << "Gross Amount :\t\t" << total_price << endl;
        cout << "GST @18% :\t\t" << tax << endl;
        cout << "Total Amount :\t\t" <<"Rs. " <<tax_price << endl;
        drawLine();
        cout << "Do you want to back to Main Menu for New Order (Y/N): ";
        cin >> men;

        if (men == 'y' || men == 'Y')
        {
            index();
        }
        else
        {
            system("cls");
            drawLine();
            cout << "\t\t!! |Thanks for Visiting Us| !!\n";
            drawLine();
        }
    }

    //*********************input (name of costumer) function**********************
    void e_name()
    {
        drawLine();
        cout << "\t\t| Welcome To CCD Online Order |" << endl;
        drawLine();
        cout << "To Place order please Enter your Name : ";
        cin >> name;
    }

    //**************Food Menu for choosing no of items***********************
    void howmany()
    {
        system("cls");
        changeColor(3);
        drawLine();
        cout << "\t\t| Welcome ' " << name << " ' To Our Shop | \n";
        drawLine();
        cout << "Items Available\t\tRate\n";
        drawLine();
        cout << "0. Exit\n";
        cout << "1. Coffee\t\t50.00\n";
        cout << "2. Tea\t\t\t30.00\n";
        cout << "3. Soda\t\t\t20.00\n";
        cout << "4. Juice\t\t100.00\n";
        cout << "5. Special Combo\t150.00\n";
        upmenu();
        cout << "How many Items would you like to Order : ";
        cin >> sizes;
    }

    //******************************main food menu*****************
    void menu()
    {
        system("cls");
        drawLine();
        cout << "\t\t| Welcome '" << name << "' To Our Shop |\n";
        drawLine();
        cout << "Items Available\t\tRate\n";
        drawLine();
        cout << "1. Coffee\t\t50.00\n";
        cout << "2. Tea\t\t\t30.00\n";
        cout << "3. Soda\t\t\t20.00\n";
        cout << "4. Juice\t\t100.00\n";
        cout << "5. Special Combo\t150.00\n";
        upmenu();
    }

    //*****************order function*************************
    void order()
    {
        changeColor(2);
        for (int i = 0; i < sizes; i++)
        {
            cout << "Enter your " << i + 1 << " Choice (no.): ";
            cin >> ch;

            if (ch == 1)
            {
                cout << "How Many Coffee's do you want : ";
                cin >> qty;
                item_id[i] = 1;
                quantity[i] = qty;
                rate[i] = qty * 50;
                item_name[i] = "Coffee";
            }
            else if (ch == 2)
            {
                cout << "How Many Tea's do you want : ";
                cin >> qty;

                item_id[i] = 2;
                quantity[i] = qty;
                rate[i] = qty * 30;
                item_name[i] = "Tea";
            }
            else if (ch == 3)
            {
                cout << "How Many Soda's do you want : ";
                cin >> qty;
                item_id[i] = 3;
                quantity[i] = qty;
                rate[i] = qty * 20;
                item_name[i] = "Soda";
            }
            else if (ch == 4)
            {
                cout << "How Many Juice's do you want : ";
                cin >> qty;
                item_id[i] = 4;
                quantity[i] = qty;
                rate[i] = qty * 100;
                item_name[i] = "Juice";
            }
            else if (ch == 5)
            {
                cout << "How Many combo's do you want : ";
                cin >> qty;
                item_id[i] = 5;
                quantity[i] = qty;
                rate[i] = qty * 150;
                item_name[i] = "combo";
            }
            else if (ch == (i + 6))
            {
                cout << "| How Many " << item[i] << " do you want | : ";
                cin >> qty;
                item_id[i] = (i + 6);
                quantity[i] = qty;
                rate[i] = qty * ad_price[i];
                item_name[i] = item[i];
            }

            else
            {
                cout << "Wrong Input, try again!!";
            }
        }
        showbill();
    }

    //*****************start function***************
    void start()
    {
        animation();
        index();
    }
};

//****************main function******************************
int main()
{

    CCD ob; //********object instance of class CCD
    ob.start();
    system("pause"); //****does not let terminal close
    return 0;
}
