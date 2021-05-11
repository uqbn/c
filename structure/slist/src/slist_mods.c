#include <stdlib.h>
#include "slist.h"

#undef slistc_mods

static ssize_t _slistc_mods(Slistc *_dst, size_t _nold, const Slistc *_new);

static ssize_t _slistc_mods(Slistc *_dst, size_t _nold, const Slistc *_new)
{
    Slistc *p = _dst; //pointer
    Slistc *prev = p; //record previous pointer

    for (size_t j = 0; p && j < _nold; j++)
    {
        prev = p;    //record previous pointer
        p = p->next; //goto next
    }

    prev->next = NULL;       //cut list
    slistc_free(_dst->next); //delete list

    Slistc *pnew = slistc_init(); //craete head node

    prev = pnew; //record previous pointer

    _new = _new->next; //skip head node

    while (_new) //traverse lst
    {
        pnew->next = slistc_init(); //create a node
        pnew = pnew->next;          //goto node

        pnew->ch = _new->ch; //assign value

        _new = _new->next; //goto node
    }

    pnew->next = p->next;    //link
    _dst->next = prev->next; //link

    free(prev); //free memory of head node of prev

    return 1;
}

ssize_t slistc_mods(Slistc *_dst, const Slistc *_old, const Slistc *_new)
{
    if (!_dst) //_dst is void
        return -1;
    else if (!_old) //_old is void
        return -2;
    else if (!_new)
        return -3;

    size_t nold = slistc_len(_old); //get length of _old
    if (!nold)                      //if ""
        return 0;                   //failure

    size_t count = 0; //count variable
    ssize_t i = 0;    //subscript

    while ((i = slistc_str(_dst, _old)) > -1) //find _old
    {
        for (size_t j = 0; j < i; j++) //get pointer
            _dst = _dst->next;

        count += _slistc_mods(_dst, nold, _new);
    }

    return count;
}

ssize_t slistc_modsi(Slistc *_dst, const Slistc *_old, const Slistc *_new, size_t _index)
{
    if (!_dst) //_dst is void
        return -1;
    else if (!_old) //_old is void
        return -2;
    else if (!_new)
        return -3;

    size_t nold = slistc_len(_old); //get length of _old
    if (!nold)                      //if ""
        return 0;                   //failure

    size_t count = 0; //count variable
    ssize_t i = 0;    //subscript

    while ((i = slistc_str(_dst, _old)) > -1) //find _old
    {
        if (count == _index)
        {
            for (size_t j = 0; j < i; j++) //get pointer
                _dst = _dst->next;

            count += _slistc_mods(_dst, nold, _new);

            return 1;
        }

        for (size_t j = 0; j < nold; j++) //get pointer
            _dst = _dst->next;
    }

    return 0;
}

ssize_t slistc_mods1(Slistc *_dst, const Slistc *_old, const Slistc *_new)
{
    if (!_dst) //_dst is void
        return -1;
    else if (!_old) //_old is void
        return -2;
    else if (!_new)
        return -3;

    size_t nold = slistc_len(_old); //get length of _old
    if (!nold)                      //if ""
        return 0;                   //failure

    size_t count = 0; //count variable
    ssize_t i = 0;    //subscript

    if ((i = slistc_str(_dst, _old)) > -1) //find _old
    {
        for (size_t j = 0; j < i; j++) //get pointer
            _dst = _dst->next;

        count += _slistc_mods(_dst, nold, _new);
    }

    return count;
}

ssize_t slistc_rmods1(Slistc *_dst, const Slistc *_old, const Slistc *_new)
{
    if (!_dst) //_dst is void
        return -1;
    else if (!_old) //_old is void
        return -2;
    else if (!_new)
        return -3;

    size_t nold = slistc_len(_old); //get length of _old
    if (!nold)                      //if ""
        return 0;                   //failure

    size_t count = 0; //count variable
    ssize_t i = 0;    //subscript

    if ((i = slistc_rstr(_dst, _old)) > -1) //find _old
    {
        for (size_t j = 0; j < i; j++) //get pointer
            _dst = _dst->next;

        count += _slistc_mods(_dst, nold, _new);
    }

    return count;
}

ssize_t slistc_modsn(Slistc *_dst, const Slistc *_old, const Slistc *_new, size_t _n)
{
    if (!_dst) //_dst is void
        return -1;
    else if (!_old) //_old is void
        return -2;
    else if (!_new)
        return -3;

    size_t nold = slistc_len(_old); //get length of _old
    if (!nold)                      //if ""
        return 0;                   //failure

    size_t count = 0; //count variable
    ssize_t i = 0;    //subscript

    while ((i = slistc_str(_dst, _old)) > -1 && count < _n) //find _old
    {
        for (size_t j = 0; j < i; j++) //get pointer
            _dst = _dst->next;

        count += _slistc_mods(_dst, nold, _new);
    }

    return count;
}

ssize_t slistc_rmodsn(Slistc *_dst, const Slistc *_old, const Slistc *_new, size_t _n)
{
    if (!_dst) //_dst is void
        return -1;
    else if (!_old) //_old is void
        return -2;
    else if (!_new)
        return -3;

    size_t nold = slistc_len(_old); //get length of _old
    if (!nold)                      //if ""
        return 0;                   //failure

    size_t count = 0; //count variable
    ssize_t i = 0;    //subscript

    while ((i = slistc_rstr(_dst, _old)) > -1 && count < _n) //find _old
    {
        Slistc *p = _dst;
        for (size_t j = 0; j < i; j++) //get pointer
            p = p->next;

        count += _slistc_mods(p, nold, _new);
    }

    return count;
}