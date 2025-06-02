#include <iostream>
using namespace std;

class mahasiswa {
    //Syarat untuk Encapsulation:
    //Atribut private:
    protected:
    string nama;
    string nim;
    private:
    string umur;

    public:
    mahasiswa (string pnama, string pnim, string pumur):
    nama(pnama), nim(pnim), umur(pumur){
    } 

    //Menandakan bahwa ini abstrak class 
    //dan sebagai syarat untuk polimorfi
    virtual void infoMhs() = 0;

    //enkapsulasi hanya dapat mengakses melalui method
    void setNama(string pnama) {
        nama = pnama;
    }
    string getNama() {
        return nama;
    }
    void setNim(string pnim) {
        nim = pnim;
    }
    string getNim() {
        return nim;
    }
    void setUmur(string pumur) {
        umur = pumur;
    }
    string getUmur() {
        return umur;
    }

};

class mhsBaru : public mahasiswa{
    public:
   mhsBaru(string pnama, string pnim, string pumur):
   mahasiswa(pnama, pnim, pumur) {}

   void infoMhs() override{
        cout << "Nama Mhs : " << nama << endl;
        cout << "Nim Mhs : " << nim << endl;
        cout << "Umur Mhs : " << getUmur() << endl;
   }
};

class mhsLama : public mahasiswa{
    public:
   mhsLama(string pnama, string pnim, string pumur):
   mahasiswa(pnama, pnim, pumur) {}

   void infoMhs() override{
        cout << "Nama Mhs : " << nama << endl;
        cout << "Nim Mhs : " << nim << endl;
        cout << "Umur Mhs : " << getUmur() << endl;
   }

};

int main() {
    mahasiswa *mhs;
        mhsBaru mhsb("Joko","2023", "45");
        mhsBaru mhsl("Jarwo","2021", "35");

        mhs = &mhsb;
        //polimorpi dengan method yang sama dan nilai yang berbeda
        mhs->infoMhs();
        mhs = &mhsl;
        mhs->infoMhs();

}