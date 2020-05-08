#include "../inc/graphlist.hh"





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

