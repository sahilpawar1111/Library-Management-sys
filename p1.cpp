#include <iostream>
#include <string>
using namespace std;

class LibraryItem
{
private:
    string title;
    string author;
    string dueDate;
    int quantity;

public:
    void setTitle(string t) { title = t; }
    void setAuthor(string a) { author = a; }
    void setDueDate(string d) { dueDate = d; }
    void setquantity(int q) { quantity = q; }

    string getTitle() { return title; }
    string getAuthor() { return author; }
    string getDueDate() { return dueDate; }
    int getquantity() { return quantity; }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;

    virtual ~LibraryItem() {}
};

class Book : public LibraryItem
{
public:
    void checkOut() override
    {
        cout << "Book checked out." << endl;
    }
    void returnItem() override
    {
        cout << "Book returned." << endl;
    }
    void displayDetails() override
    {
        cout << "Item Type: Book" << endl;
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "Due Date: " << getDueDate() << endl;
        cout << "Quantity: " << getquantity() << endl;
    }
};

class DVD : public LibraryItem
{
public:
    void checkOut() override
    {
        cout << "DVD checked out." << endl;
    }
    void returnItem() override
    {
        cout << "DVD returned." << endl;
    }
    void displayDetails() override
    {
        cout << "Item Type: DVD" << endl;
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "Due Date: " << getDueDate() << endl;
        cout << "Quantity: " << getquantity() << endl;
    }
};

class Magazine : public LibraryItem
{
public:
    void checkOut() override
    {
        cout << "Magazine checked out." << endl;
    }
    void returnItem() override
    {
        cout << "Magazine returned." << endl;
    }
    void displayDetails() override
    {
        cout << "Item Type: Magazine" << endl;
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "Due Date: " << getDueDate() << endl;
        cout << "Quantity: " << getquantity() << endl;
    }
};

int main()
{
    const int MAX_ITEMS = 10;
    LibraryItem *libraryItems[MAX_ITEMS];
    int count = 0;

    int choice;
    do
    {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Add Book\n";
        cout << "2. Add DVD\n";
        cout << "3. Add Magazine\n";
        cout << "4. Display Items\n";
        cout << "5. Check Out Item\n";
        cout << "6. Return Item\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        try
        {
            if (choice == 1 || choice == 2 || choice == 3)
            {
                if (count >= MAX_ITEMS)
                    throw "Library full!";

                string t, a, d;
                int q;
                cout << "Enter Title: ";
                cin.ignore();
                getline(cin, t);
                cout << "Enter Author: ";
                getline(cin, a);
                cout << "Enter Due Date: ";
                getline(cin, d);
                cout << "Enter Quanty: ";
                cin >> q;

                if (t == "" || a == "" || d == "")
                    throw "Invalid input!";
                if (q <= 0)
                    throw "Invalid input Quantity Should be Positive!";

                if (choice == 1)
                    libraryItems[count] = new Book();
                else if (choice == 2)
                    libraryItems[count] = new DVD();
                else
                    libraryItems[count] = new Magazine();

                libraryItems[count]->setTitle(t);
                libraryItems[count]->setAuthor(a);
                libraryItems[count]->setDueDate(d);
                libraryItems[count]->setquantity(q);
                count++;

                cout << "Item added successfully!\n";
            }
            else if (choice == 4)
            {
                for (int i = 0; i < count; i++)
                {
                    cout << "------------------\n";
                    libraryItems[i]->displayDetails();
                    cout << "------------------\n";
                }
            }
            else if (choice == 5)
            {
                int idx;
                cout << "Enter item number to check out (0-" << count - 1 << "): ";
                cin >> idx;
                if (idx < 0 || idx >= count)
                    throw "Invalid index!";
                libraryItems[idx]->checkOut();
            }
            else if (choice == 6)
            {
                int idx;
                cout << "Enter item number to return (0-" << count - 1 << "): ";
                cin >> idx;
                if (idx < 0 || idx >= count)
                    throw "Invalid index!";
                libraryItems[idx]->returnItem();
            }
            else if (choice == 7)
            {
                cout << "Exiting program...\n";
            }
            else
            {
                throw "Invalid menu choice!";
            }
        }
        catch (const char *msg)
        {
            cout << "Error: " << msg << endl;
        }
    } while (choice != 7);

    for (int i = 0; i < count; i++)
    {
        delete libraryItems[i];
    }

    return 0;
}
