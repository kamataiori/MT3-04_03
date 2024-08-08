#pragma once
#include "MathFunc.h"
class Result
{

public:

	ConicalPendulum conicalPendulum
	{
		{0,1.0f,0},
		0.8f,
		0.7f,
		0,
		0
	};

	Sphere sphere
	{
		{0,0,0},
		0.08f
	};

	Vector3 linePoint[2] =
	{
		{0,0,0},
		{0,0,0}
	};

	unsigned int color = WHITE;

	float deltaTime = 1.0f / 60.0f;

	bool isStart = false;

	Vector3 cameraTranslate{ 0.0f,1.9f,-6.49f };
	Vector3 cameraRotate{ 0.26f,0.0f,0.0f };

	float cameraSpeed = 0.01f;

	Matrix4x4 cameraMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, cameraRotate, cameraTranslate);
	Matrix4x4 viewMatrix = Inverse(cameraMatrix);
	Matrix4x4 projectionMatrix = MakePerspectiveFovMatrix(0.45f, (float)kWindowWidth / (float)kWindowHeight, 0.1f, 100.0f);
	Matrix4x4 viewProjectionMatrix = Multiply(viewMatrix, projectionMatrix);
	Matrix4x4 viewportMatrix = MakeViewportMatrix(0, 0, (float)kWindowWidth, (float)kWindowHeight, 0.0f, 1.0f);



	void Initialize();


	void Update();


	void Draw();

};

