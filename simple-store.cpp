#include<iostream>
#include<string>
#include <fstream>
#include <sstream>
// fungsi
using namespace std;
int search(int);
int tampilkan();
string check(int); // liat jumlah Barang

struct Barang
{
	int jumlah;
	string nama;
	string merk;
	int harga;	
};

void input_data(Barang &brg);
void print_data(Barang &brg);


void input_data(Barang &brg)
{
	system ("cls");
	cout<<"======================== Admin Toko Elektronik ==========================\n\n";
	cout << "Input data Barang Elektronik" <<endl;
	cout << "============================" <<endl;
	cout << "\nJumlah Barang Elektronik : "; 
	cin >> brg.jumlah;
	cin.ignore(1, '\n');
	cout << endl;
	cout << "Nama Barang Elektronik   : "; 
	getline(cin, brg.nama);
	cout << endl;
	cout << "Merk Barang Elektronik   : "; 
	getline(cin, brg.merk);
	cout << endl;
	cout << "Harga Barang Elektronik  : Rp. "; 
	cin >> brg.harga;
	cout << endl; 
}

void print_data(Barang &brg)
{
	system ("cls");
	cout<<"======================== Admin Toko Elektronik ==========================\n\n";
	cout << "--------------------------------"<<endl;
	cout << "Tampilan data Barang Elektronik" <<endl;
	cout << "Nama Barang Elektronik : " << brg.nama << endl;
	cout << "Merk Barang Elektronik : " << brg.merk << endl;
	cout << "Jumlah Barang Elektronik : " << brg.jumlah << endl;
	cout << "Harga Barang : Rp. " << brg.harga << endl;
}



// judul
void judul(){
		cout<<"======================== Toko Elektronik ==========================\n";  
}
//node 
struct node {
	int ID;
	string nama;
	double harga;  // Harga Barang
	int jumlah;
struct    node* next;
};
struct node *head=NULL;

 void awal()      
{
	system("cls");
	judul();
	int id,banyak;           
	string name;
	double harge;            
	struct node *t=new node;
	cout<<"\n Id Barang : ";
	cin>>id;
	t->ID=id;
	cout << endl;
	cout<<" Nama Barang : ";
	cin.ignore(1, '\n');
	getline (cin, name);
	t->nama=name;
	cout << endl;
	cout<<" Harga Barang : Rp. ";
	cin>>harge;
	t->harga=harge;
	cout << endl;
	cout<<" Jumlah Barang : ";
	cin>>banyak;
	cout << endl;
	t->jumlah=banyak;
	t->next=head;
	head=t;
	system("cls");
	judul();
		cout<<"\nBarang Telah Berhasil Ditambahkan!"<<endl;
	}

	void akhir()
	{
	system("cls");
	judul();
	int id,banyak;     
	string name;
	double harge;            
	struct node *t=new node;
	struct node *p=head;
	cout<<"\n Id Barang : ";
	cin>>id;
	t->ID=id;
	cout << endl;
	cout<<" Nama Barang : ";
	cin>>name;
	t->nama=name;
	cout << endl;
	cout<<" Harga Barang : ";
	cin>>harge;
	t->harga=harge;
	cout << endl;
	cout<<" Jumlah Barang : ";
	cin>>banyak;
	t->jumlah=banyak;
		while(p->next!=NULL)
		{
		p=p->next;
		}
			p->next=t;
			t->next=NULL;
		system("cls");
		judul();
		cout<<"Barang Telah Berhasil Ditambahkan!\n";
	}
	void hapus()
	{
		system("cls");
		judul();
		tampilkan();
		int id;
		struct node *cur=head;
		struct node *harge=head;
		cout<<"Id Barang yang ingin dihapus : ";
		cin>>id;
		 if (head == NULL)
    {
    	system("cls");
        cout<<"Daftar Kosong "<<endl;
    }
	int pos=0;
	int count=tampilkan();               
	pos=search(id);                         
	if(pos<=count){
		
		while(cur->ID!=id){                
			harge=cur;
			cur=cur->next;
}
		harge->next=cur->next;
		system("cls");
		judul();
		cout<<"\nBarang Telah Dihapus\n";
	}else{
		cout<<"Tidak Ditemukan\n";
	}
	}	

	void simpan()
	{
	system("cls");

  ofstream myfile ("catatanBarang.txt");
  
  if (myfile.is_open())
  {
  	judul();
  	cout << endl;
    myfile << "  ID\t\t Nama Barang \t\t\ Harga \t\t Jumlah \n";
    struct node *p=head;
    int c=0;          
		while(p!=NULL)
		{
			myfile<<" "<<p->ID<<"\t\t  "<<p->nama<<"\t\t"<<p->harga<<"\t   "<<check(p->jumlah)<<"\n"; 
			p=p->next;
			c=c+1;
		}
		myfile<<"\nJenis Barang yang ada di Toko : "<<c;
		}
    myfile.close();
    system("cls");
    judul();
    cout<<"\n\n\t\t\tData Disimpan!\n";
}

int tampilkan(){
		system("cls");
		judul();
		int c=0;             
		struct node *p=head;
		cout<<"\n Data Barang : \n\n";
		cout<<"  ID\t\t Nama Barang \t\t\ Harga \t\t Jumlah \n";
		while(p!=NULL)
		{
			cout<<" "<<p->ID<<"\t\t  "<<p->nama<<"\t\t"<<p->harga<<"\t   "<<check(p->jumlah)<<"\n"; 
			p=p->next;
			c=c+1;
		}
		cout<<"\n Jenis Barang di Toko : "<<c<<"\n\n\n";
		return c;
	    }
	    string check(int banyak){             
	    int a = banyak;
       stringstream ss;
       ss << a;
       string jumlah = ss.str();
       
	    	if(banyak<=0)
	    	return "Stok Sudah Habis!";
	    	else
	    	return jumlah;
		}
	    
		void Baranglama(){
	   	system("cls");
	   	judul();
	   	cout << endl;
	   	string line;
        ifstream myfile ("catatanBarang.txt");
        if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
    }
    cout<<"\n\n";
    myfile.close();
  }
  else cout << " Data masih kosong \n\n"; 
		}
			
	int search(int id)                    
 {
 	int count=1;
 	struct node *p=head;
 	while(p!=NULL)
 	{
 		if(p->ID==id)
 			break;              
 		else
 			count++;
 			p=p->next;
	}
 	return count;
 }
	                        //        Fungsi Main
int main(){	
	system("cls");
	judul();
	int temp=1;
	while(true){
	int ch;
	int pil;                     //            Pilihan Menu
	cout << endl;
	menu :
	cout << "Pilih Menu"<<endl<<endl;
	cout << " 1. Sorting dan Searching Data Barang Elektronik "<<endl<<endl;
	cout << " 2. Inputan Stok Barang Elektronik "<<endl<<endl;
	cout << " Pilihan Anda : ";
	cin  >> pil;
	if(pil==1)
	{
		Barang brg[25];
	int x, id, pilihan;
	
	opsi:
		
	system ("cls");
	judul();
	cout << endl << endl;
	cout << "Aplikasi Input Data Barang Elektronik" << endl;
	cout << "------------------------------------" << endl;
	cout << "\nBanyak Data Barang yang akan di inputkan : ";
	cin >> x;
	cout << "------------------------------------" << endl;
	
	for (int i = 0; i < x; i++)
	{
		system ("cls");
		cout << "Barang Elektronik ke-"<<(i+1)<<endl;
		cout << "------------------------------------" << endl;
		input_data(brg[i]);
	}
	

	cari:
	cout << "Tampilkan Data Barang no. : ";
	cin >> id;
	if(id <= x)
	{
		print_data(brg[id-1]);
		cout << "----------------------------"<<endl;
		cout << "1. Cari Data Barang Elektronik"<<endl<<endl;
		cout << "2. Buat Data Baru Barang Elektronik"<<endl<<endl;
		cout << "3. Kembali ke Menu Utama"<<endl<<endl;
		cout << "4. Keluar dari Aplikasi"<<endl<<endl;
		cout << "Pilihan : ";
		cin>>pilihan;
		if(pilihan == 1){
			goto cari;
		}
		else if (pilihan == 2)
		{
			goto opsi;
		}
		else if (pilihan ==3)
		{
			goto menu;
		}
		else
		{
			exit(0);
		}
	}
	else
	{
		system("cls");
		judul();
		cout << "Data Tidak Ada" << endl << endl;
		cout << "1. Cari Data Barang Elektronik"<<endl<<endl;
		cout << "2. Buat Data Baru Barang Elektronik"<<endl<<endl;
		cout << "3. Kembali Ke Menu Utama"<<endl<<endl;
		cout << "4. Keluar dari Aplikasi"<<endl<<endl;
		cout << "Pilihan : ";
		cin>>pilihan;
		if(pilihan == 1){
			goto cari;
		}
		else if (pilihan == 2)
		{
			goto opsi;
		}
		else if (pilihan == 3)
		{
			goto menu;
		}
		else
		{
			exit(0);
		}
	}
	return 0;
	} 
	else
	{
		cout << " 1. Tambah Barang Baru \n"<<endl;
	cout << " 2. Lihat Barang\n"<<endl;
	cout << " 3. Hapus Barang\n"<<endl;
	cout << " 4. Keluar\n"<<endl;
	cout << "    Pilihan : ";
	cin>>ch;     
	switch(ch){
	case 1:
	if (temp==0){              
	judul();
	akhir();	
	}
	if(temp==1){               
	judul();
	awal();	
	temp=0;
	}
	break;
case 2:
	system("cls");
	judul();
	cout << endl;
	cout<<"1. Tampilkan Barang yang telah tersimpan \n"<<endl;
    cout<<"2. Save Data Barang\n"<<endl;
    cout<<"3. Tampilkan Barang Sekarang"<<endl;
    cout << "\nPilihan : ";
	int c; cin>>c;
    if(c==1) Baranglama();
    if(c==2) simpan();
    if(c==3) tampilkan();
    break; 
case 3:
	judul();
	hapus();
	break;		

default: system("cls");
         goto menu;
	}
}	
	}
	
}

