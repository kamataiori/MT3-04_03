#include "Result.h"

void Result::Initialize()
{
	

}

void Result::Update()
{

	if (isStart)
	{
		conicalPendulum.angularVelocity = std::sqrt(9.8f / (conicalPendulum.length * std::cos(conicalPendulum.halfApexAngle)));
	}
	else
	{
		conicalPendulum =
		{
			{0,1.0f,0},
			0.8f,
			0.7f,
			0,
			0
		};

		sphere.center = conicalPendulum.anchor;
	}
	conicalPendulum.angle = conicalPendulum.angle + conicalPendulum.angularVelocity * deltaTime;

	float radius = std::sin(conicalPendulum.halfApexAngle) * conicalPendulum.length;
	float height = std::cos(conicalPendulum.halfApexAngle) * conicalPendulum.length;
	sphere.center.x = conicalPendulum.anchor.x + std::cos(conicalPendulum.angle) * radius;
	sphere.center.y = conicalPendulum.anchor.y - height;
	sphere.center.z = conicalPendulum.anchor.z - std::sin(conicalPendulum.angle) * radius;

	linePoint[0] = Transform(Transform({ 0,1.2f,0 }, viewProjectionMatrix), viewportMatrix);
	linePoint[1] = Transform(Transform(sphere.center, viewProjectionMatrix), viewportMatrix);


	ImGui::Begin("window");


	ImGui::Text("camera");
	ImGui::DragFloat3("CameraRotate", &cameraRotate.x, 0.01f);

	ImGui::Text("setting");

	if (ImGui::Button("start"))
	{
		if (!isStart)
		{
			isStart = true;
		}
		else
		{
			isStart = false;
		}
	}


	ImGui::End();
}

void Result::Draw()
{
	
	//Novice::DrawLine((int)screenBall.x, (int)screenBall.y, (int)screenSpring.x, (int)screenSpring.y, WHITE);

	//DrawGrid(viewProjectionMatrix, viewportMatrix);
	DrawSphere(sphere, viewProjectionMatrix, viewportMatrix, color);
	Novice::DrawLine((int)linePoint[0].x, (int)linePoint[0].y, (int)linePoint[1].x, (int)linePoint[1].y, color);


	DrawGrid(viewProjectionMatrix, viewportMatrix);
}
