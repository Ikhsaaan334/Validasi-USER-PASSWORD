#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char user_data[101][101];
    char pass_data[101][101];
    int input;
    int i, pilih;

    while (1) {
        puts("Menu");
        puts("1. Register USER");
        puts("2. Login USER");
        puts("0. Exit Program");

        printf("Nomor yang dipilih: ");
        scanf("%d", &pilih);
        getchar(); 

        switch (pilih) {
            case 1: {
                system("cls");
                printf("Jumlah data USER yang ingin dimasukkan: ");
                scanf("%d", &input);
                getchar(); 

                for (i = 0; i < input; i++) {
                    printf("Ketikkan USER dan PASS yang ingin dimasukkan\n");
                    printf("USER %d: ", i + 1);
                    scanf("%s", user_data[i]);
                    printf("PASS %d: ", i + 1);
                    scanf("%s", pass_data[i]);
                }

                char balik;
                printf("Apakah anda ingin kembali ke menu awal? (Y/N): ");
                getchar(); 
                balik = getchar();

                if (balik == 'Y' || balik == 'y') {
                    system("cls");
                    continue;  // Kembali ke awal loop
                } else {
                    puts("Program ditutup");
                    exit(0);
                }
                break;
            }
            case 2: {
                system("cls");
                char loginUser[101], passUser[101];

                printf("Masukkan USER yang sudah didaftarkan: ");
                scanf("%s", loginUser);
                printf("Masukkan PASS yang sudah didaftarkan: ");
                scanf("%s", passUser);

                int found = 0;
                for (i = 0; i < input; i++) {
                    if (strcmp(user_data[i], loginUser) == 0 && strcmp(pass_data[i], passUser) == 0) {
                        puts("Login Berhasil!");
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    puts("Identitas tidak sesuai, silakan coba lagi.");
                }
                break;
            }
            case 0: {
                puts("Program ditutup");
                exit(0);
                break;
            }
            default: {
                puts("INPUT INVALID, Masukkan ulang!");
                break;
            }
        }
    }
    return 0;
}

