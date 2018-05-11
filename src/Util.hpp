#ifndef UTIL
#define UTIL

#include "Vector.hpp"
#include <GL/glut.h>
#include <map>
#include <time.h>
#include <sys/stat.h>
#include <string>
#include <vector>

// Cell States
typedef enum
{
	UND = -1, /***  Undefined		***/
	NEC = 0,  /***  Necrotic		***/
	QUI = 1,  /***  Quiescent		***/
	PRO = 2,  /***  Proliferative	***/
	HIP = 3,  /***  Hipoxic			***/
	APO = 4,  /***  Apoptotic		***/
	G1 	= 5,  /***  G1				***/
	NOR = 6,  /***  Normal			***/
	TC	= 7,
	SC1	= 8,
	SC2	= 10,

} CellState;

typedef enum
{
	PNG,
	JPG
} ImageFormat;

typedef enum
{
	PAUSE,
	PLAY,
	PREVIOUS,
	NEXT,
	REVERSE
} PlayerStates;

typedef enum
{
	STD = 0,
	NUT = 1,
	EGF = 2
} ViewMode;

typedef struct ColorRGBA {
	GLfloat r, g, b, a;
};

typedef struct CellDisplay{
	bool visibility;
	struct {
		ColorRGBA 	primary,
					secondary;
	} color;
};

typedef struct CellDisplayTypes
{
	CellDisplay NEC,
				QUI,
				PRO,
				HIP,
				APO,
				G1,
				NOR,
				TC,
				SC1,
				SC2;
};

typedef enum
{
	BI_D, 	// 2D
	TRI_D	// 3D
} FileFormat;

class Util
{
public:
	static std::string generateImageFileName(std::string name, std::string path = "out/", ImageFormat imageFormat = PNG)
	{
		std::string _type;

		mkdirIfNot(path);

		switch (imageFormat)
		{
			case PNG:
				_type = ".png";
				break;
			case JPG:
				_type = ".jpg";
				break;
		}

		return path + name + _type;
	}

	static void mkdirIfNot(std::string path)
	{
		mkdir(path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	}

	static std::string getCurrentTime()
	{
		time_t _t = time(0);   // get time now
		struct tm * _now = localtime(&_t);

		char _buffer[80];
		strftime(_buffer, 80, "%Y-%m-%d-%I-%M-%S", _now);

		return std::string(_buffer);
	}
};

#endif /* end of include guard: UTIL */
