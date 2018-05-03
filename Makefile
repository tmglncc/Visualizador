CXX = g++
CXXFLAGS = -std=c++11 -m64 -g -Wall -w
FOLDER = src/
BUILD_FOLDER = build/
PROG = $(BUILD_FOLDER)main.exe
CPP_FILES := $(wildcard $(FOLDER)*.cpp)
OBJ_FILES := $(addprefix $(BUILD_FOLDER),$(notdir $(CPP_FILES:.cpp=.o)))

OPENCV = `pkg-config opencv --cflags --libs`
LIBCONFIG = -lconfig++
LIBS = -lglut -lGLU -lGL -lGLEW
LIBS += $(OPENCV)
LIBS += $(LIBCONFIG)

$(PROG):$(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $(PROG) $^ $(LIBS)

$(BUILD_FOLDER)%.o: $(FOLDER)%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^ $(LIBS)

run:
	$(PROG)

clean:
	rm -f $(PROG) $(BUILD_FOLDER)*.o
