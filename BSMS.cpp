#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
using namespace std;

//-----------------------------------Functions prototypes Start

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);  //--for color
void header(); //--This is simple header file
char menu1();  //--Menu for Admin
char menu2();  //--Menu for user
char noticeBoard();  //--Notice Board menu
char LoginChoice();  //--Login Page Menu
char MagazineNewspaper();  //--Menu for newspaper and magazines Section
char editInfo();  //--Menu for changing Name,Price,Category 
void invalidInput();  //--this function is for validation
void clearScreen();  //--This function clear screen after even a single implementation
void addNewStock();  //--This Function is to ask the book info
void addIntoTheArray(string name,int price,string catg); //--Book info store in array through this Function
void viewAllBooks();  //--for view all books 
void viewBooks();  //--This is also the same except showing price
void buyAnyBook();  //--for buy book from list
void viewNotice();  //--for view Important notices
void giveFeedback();  //--for taking feedback
void addNotice();  //--for add notices
void viewNoticeB();  
void delNotice();  //--for delete notice
void editNames();  //--for edit names of books
void editPrices();  //--for edit prices of books
void editCatg();  //--for edit category of books
void delBook(); //--for delete any book
int Largest(int s); //--for arrange books in order of prices
void LoadData(); //--for load data
void storeData();  //--for store data 
string parseData(string line, int field); //--for comma separation
void addDiscount();  //--for add discount 
char subMenuMN();  //--Menu for newspaper and magazines Section
char magazines();  //--for explore magazines menu
char newspaper();  //--for explore newspaper menu
void addMagazines();  //--for add magazines to array
void addNewspaper();  //--for add newspaper to array
void seeNewspaper();  //--for view newspaper
void seeMagazines();  //--for view magazines
void delNewspaper();  //--for delete newspaper
void delMagazines();  //--for delete magazines

//----------------------------------Functions prototypes End

//----------------------------------Data Structures Start

const int MAX_REC = 200; //---Max record cons can be change any time
string User_NamesA[2]; //---to load Username into the file
string PasswordsA[2]; //---to load Password into the file
string bookNamesA[MAX_REC]; //---To store Book Name
int bookPriceA[MAX_REC];  //---To Store Book price
string bookCatgA[MAX_REC];  //---To Store Book category
string noticeA[MAX_REC];  //---To Store notices
string magazinesA[MAX_REC];  //---To Store Magazines links
string newspaperA[MAX_REC];  //---To Store Newspaper links
int Book_Counter = 0; //---To calculate no. of Books
int Notice_Counter = 0;  //---To calculate no. of Notice
int User_Counter = 0;  //---To calculate no. of Users
int magazines_Counter = 0;  //---To calculate no. of magazines links
int newspaper_counter = 0;  //---To calculate no. of newspaper links
float pBook; //---To store value for temporary reason
string feedback;  //---To store feedback
int count = 0;
//----For store Username & Password
string Username,Password;

//----------------------------------Data Structures End
main()
{
    LoadData(); //-----Calling function to store data from file to array
    char opt = ' ';
    while(true) //-----loop for the main llop
    {
        system("cls");
        opt = '0';
        opt = LoginChoice();  //------calling function for the login page
        if(opt == '1')
        {
            system("cls");
            while(Username != User_NamesA[0] && Password != PasswordsA[0])  
            {   		//---------------------------loop for login username and password
                header();
                cout << "Login Page >" <<endl;
                cout << "Enter username(as an admin).."; //------Add ID For login as admin
                cin >> Username;
                cout << "Enter Password..............."; //------Add Password for login as admin
                cin >> Password;
                if(Username != User_NamesA[0] && Password != PasswordsA[0])
                {       //------This condition is for the validation purpose
                    SetConsoleTextAttribute(h,4);  //----This function is for colouring the text
                    cout << "Invalid Username & Password" <<endl;   //------wrong password statement
                    cout << "Press any key to continue...";
                    getch();
                    SetConsoleTextAttribute(h,15);
                    system("cls");
                    break;
                }
                if(Username == User_NamesA[0] && Password == PasswordsA[0])
                {       //----------------If information is correct 
                    system("cls");
                    char opt1 = ' ';
                    while(true)
                    {       //---------------------------Start of While Loop
                        opt1 = '0';
                        opt1 = menu1(); //----Calling function for admin menu
                        if(opt1 == '1')
                        {       //---------------------------Add new stock (brackets start)
                            system("cls");
                            addNewStock(); //----Calling function for add new books
                        }
                        else if(opt1 == '2')
                        {       //---------------------------View All books (brackets start)
                            system("cls");
                            header();
                            viewAllBooks(); //----Calling function for view all books
                        }
                        else if(opt1 == '3')
                        {       //---------------------------Edit prices of the books 
                            system("cls");
                            char opt2 = ' ';
                            while(true)
                            {
                                opt2 = '0';
                                header();
                                opt2 = editInfo(); //----Calling function for edit info of the book
                                if(opt2 == '1')
                                {
                                    system("cls");
                                    header();
                                    editNames();  //----Calling function for edit name
                                }
                                else if(opt2 == '2')
                                {
                                    system("cls");
                                    header();
                                    editPrices(); //----Calling function for edit prices
                                }
                                else if(opt2 == '3')
                                {
                                    system("cls");
                                    header();
                                    editCatg(); //----Calling function for edit category
                                }
                                else if(opt2 == '4')
                                {
                                    system("cls");
                                    header();
                                    delBook(); //----Calling function for delete book
                                }
                                else if(opt2 == '5')
                                {
                                    system("cls");
                                    break;
                                }
                                else
                                {
                                    invalidInput(); //----Calling function for invaid input statement
                                    continue;
                                }
                                clearScreen();
                            }
                            continue;
                        }
                        else if(opt1 == '4')
                        {       //---------------------------Add discount on a particuler
                            system("cls");
                            header();
                            addDiscount(); //----Calling function for adding discount
                        }
                        else if(opt1 == '5')
                        {       //---------------------------View all books in order of prices
                            system("cls");
                            header();
                            int largest_idx; //---variable for swaping
                            int temp1; //---variable for swaping
                            string temp2,temp3;
                            for(int i = 0; i < Book_Counter; i++)
                            { //---Implement loop for swaping in parrallel array
                                largest_idx = Largest(i);
                                temp1 = bookPriceA[largest_idx];
                                bookPriceA[largest_idx] = bookPriceA[i];
                                bookPriceA[i] = temp1;

                                temp2 = bookNamesA[largest_idx];
                                bookNamesA[largest_idx] = bookNamesA[i];
                                bookNamesA[i] = temp2;

                                temp3 = bookCatgA[largest_idx];
                                bookCatgA[largest_idx] = bookCatgA[i];
                                bookCatgA[i] = temp3;
                            }
                            cout <<"Main Menu > View all books in order of prices" <<endl;
                            cout <<"----------------------------------------------------------------" <<endl; 
                            cout << "NAMES\t\t\tCATEGORIES\t\tPRICES" <<endl;
                            for(int j = 0; j < Book_Counter; j++)
                            {   //---implement loop for view all books in order of prices
                                cout << bookNamesA[j] << "\t\t\t" << bookCatgA[j] << "\t\t\t" << bookPriceA[j] <<endl;
                            }
                        }
                        else if(opt1 == '6')
                        {       //---------------------------Add Magazines and Newspapers
                            system("cls");
                            char opt2 = ' ';
                            while(true)
                            {
                                
                                opt2 = '0';
                                header();
                                opt2 = subMenuMN(); //---calling function for Magazine & Newspapers menu
                                if(opt2 == '1')
                                {
                                    char opt3 = ' ';
                                    while(true)
                                    {
                                        opt3 = '0';
                                        system("cls");
                                        header();
                                        opt3 = magazines();//---calling function for Magazine menu
                                        if(opt3 == '1')
                                        {
                                            system("cls");
                                            header();
                                            addMagazines();//---calling function for add Magazine
                                        }
                                        else if(opt3 == '2')
                                        {
                                            system("cls");
                                            header();
                                            seeMagazines(); //---calling function for view Magazines  
                                        }
                                        else if(opt3 == '3')
                                        {
                                            system("cls");
                                            header();
                                            delMagazines(); //---calling function for delete Magazine
                                        }
                                        else if(opt3 == '4')
                                        {
                                            system("cls");
                                            break;
                                        }
                                        else
                                        {
                                            invalidInput();
                                            system("cls");
                                            continue;
                                        }
                                        clearScreen(); //---calling function for clear screen
                                    }
                                    break;
                                }
                                else if(opt2 == '2')
                                {
                                    char opt3 = ' ';
                                    while(true)
                                    {
                                        system("cls");
                                        opt3 = '0';
                                        header();
                                        opt3 = newspaper(); //---calling function for Newspapers menu
                                        if(opt3 == '1')
                                        {
                                            system("cls");
                                            header();
                                            addNewspaper(); //---calling function for Newspapers
                                        }
                                        else if(opt3 == '2')
                                        {
                                            system("cls");
                                            header();
                                            seeNewspaper(); //---calling function for view Newspapers
                                        }
                                        else if(opt3 == '3')
                                        {
                                            system("cls");
                                            header();
                                            delNewspaper(); //---calling function for delete Newspapers
                                        }
                                        else if(opt3 == '4')
                                        {
                                            system("cls");
                                            break;
                                        }
                                        else
                                        {
                                            invalidInput();
                                            system("cls");
                                            continue;
                                        }
                                        clearScreen(); //---calling function for clear screen
                                    } 
                                    break;  
                                }
                                else if(opt2 == '3')
                                {
                                    system("cls");
                                    break;
                                }
                                else
                                {
                                    invalidInput(); //---calling function for Invalid input statement
                                    continue;
                                }
                                clearScreen(); //---calling function for clear screen
                            }
                            continue;
                        }
                        else if(opt1 == '7')
                        {       //---------------------------Add Important Notices
                            system("cls");
                            char opt2 = ' ';
                            while(true)
                            {
                                opt2 = '0';
                                header();
                                opt2 = noticeBoard(); //---calling function for notice board menu
                                if(opt2 == '1')
                                {   //------Add Important Notices
                                    system("cls");
                                    header();
                                    addNotice(); //---calling function for add notice
                                }
                                else if(opt2 == '2')
                                {   //------View Important Notices
                                    system("cls");
                                    header();
                                    viewNoticeB(); //---calling function for view notice
                                }
                                else if(opt2 == '3')
                                {   //------Delete Important Notices
                                    system("cls");
                                    header();
                                    delNotice(); //---calling function for delete notice
                                }
                                else if(opt2 == '4')
                                {   //------Exit
                                    system("cls");
                                    break;
                                }
                                else
                                {
                                    invalidInput(); //---calling function for Invalid input statement
                                    continue;
                                }
                                clearScreen(); //---calling function for clear screen
                            }
                            continue;
                        }
                        else if(opt1 == '8')
                        {       //---------------------------Exit (brackets start)
                            system("cls");
                            break;
                        }
                        else
                        {   /*---------------------------If you enter wrong input
                            this program will show this output (brackets start) */
                            invalidInput(); //---calling function for Invalid input
                            continue;
                        }
                        clearScreen(); //---calling function for clear screen
                    }
                }
                Username = " ";
                Password = " ";
                break;
            }          
        }
        else if(opt == '2')
        {
            system("cls");
            while(Username != User_NamesA[1] && Password != PasswordsA[1])
            {       /*---------------------------If information is incorrect
                    it will ask Again Username & password (brackets start) */
                header();
                cout <<"Login Page >" <<endl;
                cout <<"Enter username(as a user)..."; //Enter ID For Admin
                cin >>Username;
                cout <<"Enter Password.............."; //Enter Password for Admin
                cin >>Password;
                if(Username != User_NamesA[1] && Password != PasswordsA[1])
                {       /*---------------------------If information is incorrect
                        it will show this interface (brackets start) */
                    SetConsoleTextAttribute(h,4); //---calling function for coloring the text
                    cout << "Invalid Username & Password" <<endl; //---Invalid input statement
                    cout << "Press any key to continue...";
                    getch();
                    SetConsoleTextAttribute(h,15);
                    system("cls");
                }
                if(Username == User_NamesA[1] && Password == PasswordsA[1])
                {   /*---------------------------If information is correct
                    it will show this interface */
                    system("cls");
                    char opt2 = ' ';
                    while(true)
                    {       //---------------------------Start of While Loop (brackets start)
                        opt2 = '0';
                        opt2 = menu2(); //---calling function for user's menu
                        if(opt2 == '1')
                        {             //---------------------------View All books (brackets start)
                            system("cls");
                            header();
                            viewBooks(); //---calling function for view all books
                        }
                        else if(opt2 == '2')
                        {             //---------------------------Buy any book from list
                            system("cls");
                            buyAnyBook(); //---calling function for buy any book from the list
                        }
                        else if(opt2 == '3')
                        {              /*---------------------------View Magazines & Newspaper
                                       (brackets start) */
                            char choice = ' ';
                            while(true)
                            {
                                system("cls");
                                header();
                                choice = '0';
                                choice = MagazineNewspaper(); //---calling function for Magazine & Newspapers menu
                                if(choice == '1')
                                {
                                    system("cls");
                                    header();
                                    seeMagazines(); //---calling function for view Magazine links
                                }
                                else if(choice == '2')
                                {
                                    system("cls");
                                    header();
                                    seeNewspaper(); //---calling function for view Newspapers links
                                }
                                else if(choice == '3')
                                {
                                    system("cls");
                                    break;
                                }
                                else
                                {
                                    invalidInput(); //---calling function for Invalid input statement
                                    continue; // //---calling for continue the loop
                                }
                                clearScreen(); //---calling function for clear screen
                            }
                            continue;
                        }
                        else if(opt2 == '4')
                        {             //---------------------------View All Important notices 
                            system("cls");
                            header();
                            viewNoticeB(); //---calling function for view notices
                        }
                        else if(opt2 == '5')
                        {             //---------------------------Enter your feedback (brackets start)
                            system("cls");
                            header();
                            giveFeedback(); //---calling function for enter feed back
                        }
                        else if(opt2 == '6')
                        {             //---------------------------Exit (brackets start)
                            system("cls");
                            break; //---to break the loop
                        }
                        else
                        {             //---------------------------If you enter wrong input
                            invalidInput();
                            continue;
                        }
                        clearScreen();
                    }
                }
                Username = " ";
                Password = " ";
                break; 
            }
        }
        else if(opt == '3')
        {
            system("cls");
            break;
        }
        else
        {   /*---------------------------If you enter wrong input
            this program will show this output (brackets start) */
            invalidInput(); 
        }
    }
    storeData();
}
//----------------------------------Function Implementation Start

void header()
{       //------------------This is simple header file for this program
	cout <<"***************************************************" <<endl;
	cout <<"**          BOOK STORE MANAGEMENT SYSTEM         **" <<endl;	
	cout <<"***************************************************" <<endl;
	cout <<endl;
	cout <<endl;
}

char LoginChoice()
{       //------------------This is Login Page
    header();						
    cout << "Enter as a Admin or User";
    cout <<"--------------------------" <<endl;
    cout << "1. ADMIN" <<endl;  
    cout << "2. USER" <<endl;
    cout << "3. Exit" <<endl;
    char option;
    cout << "Your Option...";
    cin >> option;
    return option;
}

char menu1()
{       //-----------------This is the Main Menu for Admin
    header();
	cout <<"Main Menu >" <<endl;
	cout <<"--------------------------" <<endl;
	cout <<"Select one of the following" <<endl;
	cout <<"1. Add New Books" <<endl;
	cout <<"2. View All Books" <<endl;
	cout <<"3. Edit Book Info" <<endl;
	cout <<"4. Add discount on a particular book" <<endl;
	cout <<"5. View all Books in order of prices" <<endl;
	cout <<"6. Magazines and Newspapers" <<endl;
	cout <<"7. Notice Board" <<endl;
	cout <<"8. Exit" <<endl;
    char option;
	cout <<"Your Option..";
    cin >> option;
    return option;
}

char menu2()
{       //-----------------This is the Main Menu for User
    header();
	cout <<"Main Menu >" <<endl;
	cout <<"--------------------------" <<endl;
	cout <<"Select one of the following" <<endl;
	cout <<"1. View all availble Books" <<endl;
	cout <<"2. Buy any book from the list" <<endl;
	cout <<"3. Magazines and Newspapers" <<endl;
	cout <<"4. View all Important notices" <<endl;
	cout <<"5. Enter your feedback" <<endl;
	cout <<"6. Exit" <<endl;
	char option;
	cout <<"Your Option..";
    cin >> option;
    return option;
}

void invalidInput()
{   //----It is for the invalid input statement
    SetConsoleTextAttribute(h,4);
    cout << "Invalid Input" <<endl;
    cout << "Press any key to continue...";
    getch();
    SetConsoleTextAttribute(h,15);
    system("cls");
}

void clearScreen()
{   //----This function is for clear screen
    cout << "Press any key to continue...";
    getch(); 
    system("cls");  
}

void addNewStock()
{   //----Function Implemetation for add new books
    while(true)
    {
        header();
        string name,catg;
        int price;
        cout <<"Main Menu > Add New Books" <<endl;
	    cout <<"--------------------------" <<endl;
        cout << "Enter Book Name.......";
        cin >> name;
        cout << "Enter Book price......";
        cin >> price;
        if(price < 0)
        {
            SetConsoleTextAttribute(h,4);
            cout << "You can't enter price in negative" <<endl;
            cout << "Press any key to continue" <<endl;
            getch();
            SetConsoleTextAttribute(h,15);  
            system("cls");
            continue;
        }
        cout << "Enter Book Category...";
        cin >> catg;
        addIntoTheArray(name,price,catg);
        break;
    }
}

void addIntoTheArray(string name,int price,string catg)
{   //----Function Implemetation for storing data into array from variable
    bookNamesA[Book_Counter] = name;
    bookPriceA[Book_Counter] = price;
    bookCatgA[Book_Counter] = catg;
    Book_Counter++;
}

void viewAllBooks()
{   //----Function Implemetation for view all books
    cout <<"Main Menu > View All Books" <<endl;
	cout <<"--------------------------" <<endl;
    cout << "Name\t\t\t\t\tcategory" <<endl;
    cout <<endl;
    for(int i = 0; i < Book_Counter; i++)
    {
        cout << bookNamesA[i] << "\t\t\t\t\t" << bookCatgA[i] <<endl;
    }
}

char editInfo()
{   //----Function Implemetation for edit info menu
    cout << "Main Menu > Edit prices of books" <<endl;
    cout << "--------------------------------" <<endl;
    cout << "1. Edit Book Name" <<endl;
    cout << "2. Edit Book Price" <<endl;
    cout << "3. Edit Book Category" <<endl;
    cout << "4. Delete Book" <<endl;
    cout << "5. Exit" <<endl;
    char option;
    cout << "Your Options...";
    cin >> option;
    return option;
}

char subMenuMN()
{   //----Function Implemetation for Magazines and newspaper menu
    cout << "Main Menu > Magazines & Newspaper" <<endl;
    cout << "---------------------------------" <<endl;
    cout << "1. Magazines" <<endl;
    cout << "2. Newspapers" <<endl;
    cout << "3. Exit" <<endl;
    char option;
    cout << "Your Options...";
    cin >> option;
    return option;
}

char magazines()
{   //----Function Implemetation for magazines menu
    cout << "Main Menu > Magazines" <<endl;
    cout << "---------------------------------" <<endl;
    cout << "1. Add Magazines" <<endl;
    cout << "2. View Magazines" <<endl;
    cout << "3. Delete Magazines" <<endl;
    cout << "4. Exit" <<endl;
    char option;
    cout << "Your Options...";
    cin >> option;
    return option;
}

char newspaper()
{   //----Function Implemetation for newspaper menu
    cout << "Main Menu > Newspaper" <<endl;
    cout << "---------------------" <<endl;
    cout << "1. Add Newspaper" <<endl;
    cout << "2. View Newspaper" <<endl;
    cout << "3. Delete Newspaper" <<endl;
    cout << "4. Exit" <<endl;
    char option;
    cout << "Your Options...";
    cin >> option;
    return option;
}

void addMagazines()
{   //----Function Implemetation for add magazines
    cout << "Main Menu > Magazies" <<endl;
    cout << "--------------------" <<endl;
    cout << "Add links of magazines..." <<endl;
    cout << endl;
    string link;
    cin.ignore();
    getline(cin,link);
    magazinesA[magazines_Counter] = link;
    magazines_Counter++;
}

void addNewspaper()
{   //----Function Implemetation for add newspaper
    cout << "Main Menu > Newspaper" <<endl;
    cout << "---------------------" <<endl;
    cout << "Add links of Newspapers..." <<endl;
    cout << endl;
    string link;
    cin.ignore();
    getline(cin,link);
    newspaperA[newspaper_counter] = link;
    newspaper_counter++;
}

void seeNewspaper()
{   //----Function Implemetation for view newspaper
    cout << "Main Menu > View Newspaper" <<endl;
    cout << "--------------------------" <<endl;
    for(int i = 0; i < newspaper_counter; i++)
    {
        cout << i+1 << "." << newspaperA[i] <<endl;
    }
}

void seeMagazines()
{   //----Function Implemetation for view magazines
    cout << "Main Menu > View Magazines" <<endl;
    cout << "--------------------------" <<endl;
    for(int i = 0; i < magazines_Counter; i++)
    { //----This loop is for view magazines
        cout << i+1 << "." << magazinesA[i] <<endl;
    }
}

void delNewspaper()
{   //----Function Implemetation for delete newspaper
    cout << "Main Menu > Delete Newspaper Links" <<endl;
    cout << "----------------------------------" <<endl;
    cout << "To delete the notice please enter no. of "<<endl;
    cout << "newspaper(As in View Newspaper option)...";
    int num;
    cin >> num;
    for(int i = 0; i < newspaper_counter; i++)
    {  
        if(num == i+1)
        {
            for(int j = i; j < newspaper_counter; j++)
            {
                noticeA[j] = noticeA[j+1];
            }
            SetConsoleTextAttribute(h,2);
            cout << "The newspaper link has been deleted" <<endl;
            SetConsoleTextAttribute(h,15);
            newspaper_counter--;
        }
        else if(num > newspaper_counter)
        {
            SetConsoleTextAttribute(h,4);
            cout << "We do not have anthing on this index" <<endl;
            SetConsoleTextAttribute(h,15);
        }
    }
}

void delMagazines()
{   //----Function Implemetation for delete magazines
    cout << "Main Menu > Delete Magazine Links" <<endl;
    cout << "----------------------------------" <<endl;
    cout << "To delete the notice please enter no. of" <<endl; 
    cout << "magazine(As in View Magazines option)...";
    int num;
    cin >> num;
    for(int i = 0; i < magazines_Counter; i++)
    {
        if(num == i+1)
        {
            for(int j = i; j < magazines_Counter; j++)
            {
                noticeA[j] = noticeA[j+1];
            }
            SetConsoleTextAttribute(h,2);
            cout << "The magazine link has been deleted" <<endl;
            SetConsoleTextAttribute(h,15);
            magazines_Counter--;
            break;
        }
        else if(num > magazines_Counter)
        {
            SetConsoleTextAttribute(h,4);
            cout << "We do not have anthing on this index" <<endl;
            SetConsoleTextAttribute(h,15);
        }
    }
}

void editNames()
{   //----Function Implemetation for edit names of the book
    while(true)
    {
        cout <<"Main Menu > Edit name of books" <<endl;
        cout <<"--------------------------------" <<endl;
        string nameOfBook;
        cout << "Enter Book Name to edit name...";
        cin.ignore();
        getline(cin,nameOfBook);
        for(int i = 0; i < Book_Counter; i++)
        {
            if(bookNamesA[i] == nameOfBook)
            {
                string newName;
                cout << "Enter the revised name of " << bookNamesA[i] << "...";
                cin >> newName;
                SetConsoleTextAttribute(h,2);
                cout << "The name has been changed" <<endl;
                SetConsoleTextAttribute(h,15);
                bookNamesA[i] = newName;
                break;
            }
            if(i == Book_Counter-1)
            {
                SetConsoleTextAttribute(h,4);
                cout << "We do not have such book" <<endl;
                SetConsoleTextAttribute(h,15);
            }
        }
        break;
    }
}

void editPrices()
{   //----Function Implemetation for edit prices of the book
    while(true)
    {
        cout <<"Main Menu > Edit prices of books" <<endl;
        cout <<"--------------------------------" <<endl;
        string nameOfBook;
        cout << "Enter Book Name to edit Price...";
        cin.ignore();
        getline(cin,nameOfBook);
        for(int i = 0; i < Book_Counter; i++)
        {
            if(bookNamesA[i] == nameOfBook)
            {
                int newCost;
                cout << "Enter the revised price of " << bookNamesA[i] << "...";
                cin >> newCost;
                if(newCost < 0)
                {
                    SetConsoleTextAttribute(h,4);
                    cout << "You can't enter price in negative" <<endl;
                    cout << "Press any key to continue" <<endl;
                    getch();
                    SetConsoleTextAttribute(h,15);
                    system("cls");
                    continue;
                }
                else
                {
                    SetConsoleTextAttribute(h,2);
                    cout << "The price has been changed" <<endl;
                    SetConsoleTextAttribute(h,15);
                    bookPriceA[i] = newCost;
                    break;
                }
            }
            if(i == Book_Counter-1)
            {
                SetConsoleTextAttribute(h,4);
                cout << "We do not have such book" <<endl;
                SetConsoleTextAttribute(h,15);
            }
        }
        break;
    }
}

void editCatg()
{   //----Function Implemetation for edit categories
    while(true)
    {
        cout <<"Main Menu > Edit category of book" <<endl;
        cout <<"--------------------------------" <<endl;
        string nameOfBook;
        cout << "Enter Book Name to edit category...";
        cin.ignore();
        getline(cin,nameOfBook);
        for(int i = 0; i < Book_Counter; i++)
        {
            if(bookNamesA[i] == nameOfBook)
            {
                string newcatg;
                cout << "Enter the revised Category of " << bookNamesA[i] << "...";
                cin >> newcatg;
                SetConsoleTextAttribute(h,2);
                cout << "The Category has been changed" <<endl;
                SetConsoleTextAttribute(h,15);
                bookCatgA[i] = newcatg;
                break;
            }
            if(i == Book_Counter-1)
            {
                SetConsoleTextAttribute(h,4);
                cout << "We do not have such book" <<endl;
                SetConsoleTextAttribute(h,15);
            }
        }
        break;
    }
}

void delBook()
{
    while(true)
    {
        cout <<"Main Menu > Delete Book" <<endl;
        cout <<"--------------------------------" <<endl;
        string nameOfBook;
        cout << "For delete a book you need to enter Book Name...";
        cin.ignore();
        getline(cin,nameOfBook);
        for(int i = 0; i < Book_Counter; i++)
        {
            if(bookNamesA[i] == nameOfBook)
            {
                for(int j = i; j < Book_Counter; j++)
                {
                    bookNamesA[j] = bookNamesA[j+1];
                    bookPriceA[j] = bookPriceA[j+1];
                    bookCatgA[j] = bookCatgA[j+1];
                }
                Book_Counter--;
                SetConsoleTextAttribute(h,2);
                cout << "The book has been deleted" <<endl;
                SetConsoleTextAttribute(h,15);
                break;
            }
            if(i == Book_Counter-1)
            {
                SetConsoleTextAttribute(h,4);
                cout << "We do not have such book" <<endl;
                SetConsoleTextAttribute(h,15);
            }
        }
        break;
    }
}

char noticeBoard()
{   //----Function Implemetation for notice Board menu
    cout << "Main Menu > Notice Board" <<endl;
    cout << "------------------------" <<endl;
    cout << "1. Add Important Notices" <<endl;
    cout << "2. View Important Notices" <<endl;
    cout << "3. Delete Important Notices" <<endl;
    cout << "4. Back" <<endl;
    char opt4;
    cout << "Your Option...";
    cin >> opt4;
    return opt4;
}

void addNotice()
{   //----Function Implemetation for add notices
    cout << "Main Menu > Add Important Notices" <<endl;
    cout << "---------------------------------" <<endl;
    cout << "Add Important Notice...";
    cin.ignore();
    getline(cin,noticeA[Notice_Counter]);
    Notice_Counter = Notice_Counter + 1;
}

void viewNoticeB()
{   //----Function Implemetation for view notices
    cout << "Main Menu > View Important Notices" <<endl;
    cout << "----------------------------------" <<endl;
    cout << "              NOTICES             " <<endl;
    for(int i = 0; i < Notice_Counter; i++)
    {
        cout << i+1 << "." << noticeA[i] <<endl;
    }
}

void delNotice()
{   //----Function Implemetation for delete notices
    cout << "Main Menu > Delete Important Notices" <<endl;
    cout << "----------------------------------" <<endl;
    cout << "To delete the notice please enter no. of " <<endl;
    cout << "notice(As in View Notice option)...";
    int num;
    cin >> num;
    for(int i = 0; i < Notice_Counter; i++)
    {
        if(num == i+1)
        {
            for(int j = i; j < Notice_Counter; j++)
            {
                noticeA[j] = noticeA[j+1];
            }
            SetConsoleTextAttribute(h,2);
            cout << "Notice has been deleted" <<endl;
            SetConsoleTextAttribute(h,15);
            Notice_Counter--;
        }
        else if(num > Notice_Counter)
        {
            SetConsoleTextAttribute(h,4);
            cout << "We do not have anthing on this index" <<endl;
            SetConsoleTextAttribute(h,15);
        }
    }
}

void viewBooks()
{   //----Function Implemetation for view books
    cout <<"Main Menu > View all books" <<endl;
    cout <<"--------------------------" <<endl;
    cout <<" BOOKS\t\tPRICES\t\tCATEGORY  " <<endl;
    for(int i = 0; i < Book_Counter; i++)
    {
        cout << bookNamesA[i] << "\t\t" << bookPriceA[i] << "\t\t" << bookCatgA[i] <<endl;   
    }
}

void buyAnyBook()
{   //----Function Implemetation for buy any book from the list
    while(true)
    {
        system("cls");
        header();
        cout <<"Main Menu > Buy any book from the list" <<endl;
        cout <<"---------------------------------" <<endl;
        string name;
        int quan;
        cout <<"Enter the book name....";
        cin.ignore();
        getline(cin,name); //---calling getline function to add name with spaces
        for(char i = 0; i < Book_Counter; i++)
        {
            if(name == bookNamesA[i])
            {
                while(true)
                {
                    if(count >= 1)  //-----In the second or after second iteration of loop the following data print
                    {
                        header();
                        cout <<"Main Menu > Buy any book from the list" <<endl;
                        cout <<"---------------------------------" <<endl;
                        cout <<"Enter the book name...." << name <<endl;
                    }
                    cout << "Book price is " << bookPriceA[i] <<endl;
                    cout << "How many you want....";
                    cin >> quan;
                    count++;
                    if(quan > 100)
                    {
                        SetConsoleTextAttribute(h,4);
                        cout << "You cannot buy more than 100 books" <<endl;
                        cout << "Press any key to continue...";
                        getch();
                        SetConsoleTextAttribute(h,15);
                        system("cls");
                        continue;
                    }
                    if(quan < 0)
                    {
                        SetConsoleTextAttribute(h,4);
                        cout << "You can't enter price in negative" <<endl;
                        cout << "Press any key to continue" <<endl;
                        getch();
                        SetConsoleTextAttribute(h,15);
                        system("cls");
                        continue;
                    }
                    pBook = quan*bookPriceA[i];
                    break;
                }
            }
        }
        cout << "You have to pay...." <<pBook <<endl;
        SetConsoleTextAttribute(h,2);
        cout << "Thank You for shoping" <<endl;
        SetConsoleTextAttribute(h,15);
        break;
    }
}

char MagazineNewspaper()
{   //----Function Implemetation for Magazines & newspaper menu
    cout << "Main Menu > Magazines and Newspaper" <<endl;
    cout << "----------------------------------------" <<endl;
    cout << "1. View Magazines......." <<endl;
    cout << "2. View Newspapers......" <<endl;
    cout << "3. Back" <<endl;
    char opt3;
    cout << "Your Option...";
    cin >> opt3;
    return opt3;
}

void giveFeedback()
{   //----Function Implemetation for taking feedback
    cout << "Main Menu > Enter your feedback" <<endl;
    cout << "-------------------------------" <<endl;
    cout << "Add your feedback...";
    cin.ignore();
    getline(cin,feedback);
}

int Largest(int s)
{   //----Function Implemetation for sorting data in the parallel array array
    int largest = -1;
    int idx;
    for(int i = s; i < Book_Counter; i++)
    {
        if(largest < bookPriceA[i])
        {
            largest = bookPriceA[i];
            idx = i;
        }
    }
    return idx;
}

void LoadData()
{   //----Function Implemetation for load data into the array
    string UserPass; // for temporary store data from file
    fstream newfile; // declare file variable
    newfile.open("UserPass.txt", ios::in); // read data from file
    while(!newfile.eof())
    {
        getline(newfile,UserPass); // getline is used for getting info with spaces
        User_NamesA[User_Counter] = parseData(UserPass,1); // for store data into the Usernames rray with parse data function
        PasswordsA[User_Counter] = parseData(UserPass,2);  // for store data into the passwords array with parse data function
        User_Counter++; // for every iteration data store in the next index of array
    }
    newfile.close(); // for closing file
    
    string line; // for temporary store data from file
    fstream file; // declare file variable
    file.open("BooksData.txt", ios::in); // read data from file
    while(!file.eof())
    {
        getline(file,line); // getline is used for getting info with spaces
        bookNamesA[Book_Counter] = parseData(line,1); // for store data into the books names array with parse data function
        string a; // for temporary store data
        a = parseData(line,2); // for store data into the books names array with parse data function
        bookPriceA[Book_Counter] = stoi(a); // stoi is used because sometimes function ',' into the aaray
        bookCatgA[Book_Counter] = parseData(line,3); // for store data into the books names array with parse data function
        Book_Counter++; // for every iteration data store in the next index of array
    }
    file.close(); // for closing file

    string magazine; // for temporary store data from file
    fstream magazinefile; // declare file variable
    magazinefile.open("Magazines.txt", ios::in); // read data from file
    while(!magazinefile.eof())
    {
        getline(magazinefile,magazine); // getline is used for getting info with spaces
        magazinesA[magazines_Counter] = magazine; // for store data into the magazines array with parse data function
        magazines_Counter++; // for every iteration data store in the next index of array
    }
    magazinefile.close(); // for closing data

    string newsPaper; // for temporary store data from file
    fstream newspaperfile; // declare file variable
    newspaperfile.open("Newspaper.txt", ios::in); // read data from file
    while(!newspaperfile.eof())
    {
        getline(newspaperfile,newsPaper); // getline is used for getting info with spaces
        newspaperA[newspaper_counter] = newsPaper; // for store data into the newspaper array with parse data function
        newspaper_counter++; // for every iteration data store in the next index of array 
    }
    newspaperfile.close(); // for closing data

    string notice; // for temporary store data from file
    fstream noticefile; // declare file variable
    noticefile.open("Notices.txt", ios::in); // read data from file
    while(!noticefile.eof())
    {
        getline(noticefile,notice); // getline is used for getting info with spaces
        noticeA[Notice_Counter] = notice; // for store data into the notices array with parse data function
        Notice_Counter++; // for every iteration data store in the next index of array
    }
    noticefile.close(); // for closing data
}

string parseData(string line,int field)
{   //----Function Implemetation for comma separation
    int commaCount = 1;
    string item;
    for(int i = 0; i < line.length(); i++)
    {
        if(line[i] == ',')
        {
            commaCount++; // if ',' found, it add one in variable of commaCount
        }
        else if(field == commaCount)
        {
            item = item + line[i]; // this codition will add all the characters of the required field in the item Variable
        }
    }
    return item;
}

void storeData()
{
    fstream file; // declare file variable
    file.open("BooksData.txt", ios::out); // data from the arrays add into the file
    for( int i = 0; i < Book_Counter; i++)
    {   // it will add data with commas in order to extract data with comma separation function
        file << bookNamesA[i] << "," << bookPriceA[i] <<"," << bookCatgA[i] << "," ;
        if ( i < Book_Counter-1)
        {
            file << endl;
        }
    }
    file.close(); // for closing file

    fstream noticefile; // declare file variable
    noticefile.open("Notices.txt", ios::out); // data from the arrays add into the file
    for(int j = 0; j < Notice_Counter; j++)
    {
        if(noticeA[j] != "/0") //If array is not empty it will add its data into the array
        {
            noticefile << noticeA[j] <<endl;
        }
    }
    noticefile.close(); // for closing file

    fstream magazinefile; // declare file variable
    magazinefile.open("Magazines.txt", ios::out); // data from the arrays add into the file
    for(int k = 0; k < magazines_Counter; k++)
    {
        if(magazinesA[k] != "/0") //If array is not empty it will add its data into the array
        {
            noticefile << magazinesA[k] <<endl;
        }
    }
    magazinefile.close(); // for cloasing file

    fstream newspaperfile; // declare file variable
    newspaperfile.open("Newspaper.txt", ios::out); // data from the arrays add into the file
    for(int l = 0; l < newspaper_counter; l++)
    {
        if(newspaperA[l] != "/0") //If array is not empty it will add its data into the array
        {
            newspaperfile << newspaperA[l] <<endl;
        }
    }
    newspaperfile.close(); // for closing file
}

void addDiscount()
{   //-----Function Implementation for discount purpose
    cout << "Main Menu > Add discount on a particular Book" <<endl;
    cout << "---------------------------------------------" <<endl;
    cout << "Enter Book Name...";
    string name;
    cin.ignore();
    getline(cin,name);
    float disc;
    float newPrice;
    for(int i = 0; i < Book_Counter; i++)
    {
        if(name == bookNamesA[i])
        {
            cout << "Book original price is " << bookPriceA[i] <<endl; 
            cout << "Enter the discount in percentage...";
            cin >> disc;
            newPrice = bookPriceA[i]-disc/100.00*bookPriceA[i];
            bookPriceA[i] = newPrice;
            cout << "Book new price is..." << bookPriceA[i] <<endl;
            break;
        }
        else if(i == Book_Counter-1)
        {
            SetConsoleTextAttribute(h,4);
            cout << "We do not have such book" <<endl;
            SetConsoleTextAttribute(h,15);
        }
    }
}

//----------------------------------Functions Implementation End