#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#ifdef _WIN32
#include <windows.h> // For Windows
#else
#include <unistd.h> // For POSIX
#endif

// Function to encrypt a file using one-time pad encryption
void encrypt(FILE* secret_file, FILE* encrypted_file, FILE* key_file)
{
    int c;

    // Reading each character until EOF (End of File)
    while((c = fgetc(secret_file)) != EOF)
    {
        int key = rand();
        int encrypted_c = key ^ c; // XOR encryption

        // Storing the encrypted data
        fputc(key, key_file);
        fputc(encrypted_c, encrypted_file);
    }
}

int main(int argc, char* argv[])
{
    if(argc != 2) // To ensure the user provides an input file
    {
        printf("Please provide the file to be encrypted\n");
        return 1;
    }
    else
    {
        char* file_name = argv[1];

        FILE* secret_file = fopen(file_name, "rb");
        if(secret_file == NULL)
        {
            perror("Error opening input file");
            return 1;
        }

        FILE* encrypted_file = fopen("crypt.out", "wb");
        if(encrypted_file == NULL)
        {
            perror("Error opening encrypted file");
            fclose(encrypted_file);
            return 1;
        }

        FILE* key_file = fopen("key.out", "wb");
        if(key_file == NULL)
        {
            perror("Error opening key file");
            fclose(secret_file);
            fclose(encrypted_file);
            return 1;
        }
        // Seed the random number generator using time and process ID for better randomness
        unsigned int seed = time(NULL);
#ifdef _WIN32
        seed ^= GetCurrentProcessId(); // Process ID in Windows
#else
        seed ^= getpid(); // Process ID in POSIX systems
#endif

        srand(seed);
        encrypt(secret_file, encrypted_file, key_file);

        fclose(secret_file);
        fclose(encrypted_file);
        fclose(key_file);

        printf("Encryption successful! Files created: crypt.out, key.out\n");
        return 0;
    }
}