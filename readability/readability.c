#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string input);
int count_words(string input);
int count_sentences(string input);
double calc_index(long letters, long words, long sentences);

unsigned long c;

int main(void)
{
    string input = get_string("Text: ");
    long cL =  count_letters(input);
    long cW =  count_words(input);
    long cS =  count_sentences(input);

    double index = calc_index(cL, cW, cS);
    int answer = round(index);

    if (answer < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (answer >= 1 && answer < 16)
    {
        printf("Grade %i\n", answer);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string input)
{
    unsigned long len = strlen(input);
    unsigned long count = 0;
    for (c = 0; c < len; c++)
        {
            if ((input[c] >= 65 && input[c] <= 90) || (input[c] >= 97 && input[c] <= 122))
            {
                count++;
            }
            else count += 0;
        }
    return count;
}

int count_words(string input)
{
    unsigned long len = strlen(input);
    unsigned long count = 0;
    for (c = 0; c < len; c++)
        {
            if ((input[c] >= 65 && input[c] <= 90) || (input[c] >= 97 && input[c] <= 122))
            {
                if (input[c+1] == 32) count++;

                else count+= 0;
            }
            else
            {
                if (input[c+1] == 32 || input[c+1] == 0) count++;

                else count += 0;
            }
        }

    return count;
}

int count_sentences(string input)
{
    unsigned long len = strlen(input);
    unsigned long count = 0;

    for (c = 0; c < len; c++)
    {
        if (input[c+1] == 46 || input[c+1] == 63 || input[c+1] == 33)
        {
            count++;
        }
    }
    return count;
}

double calc_index(long letters, long words, long sentences)
{
    double L =  ((double)letters / words) * 100;
    double S = ((double)sentences / words) * 100.0;

    double result = ((0.0588 * L) - (0.296 * S) - 15.8);

    return  result;

}