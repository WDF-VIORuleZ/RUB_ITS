#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void print_array(int *array, size_t size);
void print_array(int *array, size_t size);
int *generate_array(size_t size);
int *sort_array(int *array, size_t size);


int main(int argc, char **argv)
{
    const unsigned int size = 12;
    int *res, *nums = generate_array(size);

    print_array(nums, size);
    res = sort_array(nums, 12);
    print_array(res, size);

    return EXIT_SUCCESS;
}

void print_array(int *array, size_t size)
{
    for(int i = 0; i < size; i++)
        fprintf(stdout, "[%d] : (%d)  ", i, *(array + i));
    puts("");
}

int *generate_array(size_t size)
{
    srand(time(NULL));
    int *result = calloc(size, sizeof(int)*size);

    for(int i = 0; i < size; i++)
    {
        int akt = 0;
        do akt = 2 + rand() % 30;
        while(akt % 2 != 0 && akt > 0 && akt <= 32);

        *(result + i) = akt;
    }
    return result;
}

int *sort_array(int *array, size_t size)
{
    int *result            = array;
    int akt, next, tmp,  i = 0;
    int count = 0;

    do
    {
        akt  = *(result + i);
        next = *(result + i + 1);

        printf("\n[POS_SANTA] : %d\n", i);
        print_array(array, size);

        if (akt > next)
        {
            tmp               = next;
            *(result + i + 1) = akt;
            *(result + i)     = tmp;

            if (i > 0) i--;
        }
        else i++;
        count++;
    }
    while(i < (size - 1) || (*(array + size - 1) < *(array + size - 2)));
    printf("\nCOUNTER: %d\n", count);

    return result;
}
