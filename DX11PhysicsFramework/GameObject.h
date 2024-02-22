#pragma once

#include <directxmath.h>
#include <d3d11_1.h>
#include <string>

#include "Transform.h"
#include "Appearance.h"
#include "PhysicsModel.h"

using namespace DirectX;
using namespace std;
//class Vector3;

class GameObject
{
public:
	GameObject(string type, Transform* transform, Appearance* appearance, PhysicsModel* physicsModel);
	~GameObject();

	string GetType() const { return _type; }

	void SetParent(GameObject * parent) { _parent = parent; }


	void Update(float dt);
	void Move(XMFLOAT3 direction);
	void Draw(ID3D11DeviceContext * pImmediateContext);

	Transform* GetTransform() const { return _transform; }
	Appearance* GetAppearance() const { return _appearance; }
	PhysicsModel* GetPhysicsModel() const { return _physicsModel; }

private:
	GameObject* _parent = nullptr;

	string _type;
	XMFLOAT4X4 _world;

	Transform* _transform;
	Appearance* _appearance;
	PhysicsModel* _physicsModel;

	ID3D11ShaderResourceView* _textureRV = nullptr;
};

