#ifndef GLOBAL
#define GLOBAL

#include <vector>
#include "Render.hpp"
#include "Frame.hpp"
#include "Screenshot.hpp"
#include "ConfigHandler.hpp"

extern ConfigHandler* config;

extern std::vector<Frame*> frames;

extern ogl::Render *render;

#endif /* end of include guard: GLOBAL */
