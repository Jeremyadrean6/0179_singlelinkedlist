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

        node *previous = START;
        node *current = START;

        while ((current != NULL) && (nim >= current->noMhs))
        {
            if (nim == current->noMhs)
            {
                cout << "\nduplikasi noMhs tidak diijinkan\n";
                return;
            }
            previous = current;
            current = current->next;
        }

        nodebaru->next = current;
        previous->next = nodebaru;
    }

    bool listempty()
    {
        return (START == NULL);
    }

    bool search(int nim, node **previous, node **current)
    {
        *previous = START;
        *current = START;
         

        while ((*current != NULL) && (nim != (*current)->noMhs))
        {
            *previous = *current;
            *current = (*current)->next;
        }

        return (*current != NULL);
    }

    bool delnode(int nim)
    {
        node *current, *previous;
        if (!search(nim, &previous, &current))
        return false;

        if (current == START)
        START = START->next;

        else 
        previous->next = current->next;

        delete current;
        return true;
    }

    void traverse()
    {
        if (listempty())
        {
            cout << "\nlist kosong\n";
        }
        else
        {
            cout <<"\ndata didalam list adalah:\n";
            node *currentnode = START;
            while (currentnode != NULL)
            {
                cout << currentnode->noMhs << endl;
                currentnode = currentnode->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    singlelinkedlist mhs;
    int nim;
    int ch;
    while (1)
    {
        cout << endl
             << "menu";
        cout << endl
             << "1. menambahkan data kedalam list" << endl;
        cout << "2. menghapus data dari dalam list"<< endl;
        cout << "3. menampilkan semua data didalam list"<< endl;
        cout << "4. mencari data dalam list"<< endl;
        cout << "5. keluar"<< endl;
        cout << endl;
             << "masukan pilihan (1-5): ";
        cin >> ch;  
        switch (ch)
        {
            case '1' :
            {
                mhs.addnode();
            }
            break;

            case '2' :
            {
                if (mhs.listempty())
                {
                    cout << endl
                         << "list kosong" << endl;
                    break;
                }
                cout << endl
                     << "\nmasukan no mahasiswa yang akan dihapus : ";
                cin >> nim;
                if (mhs.delnode(nim) == false)
                cout << endl;
                     << "data tidak ditemukan" << endl;
            else
                cout << endl
                     << "data mahasiswa dengan nomor mahasiswa" << nim << "berhasil dihapus" endl;


            }
            break;
            case '3':
            {
                mhs.traverse();
            }
            break;
            case '4':
            {
                if(mhs.listEmpty() == true)
                {
                    cout << "\nList kosong\n";
                    break;
                }
                Node *previous, *current;
                cout << endl
                     << "Masukkan no mahasiswa yang dicari : ";
                cin >> nim;
                if (mhs.Search(nim, &previous, &current) == false)
                    cout << endl
                         << "Data tidak ditemukan" << endl;
                else
                {
                    cout << endl
                         << "Data ditemukan" << endl;
                    cout << "\nNo Mahasiswa: " << current->noMhs << endl;
                    cout << "\n";
                }
            }
            break;
            case '5':
            {
                exit(0);
            }
            break;
            default:
            {
                 cout << "Pilihan salah !." << endl;
            }
            break;
            }
    
        }
    
    }



