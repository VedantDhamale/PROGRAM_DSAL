// Consider a telephone book database of N clients. Make use of a hash table implementation
// to quickly look up client‘s telephone number. Make use of two collision handling
// techniques and compare them using number of comparisons required to find aset of
// telephone numbers

#include <iostream>
using namespace std;
class Hashtable
{
public:
    long hash[10];
    long add, temp, i, x;
    char ch;
    void hash1();
    long f(long x);
    void search();
    void display();
};
void Hashtable::hash1()
{
    for (i = 0; i < 10; i++)
        hash[i] = -1;
    do
    {
        cout << "\n Enter the no:";
        cin >> x;
        add = f(x);
        if (hash[add] == -1)
        {
            hash[add] = x;
        }
        else
        {
            temp = (add + 1) % 10;
            while (temp != add)
            {
                if (hash[temp] == -1)
                {
                    hash[temp] = x;
                    break;
                }
                else
                {
                    temp = (temp + 1) % 10;
                }
            }
            if ((temp == add) && (hash[temp] != x))
            {
                cout << "\n Overflow" << endl;
                break;
            }
        }
        cout << "\n Do you want to continue (Y/N):" << endl;
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}
long Hashtable::f(long x)
{
    temp = x % 10;
    return (temp);
}
void Hashtable::search()
{
    long no;
    cout << "\n Enter the no to search :";
    cin >> no;
    add = f(no);
    if (hash[add] == no)
    {
        cout << "\n Number present" << endl;
    }
    else
    {
        temp = (add + 1) % 10;
        while (temp != add)
        {
            if (hash[temp] == no)
            {
                cout << "\n Number Present " << endl;
                break;
            }
            else
            {
                temp = (temp + 1) % 10;
            }
        }
        if ((temp == add) && (hash[temp] != no))
        {
            cout << "\n Number Not present" << endl;
        }
    }
}
void Hashtable::display()
{
    for (i = 0; i < 10; i++)
    {
        cout << "\n"
             << hash[i];
    }
}

int main()
{
    Hashtable ht;
    int ch;
    while (1)
    {
        cout << "\n1-Insert Values in hash table using Linear probing ";
        cout << "\n2-Search";
        cout << "\n3-Display";
        cout << "\n4-Exit";
        cout << "\n Enter your choice";
        cin >> ch;
        switch (ch)
        {
        case 1:
            ht.hash1();
            break;
        case 2:
            ht.search();
            break;
        case 3:
            ht.display();
            break;
        case 4:
            exit(0);
        }
    }
}
