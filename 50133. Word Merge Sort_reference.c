#include <stdio.h>
#include <string.h>
#define STRLEN 100000
#define K 3
void merge (char *source1, char *source2, char *destination)
{
    while (*source1 != '\0' && *source2 != '\0')
    {
        if (strncmp (source1, source2, K) < 0)
        {
            strncpy (destination, source1, K);
            source1 += K;
        }
        else
        {
            strncpy (destination, source2, K);
            source2 += K;
        }
        destination += K;
    }
    strcpy (destination, *source1 == '\0' ? source2 : source1);
}
 
int main()
{
    char source2[STRLEN] = "", result[STRLEN] = "";
    scanf("%s", result);
    while (scanf("%s", source2) != EOF)
    {
        char temp[STRLEN] = "";
        merge (result, source2, temp);
        strcpy (result, temp);
        printf("%s\n", result);
    }
    return 0;
}