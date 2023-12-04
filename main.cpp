#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include <windows.h>
#include <sstream>
#include <fstream>
#include <string.h>

using namespace std;

const char* HOST = "localhost";
const char* USER = "root";
const char* PW = "nayeem007$";
const char* DB = "list";
MYSQL*conn;


class product
{

   public:
        string user,pass,u,ans,P_name,name,price,P_date,quantity,price_dollar,div_name,l_price,enter;



       void StartMenu();
       void AdminLogin();
       void UserLogin();
       void registration();
       void forgot();
       void ProductAdd();
       void ProductSearch();
       void ProductList();
       void UpdateList();
       void ProductDelete();
       void AdminPannel();
       void UserPannel();

       string convert(string price);

};
void product:: StartMenu()
{

        menustart:
            system("cls");

        int choice;
        cout<<"\t\t\t ________________________________________________________________________\n";
        cout<<"\t\t\t|               Welcome to Daily Product Price List                      |\n";
        cout<<"\t\t\t|________________________________________________________________________|\n";
        cout<<"\t\t\t|1.Admin Login                                                           |"<<endl;
        cout<<"\t\t\t|                                                                        |"<<endl;
        cout<<"\t\t\t|2.User Login                                                            |"<<endl;
        cout<<"\t\t\t|                                                                        |"<<endl;
        cout<<"\t\t\t|3.REGISTER                                                              |"<<endl;
        cout<<"\t\t\t|                                                                        |"<<endl;
        cout<<"\t\t\t|4.FORGOT PASSWORD                                                       |"<<endl;
        cout<<"\t\t\t|                                                                        |"<<endl;
        cout<<"\t\t\t|5.Exit                                                                  |"<<endl;
        cout<<"\t\t\t|                                                                        |"<<endl;
        cout<<"\t\t\t|________________________________________________________________________|"<<endl;
        cout<<"\t\t\tEnter your choice[1/2/3/4/5] :"; cin>>choice;


        cout<<endl;
        switch(choice)
        {
                case 1:
                       AdminLogin();
                        break;
                case 2:
                       UserLogin();
                        break;
                case 3:
                       registration();
                        break;
                case 4:
                       forgot();
                        break;
                case 5:

                        cout<<"\n\t\t\t\t\tThanks for using this program.\n\t\t\t\t\tThis program is created by Team Antivirus.\n\n";

                        break;
                default:
                        system("cls");
                        cout<<"\t\t\t\t\tYou've made a mistake , Try again..\n"<<endl;
                        cin.get();
                        cin.get();
                        goto menustart;
        }

}

void product::AdminLogin()
{
        int count;
        string user,pass,u,p;
        system("cls");
        cout<<"\t\t\t\t----------------------------------------------"<<endl;
        cout<<"\t\t\t\t|                 LOGIN                      |"<<endl;
        cout<<"\t\t\t\t----------------------------------------------"<<endl;
        cout<<"\t\t\t\t please enter the following details"<<endl;
        cout<<"\n\t\t\t\t\tUSERNAME :";
        cin>>user;
        cout<<"\n\t\t\t\t\tPASSWORD :";
        cin>>pass;

        string Sin= "SELECT username,password FROM registration WHERE username ='"+user+"' AND password= '"+pass+"' ";

        if(mysql_query(conn,Sin.c_str()))
        {
         cout<<"Error: "<<mysql_error(conn)<<endl;
        }
        else
        {
            MYSQL_RES* res;
            res= mysql_store_result(conn);
            if(res)
            {
            int row = mysql_num_rows(res);
            if(row==1)
            {
                cout<<"\n\t\t\tWelcome..."<<endl;
                //Sleep(3000);
                AdminPannel();

            }
            else if(row==0)
            {
                cout<<"Incorrect ID Or Password. Try Again!"<<endl;
                Sleep(3000);
                StartMenu();

            }
        }
    }
}

void product::registration()
{


        system("cls");
        cout<<"\n\t\t\t----------------------------------------------------";
        cout<<"\n\t\t\t|                  REGISTER                        |";
        cout<<"\n\t\t\t----------------------------------------------------";
        cout<<"\n\n\t\t\t\tEnter the username :";
        cin>>user;
        cout<<"\n\n\t\t\t\tEnter the password :";
        cin>>pass;

       string Sup = "INSERT INTO registration  VALUES ('"+user+"', '"+pass+"')";

        if(mysql_query(conn,Sup.c_str())){
         cout<<"Error: "<<mysql_error(conn)<<endl;
        }
        else{
         cout<<"\t\t\t\tRegistration Successfuly Done"<<endl;
        }
        Sleep(3000);
        StartMenu();


}

void product :: forgot()
{
        int ch;
        system("cls");
        cout<<"\t\t\t\t-----------------------------------------------------"<<endl;
        cout<<"\t\t\t\t|                FORGOT PASSWORD                    |"<<endl;
        cout<<"\t\t\t\t-----------------------------------------------------"<<endl;
        cout<<"\t\t\t\t\tForgotten ? We're here for help!!\n\n";
        cout<<"\t\t\t\t\t1.Search your Password by user name"<<endl;

        cout<<"\t\t\t\t\t2.Main menu"<<endl;
        cout<<"\t\t\t\t\tEnter your choice :";
        cin>>ch;
        switch(ch)
        {
                case 1:
                {
                        int count=0;

                        cout<<"\n\t\t\t\t\tEnter your remembered username :";
                        cin>>user;
                        string Sin= "SELECT password FROM registration WHERE username ='"+user+"'";

                        if(mysql_query(conn,Sin.c_str()))
                        {
                         cout<<"Error: "<<mysql_error(conn)<<endl;
                        }
                        else
                        {
                            MYSQL_RES* res;
                            res= mysql_store_result(conn);
                            if(res)
                            {
                            int numFields = mysql_num_fields(res);

                                MYSQL_ROW row;

                                while ((row = mysql_fetch_row(res))) {
                                    for (int i = 0; i < numFields; i++) {
                                          pass=row[i];
                                    }

                            }
                            if(pass!="\0"){
                           system("cls");
                                 cout<<"\t\t\t\t-----------------------------------------------------"<<endl;
                                 cout<<"\t\t\t\t|                FORGOT PASSWORD                    |"<<endl;
                                 cout<<"\t\t\t\t-----------------------------------------------------"<<endl;

                                cout<<"\n\n\t\t\t\tYour account has been found.username = "<<user<<".";
                                cout<<"\n\t\t\t\tYour password is = "<< pass<<".";
                                cin.get();
                                cin.get();

                                StartMenu();}
                               else{
                            system("cls");
                                  cout<<"\t\t\t\t-----------------------------------------------------"<<endl;
                                 cout<<"\t\t\t\t|                FORGOT PASSWORD                    |"<<endl;
                                 cout<<"\t\t\t\t-----------------------------------------------------"<<endl;
                                cout<<"\n\t\t\t\t Sorry, Your username is not found in our database";
                                cout<<"\n\t\t\t\t Please kindly contact your system\n\t\t\t\t administrator for more details.";
                               cin.get();
                                cin.get();
                                StartMenu();

                                 }}

                        }
                    }


                case 2:
                {

                       StartMenu();
                }
                default:
                        cout<<"\t\t\t\t\tSorry, You entered wrong choice. Kindly try again"<<endl;
                        forgot();
        }
}
//admin panel-----------------------------------------------------------------------------

void product:: AdminPannel()
{
    enter="a";

        menustart:
            system("cls");

        int choice;
        cout<<"\t\t\t ________________________________________________________________________\n";
        cout<<"\t\t\t|               Daily Product Price List                                 |\n";
        cout<<"\t\t\t|________________________________________________________________________|\n";
        cout<<"\t\t\t|1.Add Product                                                          |"<<endl;
        cout<<"\t\t\t|                                                                       |"<<endl;
        cout<<"\t\t\t|2.Update Price                                                         |"<<endl;
        cout<<"\t\t\t|                                                                       |"<<endl;
        cout<<"\t\t\t|3.Product List                                                         |"<<endl;
        cout<<"\t\t\t|                                                                       |"<<endl;
        cout<<"\t\t\t|4.Delete Product                                                       |"<<endl;
        cout<<"\t\t\t|                                                                       |"<<endl;
        cout<<"\t\t\t|5.Search Product                                                       |"<<endl;
        cout<<"\t\t\t|                                                                       |"<<endl;
        cout<<"\t\t\t|6.Exit                                                                 |"<<endl;
        cout<<"\t\t\t|_______________________________________________________________________|"<<endl;
        cout<<"\t\t\tEnter your choice[1/2/3/4/5/6] :"; cin>>choice;


        cout<<endl;
        switch(choice)
        {
                case 1:
                       ProductAdd();
                        break;
                case 2:
                       UpdateList();
                        break;
                case 3:
                       ProductList();
                        break;
                case 4:
                       ProductDelete();
                        break;
                case 5:

                       ProductSearch();

                        break;
                 case 6:

                       enter="";
                       StartMenu();

                        break;
                default:
                        system("cls");
                        cout<<"\t\t\t\t\tYou've made a mistake , Try again..\n"<<endl;
                        cin.get();
                        cin.get();
                        goto menustart;
        }

}
//-----------------------------------------------------------------------------------------

//product add
void product::ProductAdd()
{
    system("cls");
        cout<<"\t\t\t--------------------------------------------------------------------"<<endl;
        cout<<"\t\t\t|                          Add New Product                          |\n";
        cout<<"\t\t\t--------------------------------------------------------------------"<<endl;

         cout<<"\n\n\t\t\tEnter Division Name:";
         cin>>div_name;
        cout<<"\n\n\t\t\t 1)Enter Product Name:";
        cin>>P_name;
        cout<<"\n\t\t\t 2)Enter Product Quantity:";
        cin>>quantity;
        cout<<"\n\t\t\t 3)Enter Product Price:";
        cin>>price;
        cout<<"\n\t\t\t 4)Enter last Product Price  updated:";
        cin>>l_price;


        price_dollar=convert(price);
        div_name+="_product";

        string Sup = "INSERT INTO "+div_name+"(Product_name,Product_Quantity,price_tk,price_dollar,changed_date,last_updated) VALUES ('"+P_name+"','"+quantity+"','"+price+"','"+price_dollar+"',CURRENT_DATE(),'"+l_price+"')";

        if(mysql_query(conn,Sup.c_str())){
         cout<<"Error: "<<mysql_error(conn)<<endl;
        }
        else
        {
            cout<<"\n\n\t\t\t\tYour Information Successfully Store\n";

         }
        cin.get();
        cin.get();
       AdminPannel();

}
//taka to dollar
string product::convert(string price)
{
    stringstream ss;
    ss << price;
    float x = 0.0;
    ss >> x;
    x = x / 110.28;

    string s;
    s=to_string(x);
    s+='$';
    return s;

}
//-------------------------delete product---------------------------------

void product::ProductDelete()
{
    system("cls");


                    cout<<"\t\t\t--------------------------------------------------------------------"<<endl;
                    cout<<"\t\t\t|                        Delete Product                             |\n";
                    cout<<"\t\t\t--------------------------------------------------------------------"<<endl;


                    cout<<"\n\n\t\t\t 1)Division Name:"; cin>>div_name;
                    cout<<"\n\t\t\t 2)Product Name:"; cin>>P_name;
                    div_name+="_product";

                    string del= "DELETE FROM "+div_name+" WHERE Product_name='"+P_name+"'";


                    if(mysql_query(conn,del.c_str())){
                     cout<<"Error: "<<mysql_error(conn)<<endl;
                    }
                    else
                    {
                        cout<<"\n\n\t\t\tDelete the Information Successfully";

                    }
                    cin.get();
                    cin.get();
                    AdminPannel();
}
//------------------------------update product-----------------------
void product::UpdateList()
{
    system("cls");


                    cout<<"\t\t\t--------------------------------------------------------------------"<<endl;
                    cout<<"\t\t\t|                        Update Product                             |\n";
                    cout<<"\t\t\t--------------------------------------------------------------------"<<endl;


                    cout<<"\n\n\t\t\t 1)Division Name:"; cin>>div_name;
                    div_name+="_product";
                    cout<<"\n\t\t\t 2)Product Name:"; cin>>P_name;

                    string sel="Select price_tk from "+div_name+" WHERE Product_name='"+P_name+"'";
                      if(mysql_query(conn,sel.c_str()))
                        {
                         cout<<"Error: "<<mysql_error(conn)<<endl;
                        }
                        else
                        {
                            MYSQL_RES* res;
                            res= mysql_store_result(conn);
                            if(res)
                            {
                            int numFields = mysql_num_fields(res);

                                MYSQL_ROW row;

                                while ((row = mysql_fetch_row(res))) {
                                    for (int i = 0; i < numFields; i++) {
                                          ans=row[i];
                                    }

                            }}}

                    cout<<"\n\t\t\t 3)Enter Product Quantity:";cin>>quantity;
                    cout<<"\n\t\t\t 4)Enter Product Price:";cin>>price;

                    price_dollar=convert(price);



    string upd= " UPDATE "+div_name+" SET  Product_Quantity = '"+quantity+"', price_tk='"+price+"',price_dollar='"+price_dollar+"',changed_date=CURRENT_DATE(),last_updated='"+ans+"'WHERE Product_name='"+P_name+"'";


                    if(mysql_query(conn,upd.c_str())){
                     cout<<"Error: "<<mysql_error(conn)<<endl;
                    }
                    else
                    {
                        cout<<"\n\n\t\t\tupdated the Information Successfully";

                    }
                    cin.get();
                    cin.get();
                    AdminPannel();
}
//--------------------------------------------show all product----------------------------------------------------
void product::ProductList()
{
     system("cls");


                    cout<<"\t\t\t--------------------------------------------------------------------"<<endl;
                    cout<<"\t\t\t|                     Display Product Details                      |\n";
                    cout<<"\t\t\t--------------------------------------------------------------------"<<endl;
                    cout<<"\n\n\t\t\t Division Name:"; cin>>div_name;
                    div_name+="_product";



                    string sho= "select * FROM "+div_name+"";


                    if(mysql_query(conn,sho.c_str())){
                     cout<<"Error: "<<mysql_error(conn)<<endl;
                    }
                    else
                    {
                        cout<<"+---------------------+--------------------+---------------------+---------------------+---------------------+---------------------+\n";
                        cout<<"|    Product_name     | Product_Quantity   |       price_tk      |     price_dollar    | changed_date        |   last_updated      |\n";
                        cout<<"+---------------------+--------------------+---------------------+---------------------+---------------------+---------------------+\n";
                        MYSQL_RES* res;
                            res= mysql_store_result(conn);
                            if(res)
                            {
                            int numFields = mysql_num_fields(res);

                                MYSQL_ROW row;

                                while ((row = mysql_fetch_row(res))) {

                                    for (int i = 0; i < numFields; i++)
                                        {

                                              ans=row[i];
                                          cout<<"  "<<ans;
                                          for(int j=0;j<20-ans.size();j++){ cout<<" ";}


                                    }
                                    cout<<"-----------------------------------------------------------------------------------------------------------------------------------"<<endl;
                                    }
                                    }}
                        cin.get();
                        cin.get();
                        if(enter=="a")
                        AdminPannel();
                        else
                        UserLogin();
}
void product::ProductSearch()
{
  system("cls");


                    cout<<"\t\t\t--------------------------------------------------------------------"<<endl;
                    cout<<"\t\t\t|                     Display Product Details                      |\n";
                    cout<<"\t\t\t--------------------------------------------------------------------"<<endl;
                    cout<<"\n\n\t\t\t Division Name:"; cin>>div_name;
                    div_name+="_product";
                    cout<<"\n\n\t\t\t Which method you want to find product details?(1/2)";

                    cout<<"\n\n\t\t\t 1)Search by product Name.";
                    cout<<"\n\n\t\t\t 2)Search by product changed date.";
                    cout<<"\n\n\t\t\t Enter the  value:"; cin>>u;
                    string sho;

                  if(u=="1")
                   {
                    cout<<"\n\n\t\t\t Enter product Name:";cin>>P_name;
                    sho= "select * FROM "+div_name+" where Product_name = '"+P_name+"'";
                    }
                    else
                    {
                        cout<<"\n\n\t\t\t Enter product changed date(YY-MM-DD):"; cin>>P_date;
                        sho= "select * FROM "+div_name+" where changed_date  = '"+P_date+"'";
                    }

                    if(mysql_query(conn,sho.c_str())){
                     cout<<"Error: "<<mysql_error(conn)<<endl;
                    }
                    else
                    {
                        system("cls");
                        cout<<"\t\t\t--------------------------------------------------------------------"<<endl;
                        cout<<"\t\t\t|                     Display Product Details                      |\n";
                        cout<<"\t\t\t--------------------------------------------------------------------"<<endl;

                        cout<<"\n\n\n+---------------------+--------------------+---------------------+---------------------+---------------------+---------------------+\n";
                        cout<<"|    Product_name     | Product_Quantity   |       price_tk      |     price_dollar    | changed_date        |   last_updated      |\n";
                        cout<<"+---------------------+--------------------+---------------------+---------------------+---------------------+---------------------+\n";
                        MYSQL_RES* res;
                            res= mysql_store_result(conn);
                            if(res)
                            {
                            int numFields = mysql_num_fields(res);

                                MYSQL_ROW row;

                                while ((row = mysql_fetch_row(res))) {

                                    for (int i = 0; i < numFields; i++)
                                        {

                                              ans=row[i];
                                          cout<<"  "<<ans;
                                          for(int j=0;j<20-ans.size();j++){ cout<<" ";}


                                    }
                                    cout<<"-----------------------------------------------------------------------------------------------------------------------------------"<<endl;
                                    }
                                    }}
                                    cin.get();
                                    cin.get();
                         if(enter=="a")
                        AdminPannel();
                        else
                        UserLogin();
}
void product::UserLogin()
{
            menustart:
            system("cls");

        int choice;
        cout<<"\t\t\t ________________________________________________________________________\n";
        cout<<"\t\t\t|               Daily Product Price List                                 |\n";
        cout<<"\t\t\t|________________________________________________________________________|\n";
        cout<<"\t\t\t|1.Product List.                                                         |"<<endl;
        cout<<"\t\t\t|                                                                        |"<<endl;
        cout<<"\t\t\t|2.Search Product.                                                       |"<<endl;
        cout<<"\t\t\t|                                                                        |"<<endl;
        cout<<"\t\t\t|3.Exit                                                                  |"<<endl;
        cout<<"\t\t\t|________________________________________________________________________|"<<endl;
        cout<<"\t\t\tEnter your choice[1/2/3] :"; cin>>choice;


        cout<<endl;
        switch(choice)
        {

                case 1:
                       ProductList();
                        break;

                case 2:

                       ProductSearch();

                        break;

                case 3:

                       StartMenu();

                        break;
                default:
                        system("cls");
                        cout<<"\t\t\t\t\tYou've made a mistake , Try again..\n"<<endl;
                        cin.get();
                        cin.get();
                        goto menustart;
        }
}
int main()
{
   // MYSQL*conn;
    conn=mysql_init(NULL);

    if(!mysql_real_connect(conn,HOST,USER,PW,DB,3306,NULL,0))
        {
	     cout<<"Error: "<<mysql_error(conn)<<endl;
        }
    else
        {
	     cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\tLogged in project....."<<endl;
        }
 Sleep(3000);
    product object1;
    object1.StartMenu();

    return 0;
}
