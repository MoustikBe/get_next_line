
#include "get_next_line.h"

static int current_position = 0;
 

int ft_strlen(char *str)
{
    int count;

    count = 0; 
    while (str[count] != '\0')
        count++;
    return(count);
}
char *ft_strrch(char *s, int c)
{
    int count; 

    count = ft_strlen(s);
    while(count >= 0)
    {
        if (s[count] == (char)c)
            return &s[count];
        count--; 
    }
    return(NULL);
}
char *ft_strjoin(char *s1, char *s2)
{
	int len1;
	int len2;
	int count;
	char *new_char; 

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	count = 0; 
	new_char = malloc((len1 + len2) * sizeof(char));
	if (new_char == NULL)
		return(NULL);
	if (s1 && s2) 
	{
		while(s1[count] != '\0')
		{
			new_char[count] = s1[count];
			count++; 
		}
		count = 0;
		while(s2[count] != '\0')
		{
			new_char[len1] = s2[count];
			count++;
			len1++;
		}
		new_char[len1] = '\0';  
	}
	return(new_char);
}
char *ft_cpy(char *s1, char *s2)
{
    int count = 0; 
    int len_s1 = ft_strlen(s1);

    while(s2[count] != '\n')
        s1[len_s1++] = s2[count++];
    return(s1);

}
char *ft_recall(char *s1)
{
    int count; 
    int count2; 

    count2 = 0;
    count = 0; 
    while(s1[count] != '\n')
        count++;
    count = count + 1;
    while(s1[count] != '\0')
    {
        count++;
        s1[count2] = s1[count];
        count2++;
    }
    return(s1);
}

char *get_next_line(int fd)
{
    int nb_byt = 5;
    int result;
    int count = 0;
    char *str = malloc(sizeof(char) * 100);
    char *str_new = malloc(sizeof(char) * 100);
    char *new_char = malloc(sizeof(char) * 100);

    if (!str || !str_new || !new_char)
        return NULL;
    result = read(fd, str, 20);
    while (result && ft_strrch(str, '\n') == NULL)
    {
        // # --- Ajout du caractere 0 --- # 
        str[result] = '\0';
        //printf("%s\n", str);
        
        // # --- Concatenation  --- # //
        //printf("%s -> AVANT APPEL \n", str_new);
        str_new = ft_strjoin(str_new, str);
        printf("%s -> APRES APPEL \n", str_new);
        
        // # --- Rappelle de read pour continuer la boucle --- # //   
        result = read(fd, str, 15);
        if (ft_strrch(str, '\n') != NULL)
        {
            ft_cpy(str_new, str);
            // -- Parite de gestion de rapelle (Pas oublier le rajout d'une verif de fin de fichier)-- //
            ft_recall(str);
            // -- Parite de gestion de rapelle -- //
            printf("%s\n", str_new);
        }
    }
    free(str);
    free(str_new);
    free(new_char);
    return(str_new);
}
int main (void)
{
    int fd = open("./get_next_line.h", O_RDONLY);
    get_next_line(fd);
    printf("\n");
    get_next_line(fd);
    return(0);
}

