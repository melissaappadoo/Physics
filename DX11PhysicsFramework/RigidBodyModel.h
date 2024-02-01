#pragma once

#include "PhysicsModel.h"

class RigidBodyModel : public PhysicsModel
{
public:
	XMFLOAT3 Torque(XMFLOAT3 force);
};

