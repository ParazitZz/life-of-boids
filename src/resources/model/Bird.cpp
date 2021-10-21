#include <array>
#include <vector>
#include "../../lib/myMath/Vec2.hpp"
#include "../../lib/myMath/utils.hpp"
#include "Bird.hpp"

Bird::Bird() : Agent(-5, 5, 6, 270, 50) {};
//
Bird::Bird(const Vec2& position, const Vec2& velocity) : 
	Agent(position, velocity, 6, 270, 50) {};

Bird::Bird(const Vec2& position, const Vec2& velocity, const int& bodySize, const int& viewAngle, const int& range, const float &maxSpeed, const Color& color) :
	Agent(position, velocity, bodySize, viewAngle, range, maxSpeed, color), m_alignmentLaw(), m_cohesionLaw(), m_separationLaw(){};

Bird::Bird(const Vec2& position, const Vec2& velocity, const int& bodySize, const int& viewAngle, const int& range, const float &maxSpeed, const Color& color, const CohesionLaw &cohesionLaw, const AlignmentLaw &alignmentLaw, const SeparationLaw &separationLaw) :
	Bird(position, velocity, bodySize, viewAngle, range, maxSpeed, color) {
	m_alignmentLaw = alignmentLaw;
	m_cohesionLaw = cohesionLaw;
	m_separationLaw = separationLaw;
};



void Bird::computeLaws(const std::vector<Agent*>& neighbors) {
	Vec2 vec_displacement{};
	if (neighbors.size() > 0) {
		Vec2 vecCohesion = m_cohesionLaw.compute(*this, neighbors);
		Vec2 vecAlignment = m_AlignmentLaw.compute(*this, neighbors);
		Vec2 vecSeparation = m_separationLaw.compute(*this, neighbors);
		vec_displacement = vecAlignment + vecCohesion  + vecSeparation;
		float norm = vec_displacement.norm();

		if (norm > 5) {
			vec_displacement = vec_displacement / norm;
		}
	}

	//std::cout << "Bird id " << this->_id << " | nb neigh : " << neighbors.size() << " | alignment vec " << vecAlignment << " | cohesion vec " << vecCohesion << " | Separation vec " << vecSeparation << '\n';
	m_nextVelocity = (m_velocity * 0.99 + vec_displacement) ; 
	if (m_nextVelocity.norm() > m_maxSpeed) {
		m_nextVelocity = m_nextVelocity.normalize() * m_maxSpeed;
	}
};

void Bird::print() const {
	std::cout << ">>>Printing bird : P(" << m_position.x << ", " << m_position.y << " ) / V(" << m_velocity.x << ", " << m_velocity.y << " )";
};


