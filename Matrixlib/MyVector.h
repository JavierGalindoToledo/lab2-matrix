#ifndef _MY_VECTOR_
#define _MY_VECTOR_

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000;


template <class ValType>
class TVector
{
protected:
    ValType* pVector;
    int SizeM;

public:
    TVector();
    TVector(int _v);
    TVector(int s, int si);
    TVector(const TVector& v); 
    virtual ~TVector();

    int GetSize() { return SizeM; } 

    ValType& operator[](int pos);            
    bool operator==(const TVector& v) const; 
    TVector& operator=(const TVector& v);    

    
    TVector operator+(const ValType& val); 
    TVector operator-(const ValType& val); 
    TVector operator*(const ValType& val); 
    TVector operator/(const ValType& val); 

    
    TVector operator+(const TVector& v); 
    TVector operator-(const TVector& v); 
    TVector operator*(const TVector& v); 

    
    friend istream& operator>>(istream& in, TVector& v)
    {
        for (int i = 0; i < v.SizeM; i++)
        {
            in >> v.pVector[i];
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, const TVector& v)
    {
        for (int i = 0; i < v.SizeM; i++)
        {
            out << v.pVector[i] << '\t';
        }
        return out;
    }
};

template <class ValType>
inline TVector<ValType>::TVector()
{
    SizeM = NULL;
}

template <class ValType>
TVector<ValType>::TVector(int v)
{
    if (v < 0 || v > MAX_VECTOR_SIZE)
    {
        throw logic_error("ERROR");
    }

    SizeM = v;
    pVector = new ValType[SizeM];

    for (int i = 0; i < SizeM; i++)
    {
        pVector[i] = v;
    }
}

template <class ValType>
TVector<ValType>::TVector(int s, int si)
{
    if (si < 0)
    {
        throw logic_error("ERROR");
    }

    SizeM = s;
    pVector = new ValType[SizeM];

    for (int i = 0; i < SizeM; i++)
    {
        pVector[i] = si;
    }
}

template <class ValType>
TVector<ValType>::TVector(const TVector<ValType>& v)
{
    SizeM = v.SizeM;
    pVector = new ValType[SizeM];

    for (int i = 0; i < SizeM; i++)
    {
        pVector[i] = v.pVector[i];
    }
}

template <class ValType>
TVector<ValType>::~TVector()
{
    SizeM = NULL;

    if (pVector != 0)
    {
        delete[] pVector;
    }

    pVector = NULL;
}

template <class ValType>
ValType& TVector<ValType>::operator[](int index)
{
    if (index < 0 || index > SizeM)
    {
        throw logic_error("ERROR");
    }

    if ((index >= 0) && (index < SizeM))
    {
        return pVector[index];
    }

    return pVector[0];
}

template <class ValType>
bool TVector<ValType>::operator==(const TVector& v) const
{
    bool res = true;
    if (SizeM != v.SizeM)
    {
        res = false;
    }

    for (int i = 0; i < SizeM; i++)
    {
        if (pVector[i] != v.pVector[i])
        {
            res = false;
        }
    }
    return res;
}

template <class ValType>
TVector<ValType>& TVector<ValType>::operator=(const TVector& v)
{
    if (this == &v)
    {
        return *this;
    }

    SizeM = v.SizeM;
    pVector = new ValType[SizeM];

    for (int i = 0; i < SizeM; i++)
    {
        pVector[i] = v.pVector[i];
    }
    return *this;
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator+(const ValType& val)
{
    TVector<ValType> res;
    res.SizeM = SizeM;
    res.pVector = new ValType[res.SizeM];

    for (int i = 0; i < res.SizeM; i++)
    {
        res.pVector[i] = pVector[i] + val;
    }
    return res;
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator-(const ValType& val)
{
    TVector<ValType> res;
    res.SizeM = SizeM;
    res.pVector = new ValType[res.SizeM];

    for (int i = 0; i < res.SizeM; i++)
    {
        res.pVector[i] = pVector[i] - val;
    }
    return res;
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator*(const ValType& val)
{
    TVector<ValType> res;
    res.SizeM = SizeM;
    res.pVector = new ValType[res.SizeM];

    for (int i = 0; i < res.SizeM; i++)
    {
        res.pVector[i] = pVector[i] * val;
    }
    return res;
}

template <class ValType>
inline TVector<ValType> TVector<ValType>::operator/(const ValType& val)
{
    TVector<ValType> res;
    res.SizeM = SizeM;
    res.pVector = new ValType[res.SizeM];

    for (int i = 0; i < res.SizeM; i++)
    {
        res.pVector[i] = pVector[i] / val;
    }
    return res;
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType>& v)
{
    if (v.SizeM != SizeM)
    {
        throw logic_error("ERROR");
    }

    TVector<ValType> res;
    res.SizeM = SizeM;
    res.pVector = new ValType[res.SizeM];

    for (int i = 0; i < res.SizeM; i++)
    {
        res.pVector[i] = pVector[i] + v.pVector[i];
    }
    return res;
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType>& v)
{
    if (v.SizeM != SizeM)
    {
        throw logic_error("ERROR");
    }

    TVector<ValType> res;
    res.SizeM = SizeM;
    res.pVector = new ValType[res.SizeM];

    for (int i = 0; i < res.SizeM; i++)
    {
        res.pVector[i] = pVector[i] - v.pVector[i];
    }
    return res;
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator*(const TVector<ValType>& v)
{
    if (v.SizeM != SizeM)
    {
        throw logic_error("ERROR");
    }

    TVector<ValType> res;
    res.SizeM = SizeM;
    res.pVector = new ValType[res.SizeM];

    for (int i = 0; i < res.SizeM; i++)
    {
        res.pVector[i] = pVector[i] * v.pVector[i];
    }
    return res;
}
#endif 