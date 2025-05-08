#include <iostream>
#include <string.h>
using namespace std;

class node {
    public :
    int noMhs;
    node *next;
};

class list {
    node *START;

    public :
    list()
    {
        START = NULL;
    }

    void addnode()
    {
        int nim;
        cout << "\nMasukan nomor mahasiswa:";
        cin >> nim;

        node *nodebaru = new node;
        nodebaru->noMhs = nim;

        if (START == NULL || nim <= START-> noMhs)
        {
            if((START != NULL) && (nim == START-> noMhs))
            {
                cout << "\nduplikat noMhs tidak diijinkan\n";
                return;
            }
            nodebaru->next = START;
            START = nodebaru;
            return;
        }

       
    }

    
}

