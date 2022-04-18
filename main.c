// ABDULLAH YILMAZ
// YAZILIM MÜHENDÝSLÝÐÝ 1. SINIF
// 210229027

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>

void Soft(char *text);                       // Yumuþak ünsüzleri bulduran fonksiyon
void Strong(char *text);                     // Sert ünsüzleri bulduran fonksiyon
void Palatal(char *array[], int word_count); // Büyük ünlü bulduran fonksiyon
void wordSearch(char *word, char *array[], int word_count);
void Labial(char *array[], int word_count);

int main()
{
    SetConsoleCP(1254);
    SetConsoleOutputCP(1254);
    setlocale(LC_ALL, "Turkish_turkish.1254");

    printf("***** THE TURKISH GRAMMAR DETECTÝON STARTED *****\n");
    int plural = 0, p = 0; // for the plural

    int choose = 1, word = 0, j, k, sentence = 0, letter = 0, connexion = 0;
    int i = 0, c = 0;
    char text[10000];
    printf("TEXT\n");
    gets(text);
    char tempText[10000];
    strlwr(text);
    strcpy(tempText, text);
    char *token = strtok(tempText, " ");
    char *array[1000];
    int word_count = 0;
    char target[100];
    while (token != NULL)
    {
        array[word_count] = token;
        token = strtok(NULL, " .,?!;:'");
        word_count++;
    }
    printf("TEXT = %s\n", text);
    char *sesli = "aeiýöüouAEIÝÖÜOU";
    char *sessiz = "b, z, y, v, t, þ, s, r, p, n, r, m, l, k, h, j, ð, g, d, ç, c,B ,Z ,Y, V, T, Þ, S, R, P, N, R, M, L, K, H, J, Ð, G, D, Ç, C";
    // Ý FÝND THE PLURAL COUNT
    for (int p = 0; p < strlen(text); p++)
    {
        if (text[p] == 'l' && text[p + 1] == 'a' && text[p + 2] == 'r')
            plural++;
    }
    for (int p = 0; p < strlen(text); p++)
    {
        if (text[p] == 'l' && text[p + 1] == 'e' && text[p + 2] == 'r')
        {
            plural++;
        }
    }
    // Ý FÝND THE WORD COUNT

    for (k = 0; k < strlen(text); k++)
    {
        if (text[k] == ' ')
        {
            word++;
        }
    }
    // Ý FÝND THE LETTER COUNT

    for (k = 0; k < strlen(text); k++)
    {
        if (!(text[k] == '.' || text[k] == '?' || text[k] == '!' || text[k] == '...' || text[k] == ';' ||
              text[k] == ':' || text[k] == ' '))
        {
            letter++;
        }
    }
    // Ý FÝND THE SENTENCE COUNT

    for (k = 0; k < strlen(text); k++)
    {
        if (text[k] == '.' || text[k] == '?' || text[k] == '!' || text[k] == '...' || text[k] == ';' ||
            text[k] == ':')
        {
            sentence++;
        }
    }
    for (k = 0; k < strlen(text); k++)

    {
        if ((strchr(sessiz, (int)text[c]) != NULL) && (text[c + 1] == ' ') && (strchr(sesli, (int)text[c + 2]) != NULL))
            connexion++;
        c++;
    }

    while (choose != 0)
    {

        printf("1-Find the connexion\n");
        printf("2-Find the palatal harmony\n");
        printf("3-Find the labial harmony\n");
        printf("4-Find the strong-soft count\n");
        printf("5-Find the plural words\n");
        printf("6-Find the number of words\n");
        printf("7-Find the number of sentences\n");
        printf("8-Find the number of letters\n");
        printf("9-Search the word\n");
        printf("0-Exit\n");

        printf("choose the process\n", choose);
        scanf("%d", &choose);
        switch (choose)
        {
        case 0:

            break;
        case 1:
            printf("Text = %s \n", text);

            printf("Number of connexion : %d\n", connexion);

            break;
        case 2:
            Palatal(array, word_count);

            break;
        case 3:
            Labial(array, word_count);
            break;
        case 4:
            Strong(text);
            Soft(text);
            break;
        case 5:
            printf("Number of plural : %d\n", plural);
            break;
        case 6:

            printf("Text = %s \n", text);

            printf("%d\n", word + 1);

            break;

        case 7:
            printf("Text = %s \n", text);

            printf("%d\n", sentence);
            break;
        case 8:

            printf("Text = %s \n", text);

            printf("Letter = %d\n", letter);

            break;
        case 9:
            printf("Please enter the word you want to search = ");
            fflush(stdin);
            gets(target);
            wordSearch(target, array, word_count);
            break;

        default:
            printf("Please enter number 1-9\n");
        }
    }
    printf("***** THE TURKISH GRAMMAR DETECTÝON FÝNÝSHED *****\n");

    return 0;
}

void Soft(char *text)
{

    int soft = 0;
    for (int i = 0; i <= strlen(text); i++)
    {
        if (text[i] == 'b' || text[i] == 'c' || text[i] == 'd' || text[i] == 'g' || text[i] == 'j' || text[i] == 'l' || text[i] == 'm' || text[i] == 'n' || text[i] == 'r' || text[i] == 'v' || text[i] == 'y' || text[i] == 'z' || text[i] == 'ð')
        {
            soft++;
        }
    }
    printf("Number of soft letters : %d\n", soft);
}
void Strong(char *text)
{

    int strong = 0;
    for (int i = 0; i <= strlen(text); i++)
    {
        if (text[i] == 'f' || text[i] == 's' || text[i] == 't' || text[i] == 'k' || text[i] == 'ç' || text[i] == 'þ' || text[i] == 'h' || text[i] == 'p')
        {
            strong++;
        }
    }
    printf("Number of strong letters : %d \n", strong);
}
// PALATAL FUNCTÝON
void Palatal(char *array[], int word_count)
{
    char *buyuk[1000];
    int buyuk_sayisi = 0;
    int kalin = 0, ince = 0;

    for (int i = 0; i < word_count; i++)
    {
        kalin = 0;
        ince = 0;
        for (int k = 0; k < strlen(array[i]); k++)
        {
            if (array[i][k] == 'a' || array[i][k] == 'ý' || array[i][k] == 'o' || array[i][k] == 'u')
            {
                kalin = 1;
            }
            if (array[i][k] == 'e' || array[i][k] == 'i' || array[i][k] == 'ö' || array[i][k] == 'ü')
            {
                ince = 1;
            }
        }

        if (!(kalin == 1 && ince == 1))
        {
            buyuk[buyuk_sayisi] = array[i];
            buyuk_sayisi++;
        }
    }
    printf("Number of palatals : %d\n", buyuk_sayisi);
    printf("Palatals:\n");
    for (int i = 0; i < buyuk_sayisi; i++)
    {
        printf("%s ,", buyuk[i]);
    }
    printf("\n");
}

void Labial(char *array[], int word_count)
{
    char *kucuk[1000];
    int kucuk_sayisi = 0;
    int duz = 0, yuvarlak = 0;

    for (int i = 0; i < word_count; i++)
    {
        duz = 0;
        yuvarlak = 0;
        for (int k = 0; k < strlen(array[i]); k++)
        {
            if (array[i][k] == 'a' || array[i][k] == 'e' || array[i][k] == 'ý' || array[i][k] == 'i')
            {
                duz = 1;
            }
            if (array[i][k] == 'o' || array[i][k] == 'ö' || array[i][k] == 'u' || array[i][k] == 'ü')
            {
                yuvarlak = 1;
            }
        }

        if (duz != 1 || yuvarlak != 1)
        {
            kucuk[kucuk_sayisi] = array[i];
            kucuk_sayisi++;
        }
    }
    printf("Numbers of labial : %d \n", kucuk_sayisi);
    printf("Labials :\n");
    for (int i = 0; i < kucuk_sayisi; i++)
    {
        printf("%s ,", kucuk[i]);
    }
    printf("\n");
}

void wordSearch(char *word, char *array[], int word_count)
{
    int count = 0;
    for (int i = 0; i < word_count; i++)
    {
        if (strcmp(word, array[i]) == 0)
        {
            count++;
        }
    }
    printf("%s were found %d times.\n", word, count);
}
