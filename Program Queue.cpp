#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#define max 15

using namespace std;

struct queue //Mendefinisikan queue dengan menggunakan struct
{
    int head;
    int tail ;
    int data [15]; // menampung 15 data
};
queue antri;
//Menginputkan data queue
void enqueue(int d){
    antri.head=0;
    antri.tail++;
    antri.data[antri.tail]=d;
    cout<<"data berhasil dimasukkan"<<endl;
    cout<<endl;
}
//Mengambil data dari queue
void dequeue()
{
    cout<<"data terambil "<<antri.data[antri.head];
    for (int i=antri.head;i<=antri.tail;i++)
        (antri.data[i]=antri.data[i+1]);
        antri.tail--;
        cout<<endl;
}
//Mengecek apakah antrian penuh
int isFull(){
    if (antri.tail==max-1)
        return 1;
    else
        return 0;
}
//Mengecek apakah antrian kosong
int isEmpty(){
    if (antri.tail==-1)
    {
        antri.head=-1;
        return 1;
    }
    else
        return 0;
}
//Membersihkan seluruh antrian
void clear(){
    antri.head=antri.tail=-1;
    cout<<"semua data terhapus.";
    cout<<endl;
}
//Mencetak seluruh antrian yang telah disorting secara askending
void print_as(){
    int j,i;
    int tampung;
    for(i=0;i<=antri.tail;i++)
    {
    for(j=i+1;j<=antri.tail;j++)
        {
            if(antri.data[i]>antri.data[j])
            {
                tampung=antri.data[i];
                antri.data[i]=antri.data[j];
                antri.data[j]=tampung;
            }
        }
    }
    for (int c=0;c<=antri.tail;c++)
    cout<<antri.data[c]<<endl;
    cout<<endl;
}
int main()
{
    int pil;
    int input;
    antri.tail=-1;
    do
    {
        cout<<"MENU\n";
        cout<<"1. ENQUEUE\n";
        cout<<"2. DEQUEUE\n";
        cout<<"3. DELETE ALL\n";
        cout<<"4. VIEW\n";
        cout<<"5. EXIT\n";
        cout<<endl<<"Masukkan Pilihan Anda = ";cin>>pil;
        fflush(stdin);
    switch(pil)
    {
    //Menginputkan antrian
    case 1 :
                        cout<<endl;
        cout<<"1. ENQUEUE ";
        if(isFull()==1){ //Kondisi jika antrian sudah penuh
            cout<<"Antrian Penuh ! "<<endl;
        }
        else //Menginputkan antrian
        cout<<endl<<" Masukkan Data = ";cin>>input;
        fflush(stdin);
        enqueue(input);
        getch();
    break;
    //Mengambil data dari antrian
    case 2 :
                                    cout<<endl;
            cout<<"2. DEQUEUE";
            if(isEmpty()==1){
                cout<<endl<<"Antrian Kosong ! ";
            }
            else
                cout<<endl;
                dequeue();
                        getch();
    break;
    //Menghapus seluruh antrian
            case 3:
                                    cout<<endl;
            cout<<"3. DELETE ALL"<<endl;
            clear();
            cout<<endl<<"Antrian Kosong"<<endl;
    break;
    //Mencetak seluruh antrian
    case 4 :
                                    cout<<endl;
            cout<<"4. VIEW";
            if(isEmpty()==1){ //Pilihan jika antrian kosong
                cout<<endl<<"Antrian Kosong"<<endl;
            }
            else
                cout<<endl<<"Data yang dicetak ";
                                    cout<<endl;
                                    print_as();
                                    getch();
    break;
    //Keluar dari program
    case 5:
                                    return 0;
            }
            }while (pil!=6);
            getch();
    return 0;
}
