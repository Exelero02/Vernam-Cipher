File Encryption and Decryption System

📌 Overview

This project provides a simple yet effective file encryption and decryption system using the XOR cipher. It consists of two C programs:

encrypt.c: Encrypts a given file using a randomly generated key and produces two output files: an encrypted file and a key file.

decrypt.c: Uses the key file to decrypt the encrypted file and recover the original content.

✨ Features

✅ Uses a one-time pad (OTP) style XOR encryption for security.✅ Generates a unique key for every character in the input file.✅ Supports encryption and decryption of any text-based file.✅ Ensures platform compatibility with Windows and Linux.

📂 File Outputs

After running the encryption process, the following files are generated:

crypt.out - The encrypted file containing unreadable data.

key.out - A key file necessary to decrypt crypt.out.

After decryption, the following file is generated:

decrypt.out - The original file restored from crypt.out.

⚙️ Compilation Instructions

To compile the encryption and decryption programs, use the following commands:

gcc encrypt.c -o encrypt
gcc decrypt.c -o decrypt

🚀 Usage

🔒 Encryption

To encrypt a file, run:

./encrypt <filename>

Example:

./encrypt secret.txt

This will generate crypt.out (encrypted content) and key.out (encryption key).

🔓 Decryption

To decrypt a file, run:

./decrypt crypt.out key.out

Example:

./decrypt crypt.out key.out

This will restore the original content in decrypt.out.

⚠️ Error Handling

The program checks for missing input arguments.

Handles file opening errors and prints relevant error messages.

Ensures proper cleanup of file resources to prevent memory leaks.

⚠️ Limitations

❌ The encryption method is simple and not suitable for highly sensitive data.❌ If the key file is lost, decryption is impossible.❌ Works best with text files; binary files may not be fully supported.
