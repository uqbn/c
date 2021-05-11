#include <stdlib.h>
#include "slist.h"

#undef slistc_dels

static ssize_t _slistc_dels(Slistc *_dst, size_t _n);

static ssize_t _slistc_dels(Slistc *_dst, size_t _n)
{
    Slistc *p = _dst; //pointer
    Slistc *prev = p; //record previous pointer

    for (size_t j = 0; p && j < _n; j++) //get pointer
    {
        prev = p;    //record previous pointer
        p = p->next; //goto next
    }

    prev->next = NULL;       //cut list
    slistc_free(_dst->next); //delete list

    _dst->next = p->next; //link list

    return 1;
}

ssize_t slistc_dels(Slistc *_dst, const Slistc *_src)
{
    if (!_dst) //_dst is void
        return -1;
    else if (!_src) //_src is void
        return -2;

    size_t nsrc = slistc_len(_src); //get length of _src
    if (!nsrc)                      //if ""
        return 0;                   //failure

    size_t count = 0; //count variable
    ssize_t i = 0;    //subscript

    while ((i = slistc_str(_dst, _src)) > -1)
    {
        for (size_t j = 0; j < i; j++) //get pointer
            _dst = _dst->next;

        count += _slistc_dels(_dst, nsrc); //delete
    }

    return count; //count of delete
}

ssize_t slistc_delsi(Slistc *_dst, const Slistc *_src, size_t _index)
{
    if (!_dst) //_dst is void
        return -1;
    else if (!_src) //_src is void
        return -2;

    size_t nsrc = slistc_len(_src); //get length of _src
    if (!nsrc)                      //if ""
        return 0;                   //failure

    size_t count = 0; //count variable
    ssize_t i = 0;    //subscript

    while ((i = slistc_str(_dst, _src)) > -1)
    {
        if (count++ == _index)
        {
            for (size_t j = 0; j < i; j++) //get pointer
                _dst = _dst->next;

            _slistc_dels(_dst, nsrc); //delete

            return 1;
        }

        for (size_t j = 0; j < nsrc; j++) //get pointer
            _dst = _dst->next;
    }

    return 0; //count of delete
}

ssize_t slistc_dels1(Slistc *_dst, const Slistc *_src)
{
    if (!_dst) //_dst is void
        return -1;
    else if (!_src) //_src is void
        return -2;

    size_t nsrc = slistc_len(_src); //get length of _src
    if (!nsrc)                      //if ""
        return 0;                   //failure

    size_t count = 0; //count variable
    ssize_t i = 0;    //subscript

    if ((i = slistc_str(_dst, _src)) > -1)
    {
        for (size_t j = 0; j < i; j++) //get pointer
            _dst = _dst->next;

        count += _slistc_dels(_dst, nsrc); //delete
    }

    return count; //count of delete
}

ssize_t slistc_rdels1(Slistc *_dst, const Slistc *_src)
{
    if (!_dst) //_dst is void
        return -1;
    else if (!_src) //_src is void
        return -2;

    size_t nsrc = slistc_len(_src); //get length of _src
    if (!nsrc)                      //if ""
        return 0;                   //failure

    size_t count = 0; //count variable
    ssize_t i = 0;    //subscript

    if ((i = slistc_rstr(_dst, _src)) > -1)
    {
        for (size_t j = 0; j < i; j++) //get pointer
            _dst = _dst->next;

        count += _slistc_dels(_dst, nsrc); //delete
    }

    return count; //count of delete
}

ssize_t slistc_delsn(Slistc *_dst, const Slistc *_src, size_t _n)
{
    if (!_dst) //_dst is void
        return -1;
    else if (!_src) //_src is void
        return -2;

    size_t nsrc = slistc_len(_src); //get length of _src
    if (!nsrc)                      //if ""
        return 0;                   //failure

    size_t count = 0; //count variable
    ssize_t i = 0;    //subscript

    while ((i = slistc_str(_dst, _src)) > -1 && count < _n)
    {
        for (size_t j = 0; j < i; j++) //get pointer
            _dst = _dst->next;

        count += _slistc_dels(_dst, nsrc); //delete
    }

    return count; //count of delete
}

ssize_t slistc_rdelsn(Slistc *_dst, const Slistc *_src, size_t _n)
{
    if (!_dst) //_dst is void
        return -1;
    else if (!_src) //_src is void
        return -2;

    size_t nsrc = slistc_len(_src); //get length of _src
    if (!nsrc)                      //if ""
        return 0;                   //failure

    size_t count = 0; //count variable
    ssize_t i = 0;    //subscript

    while ((i = slistc_rstr(_dst, _src)) > -1 && count < _n)
    {
        Slistc *p = _dst;
        for (size_t j = 0; j < i; j++) //get pointer
            p = p->next;

        count += _slistc_dels(p, nsrc); //delete
    }

    return count; //count of delete
}