#include "expcc.h"
//#include "str.h"
//#include "strbuf.h"

static const char *tabopch = "+-*/!_";
static const char tabop[OPLEN][4] = {"+", "-", "*", "/", "e", "**", "!", "_"};
static const int tabopp[OPLEN] = {1, 1, 2, 2, 4, 4, 3, 3};
static Decimal (*funcop[OPLEN])(Decimal, Decimal) = {decimaladd, decimalsub, decimalmul, decimaldiv, decimale, decimalpow, decimala, decimalc};

typedef struct Stackn
{
    Decimal n;
    struct Stackn *next;
} Stackn;

typedef struct Stacki
{
    int i;
    struct Stacki *next;
} Stacki;

static void freen(Stackn *_h)
{
    if (_h)
    {
        freen(_h->next);
        free(_h);
    }

    return;
}

static void freei(Stacki *_h)
{
    if (_h)
    {
        freei(_h->next);
        free(_h);
    }

    return;
}

static int topn(Stackn *_h, Decimal *_num)
{
    if (_h->next == NULL)
        return -1;

    if (!_num)
        return 0;

    *_num = _h->next->n;

    return 1;
}

static int topi(Stacki *_h, int *_op)
{
    if (_h->next == NULL)
        return -1;

    if (!_op)
        return 0;

    *_op = _h->next->i;

    return 1;
}

static int popn(Stackn *_h, Decimal *_num)
{
    Stackn *next = NULL;

    next = _h->next;
    if (next == NULL)
        return -1;

    if (!_num)
        return 0;

    *_num = next->n;

    _h->next = _h->next->next;
    free(next);

    return 1;
}

static int popi(Stacki *_h, int *_op)
{
    Stacki *next = NULL;

    next = _h->next;
    if (next == NULL)
        return -1;

    if (!_op)
        return 0;

    *_op = next->i;

    _h->next = _h->next->next;
    free(next);

    return 1;
}

static int pushn(Stackn *_h, Decimal _num)
{
    Stackn *p = NULL;

    p = (Stackn *)malloc(sizeof(Stackn));
    if (p == NULL)
        return -1;

    p->n = _num;
    p->next = _h->next;
    _h->next = p;

    return 0;
}

static int pushi(Stacki *_h, int _op)
{
    Stacki *p = NULL;

    p = (Stacki *)malloc(sizeof(Stacki));
    if (p == NULL)
        return -1;

    p->i = _op;
    p->next = _h->next;
    _h->next = p;

    return 0;
}

#ifdef DEBUG

static void shown(Stackn *_h)
{
    _h = _h->next;

    printf("D:");

    while (_h)
    {
        printf("%g/%g ", _h->n.a, _h->n.b);
        _h = _h->next;
    }

    putchar('\n');

    return;
}

static void showi(Stacki *_h)
{
    _h = _h->next;

    printf("P:");

    while (_h)
    {
        printf("%s ", tabop[_h->i]);
        _h = _h->next;
    }

    putchar('\n');

    return;
}

#endif

static size_t strdelc(char *_str, int _ch)
{
    size_t count = 0;
    size_t i = 0;
    size_t j = 0;

    while (_str[i])
    {
        while (_str[i] != (char)_ch && _str[i])
        {
            j++;
            i++;
        }

        while (_str[i] == (char)_ch && _str[i])
        {
            i++;
            count++;
        }

        if (i != j)
        {
            _str[j++] = _str[i++];
        }
    }

    _str[j] = '\0';

    return count;
}

static size_t strdelnc(char *_str, int _ch)
{
    size_t i = 0;

    while (_str[i])
    {
        while (_str[i] != (char)_ch && _str[i])
        {
            i++;
        }

        if (_str[i] == (char)_ch && _str[i])
        {
            i++;
            return strdelc(_str + i, _ch);
        }
    }

    return 0;
}

static int typeop(char *_str)
{
    for (int i = 0; i < OPLEN; i++)
    {
        if (!strcmp(_str, tabop[i]))
            return i;
    }

    return -1;
}

static int expcc1(Stackn *_hnum, Stacki *_hop)
{
    int op = -1;
    Decimal result,
        num1,
        num2;

    popi(_hop, &op);

    popn(_hnum, &num2);
    popn(_hnum, &num1);

    result = funcop[op](num1, num2);

    pushn(_hnum, result);

    return 0;
}

Decimal expcc(const char *_str)
{
    char buffop[BUFSIZ] = {};
    char buffnum[BUFSIZ] = {};
    char buffstr[BUFSIZ] = {};

    Decimal_t num = 0;
    Decimal num1 = {};

    int op = -1;
    int tempop = -1;

    size_t n = strlen(_str) + 1;
    size_t inum = 0;
    size_t iop = 0;
    size_t istr = 0;
    size_t markdel = 0;

    Stackn *hnum = (Stackn *)calloc(1, sizeof(Stackn));
    Stacki *hop = (Stacki *)calloc(1, sizeof(Stacki));

    for (size_t i = 0; i < n;)
    {

#ifdef DEBUG
        int showmark = 1;
#endif

        num1.a = 0;
        num1.b = 1;

        if (isdigit(_str[i]))
        {
            int marke = 0;

            for (inum = 0; i < n; i++)
            {
                if (isxdigit(_str[i]) || strchr("Xx", _str[i]) || _str[i] == '.')
                {
                    buffnum[inum++] = _str[i];

                    if (marke == 1) //1e1-1
                        marke = 0;

                    if (strchr("Ee", _str[i])) //1E1,1e1
                        marke = 1;
                }
                else if (marke && strchr("+-", _str[i])) //1e+-1
                {
                    buffnum[inum++] = _str[i];
                }
                else
                {
                    buffnum[inum] = '\0';
                    break;
                }
            }

            strdelc(buffnum, '+');         //remove +
            marke = strdelc(buffnum, '-'); //remove -

            num = strtod(buffnum, NULL);

            if (markdel % 2) //2*n-1 '-'
            {
                markdel = 0;
                num = -num;
            }

#ifdef SHOW
            if (marke % 2) //2*n-1 '-'
                printf("(1 / %g)", num);
            else
                printf("%g", num);
#endif

            if (marke % 2) //2*n-1 '-'
            {
                num1.b = num; // 1/num
                num1.a = 1;
            }
            else
            {
                num1.a = num; //num/1
                num1.b = 1;
            }

            pushn(hnum, num1);
        }
        else if (strchr(tabopch, _str[i]))
        {
            for (iop = 0; i < n; i++)
            {
                if (strchr(tabopch, _str[i]))
                {
                    buffop[iop++] = _str[i];
                }
                else
                {
                    buffop[iop] = '\0';
                    break;
                }
            }

            if (i >= n) // 1+2* remove *
                break;

            op = typeop(buffop);

            if (op < 0 && topn(hnum, NULL) > -1)
            {
                if (strstr(buffop, "**") || strchr(buffop, '*') || strchr(buffop, '/')) // **+ **- ||  *+ *- || /+ /-
                {
                    strdelc(buffop, '+');
                    markdel = strdelc(buffop, '-');
                }
                else //++ --
                {
                    strdelnc(buffop, '+');           // leave 1 +
                    markdel = strdelnc(buffop, '-'); // leave -

                    if (strlen(buffop) > 1)   // -+
                        strdelc(buffop, '+'); // -+ -> -
                }

                op = typeop(buffop); //try again
                if (op < 0)          //error!
                {
                    printf("\rERROR %s", buffop); //print error option!
                    return num1;                  //return 0/1
                }
            }

            if (topn(hnum, NULL) < 0) // |>> -1 + 1
            {
                strdelc(buffop, '+');
                markdel = strdelc(buffop, '-');

                continue;
            }

            while (topi(hop, &tempop) > 0 && tabopp[op] <= tabopp[tempop])
            {
                expcc1(hnum, hop);
            }

            pushi(hop, op);

#ifdef SHOW
            printf(" %s ", tabop[op]);
#endif
        }
        else if ('(' == _str[i])
        {
            for (istr = 0, i++; i < n; i++)
            {
                buffstr[istr++] = _str[i];

                if (')' == _str[i])
                {
                    buffstr[istr] = '\0';
                    i++;
                    break;
                }
            }

#ifdef SHOW
            putchar('(');
#endif
            num1 = expcc(buffstr);
#ifdef SHOW
            putchar(')');
#endif

            if (markdel % 2)
            {
                markdel = 0;
                num1.a = -num1.a;
            }

            pushn(hnum, num1);
        }
        else
        {
            i++;
#ifdef DEBUG
            showmark = 0;
#endif
        }
#ifdef DEBUG
        if (showmark)
        {
            shown(hnum);
            showi(hop);
        }
#endif
    }

    while (topi(hop, NULL) > -1)
    {
        expcc1(hnum, hop);
    }

    popn(hnum, &num1);

    freen(hnum);
    freei(hop);

    return num1;
}