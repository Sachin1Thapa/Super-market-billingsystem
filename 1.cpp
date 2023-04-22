#include<iostream>
#include<fstream>
using namespace std;
class Shop 
{
    int procode;            
    float price;
    float dis;
    string pname;


    public:
        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void recepit();
};

void Shop :: menu()
{
    here :
    int choice;
    string email;
    string password;
       
    cout << "\n\t\t*********************************************"<<endl;
    cout << "\t\t\t                                             "<<endl;
    cout << "\t\t                 Main Menu                   "<<endl;
    cout << "\t\t\t                                             "<<endl;
    cout << "\t\t*********************************************"<<endl;
    cout << "\t\t\t                                             "<<endl;
    cout << "\t\t\t|   1) Administrator                         |"<<endl;
    cout << "\t\t\t|                                            |"<<endl;
    cout << "\t\t\t|   2) Buyer                                 |"<<endl;
    cout << "\t\t\t|                                            |"<<endl;
    cout << "\t\t\t|   3) Exit                                  |"<<endl;
    cout << "\t\t\t                                            "<<endl;
    cout << "\n\t    Please Select : ";
    cin>>choice;

    switch(choice)
    {
        case 1:
            cout<<"\t\t Please login  \n\n";
            cout<<"\t Enter Email : ";
            cin>>email;
            cout<<"\t Enter Password : ";
            cin>>password;

            if( email == "sachin" && password == "sachn")
                administrator();
            else 
                cout<<" Invalid email or password ";
            break;
    

            case 2:
            {
                buyer();
            }
            case 3:
            {
                exit(0);
            }
            default :
            {
                cout<<" Please select from the given optios ";
            }
    }
    goto here;
}


void Shop :: administrator()
{
    up :
    int choice;
    cout<<"\n\n\n\t\t Administrator menu \n";
    cout<<"\n\t\t\t|---------- 1) Add the Product----------|";
    cout<<"\n\t\t\t|                                       |";
    cout<<"\n\t\t\t|---------- 2) Change the Product-------|";
    cout<<"\n\t\t\t|                                       |";
    cout<<"\n\t\t\t|---------- 3) Delete the Product-------|";
    cout<<"\n\t\t\t|                                       |";
    cout<<"\n\t\t\t|---------- 4) Back to main menu--------|";

    cout<<"\n\n\t Please enter your choice  : ";
    cin>>choice;


    switch(choice)
    {
        case 1:
            add();
            break;
        
        case 2:
            edit();
            break;
        
        case 3:
            rem();
            break;
        
        case 4:
            menu();
            break;
        
        default :
            cout << "Invalid Choice" <<endl;

    }
    goto up;
}

void Shop :: buyer()
{
    up  : 
    int choice;
    cout<<"\n\t\t\t\t  Buyer  \n";
    cout<<"\t\t\t    ------------------ "<<endl;
    cout<<"\n\n\t 1) Buy product   ";
    cout<<"\n\t 2) Go Back   "<<endl;
    cout<<"\t\t\t Enter your choice : ";
    cin>>choice;

    switch(choice)
    {
        case 1 :
            recepit();
            break;

        case 2 : 
            menu();

        default : 
            cout << "Invalid Choice" <<endl;

    }
    goto up;


}

void Shop :: add()
{

    m : 
    fstream data;
    int c;
    int token = 0;
    float d;
    float p;
    string n;

    cout<<"\n\n\t\t\t  Add new product "<<endl;
    cout<<"\t Enter the Product code of product : "<<endl;
    cin>>procode;
    cout<<"\t Enter the name of product : "<<endl;
    cin>>pname;
    cout<<"\t Enter the price of product : "<<endl;
    cin>>price;
    cout<<"\t Enter the discount on the  product : "<<endl;
    cin>>dis;

        // ios::in open  the file in reading mode and ios::out open the file in writing node  
        data.open("database.txt",ios::in);      

        if(!data)               // if data is not present fle ma content lekne  
        {
            data.open("database.txt",ios::app|ios::out);
            data<<"  "<<procode<<"  "<<pname<<"  "<<price<<" "<<"  "<<dis<<endl; 
            data.close();     
        
        }
    
        else                   // read from file 
        {
            data>>c>>n>>p>>d;

            while(!data.eof())
            {
                if(c == procode)           // if there is duplicate value
                {
                    token++;
                }

            data>>c>>n>>p>>d;
            }
            data.close();
            


            if( token == 1)         // if there is duplicate value 
                goto m;
            else
            {
                data.open("database.txt",ios::app|ios::out);
                data<<"  "<<procode<<"  "<<pname<<"  "<<price<<" "<<"  "<<dis<<endl; 
                data.close();     
                
            }
        }
            cout<<"\n\n\t\t ~~~~~~ Record inserted  ~~~~~~ ";


}


void Shop :: edit()
{

    fstream data,data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t Modifying  the records ";
    cout<<"\n\n\t  Enter the Product code which need  to be change : ";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n File doesnt exist ";
    }
    else 
    {
        data1.open("database1.txt",ios::app|ios::out);

        data>>procode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey == procode)
            {
                cout<<"\n\t\t Enter the new code of product : ";
                cin>>c;
                cout<<"\n\t\t Name of the product : ";
                cin>>n;
                cout<<"\n\t\t price of the product ";
                cin>>p;
                cout<<"\n\t\t Discount on the product  ";
                cin>>d;
                data1<<"  "<<c<<"  "<<n<<"  "<<p<<" "<<"  "<<d<<endl; 
                cout<<"\n\n\t\t Record edited ";
                token ++;
            }
            else 
            {
                data1<<"  "<<procode<<"  "<<pname<<"  "<<price<<" "<<"  "<<dis<<endl; 
                
            }
            data>>procode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        //rename the data1 to data 
        // remove and rename
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token == 0)
        {
                cout<<"\n\nRecord not found sorry "<<endl;
        }
    }

}

void Shop ::rem ()  
{
     fstream data,data1;
    int pkey;
    int token = 0;
    cout<<"\n\t\t\t Deleting The  Product ";
    cout<<"\n\t Enter the prduct code which need to be removed :  ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n File doesnt exist ";
    }

    else 
    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>procode>>pname>>price>>dis;
        while(!data.eof())
            {
                if(procode == pkey)
                {
                    cout<<"\n\n\t Product deleted succesfully ";
                    token ++;
                }
                else 
                {
                     data1<<"  "<<procode<<"  "<<pname<<"  "<<price<<" "<<"  "<<dis<<endl; 

                }
                data>>procode>>pname>>price>>dis;

            }
            data.close();
            data1.close();
            remove("database.txt");
            rename("database1.txt","database.txt");

            if(token == 0)
            {
                cout<<" \n\n Record not found ";
            }

        
    }

}

void Shop :: list()
{

    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n_________________________________________________________________________\n";
    cout<<"  product Code\t\tName\t\tPrice\n";
    cout<<"_________________________________________________________________________\n";
    data>>procode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<"\t"<<procode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>procode>>pname>>price>>dis;
    }
    data.close();
}


// create an arry multiple data need to be store tei vayerw
void Shop :: recepit()
{
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;


    cout<<"\n\n  \t\t\t\t  RECEPIT ";
    data.open("database.txt" ,ios::in );
    if(!data)
    {
        cout<<"\n\n Empty database";
    }

    else 
    {
        data.close();
        list();
        cout << "\n\n\n*********************************************\n";
        cout << "\n|                                             |";
        cout << "\n|           Please Place The Order            | ";
        cout << "\n|                                             |";
        cout << "\n*********************************************\n";
        do
        {
            m :
            cout<<"\n\n Enter Product code : ";
            cin>>arrc[c];
            cout<<"\n Enter the quantity : ";
            cin>>arrq[c];
            // if the procode match the product key already present in the file 
            for(int i = 0 ; i < c ; i++)
            {
                if(arrc[c] == arrc[i])
                {
                cout<<"\n\n Invalid Product code :: Enter the correct code !";
                goto m;    
                }
            }
        c++;
        cout<<"\n\n Do you want to buy another product ? if yes than press y else n  : ";
        cin>>choice;
        }while(choice == 'y');

        cout<<"\n\n\t\t\t_________________________RECEIPT_________________________\n";
        cout<<"\n Product code \t Product Name \t Product quantity \t Price \t        Amount \t     Amount After Discount \n";

        for(int i = 0; i<c ;i++)
        {
            data.open("database.txt",ios::in);
            data>>procode>>pname>>price>>dis;
            while(!data.eof())
            {
                if(procode == arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount - ((amount*dis)/100);
                    total = total + dis ;
                    cout<<"\n "<<procode<<"\t\t   "<<pname<<"\t   \t"<<arrc[i]<<"\t        \t"<<price<<"\t  \t"<<amount<<"\t   \t"<<dis;
                }
                data>>procode>>pname>>price>>dis;

            }

            data.close();
        }
            cout<<"\n\n_______________________________________________________________________________";
            cout<<"\n Total Amount : "<<total<<endl<<endl;
        }
    }

int main () 
 {
    
    Shop obj;
    obj.menu();
return 0;
}