#include <iostream>
#include <vector>
using namespace std;

class penerbit;
class buku {
public:
	string namaBuku;
	buku(string pNamabuku) :namaBuku(pNamabuku) {}
};

class pengarang {
public:
	string namaPengarang;
	vector<penerbit*> daftar_penerbit;
	vector<buku*> daftar_buku;

	pengarang(string pNama) :namaPengarang(pNama){}
	void tambahpenerbit(penerbit*);
	void cetakpenerbit();
	void tambahbuku(buku*);
	void cetakbuku();
};

class penerbit {
public:
	string namaPenerbit;
	vector<pengarang*> daftar_pengarang;

	penerbit(string pNama) :namaPenerbit(pNama){}
	void tambahpengarang(pengarang*);
	void cetakpengarang();
};

void pengarang::tambahpenerbit(penerbit* pPenerbit) {
	daftar_penerbit.push_back(pPenerbit);
}

void pengarang::cetakpenerbit() {
	cout << "daftar penerbit yg diikuti \"" << this->namaPengarang << "\":\n";
	for (auto& b : daftar_penerbit) {
		cout << b->namaPenerbit << "\n";
	}
}

void pengarang::tambahbuku(buku* pBuku) {
	daftar_buku.push_back(pBuku);
}

void pengarang::cetakbuku() {
	cout << "daftar buku yg dikarang \"" << this->namaPengarang << "\":\n";
	for (auto& b : daftar_buku) {
		cout << b->namaBuku << "\n";
	}
	cout << endl;
}

int main() {
	penerbit* varPenerbit1 = new penerbit("Gama Press");
	penerbit* varPenerbit2 = new penerbit("Intan Parawira");
	pengarang* varPengarang1 = new pengarang("Joko");
	pengarang* varPengarang2 = new pengarang("Lia");
	pengarang* varPengarang3 = new pengarang("Asroni");
	pengarang* varPengarang4 = new pengarang("Giga");
	buku* varBuku1 = new buku("Fisika");
	buku* varBuku2 = new buku("Algoritma");
	buku* varBuku3 = new buku("Basisdata");
	buku* varBuku4 = new buku("Dasar pemrograman");
	buku* varBuku5 = new buku("Matematika");
	buku* varBuku6 = new buku("Muktimedia");

	varPenerbit1->tambahpengarang(varPengarang1);
	varPenerbit1->tambahpengarang(varPengarang2);
	varPenerbit1->tambahpengarang(varPengarang3);
	varPenerbit2->tambahpengarang(varPengarang1);
	varPenerbit2->tambahpengarang(varPengarang2);
	
	varPengarang4->tambahpenerbit(varPenerbit1);
	varPengarang4->tambahpenerbit(varPenerbit2);

	varPenerbit1->tambahBuku(varBuku1);
	varPenerbit2->tambahBuku(varBuku2);

}