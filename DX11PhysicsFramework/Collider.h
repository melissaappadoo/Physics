#pragma once

#include "Transform.h"
#include "SphereCollider.h"

class Collider abstract
{
protected:
	Transform* _tf;
public:
	Collider(Transform* tf) { _tf = tf; }

	virtual bool CollidesWith(Collider& other) = 0;
	//virtual bool CollidesWith(SphereCollider& other) = 0;
	
	XMFLOAT3 GetPosition() const { return _tf->GetPosition(); }
};

