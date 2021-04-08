#pragma once

#include <iostream>
#include <string>

#include "utils.h"


#ifndef ISLOT_H
#define ISLOT_H


struct ISlot
{
    const short nId;
    const std::string strPlayerName;
    const int nCurrentShape;
    const int nPlayerScore;
    const __utils::SPoint ptTopLeft;
    const __utils::SPoint ptShapesStartingPoint;
    const __utils::SPoint ptShapesCurrentPoint;
    const __utils::SSize sShapeLimits;

    // Constructor
    ISlot(short _nId, std::string _strPlayerName, int _nCurrentShape, int _nPlaterScore,
        __utils::SPoint _ptTopLeft, __utils::SPoint _ptShapesStartingPoint, __utils::SPoint _ptShapesCurrentPoint,
        __utils::SSize _sShapeLimits) : 
        nId(_nId), strPlayerName(_strPlayerName), nCurrentShape(_nCurrentShape), nPlayerScore(_nPlaterScore),
        ptTopLeft(_ptTopLeft), ptShapesStartingPoint(_ptShapesStartingPoint),
        ptShapesCurrentPoint(_ptShapesCurrentPoint), sShapeLimits(_sShapeLimits) {};
};

#endif // !ISLOT_H
