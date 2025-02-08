#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <gmp.h>

#include"miller_rabin.h"

//Konvertiere einen String in ein Hexadezimalzahl
void char_to_hex(const char * input, mpz_t in_plaintext, int l) {
    char hex[2*l+1];
    for ( int i = 0; i < l; i++ ) {
        sprintf(&hex[2*i], "%x", input[i]);
    }
    hex[2*l] = 0;
    mpz_set_str(in_plaintext, hex, 16);
}

//Konvertiere eine Hexadezimalzahl in einen String
void hex_to_char(const mpz_t out_plaintext, char * output, int l) {
    char hex[2*l+1];
    mpz_get_str(hex, 16, out_plaintext);
    for ( int i = 0; i < 2*l; i+=2 ) {
        char byte[3] = {hex[i], hex[i+1], 0};
        sprintf(&output[i/2],"%c", (char)strtol(byte, NULL, 16));
    }
    output[l] = 0;
}

// Ziehe eine zufällige angemessen große Primzahl
void generateRandomPrime(mpz_t prime, gmp_randstate_t random_state) {
    int is_prime = 0;
    int count = 0;
    printf("Versuche Primzahl zu generieren... \n");
    
    //To Do - Findem Sie durch zufälliges Ziehen einen zufälligen ungeraden Integer mit bis zu 2048 Bits bei dem es sich (wahrscheinlich) um eine Primzahl handelt
    //Zählen Sie die benötigten Versuche mit count

    printf("Primzahl wurde generiert nach %d Versuchen.\n", count);
}


// Berechnen des modularen Inversen und speichern in result
void modular_inverse(const mpz_t a, const mpz_t n, mpz_t result) {
    // To Do
}

// Finde zwei ausreichend große Primzahlen p,q und erzeuge den entsprechenden öffentlichen Schlüssel (n,e)
// und den privaten Schlüssel (n,d)
void generate_rsa_keys(mpz_t p, mpz_t q, mpz_t n, mpz_t e, mpz_t d, gmp_randstate_t random_state) {
    // To Do
}

// Verschlüsseln von in_plaintex mit öffentlichem Schlüssel (n,e)
void encrypt(const mpz_t in_plaintex, const mpz_t e, const mpz_t n, mpz_t ciphertext) {
    // To Do
}

// Entschlüsseln von ciphertext mit privatem Schlüssel (n,d)
void decrypt(const mpz_t ciphertext, const mpz_t d, const mpz_t n, mpz_t out_plaintex) {
    // To Do
}

int main(int argc, char ** argv) {

    // Initialisiere gmp random number generator
    gmp_randstate_t random_state;
    gmp_randinit_default(random_state);
    gmp_randseed_ui(random_state, time(NULL));

    // Initialisiere gmp Variablen
    mpz_t p, q, e, d, n, in_plaintext, ciphertext, out_plaintext;
    mpz_inits(p, q, n, e, d, in_plaintext, ciphertext, out_plaintext, NULL);

    // Erzeuge RSA Schlüssel
    generate_rsa_keys(p, q, n, e, d, random_state);
    gmp_printf("p: %Zd\nq: %Zd\nn: %Zd\ne: %Zd\nd: %Zd\n", p, q, n, e, d);

    // default Nachricht: "Hello, World!"
    char * message = "Hello, World!";
    // Wenn eine Nachricht an main über die Kommandozeile übergeben wurde
    if ( argc > 1 ) {
        // Länge der Nachricht muss kleiner sein als Länge des Cchlüssels, welche 2048 bits ist
        if ( strlen(argv[1]) > 256 ) {
            fprintf(stderr, "Message too long, max 256 characters\n");
            exit(1);
        }
        message = argv[1];
    }
    printf("Nachricht: %s\n", message);

    //Konvertiere zu Hexadezimalzahl
    int l = strlen(message);
    char_to_hex(message, in_plaintext, l);
    gmp_printf("Plaintext: %Zd\n", in_plaintext);

    // Verschlüsselung
    encrypt(in_plaintext, e, n, ciphertext);
    gmp_printf("Ciphertext: %Zd\n", ciphertext);

    // Entschlüsselung
    decrypt(ciphertext, d, n, out_plaintext);
    gmp_printf("Decrypted cyphertext: %Zd\n", out_plaintext);

    // Konvertiere entschlüsselte Nachricht zurück in String
    char out_message[l+1];
    hex_to_char(out_plaintext, out_message, l);
    printf("Decrypted message: %s\n", out_message);

    // Freigabe des genutzen Speichers
    mpz_clears(p, q, n, e, d, in_plaintext, ciphertext, out_plaintext, NULL);
    gmp_randclear(random_state);

    return 0;
}