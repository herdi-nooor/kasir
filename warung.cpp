#include<iostream>
#include<string>
#include<vector>

char lanjut = 'n';

void menuUtama();
void fbelanja();

int main(){
  menuUtama();
  std::cout << "selesai" << std::endl;
  return 0;
}
void menuUtama(){
  char input = '3' ;
  system("clear");
  std::cout << "============================ \n";
  std::cout << "        MENU APLIKASI \n" ;
  std::cout << "1. belanja \n" ;
  std::cout << "2. list barang \n" ;
  std::cout << "3. keluar \n" ;
  std::cout << "============================" << std::endl;
  std::cout << "pilihan anda : " ;
  std::cin >> input;
  while(input != '3'){
    switch(input){
      case '1' :
        fbelanja();
        break;
      case '2' :
        std::cout << "pilihan 2" << std::endl;
        break;
      case '3' :
        input = '3';
        break;
      default :
        std::cout << "pilihan salah" << std::endl;
        break;
    }
    label_lanjut:
    std::cout << "lanjut?Y/N : " ;
    std::cin >> lanjut;
    if (lanjut == 'y'){
       menuUtama();
    }else if(lanjut == 'n'){
       input = '3' ;
    }else{
       std::cout << "pilihan yang anda masukan salah" << std::endl;
       goto label_lanjut;
    }
  }
  std::cout << "akhiri" << std::endl;
}

void fbelanja() {
  char y = 'y';
  int n = 0;
  int totalBaya = 0 ;
  struct belanjaan {
    std::string nama;
    int harga;
    int jumlah;
    int totalharga;
  };

  std::vector <belanjaan> barang;
  while (y != 'n') {
    barang.push_back(belanjaan());
    std::cout << " nama : " ;
    std::cin.ignore();
    getline(std::cin, barang[n].nama, '\n');
    std::cout << " harga : " ;
    std::cin >> barang[n].harga ;
    std::cout << " jumlah : " ;
    std::cin >> barang[n].jumlah ;
    barang[n].totalharga = ((barang[n] .harga) * (barang[n].jumlah)) ;
    std::cout << "lagi " ;
    std::cin >> y ;
    n++;
  }
  for (int i = 0; i < n ; i++) {
    std::cout << " nama barang :" << barang[i].nama ;
    std::cout << "\n jumlah beli :" << barang[i].jumlah ;
    std::cout << "\n total harga :" << barang[i].totalharga << std::endl;
    totalBaya = totalBaya + barang[i].totalharga ;
  }
  std::cout << "total bayar : " << totalBaya << std::endl;
  std::cin.ignore();
  std::cin.get();
  menuUtama();
}