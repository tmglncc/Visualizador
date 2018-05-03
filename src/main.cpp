#include <iostream>
#include "FrameFactory.hpp"
#include "GlutWindow.hpp"
#include "FileList.hpp"

ConfigHandler* config;

ogl::Render *render;

std::vector<Frame*> frames;

int main(int argc, char** argv) {
	config = new ConfigHandler();

	if (!config->created())
		return EXIT_FAILURE;

	std::vector<std::string> files = FileList::getFileNames(config->paths.files);

    frames = FrameFactory::makeListFrames(files, config->fileFormat);

	config->display.lines.maximumLimit = Vector3(frames[0]->domain.x + config->display.lines.cellGap, frames[0]->domain.y + config->display.lines.cellGap, frames[0]->domain.z);
	config->display.lines.minimumLimit = Vector3(-config->display.lines.cellGap, -config->display.lines.cellGap, 0);

	ogl::GlutWindow window(argc, argv);

	window.start();

	return EXIT_SUCCESS;
}
