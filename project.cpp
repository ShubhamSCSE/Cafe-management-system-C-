#include<iostream>
#include <windows.h>
using namespace std;
string name;
int ch,qty;
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
int size;
int siz;
string u_name,pass;
void changeColor(int desiredColor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}


class CCD{
    public:
    void login(){
        changeColor(2);
        drawLine();
        cout<<"\t!! Hello User please Authenticate yourself !!\n";
        drawLine();
        
        cout<<"Entre Your Username : ";
        cin>>u_name;
        cout<<"Entre Your Password : ";
        cin>>pass;
    }
    void auth(){
        changeColor(3);
        login();
        if(u_name=="admin" && pass=="admin"){
            admin();
        }else{
            cout<<"wrong password !!\n";
            auth();
        }
    }
    void upmenu(){
        for(int i=0;i<siz;i++){
        cout<<i+6<<". "<<item[i]<<"\t\t\t"<<ad_price[i]<<endl;
        }
    
    }
    void index(){
            system("cls");
            changeColor(5);
            drawLine();
            cout<<"\t\t!! Welcome to CCD !!\n";
            drawLine();
            cout<<"1. Admin Login \n";
            cout<<"2. User Login\n";
            drawLine();
            cout<<"Entre your choice : ";
            cin>>choice;
            if(choice==1){
                system("cls");
                auth();
                
            }else{
                system("cls");
                e_name();
                howmany();
                menu();
                order();
                
            }
        }
    void admin(){
            system("cls");
            changeColor(2);
            drawLine();
            cout<<"\t\t\t!! Hello Admin !!\n";
            drawLine();
            cout<<"1. Add Items\n";
            cout<<"2. View Order\n";
            cout<<"3. Back to Main menu\n";
            drawLine();
            cout<<"Enter your choice : ";
            cin>>admin_choice;
            if(admin_choice==3){
                index();
            }else if(admin_choice==2){
                system("cls");
                showbill();
            }else{

                additem();
            }

        }

    void additem(){
        cout<<"How many Items do you want to add : ";
        cin>>siz;
        for(int i=0;i<siz;i++){
            cout<<"Enter "<<i+1<<" item name : ";
            cin>>item[i];
            cout<<"Enter "<<i+1<<" item prize : ";
            cin>>ad_price[i];
        }
        
        admin();
        drawLine();
        cout<<"!! Item Added Sucesfully !!\n";
        drawLine();
    }
    
    
    void drawLine()//draw line
    {
        for(int i=1;i<70;i++)
            cout<<"=";
        cout<<endl;
    }
    void showbill(){ //=======SHOW BILL=======
        system("cls"); 
        changeColor(2); 

        char men;
        drawLine();
        cout<<"!! Bill !! \t Thanks "<<name<<" for Visiting Our Shop\n";
        drawLine();
        cout<<"NO:\t\tOrder ID\tItem name\tQuantity\tRate\n";
        drawLine();
        for(int i=0 ;i<size;i++){
            cout<<i+1<<"\t\t"<<item_id[i] <<"\t\t"<<item_name[i]<<"\t\t" <<quantity[i] <<"\t\t"<<rate[i]<<endl;
            total_price+=rate[i];
        }
        tax=(0.18*total_price);
        tax_price=total_price+tax;
        drawLine();
        cout<<"Gross Amount \t\t"<<total_price<<endl;
        cout<<"GST @18%\t\t"<<tax<<endl;
        cout<<"Total Amount\t\t"<<tax_price<<endl;
        drawLine();
        cout<<"Do you want to back to main menu (Y/N): ";
        cin>>men;
        if(men=='y'||men=='Y'){
            index();
        }else{
            system("cls");
            drawLine();
            cout<<"\t\t!! Thanks for visiting us !!\n";
            drawLine();
        }

    }


    void e_name(){

        drawLine();
        cout<<"\t\tWelcome To CCD Online Order"<<endl;
        drawLine();
        cout<<"To place order please enter you Name : ";
        cin>>name;
    }
    void howmany(){
        system("cls");
        changeColor(3);
        drawLine();
        cout<<"\t\tWelcome "<<name<<" To Our Shop\n";
        drawLine();
        cout<<"Items Available\t\tRate\n";
        drawLine();
        cout<<"0. Exit\n";
        cout<<"1. Coffee\t\t50.00\n";
        cout<<"2. Tea\t\t\t30.00\n";
        cout<<"3. Soda\t\t\t20.00\n";
        cout<<"4. Juice\t\t100.00\n";
        cout<<"5. Special Combo\t150.00\n";
        upmenu();
        cout<<"How many Items would you like to order : ";
        cin>>size;
    }



    void menu()//menue
    {
    system("cls");
    drawLine();
    cout<<"\t\tWelcome "<<name<<" To Our Shop\n";
    drawLine();
    cout<<"Items Available\t\tRate\n";
    drawLine();
    cout<<"1. Coffee\t\t50.00\n";
    cout<<"2. Tea\t\t\t30.00\n";
    cout<<"3. Soda\t\t\t20.00\n";
    cout<<"4. Juice\t\t100.00\n";
    cout<<"5. Special Combo\t150.00\n";
    upmenu();
    
    }



    void order(){
        changeColor(2);
        for(int i=0;i<size;i++){
            cout<<"Enter your "<<i+1<<" choice: ";
            cin>>ch;
            if(ch==1){
                cout<<"How Many Coffee do you want : ";
                cin>>qty;
                item_id[i]=1;
                quantity[i]=qty;
                rate[i]=qty*50;
                item_name[i]="Coffee";
                
                
            }
            else if(ch==2){
                cout<<"How Many Tea do you want : ";
                cin>>qty;
                
                item_id[i]=2;
                quantity[i]=qty;
                rate[i]=qty*30;
                item_name[i]="Tea";
                
                
            }
            else if(ch==3){
                cout<<"How Many Soda do you want : ";
                cin>>qty;
                item_id[i]=3;
                quantity[i]=qty;
                rate[i]=qty*20;
                item_name[i]="Soda";
                
            }
            else if(ch==4){
                cout<<"How Many juice do you want : ";
                cin>>qty;
                item_id[i]=4;
                quantity[i]=qty;
                rate[i]=qty*100;
                item_name[i]="Juice";
                
                
            }
            else if(ch==5){
                cout<<"How Many combo do you want : ";
                cin>>qty;
                item_id[i]=5;
                quantity[i]=qty;
                rate[i]=qty*150;
                item_name[i]="combo";
                
                
            }
            else if(ch==(i+6)){
                cout<<"How Many "<<item[i]<<" do you want : ";
                cin>>qty;
                item_id[i]=(i+6);
                quantity[i]=qty;
                rate[i]=qty*ad_price[i];
                item_name[i]=item[i];
                
                
            }
            
            else{
                cout<<"Wrong input";
            }
            
        }
        showbill();
        
    }

};


int main(){
    
    CCD ob;
    ob.index();
    system("pause");
    return 0;
    
}

