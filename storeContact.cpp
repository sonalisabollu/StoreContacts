//bollu

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

class MyVector
{
public:
    MyVector();
    ~MyVector();
    void push_back(string name, string phone);
    void remove(string name, string phone);
    string get(string name);
    void clear();
private:
    struct Contact
    {
        string name;
        string phone;
    };
    Contact* list;
    int max_size;
    int list_size;
};



MyVector::MyVector()
{
    max_size = 10;
    list_size = -1;
    list = new Contact[max_size];
}


MyVector::~MyVector()
{
    delete[] list;
}

void MyVector::push_back(string name, string phone)
{
    if (list_size + 1 >= max_size)
    {
        max_size += max_size;
        Contact* newList = new Contact[max_size];
        for (int i = 0; i < list_size; i++)
        {
            newList[i] = list[i];
        }
        list = newList;
        delete[] newList;
    }
    list_size++;
    list[list_size] = {
        name,
        phone
    };
}

void MyVector::remove(string name, string phone)
{
    for (int i = 0; i < list_size; i++)
    {
        if (list[i].name.compare(name) == 0|| list[i].phone.compare(phone) == 0)
        {
            for (; i < list_size; i++)
            {
                // Assign the next element to current location.
                list[i] = list[i + 1];
            }
            list[list_size] = {};
            list_size--;
            break;
            
        }
    }
}

string MyVector::get(string name)
{
    for (int i = 0; i <= list_size; i++)
    {
        if (list[i].name.compare(name) == 0)
        {
            return list[i].phone;
        }
    }
    return "Not Found";
}

void MyVector::clear()
{
    delete[] list;
    max_size = 10;
    list_size = -1;
    list = new Contact[max_size];
}

void menu();
int main()
{
    MyVector vector = MyVector();
    bool isRunning = true;
    string phone = "";
    string name = "";
    
    while (isRunning)
    {
        menu();
        char option;
        cin >> option;
        switch (option)
        {
            case 'A':
            case 'a':
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Phone: ";
                cin >> phone;
                vector.push_back(name, phone);
                break;
            case 'R':
            case 'r':
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Phone: ";
                cin >> phone;
                vector.remove(name, phone);
                break;
            case 'C':
            case 'c':
                vector.clear();
                break;
            case 'F':
            case 'f':
                cout << "Enter Name: ";
                cin >> name;
                cout << vector.get(name) << endl;
                break;
            case 'Q':
            case 'q':
                isRunning = false;
                break;
            default:
                break;
        }
    }
}
void menu() {
    cout << "(A)dd Contact" << endl;
    cout << "(C)lear Contacts" << endl;
    cout << "(F)ind Contact" << endl;
    cout << "(Q)uit " << endl;
    cout << "(R)emove Contact " << endl;
    cout << "[ACFQR]: ";
}
