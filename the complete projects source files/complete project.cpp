#include <iostream>
#include "category.h"
#include "product.h"
#include"menu.h"
#include"customer.h"
#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

// the protypes for functions
void start(menu& me,  customer&cus);
void display_intro();


int main()
{ 
    // start extraxt the data from text file by c++ files handling method
    ifstream in("in.txt", ios::in);
   
    category obj;
    map<string, vector<product>>m;

    string name; // for cat. name 
    int count;// for the quantity of this cat
    
    // set up the categoty linklist and product map objs
    while (!in.eof()) {
         
         in >> name >> count;
         if (!in.eof()) {
             cat_node temp1(name, count); // category details like  ( fruits 4 )
             obj + temp1;//add to the category linked list

             string proname;//pro. name
             float price;// pro. price
             int quantity;//pro. quantity
             
              
                 for (int c = 0; c < count; c++) {
                     in >> proname >> price >> quantity;
                     product p(proname, price, quantity);
                     m[name].push_back(p);
                   
                 }

         }
           
           
       } 
       

    in.close();

    menu me(obj, m);// set up the menu obj
   
    
    customer cus;//set up the customer obj 

    cout << "WELLCOME TO MY MINI MARKET SYSTEM \n";
    
    // in case that the market is empty from the begining we will not show the menu , but we will exit the system
    if (me.is_empty() == 1)
    {
        cerr << "SORRY YOUR MARKET IS EMPTY !! PLEASE FILL IT SOON \n";
        exit(0);
    }

    display_intro();
    
    start(me,cus);
 
    return 0;


}
 


void display_intro() {
    cout << "HERE IS THE OPTIONS , PICK ONE : \n\n";

    cout << "1- SHOW UP THE COMPLETE MENUE \n";
    cout << "2- SHOW UP THE MENU BASED ON SPECIAL CATEGORY YOU NEED TO SHOP FROM  \n";
  
    cout << "3- PRINT OUT MY TOTAL BILL\n";
    cout << "4- EXIT\n";
    return;

};

void start(menu& me, customer& cus) {
    // the system will end up when the customer choose one of the last 2 options and when the market become empty

   int option;
   std:: cin >> option;

    while ((option != 3) && (option != 4)&&(!me.is_empty())) {

        if (option == 1) {

            me.show_menu();

            cout << "START SHOPPING BY WRITING DOWN THE CATEGORY AND THEN THE PRODUCT , THEN THE QUANTITY :\n";

            string cat, pro_name;
            int quantity;
            cin >> cat >> pro_name >> quantity;

            /* i have store first the price because in case that the choosen product
            * will finish ( the customer byu the last item from it it will be removed 
            * from the market so i will not be able to restore what is the price of it */
            float price = me.show_price_of_pro(pro_name, cat);

            // to show if the purchase procees will success or not 
            bool x = me.decrease(cat, pro_name, quantity);

            if (x == true) {

                //we will add the product to the customer basket with its quantity
                cus.add_to_basket(pro_name, quantity, price);
                 

                cout << "YOUR BURCHASE IS DONE SUCCESSFULLY !" << " FOR " << pro_name << " WITH  QUANTITY OF " << quantity << endl;
                cout << "WOULD YOU LIKE TO BYU ANOTHER PRODUCT ? yes / no ";
                string sec_option;
                cin >> sec_option;

                if (sec_option == "yes") {
                    option = 1;//to avoid taking another input because the user has choose
                    continue;
                }

            }
            else {
                cerr << "SORRY YOU CANT BYU THIS QUANTITY !! IT IS TOO MUCH !!\n";
                  
            }


        }

        if (option == 2) {
            cout << "PLEASE CHOOSE THE CATEGORY YOU NEED TO SHOP FROM IT : \n";
            // i will show the cat's that found in the market then he will choose from them the required cat
            me.show_cat();
            string cat;
            cin >> cat;
            // we will cosider the case that the choosen cat is found in the list
            if (me.search_cat(cat) == true) {
                //the choosen cat is found in the market
                me.show_menu(cat);
                cout << "CHOOSE THE PRODUCTS AND THEIR QUANTITY : \n";
                string  pro_name;
                int quantity;
                cin >> pro_name >> quantity;

                float price = me.show_price_of_pro(pro_name, cat);
                bool x = me.decrease(cat, pro_name, quantity);

                if (x == true) {
                    //we will add the product to the customer basket with its quantity
                    cus.add_to_basket(pro_name, quantity, price);
                    // cout << cus.get_money()<< endl;

                    cout << "YOUR BURCHASE IS DONE SUCCESSFULLY !" << " FOR " << pro_name << " WITH  QUANTITY OF " << quantity << endl;
                    cout << "WOULD YOU LIKE TO BYU ANOTHER PRODUCT FROM SPECIFIC CATEGORY ? yes / no ";
                    string sec_option;
                    cin >> sec_option;
                    if (sec_option == "yes") {
                        option = 2;
                        continue;
                    }

                }
                else {
                    cerr << "SORRY YOU CANT BYU THIS QUANTITY !! IS TOO MUCH !!\n";
                     
                }

            }
           
        }

        display_intro();
        cin >> option;
    }

    if (option == 3) {
        cus = "show customer bill on cmd";
        cout << "THE BILL HAS BEEN PRINTED SUCCESSFULLY FOR YOU ON THE CMD \n ";

        cout << "IF YOU WANT TO PRINT OUT THE BILL ON FILE , CLICK 1....";

        string res;
        cin >> res;


        if (res == "1") {
            cus = "show customer bill on file";
            cout << "THE BILL HAS BEEN PRINTED SUCCESSFULLY ON FILE\n ";
        }

        return;
            
    }


    if (option == 4) {
        cout << "THANK YOU FOR USING OUR SYSTEM !!\n";
        cus = "show customer bill on cmd";
        cus = "show customer bill on file";
        return;
    }


    /* here for sure the market initially has products but when when the user byu all items
    * the products will finish thats why each time in the loop we check if its empty or no 
    * and the evedence the customer has a bill */ 

    if (me.is_empty()) {
        cout << "SORRY THE MARKET CURRENTLY DOESNT HAVE PRODUCTS , IT WILL BE FILLED SOON , HERE IS YOUR BILL : \n";
        cus = "show customer bill on cmd";
        cus = "show customer bill on file";
    }
    
     
    return;
}


/* some of the interial functions if the classes, their staments will not be reached
* at all ( impossiple ) , simlply because i have put if-else statments in the main
* function ( above ) , ex : when we search about particular cat. when the customer 
* choose it , impossible to have 0 cat in the linked list of cat obj , because before
* we call the start function we check if we have cat or not ....... */