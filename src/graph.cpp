#include "../inc/graphlist.hh"


bool Vertex::operator !=(Vertex v)
{
    if (this->vertexListPosition == v.vertexListPosition)
    {
        return false;
    }
    else
    {
        return true;
    } 
}

bool Edge::operator !=(Edge e)
{
    if (this->sourceVertex == e.sourceVertex && this->destinationVertex == e.destinationVertex && this->weight == e.weight)
    {
        return false;
    }
    else
    {
        return true;
    }
}


bool Vertex::operator ==(Vertex v)
{
    if (this->label == v.label)
    {
        return true;
    }
    else
    {
        return false;
    } 
}

bool Edge::operator ==(Edge e)
{
    if (this->sourceVertex == e.sourceVertex && this->destinationVertex == e.destinationVertex && this->weight == e.weight)
    {
        return true;
    }
    else
    {
        return false;
    }
}

