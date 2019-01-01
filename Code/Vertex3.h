#pragma once
#include <list>
#include <memory>
#include "Definitions.h"
#include "Inclusions.h"
#include "unique_ptr_helper.h"


class Vertex3 : public unique_ptr_helper<Vertex3>
{
	std::unique_ptr<Vec3> _position;

public:
	size_t globalNum;

	ShellFacet3* belongsToShellFacet = nullptr;
	ShellEdge3* belongsToShellEdge = nullptr;
	ShellVertex3* belongsToShellVertex = nullptr;
	
	const Point3& getPosition() const;
	      void  setPosition(const Point3& newPos);
	      void  setPosition(const double coor0, const double coor1, const double coor2);
		  
	double& operator[](const int axis);
	Vec3 operator-(const Vertex3& right) const;
	Vec3 operator-(const ShellVertex3& right) const;
	Vertex3& operator+=(const Vec3& right);
	Vertex3& operator-=(const Vec3& right);

	Vertex3();
	Vertex3(const double coor0, const double coor1, const double coor2);
	Vertex3(const Point3& position);
	~Vertex3();
};