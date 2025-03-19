#include<stdio.h>

// Function to decrypt XOR encrypted files
void decrypt(FILE* encrypted_file, FILE* key_file, FILE* decrypted_file)
{
    int enc_c;
    while ((enc_c = fgetc(encrypted_file)) != EOF)
    {
        int key_c = fgetc(key_file);
        int dec_c = enc_c ^ key_c; // XOR decryption
        fputc(dec_c, decrypted_file);
    }

}

int main(int argc, char* argv[])
{
    if (argc != 3) // To ensure the user provides encrypted data and the key
    {
        printf("You have to provide 2 input arguments!\n");
        return 1;
    }
    else
    {
        FILE* encrypted_file = fopen(argv[1], "rb");
        FILE* key_file = fopen(argv[2], "rb");
        FILE* decrypted_file = fopen("decrypt.out", "wb");
        decrypt(encrypted_file, key_file, decrypted_file);
        fclose(encrypted_file);
        fclose(key_file);
        fclose(decrypted_file);

        printf("Decryption successful! Files created: decrypt.out\n");
    }
}