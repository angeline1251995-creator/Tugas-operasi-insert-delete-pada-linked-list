#include <iostream>
using namespace std;

struct Node {
    string title;
    Node* next;
};

Node* head = NULL;

//Menampilkan playlist movie
void show() {
    Node* temp = head;
    cout<<"Playlist Movie:\n";

    while (temp != NULL) {
        cout<<"- "<<temp->title<<endl;
        temp = temp->next;
    }
    cout<<"------------------------\n";
}

int main() {
    // Kasus 1: Tambah film pertama
    Node* m1 = new Node;
    m1->title = "Avatar: Fire and Ash";
    m1->next = NULL;
    head = m1;
    show();

    //Kasus 2: Tambah film di awal
    Node* m2 = new Node;
    m2->title = "Avangers: Endgame";
    m2->next = head;
    head = m2;
    show();

    //Kasus 3: Tambah film setelah film tertentu
    Node* m3 = new Node;
    m3->title = "Zootopia";
    
    Node* search = head;
    while (search != NULL && search->title != "Avatar: Fire and Ash") {
        search = search->next;
    }

    if (search != NULL){
        m3->next = search->next;
        search->next = m3;
    }
    show();

    //Kasus 4: Tambah film di akhir
    Node* m4 = new Node;
    m4->title = "Wicked: For Good";
    m4->next = NULL;
    
    Node* walker = head;
    while (walker->next !=NULL) {
        walker = walker->next;
    }
    walker->next = m4;
    show();

    //Kasus 5: Hapus film pertama
    if (head == NULL)
        cout<<"Tidak ada film yang bisa dihapus\n";
    else {
        Node* temp = head;
        head = head->next;
        delete temp;
        show();
    }
    //Kasus 6: Hapus film terakhir
    if (head == NULL)
        cout<<"Tidak ada film yang bisa dihapus\n";
    else {
        Node* walker = head;
        while (walker->next->next != NULL) {
            walker = walker->next;
        }
        delete walker->next;
        walker->next = NULL;
        show();
    }
    return 0;
    }
