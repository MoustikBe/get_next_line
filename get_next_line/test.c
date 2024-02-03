#include <stdio.h>

static char test[] = "Bonjour";
char *ft_test()
{
    int count = 7;
    int count2 = 0;
    while(test[count] != '\0')
    {
        test[count2] = test[count]; 
        count++;
    } 
    return(test);
}

int main(void)
{
    char *try; 
    printf("Valeur de test --> %s \n", test);
    ft_test();
    printf("Valeur de test --> %s \n", test);
    ft_test();
    printf("Valeur de test --> %s \n", test);
}