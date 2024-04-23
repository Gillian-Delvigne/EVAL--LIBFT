#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void)
{		 
    // Test de ft_memcpy
    char src[50] = "Hello memcpy!";
    char dest[50];
    ft_memcpy(dest, src, 50);
    printf("Result of ft_memcpy: %s\n", dest);
	memcpy(dest, src, 50);
	printf("Result of memcpy: %s\n", dest);
		printf("\n");
		
    // Test de ft_memset
    ft_memset(dest, 'a', 5);
    printf("Result of ft_memset: %s\n", dest);
	memset(dest, 'b', 5);
    printf("Result of memset: %s\n", dest);
    printf("\n");
    
	// Test de ft_atoi
	printf("Result of ft_atoi: %i\n", ft_atoi("12345"));
	printf("Result of ft_atoi: %i\n", ft_atoi("-456"));
	printf("Result of ft_atoi: %i\n", ft_atoi("2147483647"));
	printf("Result of ft_atoi: %i\n", ft_atoi("-99999999999999999999")); // 0
	printf("Result of ft_atoi: %i\n", ft_atoi("99999999999999999999")); // -1
	printf("Result of atoi: %i\n", atoi("12345"));
	printf("Result of atoi: %i\n", atoi("-456"));
	printf("Result of atoi: %i\n", atoi("2147483647"));
	printf("Result of atoi: %i\n", atoi("-99999999999999999999")); // 0
	printf("Result of atoi: %i\n", atoi("99999999999999999999")); // -1
	printf("\n");
    
    // Test de ft_bzero
    char buffer[10];
	ft_bzero(buffer, sizeof(buffer));
	int numbers[5];
	ft_bzero(numbers, 5 * sizeof(int));
		
    printf("Testing ft_bzero on char array:\n");
    for (unsigned long i = 0; i < sizeof(buffer); i++) {
        if (buffer[i] != 0) {
            printf("Error: buffer[%zu] is not zero!\n", i);
        } else {
            printf("buffer[%zu] is zero.\n", i);
        }
    }
     printf("Testing ft_bzero on int array:\n");
    for (unsigned long i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++) {
        if (numbers[i] != 0) {
            printf("Error: numbers[%zu] is not zero!\n", i);
        } else {
            printf("numbers[%zu] is zero.\n", i);
        }
    }
    printf("\n");
    
    // Test de ft_substr
    char *str2 = "Hello, World!";
	char *substring = ft_substr(str2, 7, 5);
	char *empty_substring = ft_substr(NULL, 0, 10); 
	printf("Result of substr should be World: %s\n", substring); // World
	printf("Result of substr should be (null): %s\n", empty_substring); // (null)
	printf("\n");

	// Test de ft_memmove
	char str3[50] = "Hello, world! This is a test string.";
    
    // Test 1: Copie sans chevauchement
    printf("Original string: %s\n", str3);
    ft_memmove(str3 + 15, str3 + 7, 18); // Déplacement dans la même chaîne
    printf("After ft_memmove without overlap: %s\n", str3);
    // Réinitialisation de la chaîne
    strcpy(str3, "Hello, world! This is a test string.");
	memmove(str3 + 15, str3 + 7, 18);
	printf("After memmove without overlap: %s\n", str3);

    // Test 2: Copie avec chevauchement
	strcpy(str3, "Hello, world! This is a test string.");
	memmove(str3 + 5, str3 + 7, 18);
    printf("After memmove with overlap: %s\n", str3);
	strcpy(str3, "Hello, world! This is a test string.");
    ft_memmove(str3 + 5, str3 + 7, 18); // Déplacement avec chevauchement
    printf("After ft_memmove with overlap: %s\n", str3);

    // Test 3: Copie inversée avec chevauchement
    strcpy(str3, "Hello, world! This is a test string.");
	memmove(str3 + 7, str3 + 5, 18);
	printf("After reverse overlap memmove: %s\n", str3);
	strcpy(str3, "Hello, world! This is a test string.");
    ft_memmove(str3 + 7, str3 + 5, 18); // Déplacement avec chevauchement inverse
    printf("After reverse overlap ft_memmove: %s\n", str3);
	strcpy(str3, "Hello, world! This is a test string.");
    ft_memmove(str3, str3, 0); // Déplacement avec chevauchement inverse
    printf("Same position in ft_memmove: %s\n", str3);
	
    return 0;
}
