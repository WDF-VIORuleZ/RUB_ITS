#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define SIZEOF(a) (sizeof &a / sizeof a[0])

typedef struct mensa_table{
    const char  *_src;
    unsigned int _rows;
}m_t;

typedef struct item{
    char _tag[2+1], 
         _angebot[18+1], 
         _name[31+1], 
         _preis_s[4+1], 
         _preis_b[4+1], 
         _ort[6+1];
}item;

void m_log(item *i);
void str_to_it(char *src, char *ort, item *item);
void angeboteEinlesen(m_t _in[3], item **_arrs);
void tagesplanBilden(item _bi[], item _qw[], item _me[]);

int main(int argc, char **argv)
{
    if (argc == 7)
    {
        item *_orte_arrs[3];
        m_t _in_files[3];
        int it = 0;

        for (int i = 1; i < 6; i+= 2)
        {
            if ((fopen(argv[i], "r")) != NULL)
            {
                m_t tmp;
                tmp._src      = argv[i];
                tmp._rows     = atoi(argv[i + 1]);
                _in_files[it] = tmp;

                printf("[+] Added %12s [r = %3d]\n", tmp._src, tmp._rows);
                it++;
            }
            else
            {
                perror("Unable to open file. Exit.");
                return EXIT_FAILURE;
            }
        }

        angeboteEinlesen(_in_files, _orte_arrs);
        tagesplanBilden(_orte_arrs[0], _orte_arrs[1], _orte_arrs[2]);

        return EXIT_SUCCESS;
    }
    else
    {
        perror("Not enough arguments.");
        return EXIT_FAILURE;
    }
}

// Helper Functions
void m_log(item *i)
{   
    FILE *f;

    char _f_name[8] = { 0 };
    strncpy(_f_name, i->_tag, 2);
    strcat(_f_name, ".txt");

    if (access(_f_name, F_OK) != -1)
        f = fopen(_f_name, "a");
    else
        f = fopen(_f_name, "ab+");   

   // fprintf(stdout," DBG %5s %s %s %s %s\n", i->_ort, i->_angebot, i->_name, i->_preis_s, i->_preis_b);
    fprintf(f,"%7s %s %s %s\n", i->_ort, i->_angebot, i->_name, i->_preis_s);
    fclose(f);
}

void str_to_it(char *src, char *ort, item *item)
{   
    struct item _tmp;
    // works 4 me :)
    bzero(&_tmp._preis_s, 5);

    strncpy(_tmp._ort, ort, SIZEOF(ort));
    strncpy(_tmp._tag, src, 2);
    strncpy(_tmp._angebot , &src[3],18);
    strncpy(_tmp._name    , &src[21], 31);
    strncpy(_tmp._preis_s , &src[52], 4);
    strncpy(_tmp._preis_b , &src[57], 4);
    
    memcpy(item, &_tmp, sizeof(_tmp));
}

void angeboteEinlesen(m_t _in[3], item **_arrs)
{
    for (int k = 0; k < 3; k++)
    {
        char *line_buf = (char*) malloc(64*sizeof(char));
        FILE *file     = fopen(_in[k]._src, "r");

        // ohne file_extension
        size_t _size   = strlen(_in[k]._src) - 4;
        char *ort      = (char*) malloc(sizeof(char) * (_size + 1));
        strncpy(ort, &_in[k]._src[0], _size);

        for (size_t l = 0; l < _in[k]._rows; l++)
        {
            item it;
            fgets(line_buf, 64, file);
            str_to_it(line_buf, ort, &it);
            m_log(&it);
        }
    }
}

void tagesplanBilden(item _bi[], item _qw[], item _me[])
{
    for (size_t i = 0; i < SIZEOF(_bi); i++)
        m_log(&_bi[i]);

    for (size_t i = 0; i < SIZEOF(_qw); i++)
        m_log(&_qw[i]);
    
    for (size_t i = 0; i < SIZEOF(_me); i++)
        m_log(&_me[i]);
}