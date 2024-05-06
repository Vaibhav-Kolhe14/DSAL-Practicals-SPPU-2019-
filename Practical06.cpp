#include <iostream>
#include <cstring>
#define max 10
using namespace std;

struct node {
    char name[10];
    long int mn;
    node() {
        mn = 0;
        strcpy(name, "--------");
    }
};

class telephone {
public:
    node ht[max];
    int count;
    telephone() {
        count = 0;
    }
    int hashfun(long int);
    void insert();
    void find();
    void display();
    void delno();
    int linearProbe(long int);
    int quadraticProbe(long int);
};

int telephone::hashfun(long int num) {
    return (num % 10);
}

int telephone::linearProbe(long int num) {
    int index = hashfun(num);
    while (ht[index].mn != 0 && ht[index].mn != num) {
        index = (index + 1) % max;
    }
    return index;
}


int telephone::quadraticProbe(long int num) {
    int index = hashfun(num);
    int initialIndex = index; // Store initial index for wrap-around check
    int i = 1;
    while (ht[index].mn != 0 && ht[index].mn != num) {
        index = (initialIndex + (i * i)) % max; // Calculate index using quadratic probing formula
        i++;
        if (index == initialIndex) // Check if we've wrapped around to the initial index
            break; // Avoid infinite loop
    }
    if (ht[index].mn != 0) { // If slot is still occupied after probing
        // Switch to linear probing
        while (ht[index].mn != 0) {
            index = (index + 1) % max; // Linear probing
        }
    }
    return index;
}


void telephone::insert() {
    node s;
    int ind;
    // long int m;
    cout << "enter name and telephone no.:" << endl;
    cin >> s.name >> s.mn;
    // m = s.mn;
    int choice;
    cout << "Choose probing method:\n1. Linear Probing\n2. Quadratic Probing" << endl;
    cin >> choice;
    switch(choice) {
        case 1:
            ind = linearProbe(s.mn);
            break;
        case 2:
            ind = quadraticProbe(s.mn);
            break;
        default:
            cout << "Invalid choice!" << endl;
            return;
    }
    if (ht[ind].mn == 0) {
        ht[ind] = s;
    } else {
        cout << "Slot is already occupied!" << endl;
    }
}

void telephone::display() {
    for (int i = 0; i < max; i++) {
        cout << i << "\t" << ht[i].name << "\t" << ht[i].mn << endl;
    }
}

void telephone::find() {
    long int num;
    cout << "Enter telephone number to find: ";
    cin >> num;
    int ind = hashfun(num);
    int comparisons = 1;
    while (ht[ind].mn != 0 && ht[ind].mn != num) {
        ind = (ind + 1) % max;
        comparisons++;
    }
    if (ht[ind].mn == num) {
        cout << "Found at index " << ind << " with " << comparisons << " comparisons." << endl;
    } else {
        cout << "Not found!" << endl;
    }
}

void telephone::delno() {
    long int num;
    cout << "Enter telephone number to delete: ";
    cin >> num;
    int ind = hashfun(num);
    int comparisons = 1;
    while (ht[ind].mn != num && ht[ind].mn != 0) {
        ind = (ind + 1) % max;
        comparisons++;
    }
    if (ht[ind].mn == num) {
        ht[ind].mn = 0;
        strcpy(ht[ind].name, "--------");
        cout << "Deleted at index " << ind << " with " << comparisons << " comparisons." << endl;
    } else {
        cout << "Not found!" << endl;
    }
}

int main() {
    telephone t;
    int ch;
    char ans;
    do {
        cout << "enter your choice" << endl;
        cout << "1.insert" << endl;
        cout << "2.find" << endl;
        cout << "3.delete" << endl;
        cout << "4.display" << endl;
        cout << "5.exit" << endl;
        cin >> ch;
        switch (ch) {
            case 1:
                t.insert();
                break;
            case 2:
                t.find();
                break;
            case 3:
                t.delno();
                break;
            case 4:
                t.display();
                break;
            case 5:
                return 0;
            default:
                cout << "invalid choice!!!" << endl;
        }
        cout << "do you want to continue?(y/n)";
        cin >> ans;
    } while (ans == 'y');
    return 0;
}
