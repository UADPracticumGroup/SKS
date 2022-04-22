#pragma once
#include <iostream>
#include <vector>
#include <map>

struct MataKuliah {
    std::string nama;
    int sks;
};

class SKS {
    public:
        // Harga per SKS nya
        const int HargaPerSKS = 150000;

        // Mapping matakuliah dengan SKS nya
        std::map<int, MataKuliah> SKS_List {
            {0, { "Akhlak", 2 } },
            {1, { "Algoritma Pemrograman", 3 } },
            {2, { "Aljabar Linear Matrik", 2 } },
            {3, { "Arsitektur Komputer", 3 } },
            {4, { "Bahasa Indonesia", 2 } },
            {5, { "Matematika Diskrit", 3 } },
            {6, { "Pemrograman Web", 3 } },
            {7, { "Pendidikan Kewarganegaraan", 2 } }
        };

        std::vector<int> SKS_Pilihan;

        SKS();
        bool Input();
        void Output();

    private:
        std::string Nama;
        int NIM;
};
