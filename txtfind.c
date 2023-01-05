#include <stdio.h>
#include <stdbool.h>

#define LINE    256
#define WORD    30

int getLine(char destination[])
{
    int ret, i;
    for (i = 0; i < LINE; i++)
    {
        ret = scanf("%c", destination+i);
        if (ret == EOF)
            break;
        
        if (destination[i] == '\n')
            break;
    }
    
    return i;
}

int getNextWord(char w[], char l[], int l_size, int start)
{
    int i;
    for (i = start; i < l_size; i++)
    {
        if (l[i] == '\n' || l[i] == '\t' || l[i] == ' ')
            break;

        w[i-start] = l[i];
    }

    return i-start;
}

bool equalSubStrings(char str1[], int str1_start, int str1_end, char str2[], int str2_start, int str2_end)
{
    if (str1_end-str1_start != str2_end-str2_start)
        return false;

    for (int i = 0; i < str1_end-str1_start; i++)
    {
        if (str1[str1_start+i] != str2[str2_start+i])
            return false;
    }

    return true;
}

void copyStringAndSkipIndex(char destination[], char original[], int original_size, int skip_index)
{
    int fixed_index = 0;
    for (int i = 0; i < original_size; i++)
    {
        if (i != skip_index)
        {
            destination[fixed_index] = original[i];
            fixed_index++;
        }
    }
    
}
bool isSimilar(char str1[], int str1_end, char str2[], int str2_end)
{
    if (str1_end > str2_end+1 || str1_end < str2_end)
        return false;

    if ( equalSubStrings(str1, 0, str1_end-1, str2, 0, str2_end-1) )
        return true;

    for (int i = 0; i < str1_end; i++)
    {
        char temp[WORD];
        copyStringAndSkipIndex(temp, str1, str1_end, i);

        if( equalSubStrings(temp, 0, str1_end-1, str2, 0, str2_end) )
            return true;
    }

    return false;
}

bool isSubstring(char str1[], int str1_end, char str2[], int str2_end)
{
    if (str1_end < str2_end)
        return false;

    if ( equalSubStrings(str1, 0, str1_end-1, str2, 0, str2_end-1) )
        return true;

    for (int i = 0; i <= str1_end-str2_end; i++)
    {
        if( equalSubStrings(str1, i, i+str2_end, str2, 0, str2_end) )
            return true;
    }
    
    return false;
}

void print_lines(char str[], int str_size, bool similar_mode)
{
    char line[LINE];
    int line_size = getLine(line);

    while (line_size != 0)
    {
        int current = 0;

        if (!similar_mode && isSubstring(line, line_size, str, str_size))
            printf("%.*s\n", line_size, line);
        
        while (similar_mode && current < line_size)
        {
            char word[WORD];
            int word_size = getNextWord(word, line, line_size, current);
            

            if (word_size != 0)
            {
                bool print = false;
                if (isSimilar(word, word_size, str, str_size))
                    print = true;
                
                if (print)
                {
                    printf("%.*s\n", word_size, word);
                }
            }

            current += word_size+1;
        }
        
        line_size = getLine(line);
    }
}

int main()
{
    char first_line[LINE];
    int first_line_size = getLine(first_line);

    char search_key[WORD];
    bool similar_mode = true;

    int i;
    for (i = 0; i < first_line_size; i++)
    {
        if (first_line[i] == ' ' || first_line[i] == '\t')
        {
            if (first_line[i+1] == 'a')
                similar_mode = false;
            
            break;
        }

        search_key[i] = first_line[i];
    }

    char temp[WORD];
    scanf("%c", temp);

    print_lines(search_key, i, similar_mode);
}
