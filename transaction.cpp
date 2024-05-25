#include "transaction.h"

Transaction::Transaction()
{
    type = ' ';
    id = -1;
    medt = ' ';
    movt = ' ';
}

Transaction::Transaction(char t)
{
    type = t;
    id = -1;
    medt = ' ';
    movt = ' ';
}

Transaction::Transaction(char t, int id)
{
    type = t;
    this->id = id;
    medt = ' ';
    movt = ' ';
}

Transaction::Transaction(char t, int id, char medt, char movt, int stock, string director, string title, int year)
{
    type = t;
    this->id = id;
    this->medt = medt;
    this->movt = movt;
    
}

Transaction::Transaction(char t, int id, char medt, char movt, int stock, string director, string title, int year, string actor, int date)
{
    type = t;
    id = id;
    this->medt = medt;
    this->movt = movt;
}

char Transaction::getType()
{
    return type;
}

char Transaction::getMediaType()
{
    return medt;
}

char Transaction::getMovieType()
{
    return movt;
}

int Transaction::getId()
{
    return id;
}

//only used for inventory validation
bool Transaction::validTransaction(char t)
{
    if(t != 'I')
    {
        return false;
    }
    else
    {
        return true;
    }
}

//history validation
bool Transaction::validTransaction(char t, int id)
{
    if(t != 'H')
    {
        return false;
    }
    //function needs to be added
    else if(!doesCustomerExist(id))
    {
        return false;
    }
    else
    {
        return true;
    }
}

//borrow and return non classic validation
bool Transaction::validTransaction(char t, int id, char medt, char movt, int stock, string director, string title, int year)
{
    if(t != 'B' || t != 'R')
    {
        return false;
    }
    //function needs to be added
    else if(!doesCustomerExist(id))
    {
        return false;
    }
    else if(medt != 'D')
    {
        return false;
    }
    else if(movt != 'D' || movt != 'F' || movt != 'C')
    {
        return false;
    }
    else if (!doesMediaExist(title))
    {
        return false;
    }
    else
    {
        return true;
    }
}

//borrow and return classic validation
bool Transaction::validTransaction(char t, int id, char medt, char movt, int stock, string director, string title, int year, string actor, int date)
{
        if(t != 'B' || t != 'R')
    {
        return false;
    }
    //function needs to be added
    else if(!doesCustomerExist(id))
    {
        return false;
    }
    else if(medt != 'D')
    {
        return false;
    }
    else if(movt != 'D' || movt != 'F' || movt != 'C')
    {
        return false;
    }
    else if (!doesMediaExist(title))
    {
        return false;
    }
    else
    {
        return true;
    }
}
