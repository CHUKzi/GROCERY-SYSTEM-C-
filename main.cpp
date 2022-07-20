//DeV BY ROYAN HARSHA
//C++ Grocery System V.1.0
//©2022 Alex Lanka Developers All Rights Reserved
//https://alexlanka.com/projects/
//https://alexlanka.com/

#include <iostream>
#include <ctime>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <cstdlib>

using namespace std;

//DECLARE COLORS
const int BLUE = 1;
const int GREEN = 2;
const int RED = 4;
const int WHITE = 15;
const int BLUE2 = 11;
const int GREEN2 = 10;
const int RED2 = 12;
const int ORAN = 13;
const int YELLOW = 14;
//POSITION FUNCTION
void position(int x, int y)
{
	COORD d;
	d.X = x;
	d.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), d);
}

//COLOR FUNCTION
void changeColour(int colour) {
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, colour);
}

//CHOOSE OPTION CLASS
class option_bar {
public :
    int select;
    string String_select;
};
//CHAR DATA TYPE STYLING CLASS
class STYLING {
public :
    int h_long=0;
    char code=0;
    //ICONS
    char heart=3;
    char cart=234;
    char sub_title=175;
    char suc=251;
};
//DISPLAY SUCCESS MESSAGE CLASS
class success {
  public:
    void success_mg() {
      cout << "\t\t\t\t Your Cart is Updating... Please Wait ";
    }
    void success_mg_info() {
      cout << "\t\t\t\t\t Your information is processing... ";
    }
    void success_mg_pay() {
      cout << "\t\t\t\t\t   Check in Payment Details... ";
    }
    void success_mg_pay_suc() {
      cout << "\t\t\t\t\t  Payment has been successfully!!";
    }
};
//DISPLAY ERRORS CLASS
class error : public success {
  public:
    //INVALID INPUTS
    void error_mg() {
      cout << "\t\t\t\t Your input is invalid, Please try again ";
    }
    //CART FULL WORNING
    void error_mg2() {
      cout << "\t\t\t Your is cart full of this time (50/50), redirecting again ";
    }
    //INVALID PRODUCT NUMBERS
    void error_mg3() {
      cout << "\t\t\t\t Check Product Your Number And try again ";
    }
    //CART EMPTY WITH TRY TO BUY
    void error_mg_buy() {
      changeColour(RED);
      cout << "\t\t\t\t\t\tYou have nothing to buy ";
      changeColour(WHITE);
    }
    void error_mg_age() {
      changeColour(RED);
      cout << "\t\t\t\t\t    Your age is not enough :( ";
      changeColour(WHITE);
    }
};
//PRODUCTS AND PRICES CLASS
class Item
{
    public:
        string name;
        string weight;
        float price=NULL;
        float total_amount=NULL;
        float tax_amount=NULL;
        float final_total_amount=NULL;
};
//TAX AND OTHER CHARGES
class other_charges
{
    public:
        float d_tax=5;
};
//GET USER EARLIE PAGE NUMBER
class set_earli_product
{
    public:
        int num=NULL;
};
//PAYMENT CLASS
class check_out_info
{
    public:
        string name;
        string email;
        string address;
        string city;
        unsigned long long int contact_num=NULL;
        string card_type;
        string card_holder_name;
        unsigned long long int card_number=NULL;
        int card_ex_month=NULL;
        int card_ex_year=NULL;
        int card_cvn=NULL;
        string p_email;
        string P_password;
        unsigned long long int ez_number=NULL;
        int ez_pin=NULL;
};

//DECLARE IMPOTEN FUNCTIONS
string wc;
int wc_show=0;
void Header();
void Cart();
void category();
void option_bar1();
void product(int product);
int cart_count=0;
string name[50];
string weight[50];
float price[50];
int qty[50];
int userage=NULL;
Item total;
STYLING icon;
other_charges dili_charg;
check_out_info pay_products;
//GET PROFILE USER NAME
char* userprofile = std::getenv("USERPROFILE");

//SPECIAL FUNCTIONS
//GET TIME
void Date_Time()
{
   time_t now = time(0);
   char* dt = ctime(&now);
   cout << "\t\t\t\t\t\t    DATE & TIME : " << dt << endl;
}

//GET CURRENT HOUR
const string currentDateTime() {

    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%H", &tstruct);//%Y-%m-%d.
    return buf;
}
//SET WELCOME MASSAGE
void wc_user(){
    string hour;
    hour=currentDateTime();
    //cout<<hour;
    if(hour=="00"||hour=="01"||hour=="02"||hour=="03"||hour=="04"||hour=="05"||hour=="06"||hour=="07"||hour=="08"||hour=="09"||hour=="10"||hour=="11"){
        wc="Good Morning,";
    } else if (hour=="12"||hour=="13"||hour=="14"||hour=="15"||hour=="16"){
        wc="Good Afternoon,";
    } else {
        wc="Good Evening,";
    }
}
//LOAD SCREEN FUNCTION
void load()
{
	char a = 219;
	position(52, 8);
	cout << "Loading..."<< endl;
	position(26,10);
	changeColour(BLUE);
	for(int r =1; r<=60; r++)
	{
		for(int q=0; q<=10000000; q++);
		cout << a;
	}
	changeColour(WHITE);
    cout << ""<< endl;
    system ("CLS");
}
//DOWNLOAD SCREEN FUNCTION
void download()
{
	char a = 219;
	position(51, 8);
	cout << "Downloading..."<< endl;
	position(27,10);
	changeColour(GREEN2);
	for(int r =1; r<=60; r++)
	{
		for(int q=0; q<=60000000; q++);
		cout << a;
	}
	changeColour(WHITE);
    cout << ""<< endl;
    system ("CLS");
}
//HOME SCREEN FUNCTION
class Home {
  public:
    Home()
    {
        load();
        Header();
        Cart();
        //SHOW THIS MESSAGE ONLY ONE TIME
        if (wc_show==0){
            changeColour(ORAN);
            wc_user();
            cout <<"\t\t"<< wc <<" Welcome To Sl Online Grocery !!\n\n" << endl;
            wc_show++;
        }
        changeColour(BLUE2);
        cout << "\t\t\t\t\t    <<<<- Home Page ->>>>\n" << endl;
        changeColour(WHITE);
        category();
        option_bar1();
    }
};
//USER EARLIE PRODUCT
class USER_EARLIE_PRODUCT_PAGE
{
public:
    void set_earlie(int user_earlie_page)
    {
    load();
    Header();
    Cart();
    product(user_earlie_page);
    }
};
//OPTION BAR FUNCTION
void choose_option_bar(int add_new_option)
{
    //STYLE
    STYLING footer;
    footer.h_long;
    footer.code=22;

    cout << "\n\t\t";
    changeColour(YELLOW);
    while (footer.h_long < 76) {cout << footer.code; footer.h_long++;}
    cout << endl;
    changeColour(BLUE2);
    //HOME OPTION BAR
    if (add_new_option==1){
        cout << "\t\t\tMY CART=[91]\t\tABOUT US=[97]\t\t";
        changeColour(RED2);
        cout << "EXIT=[98]"<< endl;
    }
    //PRODUCT PAGE BAR
    if (add_new_option==2){
        cout << "\t\t\tMY CART=[91]\t\tHOME PAGE=[100]\t\t";
        changeColour(RED2);
        cout << "EXIT=[98]"<< endl;
    }
    //ADD TO CART PAGE BAR
    if (add_new_option==3){
        cout << "\t\t\tMY CART=[91]\t\tADD TO CART=[90]\t\tBACK=[99]\n\t\t\t\t\tHOME PAGE=[100]\t\t";
        changeColour(RED2);
        cout << "EXIT=[98]"<< endl;
    }
    //CART PAGE BAR *IF EMPTY CART
    if (add_new_option==4){
        if (cart_count>0){
            cout << "\t\t   CHECKOUT=[90]\t\tCHANGE QUANTITY=[91]\tREMOVE PRODUCT=[92]\n\t\t   CLEAR CART=[95]\t\tHOME PAGE=[100]\t\t ";
        changeColour(RED2);
        cout << "EXIT=[98]"<< endl;
        //*IF NOT
        } else {
            cout << "\t\t\t\tHOME PAGE=[100]\t\t\t";
        changeColour(RED2);
        cout << "EXIT=[98]"<< endl;
        }
    }
    //PAYMENT METHOD PAGE BAR
    if (add_new_option==5){
    changeColour(RED2);
    cout << "\t\t\tCANCEL=[98]"<< endl;
    }
    //MY BILL PAGE BAR
    if (add_new_option==6){
    changeColour(GREEN2);
    cout << "\t\t\tDOWNLOAD MY BILL=[97]"<< endl;
    }
    //DOWNLOAD PAGE BAR AND ABOUT US PAGE
    if (add_new_option==7){
    cout << "\t\t\t\t  HOME PAGE=[100]\t\t";
    changeColour(RED2);
    cout << "EXIT=[98]"<< endl;

    }
    changeColour(WHITE);

}
//EXIT PAGE FUNCTION
void exit()
    {
    Header();
    cout << "\n\n\n\n\t\t\t\t\t   Thanks for being with us "<< icon.heart <<"\n\n\n\n" << endl;

    STYLING footer7;
    footer7.h_long;
    footer7.code=22;

    cout << "\t\t";
    changeColour(YELLOW);
    while (footer7.h_long < 76) {cout << footer7.code; footer7.h_long++;}
    cout << endl;

    changeColour(ORAN);
    cout << "\t\t\t\t@2021 Alex Lanka Developers All Rights Reserved" << endl;


    STYLING footer8;
    footer8.h_long;
    footer8.code=22;

    cout << "\t\t";
    changeColour(YELLOW);
    while (footer8.h_long < 76) {cout << footer8.code; footer8.h_long++;}
    changeColour(WHITE);
    cout << endl;
    cout << "\t\tPress any key to continue exit...";
    getch();
    }
//ABOUT US PAGE
void about()
        {
    load();
    Header();
    changeColour(BLUE2);
    cout << "\n\t\t\t\t\t  <<<<- About Us Page ->>>>\n" << endl;
    changeColour(WHITE);
    cout <<"\n\t\t"<< wc <<" Welcome to SL Online grocery, your number one source for all\n\t\tthings grocery products. We're dedicated to providing you the very best of\n\t\tproduct.\n\n" << endl;
    cout <<"\t\tFounded in 2021 by Alex Lanka Royan Harsha, SL Online grocery has come a\n\t\tlong way from its beginnings in Colombo 7. When Alex Lanka first started\n\t\tout, his passion for cleaning grocery products drove them to start their \n\t\town business.\n\n" << endl;
    cout <<"\t\tWe hope you enjoy our products as much as we enjoy offering them to you.\n\t\tIf you have any questions or comments, please don't hesitate to contact us.\n\n\t\tSincerely,\n\t\tRoyan Harsha" << endl;

    choose_option_bar(7);

    option_bar option18;

    STYLING footer5;
    footer5.h_long;
    footer5.code=22;

    cout << "\t\t";
    changeColour(YELLOW);
    while (footer5.h_long < 76) {cout << footer5.code; footer5.h_long++;}
    changeColour(WHITE);
    cout << endl;
    cout << "\t\tchoose : ";
    cin >> option18.select;
    //HOME PAGE REDIRACTION
    if (option18.select==100){
        system("cls");
        Home home_page;
    //EXIT PAGE REDIRACTION
    } else if (option18.select==98){
        system ("CLS");
        exit();
    //ELSE WITH REDIRACTION
    }
}
//COUNT BILL FUNCTION
void my_bill()
    {
        int c1=40, c2=13,c3=7,p_num = 1;
        total.total_amount=0;
        for (int i = 0; i <cart_count;i++){
            total.total_amount=total.total_amount+qty[i]*price[i];
            std::cout<<"\t\t "<< p_num <<") " << std::setw(c1) << name[i] << std::left << std::setw(c2) << weight[i] << std::setw(c3) << qty[i] << "Rs."<< qty[i]*price[i] << endl;
            p_num++;
        }
        //COUNT DILIVERY CHARGES
        total.tax_amount=total.total_amount/100*dili_charg.d_tax;
        total.final_total_amount=total.tax_amount+total.total_amount;
        //FINAL TOTAL
        cout<<"\t\t\t\t\t\t\t\t\t___________________"<<endl;
        std::cout<<"\t\t > " << std::setw(c1) << "Delivery charges" << std::left << std::setw(c2) << "" << std::setw(c3) << "" << "Rs."<< total.tax_amount <<" ("<< dili_charg.d_tax <<"%)"<< endl;
        cout<<"\t\t\t\t\t\t\t\t\t___________________"<<endl;
        std::cout<<"\t\t > " << std::setw(c1) << "Total amount " << std::left << std::setw(c2) << "" << std::setw(c3) << "" << "Rs."<< total.final_total_amount << endl;
        cout<<"\t\t\t\t\t\t\t\t\t==================="<<endl;
    }
//CHECKOUT FUNCTION
class checkout {
  public:
    checkout()
    {
        load();
        Header();
        changeColour(BLUE2);
        cout << "\t\t\t\t\t  <<<<- Payment Method ->>>>\n" << endl;
        changeColour(WHITE);

        cout << "\n\t\t"<< icon.sub_title << " Supported payment methods" << endl;
        cout << "\t\t\t\t[1] Master Card"<< endl;
        cout << "\t\t\t\t[2] Visa Card"<< endl;
        cout << "\t\t\t\t[3] Pay Pal"<< endl;
        cout << "\t\t\t\t[4] eZ Cash\n"<< endl;

        int c1=40, c2=13,c3=7;
        cout<<"\t\t\t\t\t\t\t\t\t___________________"<<endl;
        std::cout<<"\t\t > " << std::setw(c1) << "Total amount to be paid" << std::left << std::setw(c2) << "" << std::setw(c3) << "" << "Rs."<< total.final_total_amount << endl;
        cout<<"\t\t\t\t\t\t\t\t\t==================="<<endl;

        choose_option_bar(5);

        option_bar option13;

        STYLING footer2;
        footer2.h_long;
        footer2.code=22;

        cout << "\t\t";
        changeColour(YELLOW);
        while (footer2.h_long < 76) {cout << footer2.code; footer2.h_long++;}
        changeColour(WHITE);
        cout << endl;
        cout << "\t\tchoose : ";
        cin >> option13.select;

        STYLING footer3;
        footer3.h_long;
        footer3.code=22;

        cout << "\t\t";
        while (footer3.h_long < 76) {cout << footer3.code; footer3.h_long++;}
        cout << endl;
        //GET USER SELECTED PAYMET METHOD
        if(option13.select==1){
            pay_products.card_type="Master Card";
        } else if (option13.select==2) {
            pay_products.card_type="Visa Card";
        }  else if (option13.select==3) {
            pay_products.card_type="pay Pal";
        } else if (option13.select==4) {
            pay_products.card_type="eZ Cash";
        }  else if (option13.select==98) {
            system ("CLS");
            Home home_page;
        } else {
            system("cls");
            for(int i=3;i>0;i--)
            {
                position(2,6);
                error error2;
                error2.error_mg();
                cout<<i;
                cout << " second(s)";
                Sleep(1000);
            }
        system("cls");
        Home home_page;
        }
        //MASTER CARD OR VISA CARD
        if (option13.select==1||option13.select==2){

            cout << "\t\t Pay with "<<pay_products.card_type<<endl;

            cout << "\t\t\tCard holder name: ";
            cin >> pay_products.card_holder_name;
            cout << "\t\t\tCard Number : ";
            cin >> pay_products.card_number;
            cout << "\t\t\tCard expiry year : ";
            cin >> pay_products.card_ex_year ;
            cout << "\t\t\tCard expiry Month : ";
            cin >> pay_products.card_ex_month;
            cout << "\t\t\tCard CVN  : ";
            cin >> pay_products.card_cvn;

        }
        //PAY PAL
        if (option13.select==3) {
            cout << "\t\t Pay with "<<pay_products.card_type<<endl;

            cout << "\t\t\tEmail OR Mobile Number : ";
            cin >> pay_products.p_email;
            cout << "\t\t\tPassword : ";
            cin >> pay_products.P_password;

        }
        //eZ CASH
        if (option13.select==4) {
            cout << "\t\t Pay with "<<pay_products.card_type<<endl;

            cout << "\t\t\tMobile Number/Alias : ";
            cin >> pay_products.ez_number;
            cout << "\t\t\tPIN : ";
            cin >> pay_products.ez_pin;
        }

        STYLING footer4;
        footer4.h_long;
        footer4.code=22;

        cout << "\t\t";
        while (footer4.h_long < 76) {cout << footer4.code; footer4.h_long++;}
        cout << endl;
        //CONFIRMED INFO
        option_bar option4;
        changeColour(RED2);
        cout << "\t\tIs the information you entered true? [Y]es OR [N]o : ";
        changeColour(WHITE);
        cin >> option4.String_select;
        system("cls");
        //IF *YES
        if (option4.String_select=="y"||option4.String_select=="Y"){
        //CHECKING CUSTOMER INFO
            for(int i=3;i>0;i--)
                {
                    position(2,6);
                    success success1;
                    success1.success_mg_info();
                    Sleep(1000);
                }
                system("cls");
        //CHECKING PAYMENT INFO
            for(int i=3;i>0;i--)
                {
                    position(2,6);
                    success success2;
                    success2.success_mg_pay();
                    Sleep(1000);
                }
                system("cls");
        //SHOW SUCCSESS MESSAGE
            for(int i=3;i>0;i--)
                {
                    position(2,6);
                    success success2;
                    success2.success_mg_pay_suc();
                    Sleep(1000);
                }
        //SHOW BILL
                a:
                system("cls");
                Header();
                changeColour(BLUE2);
                cout << "\t\t\t\t\t    <<<<- My Bill ->>>>\n" << endl;
                changeColour(WHITE);

                Date_Time();
                cout << "\t\tCustomer Name           : "<< pay_products.name<<endl;
                cout << "\t\tCustomer Address        : "<< pay_products.address<<", "<< pay_products.city <<endl;
                cout << "\t\tCustomer E-mail         : "<< pay_products.email<<endl;
                cout << "\t\tCustomer contact number : "<< pay_products.contact_num<<endl;

                STYLING footer2;
                footer2.h_long;
                footer2.code=4;

                cout << "\t\t";
                while (footer2.h_long < 76) {cout << footer2.code; footer2.h_long++;}
                cout << endl;
                cout << "\n\t\tPayment method : "<< pay_products.card_type<<"\n"<<endl;

                my_bill();
                STYLING footer3;
                footer3.h_long;
                footer3.code=4;

                cout << "\t\t";
                while (footer3.h_long < 76) {cout << footer3.code; footer3.h_long++;}
                cout << endl;
                cout << "\n\t\tDelivery status : Pending \n"<<endl;
                cout << "\n\t\t48 hour delivery, Thanks for being with us"<<endl;
        //END BILL
                choose_option_bar(6);

                option_bar option17;

                STYLING footer4;
                footer4.h_long;
                footer4.code=22;

                cout << "\t\t";
                changeColour(YELLOW);
                while (footer4.h_long < 76) {cout << footer4.code; footer4.h_long++;}
                changeColour(WHITE);
                cout << endl;
                cout << "\t\tchoose : ";
                cin >> option17.select;
        //*IF GENARATED DOWNLODING BILL
                if (option17.select==97){
                    system("cls");
                    download();

                    string file_name_with_path;
                    file_name_with_path = "\\Downloads\\SL-ONLINE-GROCERY-MY-BILL.html";

                    ofstream my_gen_bill;
                    my_gen_bill.open (userprofile+file_name_with_path);
                    my_gen_bill << "<html><head></head><title>SL ONLINE GROCERY- My BILL</title><body style='padding-left:34px'><div style='font-family:Segoe UI Light;font-size: 20.0pt;padding-bottom:34px;'><u>SL ONLINE GROCERY</u></div>";
                    my_gen_bill << "<table><tr><td>Customer Name</td><td> : </td><td>"<<pay_products.name<<"</td></tr>";
                    my_gen_bill << "<tr><td>Customer Address</td><td> : </td><td>"<<pay_products.address<<", "<< pay_products.city<<"</td></tr>";
                    my_gen_bill << "<tr><td>Customer E-mail</td><td> : </td><td>"<<pay_products.email<<"</td></tr>";
                    my_gen_bill << "<tr><td>Customer contact number</td><td> : </td><td>"<<pay_products.contact_num<<"</td></tr>";
                    my_gen_bill << "<td colspan='3'>";
                    my_gen_bill << "<tr><td>Payment method</td><td> : </td><td>"<<pay_products.card_type<<"</td></tr></table><br>";
                    my_gen_bill << "<table width='760' border='1px' frame='void' rules='groups'><tr style='font-family:sans-serif'><td width='3%' height='30px' valign='top'>#</td><td  width='70%' height='30px' valign='top'>Product name</td><td width='10%' height='30px' valign='top'>Weight</td><td width='10%' height='30px' valign='top'>Quantity</td><td width='10%' height='30px' valign='top'>Total</td></tr>";
                    my_gen_bill << "<tbody style='font-family:sans-serif'><tr><td height='10px' colspan='3'></tr>";
                    //START COUNT BILL
                    int c1=40, c2=13,c3=7,p_num = 1;
                    total.total_amount=0;
                    for (int i = 0; i <cart_count;i++){
                            total.total_amount=total.total_amount+qty[i]*price[i];

                                my_gen_bill << "<tr><td>"<<p_num<<"</td><td>"<< name[i]<<"</td><td>"<<weight[i]<<"</td><td>"<<qty[i]<<"</td><td>"<<"Rs."<< qty[i]*price[i]<<"</td></tr>";
                    p_num++;
                    }
                    total.tax_amount=total.total_amount/100*dili_charg.d_tax;
                    total.final_total_amount=total.tax_amount+total.total_amount;

                    my_gen_bill << "<tr><td>"<<">"<<"</td><td>"<<"Delivery charges"<<"</td><td>"<<"-"<<"</td><td>"<<"-"<<"</td><td>"<<"Rs."<< total.tax_amount<<"("<< dili_charg.d_tax <<"%)</td></tr>";
                    my_gen_bill << "<tr><td>"<<""<<"</td><td>"<<""<<"</td><td>"<<""<<"</td><td>"<<""<<"</td><td>	___________</td></tr>";
                    my_gen_bill << "<tr><td>"<<">"<<"</td><td>"<<"Total amount"<<"</td><td>"<<""<<"</td><td>"<<""<<"</td><td>"<<"Rs."<< total.final_total_amount <<"</td></tr>";

                    my_gen_bill << "</tbody></table><br><br>";
                    //END
                    time_t now = time(0);
                    char* dt = ctime(&now);

                    my_gen_bill << "<table><tr><td>DATE & TIME</td><td> : </td><td>"<<dt<<"</td></tr>";
                    my_gen_bill << "<tr><td colspan='3'></tr>";
                    my_gen_bill << "<tr><td>Delivery Status</td><td> : </td><td>Pending</td></tr>";
                    my_gen_bill << "<tr><td>Bill issued bY</td><td> : </td><td>System</td></tr>";
                    my_gen_bill << "</table><br><hr><p>@2021 Alex Lanka Developers All Rights Reserved</p></div></body></html>";
                    my_gen_bill << "<!--DeV BY ROYAN HARSHA-->";
                    my_gen_bill.close();

                //CLEAR CART
                    for (int i = 0; i <cart_count;i++){
                        name[i]= {};
                        weight[i]={};
                        price[i]=NULL;
                        qty[i]=NULL;
                    }
                    cart_count=0;
                    b:
                    Header();
                    cout << "\n\n\n\n\t\t\t\t\t     Download successful "<<icon.suc <<"\n" << endl;
                    changeColour(GREEN2);
                    cout << "\t\t\t\t\tPlease Check Your Download Folder\n\n\t\t     ( "<<userprofile+file_name_with_path<<" )\n\n\n\n" << endl;
                    changeColour(WHITE);
                    choose_option_bar(7);

                    option_bar option18;

                    STYLING footer5;
                    footer5.h_long;
                    footer5.code=22;

                    cout << "\t\t";
                    changeColour(YELLOW);
                    while (footer5.h_long < 76) {cout << footer5.code; footer5.h_long++;}
                    changeColour(WHITE);
                    cout << endl;
                    cout << "\t\tchoose : ";
                    cin >> option18.select;
            //HOME PAGE REDIRACTION
                    if (option18.select==100){
                        system("cls");
                        Home home_page;
            //EXIT PAGE REDIRACTION
                    } else if (option18.select==98){
                        system ("CLS");
                        exit();
            //ELSE WITH REDIRACTION
                    } else {
                    system ("CLS");
                    for(int i=3;i>0;i--)
                    {
                        position(2,6);
                        error error6;
                        error6.error_mg();
                        cout<<i;
                        cout << " second(s)";
                        Sleep(1000);
                    }
                    system("cls");
                    load();
                    goto b;
                    }

                } else {
                    system ("CLS");
                    for(int i=3;i>0;i--)
                    {
                        position(2,6);
                        error error3;
                        error3.error_mg();
                        cout<<i;
                        cout << " second(s)";
                        Sleep(1000);
                    }
                    system("cls");
                    load();
                    goto a;
                }

            } else if (option4.String_select=="n"||option4.String_select=="N") {
                system("cls");
                checkout checkout_page;

            } else {
                system ("CLS");
                for(int i=3;i>0;i--)
                {
                    position(2,6);
                    error error3;
                    error3.error_mg();
                    cout<<i;
                    cout << " second(s)";
                    Sleep(1000);
                }
                system("cls");
                checkout checkout_page;
            }

        }
    };

//MY CART UPDATE CLASS
class mycart
{
public:
    void mycart_item(string item_name,string item_weight,float item_price,int item_qty,int buy_page_earlie)
    {
        //IF NOT *CART HAS 50 PRODUCTS WITH DO THIS
        if (cart_count!=50){
            name[cart_count]=item_name;
            weight[cart_count]=item_weight;
            price[cart_count]=item_price;
            qty[cart_count]=item_qty;

            cart_count++;

            system("cls");
        //UPDATING MESSAGE
            for(int i=3;i>0;i--)
            {
                position(2,6);
                success success1;
                success1.success_mg();
                cout<<i;
                cout << " second(s)";
                Sleep(1000);
            }
            system("cls");
            load();
            Header();
            Cart();
        //USER REDIRECT IN TO EARLIE PAGE
            product(buy_page_earlie);
        } else {
                system("cls");
                for(int i=3;i>0;i--)
                {
                    position(2,6);
                    cout << "\t\t\t\t\t\t\tWARNING\n" << endl;
                    error error_limited;
                    error_limited.error_mg2();
                    cout<<i;
                    cout << " second(s)";
                    Sleep(1000);
                }
                system("cls");
                load();
                Header();
                Cart();
                product(buy_page_earlie);
            }
        }
    //SHOW MY CART
    void show_my_cart()
        {
        system("cls");
        load();
        Header();
        Cart();
        changeColour(BLUE2);
        cout << "\t\t\t\t\t    <<<<- My Cart ->>>>\n" << endl;
        changeColour(WHITE);
    //IF *CART IS EMPTY
        if (cart_count==0){
            cout << "\n\t\t\t\t\t\tEmpty Cart\n\n" <<endl;
    //IF *NOT
        } else {
            my_bill();
        }

        choose_option_bar(4);

        option_bar option6;

        STYLING footer2;
        footer2.h_long;
        footer2.code=22;

        cout << "\t\t";
        changeColour(YELLOW);
        while (footer2.h_long < 76) {cout << footer2.code; footer2.h_long++;}
        changeColour(WHITE);
        cout << endl;
        cout << "\t\tchoose : ";
        cin >> option6.select;

        //REDIRECT HOME PAGE
        if (option6.select==100){
            system("cls");
            Home home_page;

        //REDIRECT EXIT PAGE
        } else if (option6.select==98){
            system ("CLS");
            exit();

        //CHNAGE PRODUCT QUANTITY
        } else if (option6.select==91){
            option_bar option7;
            cout << "\t\tEnter Product Number : ";
            cin >> option7.select;

            //IF *CART COUNT AS BETWEEN, USER SELECTTION DOES
            if(option7.select<=cart_count) {
                option7.select--;
                int c1=40, c2=15,c3=10;
                std::cout<< "\n\t\t"<< std::setw(c1) << name[option7.select] << std::left << std::setw(c2) << weight[option7.select] << std::setw(c3) << qty[option7.select] << "Rs."<< qty[option7.select]*price[option7.select] << endl;

                STYLING footer3;
                footer3.h_long;
                footer3.code=22;
                cout << "\t\t";
                while (footer3.h_long < 76) {cout << footer3.code; footer3.h_long++;}
                cout << endl;

                option_bar option8;
                cout << "\t\tEnter New Quantity : ";
                cin >> option8.select;
                qty[option7.select]=option8.select;
                system("cls");
                //CHANGE IS UPDATING MESSAGE
                for(int i=3;i>0;i--)
                {
                    position(2,6);
                    success success1;
                    success1.success_mg();
                    cout<<i;
                    cout << " second(s)";
                    Sleep(1000);
                }
            system("cls");
            mycart my_cart_details;
            my_cart_details.show_my_cart();
        //IF NOT
        } else {
            system ("CLS");
            for(int i=3;i>0;i--)
            {
                position(2,6);
                error error_limited;
                error_limited.error_mg3();
                cout<<i;
                cout << " second(s)";
                Sleep(1000);
            }
            system("cls");
            mycart my_cart_details;
            my_cart_details.show_my_cart();
            }
        //REMOVE PRODUCT
        } else if (option6.select==92){
            option_bar option9;
            cout << "\t\tEnter Product Number : ";
            cin >> option9.select;
            //IF *CART COUNT AS BETWEEN, USER SELECTTION DOES
            if(option9.select<=cart_count) {
                option9.select--;
                int c1=40, c2=15,c3=10;
                std::cout<< "\n\t\t"<< std::setw(c1) << name[option9.select] << std::left << std::setw(c2) << weight[option9.select] << std::setw(c3) << qty[option9.select] << "Rs."<< qty[option9.select]*price[option9.select] << endl;

                STYLING footer3;
                footer3.h_long;
                footer3.code=22;
                cout << "\t\t";
                while (footer3.h_long < 76) {cout << footer3.code; footer3.h_long++;}
                cout << endl;

                option_bar option2;
                changeColour(RED2);
                cout << "\t\tAre You sure you want to Remove? [Y]es OR [N]o : ";
                changeColour(WHITE);
                cin >> option2.String_select;
                system("cls");
                //IF SAY YES
                if (option2.String_select=="y"||option2.String_select=="Y"){
                    name[option9.select]={"[ REMOVED ]"};
                    weight[option9.select]={};
                    price[option9.select]=NULL;
                    qty[option9.select]=NULL;
                    for(int i=3;i>0;i--)
                    {
                        position(2,6);
                        success success1;
                        success1.success_mg();
                        cout<<i;
                        cout << " second(s)";
                        Sleep(1000);
                    }
                system("cls");
                mycart my_cart_details;
                my_cart_details.show_my_cart();
                //IF SAY NO
                } else if (option2.String_select=="n"||option2.String_select=="N") {
                    mycart my_cart_details;
                    my_cart_details.show_my_cart();
                //IT'S NOT
                } else {
                    system ("CLS");
                    for(int i=3;i>0;i--)
                    {
                        position(2,6);
                        error error3;
                        error3.error_mg();
                        cout<<i;
                        cout << " second(s)";
                        Sleep(1000);
                    }
                    system("cls");
                    mycart my_cart_details;
                    my_cart_details.show_my_cart();
                }

            }
            //IF NOT
            else {
            system ("CLS");
            for(int i=3;i>0;i--)
            {
                position(2,6);
                error error_limited;
                error_limited.error_mg3();
                cout<<i;
                cout << " second(s)";
                Sleep(1000);
            }
            system("cls");
            mycart my_cart_details;
            my_cart_details.show_my_cart();
        }
        //CLEAR CART
        } else if (option6.select==95){
            option_bar option3;
            changeColour(RED2);
            cout << "\t\tAre you Sure? [Y]es OR [N]o : ";
            changeColour(WHITE);
            cin >> option3.String_select;
            //IF SAY YES
            if (option3.String_select=="y"||option3.String_select=="Y"){
                for (int i = 0; i <cart_count;i++){
                name[i]= {};
                weight[i]={};
                price[i]=NULL;
                qty[i]=NULL;
            }
            cart_count=0;
            mycart my_cart_details;
            my_cart_details.show_my_cart();
            //IF SAY NO
            } else if (option3.String_select=="n"||option3.String_select=="N") {
                mycart my_cart_details;
                my_cart_details.show_my_cart();
            }
            //IF NOT
            else {
                system ("CLS");
            for(int i=3;i>0;i--)
                {
                    system("cls");
                    position(2,6);
                    error error2;
                    error2.error_mg();
                    cout<<i;
                    cout << " second(s)";
                    Sleep(1000);
                }
                system("cls");
                mycart my_cart_details;
                my_cart_details.show_my_cart();
            }
        }
        //CHECKOUT
        else if (option6.select==90){
            if(total.final_total_amount!=0){
                STYLING footer3;
                footer3.h_long;
                footer3.code=22;

                cout << "\t\t";
                while (footer3.h_long < 76) {cout << footer3.code; footer3.h_long++;}
                cout << endl;

                cout << "\t\t\tEnter Your First Name : ";
                cin >> pay_products.name;
                cout << "\t\t\tEnter Your Address : ";
                cin >> pay_products.address;
                cout << "\t\t\tEnter Your City : ";
                cin >> pay_products.city;
                cout << "\t\t\tEnter Your E-mail : ";
                cin >> pay_products.email;
                cout << "\t\t\tEnter Your Contact number : ";
                cin >> pay_products.contact_num;

                STYLING footer4;
                footer4.h_long;
                footer4.code=22;

                cout << "\t\t";
                while (footer4.h_long < 76) {cout << footer4.code; footer4.h_long++;}
                cout << endl;

                option_bar option4;
                changeColour(RED2);
                cout << "\t\tIs the information you entered true? [Y]es OR [N]o : ";
                changeColour(WHITE);
                cin >> option4.String_select;
                system("cls");

                //IF SAY YES
                if (option4.String_select=="y"||option4.String_select=="Y"){

                    for(int i=3;i>0;i--)
                        {
                            position(2,6);
                            success success1;
                            success1.success_mg_info();
                            Sleep(1000);
                        }
                    system("cls");
                    checkout checkout_page;

                //IF SAY NO
                } else if (option4.String_select=="n"||option4.String_select=="N") {
                    system("cls");
                    mycart my_cart_details;
                    my_cart_details.show_my_cart();
                //NOT
                } else {
                system ("CLS");
                for(int i=3;i>0;i--)
                    {
                        position(2,6);
                        error error2;
                        error2.error_mg();
                        cout<<i;
                        cout << " second(s)";
                        Sleep(1000);
                    }
                system("cls");
                mycart my_cart_details;
                my_cart_details.show_my_cart();
                }
            }
            //IF NOT BUY PRODUCTS
            else {
                system ("CLS");
                for(int i=3;i>0;i--)
                {
                    position(2,6);
                    error error1;
                    error1.error_mg_buy();
                    Sleep(1000);
                }
                system("cls");
                mycart my_cart_details;
                my_cart_details.show_my_cart();
            }
        }
        //IF ENTER INVALIED INPUTS
        else {
            system ("CLS");
            for(int i=3;i>0;i--)
                {
                    position(2,6);
                    error error2;
                    error2.error_mg();
                    cout<<i;
                    cout << " second(s)";
                    Sleep(1000);
                }
            system("cls");
            mycart my_cart_details;
            my_cart_details.show_my_cart();
        }
    }
};
//HEDER FUNCTION
void Header()
    {
        STYLING header;
        header.h_long;
        header.code=22;

        STYLING header2;
        header2.h_long;
        header2.code=22;

        changeColour(YELLOW);
        cout << "\t\t";
        while (header.h_long < 76) {cout << header.code; header.h_long++;}
        cout << endl;
        cout << "\t\t\t\t <<<< S L   O n l i n e   G r o c e r y >>>>" << endl;
        cout << "\t\t";
        while (header2.h_long < 76) {cout << header2.code; header2.h_long++;}
        cout << endl;
        changeColour(WHITE);
    }
//MY CART FUNCTION
void Cart()
    {
        changeColour(GREEN2);
        cout << "\t\t\t\t\t\t\t\t\t      "<<icon.cart<<" My Cart : "<< cart_count << endl;
        changeColour(WHITE);
    }
//PRODCT CATEGORY FUNCTION
void category()
    {
        cout << "\t\t"<<icon.sub_title<<" Product Category" << endl;
        //product list here
        cout << "\t\t\t [1] Fish & Meat" << endl;
        cout << "\t\t\t [2] Frozen Food" << endl;
        cout << "\t\t\t [3] Liquor & Tobacco" << endl;
        cout << "\t\t\t [4] Bakery" << endl;
        cout << "\t\t\t [5] Baby & Toddler" << endl;
        cout << "\t\t\t [6] Fresh Produce" << endl;
        cout << "\t\t\t [7] Groceries" << endl;
        cout << "\t\t\t [8] Household & Homecare" << endl;
        cout << "\t\t\t [9] Personal Care" << endl;
        cout << "\t\t\t [10] Pharma & Wellness" << endl;
    }
//ADD TO CART CLASS
class Item_Details
{
public:
    void add_item_data(int user_earlie_page,string item_name,string item_weight,float item_price)
    {
            load();
            Header();
            Cart();
            //cout << "item_num : "<<item_num<< endl;

            cout << "\t\t\t: "<<item_name<< endl;
            cout << "\t\t\t: "<<item_weight<< endl;
            cout << "\t\t\t: Rs."<<item_price<< endl;
            changeColour(BLUE2);
            cout << "\n\t\t\tADD TO CART=[90]\n"<< endl;
            changeColour(WHITE);

            choose_option_bar(3);

            option_bar option3;

            STYLING footer2;
            footer2.h_long;
            footer2.code=22;

            cout << "\t\t";
            changeColour(YELLOW);
            while (footer2.h_long < 76) {cout << footer2.code; footer2.h_long++;}
            changeColour(WHITE);
            cout << endl;
            cout << "\t\tchoose : ";
            cin >> option3.select;

            //REDIRECTION
            if (option3.select==100){
                system("cls");
                Home home_page;

            //REDIRECTION
            } else if (option3.select==98){
                system ("CLS");
                exit();

            //REDIRECTION
            } else if (option3.select==91){
                mycart my_cart_details;
                my_cart_details.show_my_cart();

            //REDIRECTION BACK OPTION
            } else if (option3.select==99) {
                system("cls");
                load();
                Header();
                Cart();
                product(user_earlie_page);

            //SELECT ADD TO CART OPTION
            } else if (option3.select==90) {
                option_bar option4;
                cout << "\t\tEnter Quantity : ";
                cin >> option4.select;

                //IF NOT NULL SELECTION
                //SHOW TOTAL PRICE
                if (option4.select !=NULL) {
                    changeColour(GREEN2);
                    cout<<"\t\tTotal amount you have to pay for this : Rs."<< item_price*option4.select<< endl;
                    changeColour(WHITE);

                    option_bar option5;
                    STYLING footer3;
                    footer3.h_long;
                    footer3.code=22;

                    cout << "\t\t";
                    while (footer3.h_long < 76) {cout << footer3.code; footer3.h_long++;}
                    cout << endl;
                    changeColour(RED2);
                    cout << "\t\tDo you want to add Cart ? [Y]es OR [N]o : ";
                    changeColour(WHITE);
                    cin >> option5.String_select;
                //IF SAY YES
                    if (option5.String_select=="y"||option5.String_select=="Y"){
                        mycart my_cart_details;
                        my_cart_details.mycart_item(item_name,item_weight,item_price,option4.select,user_earlie_page);
                //IF SAY NO
                    } else if (option5.String_select=="n"||option5.String_select=="N") {
                        system("cls");
                        load();
                        Header();
                        Cart();
                        product(user_earlie_page);
                    } else {
                        system("cls");
                        for(int i=3;i>0;i--)
                            {
                                position(2,6);
                                error error21;
                                error21.error_mg();
                                cout<<i;
                                cout << " second(s)";
                                Sleep(1000);
                            }
                        system("cls");
                        load();
                        Header();
                        Cart();
                        product(user_earlie_page);
                    }
                //INVALID REDIRECTION
                } else {
                    system("cls");
                    load();
                    Header();
                    Cart();
                    product(user_earlie_page);
                }
            //INVALID REDIRECTION
            } else {
                system("cls");
                for(int i=3;i>0;i--)
                    {
                        position(2,6);
                        error error2;
                        error2.error_mg();
                        cout<<i;
                        cout << " second(s)";
                        Sleep(1000);
                    }
                system("cls");
                load();
                Header();
                Cart();
                product(user_earlie_page);
            }
        }
    };
//PORODUCTS PAGE
void product(int product)
{
    //DECLARR
    Item item1;
    Item item2;
    Item item3;
    Item item4;
    Item item5;
    Item item6;
    Item item7;
    Item item8;
    Item item9;
    Item item10;
    Item item11;
    Item item12;
    Item item13;
    Item item14;
    Item item15;

    set_earli_product earli;

    changeColour(BLUE2);
    cout << "\t\t\t\t\t    <<<<- Products ->>>>\n" << endl;
    changeColour(WHITE);

    if (product==1){
        cout << "\t\t"<<icon.sub_title<<" Fish & Meat" << endl;
        //PRODUCT LIST
        item1.name = "Alpex Crab Meat (Body & Leg)";
        item1.weight = "200g";
        item1.price = 500.00;

        item2.name = "Alpex Cut Crab – Medium Size";
        item2.weight = "800g";
        item2.price = 1750.00;

        item3.name = "Alpex Cuttle Fish Fillet";
        item3.weight = "500g";
        item3.price = 800.00;

        item4.name = "Squid Cone";
        item4.weight = "500g";
        item4.price = 1200.00;

        item5.name = "Alpex Lobster Meat";
        item5.weight = "500g";
        item5.price = 1250.00;

        item6.name = "Australian Lamb Boneless Leg Slice";
        item6.weight = "200g";
        item6.price = 950.00;

        item7.name = "Bairaha Chicken Meatballs";
        item7.weight = "500g";
        item7.price = 450.00;

        item8.name = "Bairaha Chicken Sandwich Slices";
        item8.weight = "150g";
        item8.price = 250.00;

        item9.name = "Bairaha Chicken Sausage";
        item9.weight = "500g";
        item9.price = 550.00;

        item10.name = "Crescent Onion Chicken Sausage";
        item10.weight = "250g";
        item10.price = 450.00;

        item11.name = "Frozen Pangasius Fish Fillet";
        item11.weight = "1kg";
        item11.price = 1300.00;

        item12.name = "Keells Chicken Sausage";
        item12.weight = "500g";
        item12.price = 600.00;

        item13.name = "Keells Chicken Garlic Sausage";
        item13.weight = "250g";
        item13.price = 355.00;

        earli.num = 1;
    }
    if (product==2){
        cout << "\t\t"<<icon.sub_title<<" Frozen Food" << endl;
        //PRODUCT LIST
        item1.name = "Elephant House Chocolate Ice Cream";
        item1.weight = "-";
        item1.price = 310.00;

        item2.name = "Elephant House Fruit & Nut Ice Cream";
        item2.weight = "-";
        item2.price = 420.00;

        item3.name = "Elephant House Karutha Kolumban Ice Cream";
        item3.weight = "-";
        item3.price = 400.00;

        item4.name = "Imorich Cookie Cream Ice Cream";
        item4.weight = "-";
        item4.price = 725.00;

        item5.name = "Finagle Chapathi";
        item5.weight = "450g";
        item5.price = 351.00;

        item6.name = "Harpo’s Beef Lasagna";
        item6.weight = "300g";
        item6.price = 800.00;

        item7.name = "Bairaha Chicken Meatballs";
        item7.weight = "500g";
        item7.price = 450.00;

        item8.name = "Crescent Chicken Kochchi Bites";
        item8.weight = "450g";
        item8.price = 625.00;

        item9.name = "Bairaha Chicken Sausage";
        item9.weight = "500g";
        item9.price = 550.00;

        item10.name = "Crescent Onion Chicken Sausage";
        item10.weight = "240g";
        item10.price = 280.00;

        item11.name = "Australian Beef Liver Pack";
        item11.weight = "500g";
        item11.price = 658.00;

        item12.name = "Elephant House Back Bacon";
        item12.weight = "150g";
        item12.price = 675.00;

        item13.name = "Elephant House Chicken Bratwurst";
        item13.weight = "200g";
        item13.price = 410.00;

        item14.name = "Elephant House Pawkies";
        item14.weight = "300g";
        item14.price = 795.00;

        item15.name = "Gills Chicken Sausages";
        item15.weight = "250g";
        item15.price = 300.00;

        earli.num = 2;

    }  if (product==3){
        cout << "\t\t"<<icon.sub_title<<" Liquor & Tobacco" << endl;
        //PRODUCT LIST
        item1.name = "Benson And Hedges";
        item1.weight = "20’S";
        item1.price = 1400.00;

        item2.name = "Dunhill Dc Green";
        item2.weight = "20’S";
        item2.price = 1600.00;

        item3.name = "Benson And Hedges";
        item3.weight = "20’S";
        item3.price = 1400.00;

        earli.num = 3;
    } if (product==4){
        cout << "\t\t"<<icon.sub_title<<" Frozen Food" << endl;
        //PRODUCT LIST

        item1.name = "Tiara Chocolate Swiss Roll";
        item1.weight = "200g";
        item1.price = 180.00;

        item2.name = "Tiara Layer Cake Chocolate";
        item2.weight = "480g";
        item2.price = 380.00;

        item3.name = "Tiara Layer Cake Vanilla";
        item3.weight = "480g";
        item3.price = 380.00;

        earli.num = 4;
    }
    if (product==5){
        cout << "\t\t"<<icon.sub_title<<" Frozen Food" << endl;
        //PRODUCT LIST
        item1.name = "Anchor Pedia Pro 1-2 Year";
        item1.weight = "350g";
        item1.price = 695.00;

        item2.name = "Baby Cheramy Cotton Buds";
        item2.weight = "-";
        item2.price = 100.00;

        item3.name = "Baby Cheramy Baby Cream";
        item3.weight = "200ml";
        item3.price = 250.00;

        item4.name = "Baby Cheramy Baby Oil";
        item4.weight = "100ml";
        item4.price = 205.00;

        item5.name = "Baby Cheramy Shampoo ";
        item5.weight = "200ml";
        item5.price = 230.00;

        item6.name = "Pampers Baby Dry Pants";
        item6.weight = "Large Size 12";
        item6.price = 720.00;

        item7.name = "Pampers Dry Pants";
        item7.weight = "XL Size 21";
        item7.price = 1450.00;

        item8.name = "Lactogen Comfopro";
        item8.weight = "1350g";
        item8.price = 590.00;

        item9.name = "Nan 1 Starter Infant Formula";
        item9.weight = "350g";
        item9.price = 1200.00;

        item10.name = "Nangrow 3";
        item10.weight = "350g";
        item10.price = 990.00;

        item11.name = "Australian Beef Liver Pack";
        item11.weight = "500g";
        item11.price = 658.00;

        item12.name = "Nangrow 4";
        item12.weight = "350g";
        item12.price = 1000.00;

        item13.name = "Lactogrow Comfopro";
        item13.weight = "350g";
        item13.price = 680.00;

        item14.name = "Cow & Gate Over 6 Months";
        item14.weight = "400g";
        item14.price = 1350.00;

        item15.name = "Baby Cheramy Shampoo";
        item15.weight = "600ml";
        item15.price = 380.00;

        earli.num = 5;
    }
    if (product==6){
        cout << "\t\t"<<icon.sub_title<<" Fresh Produce" << endl;
        //PRODUCT LIST
        item1.name = "Ash Plantain";
        item1.weight = "400g";
        item1.price = 100.00;

        item2.name = "Batana";
        item2.weight = "500g";
        item2.price = 120.00;

        item3.name = "Beetroot";
        item3.weight = "400g";
        item3.price = 120.00;

        item4.name = "Bell Pepper – Green";
        item4.weight = "300g";
        item4.price = 450.00;

        item5.name = "Bell Pepper – Red";
        item5.weight = "300g";
        item5.price = 450.00;

        item6.name = "Bell Pepper Yellow";
        item6.weight = "300g";
        item6.price = 400.00;

        item7.name = "Bitter Gourd ";
        item7.weight = "300g";
        item7.price = 150.00;

        item8.name = "Brinjal";
        item8.weight = "400g";
        item8.price = 180.00;

        item9.name = "Broccoli";
        item9.weight = "300g";
        item9.price = 680.00;

        item10.name = "Cabbage";
        item10.weight = "500g";
        item10.price = 180.00;

        item11.name = "Capsicum";
        item11.weight = "300g";
        item11.price = 180.00;

        item12.name = "Carrot";
        item12.weight = "500g";
        item12.price = 130.00;

        item13.name = "Coconut Each";
        item13.weight = "--";
        item13.price = 100.00;

        item14.name = "Dambala";
        item14.weight = "300g";
        item14.price = 120.00;

        item15.name = "Green Chillies";
        item15.weight = "200g";
        item15.price = 150.00;

        earli.num = 6;
    }
    if (product==7){
        cout << "\t\t"<<icon.sub_title<<" Groceries" << endl;
        //PRODUCT LIST
        item1.name = "7 Up";
        item1.weight = "1.5l";
        item1.price = 200.00;

        item2.name = "Papadam";
        item2.weight = "200g";
        item2.price = 280.00;

        item3.name = "Turmeric Powder";
        item3.weight = "25g";
        item3.price = 180.00;

        item4.name = "Ambewela Fresh Milk";
        item4.weight = "1l";
        item4.price = 280.00;

        item5.name = "Anchor Shape Up Milk Powder";
        item5.weight = "400g";
        item5.price = 450.00;

        item6.name = "Blueberry Juice Drink";
        item6.weight = "1l";
        item6.price = 890.00;

        item7.name = "Spicy Coating Mix";
        item7.weight = "150g";
        item7.price = 250.00;

        item8.name = "Gold Cocktail Mixture";
        item8.weight = "300g";
        item8.price = 340.00;

        item9.name = "Coca Cola";
        item9.weight = "2l";
        item9.price = 300.00;

        item10.name = "Sweet Chilli Sauce";
        item10.weight = "350ml";
        item10.price = 320.00;

        item11.name = "Elephant Dry Ginger";
        item11.weight = "500ml";
        item11.price = 150.00;

        item12.name = "Elephant Soda";
        item12.weight = "500ml";
        item12.price = 70.00;

        earli.num = 7;
    }
    if (product==8){
        cout << "\t\t"<<icon.sub_title<<" Household & Homecare" << endl;
        //PRODUCT LIST
        item1.name = "Bathroom Fragrance Bright";
        item1.weight = "10g";
        item1.price = 120.00;

        item2.name = "Airfreshener Spray Lavender";
        item2.weight = "750ml";
        item2.price = 440.00;

        item3.name = "Bathroom Cleaner Spray";
        item3.weight = "--";
        item3.price = 260.00;

        item4.name = "Comfort Lily";
        item4.weight = "860";
        item4.price = 700.00;

        item5.name = "Harpic Fresh";
        item5.weight = "750ml";
        item5.price = 290.00;

        item6.name = "Mortein";
        item6.weight = "400ml";
        item6.price = 520.00;

        item7.name = "Soorya Wax";
        item7.weight = "12S";
        item7.price = 96.00;

        item8.name = "Sunlight Care Naturals";
        item8.weight = "1l";
        item8.price = 340.00;

        item9.name = "Coca Cola";
        item9.weight = "2l";
        item9.price = 325.00;

        item10.name = "Sunlight Lemon";
        item10.weight = "1kg";
        item10.price = 180.00;

        item11.name = "Vim Dishwash";
        item11.weight = "200g";
        item11.price = 52.00;

        earli.num = 8;
    }
    if (product==9){
        cout << "\t\t"<<icon.sub_title<<" Personal Care" << endl;
        //PRODUCT LIST
        item1.name = "Axe Body Spray Musk Revive";
        item1.weight = "150ml";
        item1.price = 735.00;

        item2.name = "Axe Click Deodorant";
        item2.weight = "150ml";
        item2.price = 740.00;

        item3.name = "Bic 3 Razor";
        item3.weight = "--";
        item3.price = 100.00;

        item4.name = "Bic Easy 2 Precision Razor";
        item4.weight = "--";
        item4.price = 65.00;

        item5.name = "Bic Easy2 Precision";
        item5.weight = "4S";
        item5.price = 260.00;

         item6.name = "Black Knight Aftershave";
        item6.weight = "100ml";
        item6.price = 520.00;

        item7.name = "Black Knight Cologne Spray";
        item7.weight = "100ml";
        item7.price = 640.00;

        item8.name = "Dettol Hand Sanitizer";
        item8.weight = "50ml";
        item8.price = 240.00;

        item9.name = "Good Look Hair Gel Blue";
        item9.weight = "140g";
        item9.price = 680.00;

        item10.name = "Lifebuoy Total 10 Handwash";
        item10.weight = "100g";
        item10.price = 62.00;

        item11.name = "Rani Sandalwood";
        item11.weight = "1 Pack";
        item11.price = 235.00;

        item12.name = "Sensodyne Toothpaste";
        item12.weight = "120g";
        item12.price = 730.00;

        item11.name = "Colgate Tooth Paste";
        item11.weight = "120g";
        item11.price = 500.00;

        earli.num = 9;
    }
    if (product==10){
        cout << "\t\t"<<icon.sub_title<<" Pharma & Wellness" << endl;
        //PRODUCT LIST
        item1.name = "Link Paspanguwa";
        item1.weight = "23g";
        item1.price = 70.00;

        item2.name = "Link Samahan";
        item2.weight = "30S";
        item2.price = 750.00;

        item3.name = "Link Samahan Canister";
        item3.weight = "60S";
        item3.price = 1500.00;

        item4.name = "Link SP Balm";
        item4.weight = "20g";
        item4.price = 180.00;

        item5.name = "Link Swastha Amurtha";
        item5.weight = "7S";
        item5.price = 175.00;

        earli.num = 10;
    }
//COLUMN GAP
    int c2=40,c3=20,r_num=1;

    if(item1.price !=NULL){
        std::cout<< "\t\t ["<< r_num++ << "] "<< std::left << std::setw(c2) << item1.name << std::setw(c3) << item1.weight << "Rs."<< item1.price << endl;
    } if (item2.price !=NULL) {
        std::cout << "\t\t ["<< r_num++ << "] "<< std::left << std::setw(c2) << item2.name << std::setw(c3) << item2.weight << "Rs."<< item2.price << endl;
    } if (item3.price !=NULL) {
        std::cout << "\t\t ["<< r_num++ << "] "<< std::left << std::setw(c2) << item3.name << std::setw(c3) << item3.weight << "Rs."<< item3.price << endl;
    } if (item4.price !=NULL) {
        std::cout << "\t\t ["<< r_num++ << "] "<< std::left << std::setw(c2) << item4.name << std::setw(c3) << item4.weight << "Rs."<< item4.price << endl;
    } if (item5.price !=NULL) {
        std::cout << "\t\t ["<< r_num++ << "] "<< std::left << std::setw(c2) << item5.name << std::setw(c3) << item5.weight << "Rs."<< item5.price << endl;
    } if (item6.price !=NULL) {
        std::cout << "\t\t ["<< r_num++ << "] "<< std::left << std::setw(c2) << item6.name << std::setw(c3) << item6.weight << "Rs."<< item6.price << endl;
    } if (item7.price !=NULL) {
        std::cout << "\t\t ["<< r_num++ << "] "<< std::left << std::setw(c2) << item7.name << std::setw(c3) << item7.weight << "Rs."<< item7.price << endl;
    } if (item8.price !=NULL) {
        std::cout << "\t\t ["<< r_num++ << "] "<< std::left << std::setw(c2) << item8.name << std::setw(c3) << item8.weight << "Rs."<< item8.price << endl;
    } if (item9.price !=NULL) {
        std::cout << "\t\t ["<< r_num++ << "] "<< std::left << std::setw(c2) << item9.name << std::setw(c3) << item9.weight << "Rs."<< item9.price << endl;
    } if (item10.price !=NULL) {
        std::cout << "\t\t ["<< r_num++ << "] "<< std::left << std::setw(c2) << item10.name << std::setw(c3) << item10.weight << "Rs."<< item10.price << endl;
    } if (item11.price !=NULL) {
        std::cout << "\t\t ["<< r_num++ << "] "<< std::left << std::setw(c2) << item11.name << std::setw(c3) << item11.weight << "Rs."<< item11.price << endl;
    } if (item12.price !=NULL) {
        std::cout << "\t\t ["<< r_num++ << "] "<< std::left << std::setw(c2) << item12.name << std::setw(c3) << item12.weight << "Rs."<< item12.price << endl;
    } if (item13.price !=NULL) {
        std::cout << "\t\t ["<< r_num++ << "] "<< std::left << std::setw(c2) << item13.name << std::setw(c3) << item13.weight << "Rs."<< item13.price << endl;
    } if (item14.price !=NULL) {
        std::cout << "\t\t ["<< r_num++ << "] "<< std::left << std::setw(c2) << item14.name << std::setw(c3) << item14.weight << "Rs."<< item14.price << endl;
    } if (item15.price !=NULL) {
        std::cout << "\t\t ["<< r_num++ << "] "<< std::left << std::setw(c2) << item15.name << std::setw(c3) << item15.weight << "Rs."<< item15.price << endl;
    }
        choose_option_bar(2);
        option_bar option2;

        STYLING footer2;
        footer2.h_long;
        footer2.code=22;

        cout << "\t\t";
        changeColour(YELLOW);
        while (footer2.h_long < 76) {cout << footer2.code; footer2.h_long++;}
        changeColour(WHITE);
        cout << endl;
        cout << "\t\tchoose : ";
        cin >> option2.select;
        system("cls");

//USER INPUT WITH GET PRODUCT DETAILS
    if (option2.select==1){
        Item_Details Details;
        Details.add_item_data(earli.num,item1.name,item1.weight,item1.price);
    } else if (option2.select==2){
        Item_Details Details;
        Details.add_item_data(earli.num,item2.name,item2.weight,item2.price);
    } else if (option2.select==3){
        Item_Details Details;
        Details.add_item_data(earli.num,item3.name,item3.weight,item3.price);
    } else if (option2.select==4){
        Item_Details Details;
        Details.add_item_data(earli.num,item4.name,item4.weight,item4.price);
    } else if (option2.select==5){
        Item_Details Details;
        Details.add_item_data(earli.num,item5.name,item5.weight,item5.price);
    } else if (option2.select==6){
        Item_Details Details;
        Details.add_item_data(earli.num,item6.name,item6.weight,item6.price);
    } else if (option2.select==7){
        Item_Details Details;
        Details.add_item_data(earli.num,item7.name,item7.weight,item7.price);
    } else if (option2.select==8){
        Item_Details Details;
        Details.add_item_data(earli.num,item8.name,item8.weight,item8.price);
    } else if (option2.select==9){
        Item_Details Details;
        Details.add_item_data(earli.num,item9.name,item9.weight,item9.price);
    } else if (option2.select==10){
        Item_Details Details;
        Details.add_item_data(earli.num,item10.name,item10.weight,item10.price);
    } else if (option2.select==11){
        Item_Details Details;
        Details.add_item_data(earli.num,item11.name,item11.weight,item11.price);
    } else if (option2.select==12){
        Item_Details Details;
        Details.add_item_data(earli.num,item12.name,item12.weight,item12.price);
    } else if (option2.select==13){
        Item_Details Details;
        Details.add_item_data(earli.num,item13.name,item13.weight,item13.price);
    } else if (option2.select==14){
        Item_Details Details;
        Details.add_item_data(earli.num,item14.name,item14.weight,item1.price);
    } else if (option2.select==15){
        Item_Details Details;
        Details.add_item_data(earli.num,item15.name,item15.weight,item15.price);
    } else if (option2.select==98){
        system ("CLS");
        exit();
    } else if (option2.select==91){
        mycart my_cart_details;
        my_cart_details.show_my_cart();
    }
//USER INPUT WITH OUTHER OPTION
    else if (option2.select==100){
        Home home_page;
    } else {
        for(int i=3;i>0;i--)
            {
                position(2,6);
                error error2;
                error2.error_mg();
                cout<<i;
                cout << " second(s)";
                Sleep(1000);
            }
        system("cls");
        USER_EARLIE_PRODUCT_PAGE earlie_set;
        earlie_set.set_earlie(earli.num);
        }
    }
//HOME OPTION BAR
void option_bar1()
{
    choose_option_bar(1);
    option_bar option1;

    STYLING footer2;
    footer2.h_long;
    footer2.code=22;

    cout << "\t\t";
    changeColour(YELLOW);
    while (footer2.h_long < 76) {cout << footer2.code; footer2.h_long++;}
    changeColour(WHITE);
    cout << endl;
    cout << "\t\tchoose : ";
    cin >> option1.select;

    if (option1.select==91){
        mycart my_cart_details;
        my_cart_details.show_my_cart();
    } else if(option1.select==98){
        system ("CLS");
        exit();
    } else if(option1.select==97){
        system ("CLS");
        about();
    } else if(option1.select==3){
        //CONFIRM AGE
        if (userage==NULL){
        changeColour(RED2);
        cout<<"\n\t\t1 st, Please Enter Your Age : ";
        changeColour(WHITE);
          cin>>userage;

            if (userage<21){
            system ("CLS");
            for(int i=3;i>0;i--)
            {
                position(2,6);
                error error1;
                error1.error_mg_age();
                Sleep(1000);
            }
            system("cls");
            Home home_page;

            } else {
            system ("CLS");
            load();
            Header();
            Cart();
            product(option1.select);

            }

        } else {
            if (userage<21){
            system ("CLS");
            for(int i=3;i>0;i--)
            {
                position(2,6);
                error error1;
                error1.error_mg_age();
                Sleep(1000);

            }
            system("cls");
            Home home_page;

            } else {

            system ("CLS");
            load();
            Header();
            Cart();
            product(option1.select);
            }
        }

    } else if (option1.select==NULL || 10<option1.select){
    system ("CLS");
        for(int i=3;i>0;i--)
        {
            position(2,6);
            error error1;
            error1.error_mg();
            cout<<i;
            cout << " second(s)";
            Sleep(1000);
        }
        system("cls");
        Home home_page;
    } else {
        system ("CLS");
        load();
        Header();
        Cart();
        product(option1.select);
    }
}
int main() {
     Home home_page;
   return 0;
}
//DeV BY ROYAN HARSHA
