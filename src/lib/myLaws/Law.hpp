#pragma once
#include "../myMath/Vec2.hpp"
#include "../../resources/Agent.hpp"
#include <vector>
//need to add file in CMake.txt

class Law {
protected:
	float m_range;
	float m_angle;
	float m_relaxation;
	std::vector<Vec2> getCoordinatesArray(const std::vector<Agent>&neighbors) const;
	Vec2 computeAgentsBarycenter(const std::vector<Agent>& neighbors) const;

public:
	virtual Vec2 compute(Agent& currentAgent, const std::vector<Agent*>& neighbors) const = 0;
	//ILaw() : default;
	//~ILaw() : default;
};

