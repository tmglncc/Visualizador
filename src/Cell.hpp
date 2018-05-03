#ifndef CELL
#define CELL

#include "Util.hpp"

class Cell
{
public:
	CellState state;

	Vector3 coordinates,
			speed;

	float	nucleusRadius,
			radius,
			actionRadius,
			lifetime,
			previousState,
			oConsumption,
			egfConsumption,
			calcification;

	double 	sigmaO,
			sigmaEGF;

	Cell(CellState state = UND, Vector3 coordinates = Vector3(), float nucleusRadius = 0.0f,
		float radius = 0.0f, float actionRadius = 0.0f, float lifetime = 0.0f,
		float previousState = 0.0f, float oConsumption = 0.0f, float egfConsumption = 0.0f,
		float calcification = 0.0f, Vector3 speed = Vector3(), double sigmaO = 0.0f, double sigmaEGF = 0.0f)
		:
			state(state),
			coordinates(coordinates),
			nucleusRadius(nucleusRadius),
			radius(radius),
			actionRadius(actionRadius),
			lifetime(lifetime),
			previousState(previousState),
			oConsumption(oConsumption),
			egfConsumption(egfConsumption),
			calcification(calcification),
			speed(speed),
			sigmaO(sigmaO),
			sigmaEGF(sigmaEGF)
	{}

	std::string to_string() {
		std::string out = "Pos = " + this->coordinates.to_string();
		out += " Radius | Nuclear = " + std::to_string(this->nucleusRadius) + ", Cell = " + std::to_string(this->radius) + ", Max = " + std::to_string(this->actionRadius);
		out += " Time = " + std::to_string(this->lifetime);
		out += " V = " + this->speed.to_string();

		switch (this->state) {
			case NEC:
				out += " State = Dead";
				break;
			case QUI:
				out += " State = Alive";
				break;
			case PRO:
				out += " State = Proliferative";
				break;
			case HIP:
				out += " State = Hypoxic";
				break;
			case APO:
				out += " State = Dying";
				break;
			case G1:
				out += " State = G1";
				break;
			case NOR:
				out += " State = Normoxic";
				break;
			default:
				out += " State = " + this->state;
		}
		return out;
	}

};

#endif /* end of include guard: CELL */
