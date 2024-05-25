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