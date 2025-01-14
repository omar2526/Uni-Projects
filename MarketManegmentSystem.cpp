#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
using namespace std;
class product {
private:
    int id;
    int price;
    int month;
    int year;
    int stock;
    string name;
public:
    product* pnext;
    void setprice(int val)
    {
        price = val;
    }
    int getprice()
    {
        return price;
    }
    void setId(int val)
    {
        id = val;
    }
    int getId()
    {
        return id;
    }
    void setmonth(int val)
    {
        if (val <= 12 && val >= 1)
        {
            month = val;
        }
        else {
            cout << "Please select a month correctly" << endl;
        }
    }
    void setStock(int val)
    {
        if (val >= 0)
        {
            stock = val;
        }
    }
    int getStock()
    {
        return stock;
    }
    int getmonth()
    {
        return month;
    }
    void setyear(int val)
    {
        if (val > 2020)
        {
            year = val;
        }
    }
    int getyear()
    {
        return year;
    }
    void setname(string val)
    {
        if (val != "")
        {
            name = val;
        }
    }
    string getname()
    {
        return name;
    }

    product()
    {
        id = 0;
        price = 0;
        month = 0;
        year = 0;
        name = "";
        pnext = NULL;
    }
};
class customer
{
private:
    int id;
    string name;
    string password;

public:
    customer* pnext;
    void setid(int val)
    {
        if (val > 0)
        {
            id = val;
        }
    }
    int getid()
    {
        return id;
    }
    void setname(string val)
    {
        if (val != " ")
        {
            name = val;
        }
    }
    string getname()
    {
        return name;
    }

    void setpassword(string val)
    {
        if (val != " ")
        {
            password = val;
        }
    }
    string getpassword()
    {
        return password;
    }

    customer()
    {
        id = 0;
        name = "";
        password = "";
        pnext = NULL;
    }
};
class order {
private:
    string date;
    int quan;
public:
    product* pid;
    customer* cid;
    order* pnext;
    void setdate(string val)
    {
        date = val;
    }
    string getdate()
    {
        return date;
    }
    void setquan(int val)
    {
        if (val > 0)
        {
            quan = val;
        }
    }
    int getquan()
    {
        return quan;
    }
    order()
    {
        pid = NULL;
        cid = NULL;
        date = "";
        quan = 0;
        pnext = NULL;
    }
};
class admin {
private:
    int id;
    string name;
    string password;
public:
    admin* pnext;

    void setid(int val)
    {
        if (id > 0)
        {
            id = val;
        }
    }
    int getid()
    {
        return id;
    }

    void setname(string val)
    {
        if (val != " ") {
            name = val;
        }
    }
    string getname()
    {
        return name;
    }
    void setpassword(string val)
    {
        if (val != " ") {
            password = val;
        }
    }
    string getpassword()
    {
        return password;
    }
    admin()
    {
        id = 0;
        name = "";
        password = "";
        pnext = NULL;
    }
};
class clistProd {
public:
    product* ph;
    product* pt;

    clistProd()
    {
        ph = NULL;
        pt = NULL;
    }

    void attach(product* pnn)
    {
        if (ph == NULL)
        {
            ph = pnn;
            pt = pnn;
        }
        else {
            pt->pnext = pnn;
            pt = pnn;
        }
    }

    //~clistProd()
    //{
    //    product* ptrav = ph;
    //    while (ptrav != NULL)
    //    {
    //        product* ptemp = ptrav->pnext;
    //        delete ptrav;  
    //        ptrav = ptemp;
    //    }
    //}

};
class clistCustomer {
public:
    customer* ph;
    customer* pt;

    clistCustomer()
    {
        ph = NULL;
        pt = NULL;
    }

    void attach(customer* pnn)
    {
        if (ph == NULL)
        {
            ph = pnn;
            pt = pnn;
        }
        else {
            pt->pnext = pnn;
            pt = pnn;
        }
    }

    //~clistCustomer()
    //{
    //    customer* ptrav = ph;
    //    while (ptrav != NULL)
    //    {
    //        customer* ptemp = ptrav->pnext;
    //        delete ptrav;  // Delete node properly
    //        ptrav = ptemp;
    //    }
    //}
};
class clistOrder {
public:
    order* ph;
    order* pt;

    clistOrder()
    {
        ph = NULL;
        pt = NULL;
    }

    void attach(order* pnn)
    {
        if (ph == NULL)
        {
            ph = pnn;
            pt = pnn;
        }
        else {
            pt->pnext = pnn;
            pt = pnn;
        }
    }

    //~clistOrder()
    //{
    //    order* ptrav = ph;
    //    while (ptrav != NULL)
    //    {
    //        order* ptemp = ptrav->pnext;
    //        delete ptrav;
    //        ptrav = ptemp;
    //    }
    //}
};
class clistAdmin {
public:
    admin* ph;
    admin* pt;

    clistAdmin()
    {
        ph = NULL;
        pt = NULL;
    }

    void attach(admin* pnn)
    {
        if (ph == NULL)
        {
            ph = pnn;
            pt = pnn;
        }
        else {
            pt->pnext = pnn;
            pt = pnn;
        }
    }

    /* ~clistAdmin()
     {
         admin* ptrav = ph;
         while (ptrav != NULL)
         {
             admin* ptemp = ptrav->pnext;
             delete ptrav;
             ptrav = ptemp;
         }
     }*/
};
void dispHome()
{
    cout << "Welcome to the Market Management System" << endl;
    cout << "___________________________________________" << endl;
    cout << endl << endl;
    cout << "Please Choose" << endl << "---------------" << endl;
    cout << "1) Login" << endl;
    cout << endl;
    cout << "2) SignUp" << endl;
    cout << endl;
    cout << "3) Close" << endl;

}
void dispsign()
{
    system("cls");
    cout << "1)Customer" << endl;
    cout << "2)admin" << endl;

}
string login(clistCustomer& l, ifstream& r, customer*& user)
{
    cout << "Please enter your username" << endl;
    string tmp;
    cin >> tmp;
    int flag = 0;
    customer* ptrav = l.ph;
    while (ptrav != NULL)
    {
        if (ptrav->getname() == tmp)
        {
            while (1)
            {
                cout << "enter your password" << endl;
                cin >> tmp;
                if (ptrav->getpassword() == tmp)
                {
                    cout << "login successful" << endl;
                    flag = 1;
                    user = ptrav;
                    return ptrav->getname();
                    break;
                }
                else {
                    cout << "incorrect password" << endl;
                }
            }
        }
        ptrav = ptrav->pnext;
        if (ptrav == NULL && flag == 0)
        {
            cout << "incorrect Username" << endl;
            cin >> tmp;
            ptrav = l.ph;

        }
    }
}
void viewRecipts2(customer* pnn, clistOrder& l)
{
    order* ptrav = l.ph;

    int tot = 0;
    if (ptrav == NULL)
    {
        cout << "no orders made yet" << endl;
    }
    else {
        while (ptrav != NULL)
        {
            if (ptrav->cid == pnn)
            {
                cout << pnn->getid() << " , " << pnn->getname() << endl;
                cout << "------------------------------------" << endl;
                cout << ptrav->pid->getId() << " , " << ptrav->pid->getname() << " , " << ptrav->pid->getprice() << " , " << ptrav->getquan() << endl;
                tot += ptrav->pid->getprice() * ptrav->getquan();
            }
            ptrav = ptrav->pnext;
        }

        cout << "------------------------------------" << endl;
        cout << "Grand Total is: " << tot << endl;
    }


}
void viewRecipts(customer* pnn, clistOrder& l)
{
    order* ptrav = l.ph;
    while (1)
    {
        int tot = 0;
        if (ptrav == NULL)
        {
            cout << "no orders made yet" << endl;
        }
        else {
            while (ptrav != NULL)
            {
                if (ptrav->cid != NULL)
                {
                    if (ptrav->cid == pnn)
                    {
                        cout << pnn->getid() << " , " << pnn->getname() << endl;
                        cout << "------------------------------------" << endl;
                        cout << ptrav->pid->getId() << " , " << ptrav->pid->getname() << " , " << ptrav->pid->getprice() << " , " << ptrav->getquan() << endl;
                        tot += ptrav->pid->getprice() * ptrav->getquan();
                    }
                }
                ptrav = ptrav->pnext;
            }

            cout << "------------------------------------" << endl;
            cout << "Grand Total is: " << tot << endl;
        }
        int bk;
        cout << "5) back out" << endl;
        cin >> bk;
        if (bk == 5)
        {
            break;
        }
    }
}
void viewProd(clistProd l)
{
    product* ptrav = l.ph;
    int res;
    int bk = 0;
    while (1)
    {
        while (ptrav != NULL)
        {
            res = ptrav->getStock();
            if (res > 0)
            {
                cout << ptrav->getId() << "," << ptrav->getname() << "," << ptrav->getprice() << "," << ptrav->getStock() << endl;
            }
            ptrav = ptrav->pnext;
        }
        cout << "5) to backout" << endl;
        cin >> bk;
        if (bk == 5)
        {
            break;
        }
    }
}
void viewProd2(clistProd l)
{
    product* ptrav = l.ph;
    if (l.ph == NULL)
    {
        cout << "no items" << endl;
    }
    int res;
    while (ptrav != NULL)
    {
        res = ptrav->getStock();
        if (res > 0)
        {
            cout << ptrav->getId() << "," << ptrav->getname() << "," << ptrav->getprice() << "," << ptrav->getStock() << endl;
        }
        ptrav = ptrav->pnext;
    }
}
void Monitor(clistOrder& o, clistProd& p)
{
    while (1)
    {
        cout << "Enter your id" << endl;
        int Id;
        cin >> Id;
        order* ptrav2 = o.ph;

        int ct = 0;
        while (ptrav2 != NULL)
        {
            if (ptrav2->cid->getid() == Id)
            {
                ct++;
                cout << ptrav2->pid->getId() << " , " << ptrav2->pid->getname() << endl;
            }
            ptrav2 = ptrav2->pnext;
        }

        cout << "ID :" << Id << " has placed " << ct << " orders" << endl;
        int bk;
        cout << "5) to back out";
        cin >> bk;
        if (bk == 5)
        {
            break;
        }
    }
}
void income(clistOrder& o, clistProd& p)
{
    while (1)
    {
        int tot = 0;
        order* ptrav2 = o.ph;
        string date;
        string tmp;
        int bk = 0;
        cout << "enter day" << endl;
        cin >> date;
        tmp += date;
        tmp += "-";
        date = "";
        cout << "enter month" << endl;
        cin >> date;
        tmp += date;
        tmp += "-";
        date = "";
        cout << "enter year" << endl;
        cin >> date;
        tmp += date;
        date = "";

        product* ptrav = p.ph;


        while (ptrav2 != NULL)
        {
            if (ptrav2->getdate() == tmp)
            {


                tot += ptrav2->pid->getprice() * ptrav2->getquan();


            }
            ptrav2 = ptrav2->pnext;
        }


        cout << "Total income for  " << tmp << " is: " << tot << endl;
        cin >> bk;
        if (bk == 5)
        {
            break;
        }
    }
}
string loginadmin(clistAdmin& l, ifstream& r)
{
    cout << "Please enter your username" << endl;
    string tmp;
    cin >> tmp;
    int flag = 0;
    admin* ptrav = l.ph;
    while (ptrav != NULL)
    {
        if (ptrav->getname() == tmp)
        {
            while (1)
            {
                cout << "enter your password" << endl;
                cin >> tmp;
                if (ptrav->getpassword() == tmp)
                {
                    cout << "login successful" << endl;
                    flag = 1;
                    return ptrav->getname();
                    break;
                }
                else {
                    cout << "password is incorrect";
                }
            }
        }

        ptrav = ptrav->pnext;
        if (ptrav == NULL && flag == 0)
        {
            cout << "incorrect username" << endl;
            cin >> tmp;
            ptrav = l.ph;
        }
    }
    return ptrav->getname();
}
int checkpass(string s)
{
    int ctA = 0;
    int ct = 0;
    int ctn = 0;
    if (s.length() < 6)
    {
        return 0;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 97 && s[i] <= 122)
        {
            ct++;
        }
        if (s[i] >= 65 && s[i] <= 90)
        {
            ctA++;
        }
        if (s[i] >= 0 && s[i] <= 31)
        {
            ctn++;
        }

    }
    if (ctA > 0 && ctn > 0 && ct > 0)
    {
        return 0;
    }
    else {
        return 1;
    }
}
void purchase(clistCustomer& c, clistProd& p, ofstream& f, clistOrder& o, customer* user)
{
    while (1)
    {
        viewProd2(p);
        int res = 0;
        product* ptrav = p.ph;
        cout << "what is the id of the product you want to buy?" << endl;
        int id;
        cin >> id;
        cout << "how many would you like to buy?" << endl;
        int quan;
        cin >> quan;

        string tmp = "";
        string d;
        while (ptrav != NULL)
        {
            if (ptrav->getId() == id)
            {
                if (quan > ptrav->getStock())
                {
                    while (1)
                    {
                        cout << "there is only " << ptrav->getStock() << " items left" << endl;
                        cout << "How many would you like?" << endl;
                        cin >> quan;
                        if (quan <= ptrav->getStock())
                        {
                            break;
                        }
                    }
                }
                if (quan <= ptrav->getStock())
                {
                    ptrav->setStock(ptrav->getStock() - quan);
                    order* pnn = new order;
                    pnn->pid = ptrav;
                    pnn->cid = user;
                    cout << "what day is it?" << endl;
                    cin >> d;
                    tmp += d;
                    tmp += "-";
                    cout << "what month is it?" << endl;
                    cin >> d;
                    tmp += d;
                    tmp += "-";
                    cout << "what year is it ?";
                    cin >> d;
                    tmp += d;
                    pnn->setdate(tmp);
                    pnn->setquan(quan);
                    o.attach(pnn);



                }
            }
            ptrav = ptrav->pnext;
        }
        int bk;
        cout << "would you like to buy more?" << endl;
        cout << "1) yes" << endl;
        cout << "2) no" << endl;
        cin >> bk;
        if (bk == 1)
        {
            system("cls");
        }
        if (bk == 2)
        {
            break;
        }
    }
}
void signup(clistCustomer& l, ofstream& f, ifstream& r) {
    customer* pnn = new customer;
    string tmp;
    string check;
    int flag = 0;

    while (1) {
        cout << "Enter your username: ";
        cin >> tmp;


        r.clear();
        r.seekg(0, ios::beg);

        flag = 0;


        while (getline(r, check))
        {
            int ct = 0;
            string user = "";


            for (int i = 0; i < check.length(); i++) {
                if (check[i] == ',') {
                    ct++;
                }
                else if (ct == 1) {

                    user += check[i];
                }
                else if (ct > 1) {
                    break;
                }
            }

            if (user == tmp)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1) {
            cout << "User with this username already exists. Please select another username." << endl;
        }
        else {
            pnn->setname(tmp);
            break;
        }
    }

    while (1) {
        cout << "Enter your password: ";
        cin >> tmp;

        int res = checkpass(tmp);
        if (res == 0) {
            cout << "Password must be 6 characters or longer, include atleast one capital letter and one number, and have no special characters." << endl;
        }
        else {
            pnn->setpassword(tmp);
            break;
        }
    }


    int newID = 1;
    if (l.ph != NULL) {
        customer* ptrav = l.ph;
        while (ptrav != NULL) {
            if (ptrav->getid() >= newID) {
                newID = ptrav->getid() + 1;
            }
            ptrav = ptrav->pnext;
        }
    }

    pnn->setid(newID);


    l.attach(pnn);


    if (f.is_open()) {
        f << pnn->getid() << "," << pnn->getname() << "," << pnn->getpassword() << endl;
    }
    else {
        cout << "Error: Unable to open file for writing!" << endl;
    }
}
void makelist(clistCustomer& l, ifstream& r)
{
    string txt;
    string tmp;
    int res = 0;
    int f2 = 0;
    int f3 = 0;
    int flag = 0;
    while (getline(r, txt))
    {
        flag = 0;
        tmp = "";
        f2 = 0;
        f3 = 0;
        customer* pnn = new customer;
        for (int i = 0; i < txt.length(); i++)
        {
            if (flag == 0)
            {
                if (txt[i] == ',')
                {
                    flag++;
                    res = stoi(tmp);
                    pnn->setid(res);
                    i++;
                    tmp = "";
                }
                if (flag == 0)
                {
                    tmp += txt[i];
                }
            }
            if (flag == 1)
            {
                if (txt[i] == ',')
                {
                    flag++;
                    pnn->setname(tmp);
                    tmp = "";
                    i++;
                }
                if (flag == 1)
                {
                    tmp += txt[i];
                }

            }
            if (flag == 2)
            {
                tmp += txt[i];
            }
        }
        pnn->setpassword(tmp);
        l.attach(pnn);
    }

}
void makelistadmin(clistAdmin& k, ifstream& r)
{
    string txt;
    string tmp;
    int res = 0;
    int f2 = 0;
    int f3 = 0;
    int flag = 0;
    while (getline(r, txt))
    {
        flag = 0;
        tmp = " ";
        f2 = 0;
        f3 = 0;
        admin* pnn = new admin;
        for (int i = 0; i < txt.length(); i++)
        {
            if (flag == 0)
            {
                if (txt[i] == ',')
                {
                    flag++;
                    res = stoi(tmp);
                    pnn->setid(res);
                    i++;
                    tmp = "";
                }
                if (flag == 0)
                {
                    tmp += txt[i];
                }
            }
            if (flag == 1)
            {
                if (txt[i] == ',')
                {
                    flag++;
                    pnn->setname(tmp);
                    tmp = "";
                    i++;
                }
                if (flag == 1)
                {
                    tmp += txt[i];
                }

            }
            if (flag == 2)
            {
                tmp += txt[i];
            }
        }
        pnn->setpassword(tmp);
        k.attach(pnn);
    }

}
void makelistProd(clistProd& k, ifstream& r)
{
    string txt;
    string tmp;
    int res = 0;
    int f2 = 0;
    int f3 = 0;
    int flag = 0;
    while (getline(r, txt))
    {
        flag = 0;
        tmp = " ";
        f2 = 0;
        int i = 0;
        f3 = 0;
        product* pnn = new product;
        for (i = 0; i < txt.length(); i++)
        {
            if (flag == 0)
            {
                if (txt[i] == ',')
                {
                    flag++;
                    res = stoi(tmp);//id
                    pnn->setId(res);
                    i++;
                    tmp = "";
                }
                if (flag == 0)
                {
                    tmp += txt[i];
                }
            }
            if (flag == 1)
            {
                if (txt[i] == ',')
                {
                    flag++;
                    pnn->setname(tmp);//name
                    tmp = "";
                    i++;
                }
                if (flag == 1)
                {
                    tmp += txt[i];
                }

            }
            if (flag == 2)
            {
                if (txt[i] == ',')
                {
                    flag++;
                    res = stoi(tmp);//price
                    pnn->setprice(res);
                    tmp = "";
                    i++;
                }
                if (flag == 2)
                {
                    tmp += txt[i];
                }
            }
            if (flag == 3)
            {
                if (txt[i] == ',')
                {
                    flag++;
                    res = stoi(tmp);//stock
                    tmp = "";
                    pnn->setStock(res);
                    i++;
                }
                if (flag == 3)
                {
                    tmp += txt[i];
                }
            }
            if (flag == 4)
            {
                if (txt[i] == ',')
                {
                    flag++;
                    res = stoi(tmp);//mnth
                    tmp = "";
                    pnn->setmonth(res);
                    i++;
                }
                if (flag == 4)
                {
                    tmp += txt[i];
                }
            }
            if (flag == 5)
            {
                tmp += txt[i];
            }
        }
        flag++;
        res = stoi(tmp);//year
        tmp = "";
        pnn->setyear(res);
        i++;
        k.attach(pnn);
    }


}
void makelistord(clistOrder& l, ifstream& r, clistCustomer& c, clistProd& p)
{
    string txt;
    string tmp;
    int flag = 0;
    int res = 0;
    customer* pcust;
    product* pprod;
    while (getline(r, txt))
    {
        tmp = "";
        flag = 0;
        res = 0;
        order* pnn = new order;
        for (int i = 0; i < txt.length(); i++)
        {
            if (flag == 0)
            {
                if (txt[i] == ',')
                {
                    flag++;
                    i++;
                    res = stoi(tmp);
                    pcust = c.ph;
                    tmp = "";
                    while (pcust != NULL)
                    {
                        if (pcust->getid() == res)
                        {
                            pnn->cid = pcust;
                            break;
                        }
                        pcust = pcust->pnext;
                    }

                }
                if (flag == 0)
                {
                    tmp += txt[i];
                }
            }
            if (flag == 1)
            {
                if (txt[i] == ',')
                {
                    flag++;
                    i++;
                    res = stoi(tmp);
                    pprod = p.ph;
                    tmp = "";
                    while (pprod != NULL)
                    {
                        if (pprod->getId() == res)
                        {
                            pnn->pid = pprod;
                            break;
                        }
                        pprod = pprod->pnext;
                    }
                }
                if (flag == 1)
                {
                    tmp += txt[i];
                }
            }
            if (flag == 2)
            {
                tmp += txt[i];
            }
        }
        pnn->setdate(tmp);
        l.attach(pnn);
    }
}
void adminsignup(clistAdmin& l, ofstream& f, ifstream& r) {
    admin* pnn = new admin;
    string tmp;
    string check;
    int flag = 0;

    while (1) {
        cout << "Enter your username: ";
        cin >> tmp;


        r.clear();
        r.seekg(0, ios::beg);

        flag = 0;


        while (getline(r, check))
        {
            int ct = 0;
            string user = "";


            for (int i = 0; i < check.length(); i++) {
                if (check[i] == ',') {
                    ct++;
                }
                else if (ct == 1) {

                    user += check[i];
                }
                else if (ct > 1) {
                    break;
                }
            }

            if (user == tmp)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1) {
            cout << "User with this username already exists. Please select another username." << endl;
        }
        else {
            pnn->setname(tmp);
            break;
        }
    }

    while (1) {
        cout << "Enter your password: ";
        cin >> tmp;

        int res = checkpass(tmp);
        if (res == 0) {
            cout << "Password must be 6 characters or longer, include atleast one capital letter and one number, and have no special characters." << endl;
        }
        else {
            pnn->setpassword(tmp);
            break;
        }
    }


    int newID = 1;
    if (l.ph != NULL) {
        admin* ptrav = l.ph;
        while (ptrav != NULL) {
            if (ptrav->getid() >= newID) {
                newID = ptrav->getid() + 1;
            }
            ptrav = ptrav->pnext;
        }
    }

    pnn->setid(newID);


    l.attach(pnn);


    if (f.is_open()) {
        f << pnn->getid() << "," << pnn->getname() << "," << pnn->getpassword() << endl;
    }
    else {
        cout << "Error: Unable to open file for writing!" << endl;
    }
}
void addProd(clistProd& l, ofstream& f)
{
    string tmp;
    int price;
    int stock;
    product* pnn = new product;
    cout << "the name of the product" << endl;
    cin >> tmp;
    pnn->setname(tmp);
    cout << "enter the price of your Proudct" << endl;
    cin >> price;
    pnn->setprice(price);
    cout << "enter the stock" << endl;
    cin >> stock;
    pnn->setStock(stock);
    cout << "enter the expiration month" << endl;
    cin >> stock;
    pnn->setmonth(stock);
    cout << "enter the expiration year" << endl;
    cin >> stock;
    pnn->setyear(stock);
    int newID = 1;
    if (l.ph == NULL)
    {
        pnn->setId(1);
        l.attach(pnn);
    }
    else {

        pnn->setId(l.pt->getId() + 1);
        l.attach(pnn);
        //product* ptrav = l.ph;
        //while (ptrav != NULL) 
        //{
        //    if (ptrav->getId() >= newID) 
        //    {
        //        newID = ptrav->getId() + 1;
        //        pnn->setId(newID);
        //        l.attach(pnn);
        //    }
        //    ptrav = ptrav->pnext;
        //}

    }

}
void dispProd(product* pnn)
{
    cout << pnn->getId() << "," << pnn->getname() << "," << pnn->getprice() << "," << pnn->getStock() << "," << pnn->getmonth() << "," << pnn->getyear() << endl;
}
void dispList(clistCustomer l)
{
    customer* ptrav = l.ph;
    while (ptrav != NULL)
    {
        cout << ptrav->getname() << endl;
        cout << ptrav->getpassword() << endl;
        cout << ptrav->getid() << endl;
        ptrav = ptrav->pnext;
    }
}
void dispListProd(clistProd l)
{
    product* ptrav = l.ph;
    while (ptrav != NULL)
    {
        cout << ptrav->getId() << "," << ptrav->getname() << "," << ptrav->getprice() << "," << ptrav->getStock() << "," << ptrav->getmonth() << "," << ptrav->getyear() << endl;
        ptrav = ptrav->pnext;
    }
}
void deleteProd(clistProd& l, int id, ofstream& f, ifstream& r)
{
    product* ptrav = l.ph;
    product* ptmp = NULL;
    string txt;
    string tmp;
    int res = 0;
    int flag = 0;
    product* pb = NULL;
    while (ptrav != NULL)
    {
        if (ptrav->getId() == id)
        {
            if (l.ph == ptrav)
            {
                l.ph = ptrav->pnext;
                ptmp = ptrav;
                ptrav = ptrav->pnext;
                ptmp->pnext = NULL;
                delete ptmp;
                break;
            }
            else
            {
                pb->pnext = ptrav->pnext;
                ptrav->pnext = NULL;
                delete ptrav;
                break;
            }
        }

        pb = ptrav;
        ptrav = ptrav->pnext;
    }

}
void editProd(clistProd& l, ofstream& f, int flag, int id, string edit)
{
    product* ptrav = l.ph;
    int res = 0;
    float res2 = 0;
    while (ptrav != NULL)
    {

        if (ptrav->getId() == id)
        {
            if (flag == 1)
            {
                ptrav->setname(edit);
            }
            if (flag == 2)
            {
                res2 = stof(edit);
                ptrav->setprice(res2);
            }
            if (flag == 3)
            {
                res = stoi(edit);
                ptrav->setStock(res);
            }
        }
        ptrav = ptrav->pnext;
    }


}
void returnProd(clistProd& p, clistOrder& o, customer*& pnn)
{
    system("cls");
    viewRecipts2(pnn, o);
    cout << "the ID of the product that you want to return" << endl;
    int id;
    cin >> id;
    product* pprod = p.ph;
    order* pord = o.ph;
    order* pb = NULL;
    while (pord != NULL)
    {
        if (pord->pid->getId() == id)
        {

            pord->pid->setStock(pord->pid->getStock() + pord->getquan());
            if (pb == NULL)
            {
                delete pord;
                break;

            }
            else {

                pb->pnext = pord->pnext;
                pord->pnext = NULL;
                delete pord;
                break;
            }
        }
        pb = pord;
        pord = pord->pnext;
    }

}
void stockAlert(clistProd l, int num)
{
    int bk = 0;
    while (1)
    {
        product* ptrav = l.ph;
        while (ptrav != NULL)
        {
            if (ptrav->getStock() <= num)
            {
                dispProd(ptrav);
            }
            ptrav = ptrav->pnext;
        }
        cout << "5) to back out" << endl;
        cin >> bk;
        if (bk == 5)
        {
            break;
        }
    }
}
void DispAdminPageIn(string admin)
{
    cout << "welcome " << admin << " what is on the checklist today?" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "1) Add New Product" << endl;
    cout << "2) Edit Product" << endl;
    cout << "3) Delete Product" << endl;
    cout << "4) Stock Alert !!" << endl;
    cout << "5) Monitor Orders" << endl;
    cout << "6) Income Summary" << endl;
    cout << "7) Log Out" << endl;

}
void dispCustpage(string cust)
{
    cout << "Welcome " << cust << " what would you like to do today? " << endl;
    cout << "__________________________________________________" << endl;
    cout << "1) Purchase Product" << endl;
    cout << "2) Return Product" << endl;
    cout << "3) View Products" << endl;
    cout << "4) View Recipts" << endl;
    cout << "5) Backout" << endl;
}
void main()
{
    int user = 0;
    clistAdmin admin;
    clistCustomer cust;
    clistOrder ord;
    clistProd prod;
    //
    ofstream fcust;
    ifstream fcustR;
    //
    ofstream fadmin;
    ifstream fadminR;
    //
    ofstream fprod;
    ifstream fprodR;
    //
    ifstream fordR;
    ofstream ford;
    //

    int pick;
    int pick2;
    string custname;
    fcustR.open("customer.txt");
    fcust.open("customer.txt", ios::app);
    fadminR.open("admin.txt");
    fadmin.open("admin.txt", ios::app);
    fprodR.open("products.txt");
    fordR.open("orders.txt");



    makelist(cust, fcustR);
    makelistadmin(admin, fadminR);
    makelistProd(prod, fprodR);
    makelistord(ord, fordR, cust, prod);
    fprod.open("products.txt");
    ford.open("orders.txt");


    while (1)
    {
        system("cls");
        dispHome();
        cin >> user;
        string currAdmin;
        if (user == 1)//a
        {
            system("cls");
            dispsign();
            cin >> user;
            if (user == 1)//cust
            {

                system("cls");
                customer* ptmp = new customer;
                custname = login(cust, fcustR, ptmp);
                while (1)
                {
                    system("cls");
                    dispCustpage(custname);

                    cin >> user;
                    if (user == 1)
                    {
                        system("cls");
                        purchase(cust, prod, ford, ord, ptmp);
                    }
                    if (user == 2)
                    {
                        system("cls");
                        returnProd(prod, ord, ptmp);
                    }
                    if (user == 3)
                    {
                        system("cls");
                        viewProd(prod);
                    }
                    if (user == 4)
                    {
                        system("cls");
                        viewRecipts(ptmp, ord);
                    }
                    if (user == 5)
                    {
                        break;
                    }
                }
            }
            if (user == 2)
            {
                system("cls");
                currAdmin = loginadmin(admin, fadminR);
                while (1)
                {
                    system("cls");
                    DispAdminPageIn(currAdmin);
                    cin >> user;
                    if (user == 1)
                    {
                        addProd(prod, fprod);

                    }
                    if (user == 2)
                    {
                        system("cls");
                        cout << "what do you want to edit ?" << endl;
                        cout << "----------------------------" << endl;
                        cout << "1) Name" << endl;
                        cout << "2) Price" << endl;
                        cout << "3) Stock" << endl;
                        cin >> pick;
                        cout << "what is the id of the Item you want to edit" << endl;
                        cin >> pick2;
                        string edit;
                        cout << "enter the new info" << endl;
                        cin >> edit;
                        editProd(prod, fprod, pick, pick2, edit);


                    }
                    if (user == 3)
                    {
                        cout << "what is the id of the item that you want to delete" << endl;
                        cin >> pick;
                        deleteProd(prod, pick, fprod, fprodR);
                    }
                    if (user == 4)
                    {
                        system("cls");
                        cout << "what is the threshold?";
                        cin >> pick;
                        stockAlert(prod, pick);

                    }
                    if (user == 5)
                    {
                        system("cls");
                        Monitor(ord, prod);
                    }
                    if (user == 6)
                    {
                        system("cls");
                        income(ord, prod);
                    }
                    if (user == 7)
                    {
                        break;
                    }
                }
            }
            user = 0;
        }
        if (user == 2)
        {
            system("cls");
            signup(cust, fcust, fcustR);
        }
        if (user == 3)
        {
            break;
        }

    }
    product* ptrav = prod.ph;
    while (ptrav != NULL)
    {
        fprod << ptrav->getId() << "," << ptrav->getname() << "," << ptrav->getprice() << "," << ptrav->getStock() << "," << ptrav->getmonth() << "," << ptrav->getyear() << endl;
        ptrav = ptrav->pnext;
    }
    order* ptrav2 = ord.ph;
    while (ptrav2 != NULL)
    {
        ford << ptrav2->cid->getid() << "," << ptrav2->pid->getId() << ptrav2->getdate() << endl;
        ptrav2 = ptrav2->pnext;
    }
    fcust.close();
    fcustR.close();
    fadmin.close();
    fadminR.close();
    fprod.close();
    fprodR.close();
}