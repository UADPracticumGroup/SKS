#include "SKS.h"
#include <fstream>

SKS::SKS() {
    // Welcome message
    std::string introduction = "Selamat datang di program untuk memilih SKS anda\n";
    introduction.append("List SKS nya adalah:\n");

    for (int i = 0; i < SKS_List.size(); i++) {
        introduction.append(std::to_string(i + 1) + ". " + SKS_List[i].nama + " (" + std::to_string(SKS_List[i].sks) + " SKS)\n");
    }

    std::cout << introduction;
}

bool SKS::Input() {
    std::cout << "Masukan nama anda: "; std::getline(std::cin, Nama);
    std::cout << "Masukan NIM anda: "; std::cin >> NIM;

    std::cout << "Ketik '0' untuk keluar dari pilihan.\n";
    while (true) {
        std::cout << "Masukkan nomor SKS yang ingin anda pilih: ";
        int pilihan;
        std::cin >> pilihan;

        if (pilihan == 0) {
            break;
        }

        bool found = false;
        for (int i : SKS_Pilihan) {
            if (i == pilihan - 1) {
                found = true;
                break;
            }
        }

        if (found) {
            std::cout << "SKS sudah anda pilih." << std::endl;
            continue;
        }

        if (pilihan > 0 && pilihan <= SKS_List.size()) {
            SKS_Pilihan.push_back(pilihan - 1);
        } else {
            std::cout << "Nomor SKS yang anda masukkan tidak ada di list SKS\n";
        }
    }

    if (SKS_Pilihan.size() == 0) {
        std::cout << "Anda tidak memilih SKS apapun\n";
        return false;
    }

    return true;
}

// recursive calculate the price
void CalculatePrice(SKS sks, std::string *output, int *total_harga, int *total_sks, int i) {
    if (i == sks.SKS_Pilihan.size()) {
        return;
    }

    *total_sks += sks.SKS_List[sks.SKS_Pilihan[i]].sks;
    *total_harga += sks.SKS_List[sks.SKS_Pilihan[i]].sks * sks.HargaPerSKS;
    output->append("- " + std::to_string(sks.SKS_Pilihan[i] + 1) + ": " + sks.SKS_List[sks.SKS_Pilihan[i]].nama + ", Harga: " + std::to_string(sks.SKS_List[sks.SKS_Pilihan[i]].sks * sks.HargaPerSKS) + " (" + std::to_string(sks.SKS_List[sks.SKS_Pilihan[i]].sks) + " SKS)" + "\n");

    CalculatePrice(sks, output, total_harga, total_sks, i + 1);
}

void SKS::Output() {
    int total_sks = 0;
    int total_harga = 0;
    int diskon_persen = 25;

    // above but in std::string
    std::string output = "=====================================================\n";
    output.append("Nama Mahasiswa: " + Nama + "\n");
    output.append("NIM Mahasiswa: " + std::to_string(NIM) + "\n");
    output.append("=====================================================\n");
    output.append("Anda memilih SKS sebagai berikut:\n");
    CalculatePrice(*this, &output, &total_harga, &total_sks, 0);

    /**
    for (int i = 0; i < SKS_Pilihan.size(); i++) {
        total_sks += SKS_List[SKS_Pilihan[i]].sks;
        total_harga += SKS_List[SKS_Pilihan[i]].sks * HargaPerSKS;

        output.append("- " + std::to_string(SKS_Pilihan[i] + 1) + ": " + SKS_List[SKS_Pilihan[i]].nama + ", Harga: " + std::to_string(SKS_List[SKS_Pilihan[i]].sks * HargaPerSKS) + " (" + std::to_string(SKS_List[SKS_Pilihan[i]].sks) + " SKS)" + "\n");
    }*/

    output.append("\n");
    output.append("Total SKS yang anda pilih: " + std::to_string(total_sks) + "\n");
    output.append("Total harga: " + std::to_string(total_harga) + "\n");

    int diskon = total_harga * diskon_persen / 100;
    output.append("Total harga setelah dikurangi diskon: " + std::to_string(total_harga - diskon) + " (Diskon " + std::to_string(diskon_persen) + "%)" + "\n");
    output.append("=====================================================\n");

    // output to file struk.txt
    std::fstream file("struk.txt", std::ios::out | std::ios::trunc);
    file << output;
    file.close();

    std::cout << output;
}
