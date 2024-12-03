#pragma once
class Game
{
public:
	bool Initialize();
	void RunLoop();
	void Shutdown();
	
private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	struct Data
	{
		float h;
		float w;
		float px;
		float py;
		float vx;
		float vy;



	};
	Data mBall;
	Data mPaddle1;
	Data mPaddle2;
	Data mAccelerate1;
	Data mAccelerate2;
	Data mAccelerate3;
	Data mDeceleration;
	Data mDeceleration2;
	Data mFlip;
	Data mFlip2;
};

