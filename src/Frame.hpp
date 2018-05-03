#ifndef FRAME
#define FRAME

#include <vector>
#include "Cell.hpp"

class Frame
{
public:
    int time, tumorCells, outCells;
    Vector3 domain;
    std::vector<Cell> cells;

    Frame(Vector3 domain = Vector3(), int time = 0, int outCells = 0, int tumorCells = 0, std::vector<Cell> cells = std::vector<Cell>())
    :
        domain(domain),
        time(time),
        outCells(outCells),
        tumorCells(tumorCells),
        cells(cells)
    {}

};

#endif /* end of include guard: FRAME */
