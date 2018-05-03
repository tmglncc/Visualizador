#ifndef FRAME_FACTORY
#define FRAME_FACTORY

#include <fstream>
#include <cmath>
#include <string>
#include "Frame.hpp"

class FrameFactory
{
public:
    [[deprecated]]
    static Frame* makeFrame2d(std::string fileName)
    {
        // FILE
        std::ifstream file;

        // FRAME
        Frame frame;

        Cell c;
        int state;
        int numCells = 0;

        file.open(fileName.c_str());

        file >> frame.domain.x >> frame.domain.y;
        frame.domain.z = frame.domain.y;
        file >> numCells >> frame.time;
        file >> frame.outCells >> frame.tumorCells;

        // Reading all cells
        for (std::size_t i = 0; i < numCells; i++) {
            file >> state;
            c.state = (CellState)state;
            file >> c.coordinates.x >> c.coordinates.y;
            c.coordinates.z = frame.domain.z/2;
            file >> c.nucleusRadius >> c.radius >> c.calcification;
            file >> c.speed.x >> c.speed.y;

            c.actionRadius = c.speed.z = c.lifetime = c.previousState = c.oConsumption = c.egfConsumption = 0;

            frame.cells.push_back(c);
        }

        file.close();
        return new Frame(frame);
    }

    static Frame* makeFrame(std::string fileName)
    {
    	// FILE
    	std::ifstream file;

        // FRAME
        Frame frame;

        Cell c;
        int state;
        int numCells = 0;

    	file.open(fileName.c_str());

    	file >> frame.domain.x >> frame.domain.y >> frame.domain.z;
    	file >> numCells >> frame.time;
    	file >> frame.outCells >> frame.tumorCells;

    	// Reading all cells
    	for (std::size_t i = 0; i < numCells; i++) {
    		file >> state;
            c.state = (CellState)state;
    		file >> c.coordinates.x >> c.coordinates.y >> c.coordinates.z;
    		file >> c.nucleusRadius >> c.radius >> c.actionRadius >> c.lifetime >> c.previousState;
            file >> c.oConsumption >> c.egfConsumption >> c.calcification >> c.sigmaEGF >> c.sigmaO;
    		file >> c.speed.x >> c.speed.y >> c.speed.z;

    		frame.cells.push_back(c);
    	}

    	file.close();
    	return new Frame(frame);
    }


    static std::vector<Frame*> makeListFrames(std::vector<std::string> files, FileFormat format)
    {
        std::vector<Frame*> frames;

        for (std::size_t i = 0; i < files.size(); i++)
    	{
            if(format == BI_D)
                frames.push_back(FrameFactory::makeFrame2d(files[i]));
            else
                frames.push_back(FrameFactory::makeFrame(files[i]));
            std::cout << files[i] << std::endl;
        }

        return frames;
    }

};

#endif /* end of include guard: FRAME_FACTORY */
