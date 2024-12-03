#include "Game.h"
#include"framework.h"
#include"graphic.h"
#include"Window.h"
#include"input.h"
bool Game::Initialize()
{
    window(1000, 800);
	mBall.h = 20;
	mBall.w = 20;
	mBall.px = 500;
	mBall.py = 100;
	mBall.vx = -300;
	mBall.vy = -300;
	
	mPaddle1.h = 150;
	mPaddle1.w = 10;
	mPaddle1.px = 10;
	mPaddle1.py = 400;
	mPaddle1.vx = 0;
	mPaddle1.vy = 0;

	mPaddle2.h = 150;
	mPaddle2.w = 10;
	mPaddle2.px = width-20;
	mPaddle2.py = 400;
	mPaddle2.vx = 0;
	mPaddle2.vy = 0;

	mDeceleration2.h = 80;
	mDeceleration2.w = 5;
	mDeceleration2.px = 500;
	mDeceleration2.py = 0;
	mDeceleration2.vx = 0;
	mDeceleration2.vy = 0;

    mFlip.h = 100;
	mFlip.w = 5;
	mFlip.px = 500;
	mFlip.py = 150;
	mFlip.vx = 0;
	mFlip.vy = 0;

	mAccelerate1.h = 100;
	mAccelerate1.w = 5;
	mAccelerate1.px = 500;
	mAccelerate1.py = 300;
	mAccelerate1.vx = 0;
	mAccelerate1.vy = 0;



	mDeceleration.h = 80;
	mDeceleration.w = 5;
	mDeceleration.px = 500;
	mDeceleration.py = 400;
	mDeceleration.vx = 0;
	mDeceleration.vy = 0;
    
	mFlip2.h = 100;
	mFlip2.w = 5;
	mFlip2.px = 500;
	mFlip2.py = 550;
	mFlip2.vx = 0;
	mFlip2.vy = 0;
	
	mAccelerate2.h = 100;
	mAccelerate2.w = 5;
	mAccelerate2.px = 500;
	mAccelerate2.py = 700;
	mAccelerate2.vx = 0;
	mAccelerate2.vy = 0;	

	



	initDeltaTime();

    return true;
}


void Game::RunLoop()
{
	while (notQuit)
	{
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
}


void Game::Shutdown()
{

}

void Game::ProcessInput()
{
	mPaddle1.vy = 0;
	if (isPress(KEY_W))mPaddle1.vy = -500;
	if (isPress(KEY_Q))mPaddle1.vy = -800;
	if (isPress(KEY_S))mPaddle1.vy=500;
	if (isPress(KEY_A))mPaddle1.vy = 800;
	mPaddle2.vy = 0;
	if (isPress(KEY_E))mPaddle2.vy = -500;
	if (isPress(KEY_R))mPaddle2.vy = -800;
	if (isPress(KEY_D))mPaddle2.vy = 500;
	if (isPress(KEY_F))mPaddle2.vy = 800;
}

void Game::UpdateGame()
{

	setDeltaTime();
	mBall.px += mBall.vx * delta;
	mBall.py += mBall.vy * delta;
	if (mBall.py < 0&&mBall.vy<0)mBall.vy *= -1;
	if (mBall.py+mBall.h > height&&mBall.vy>0)mBall.vy *= -1;
	if (mBall.px < 0 && mBall.vx < 0)Initialize();
	//if (mBall.px < 0 && mBall.vx < 0)mBall.vx*=-1;
	if(mBall.px + mBall.w > width&&mBall.vx>0)Initialize();
	//if (mBall.px + mBall.w > width && mBall.vx > 0)mBall.vx *= -1;

	if (mPaddle1.py < 0 && mPaddle1.vy < 0)mPaddle1.vy *= -1;
	if (mPaddle1.py + mPaddle1.h > height && mPaddle1.vy > 0)mPaddle1.vy *= -1;
	if (mPaddle1.vy != 0)mPaddle1.py += mPaddle1.vy * delta;

	if (mPaddle2.py < 0 && mPaddle2.vy < 0)mPaddle2.vy *= -1;
	if (mPaddle2.py + mPaddle2.h > height && mPaddle2.vy > 0)mPaddle2.vy *= -1;
	if (mPaddle2.vy != 0)mPaddle2.py += mPaddle2.vy * delta;

	if (mPaddle1.py<mBall.py+mBall.h
		&&mPaddle1.py+mPaddle1.h>mBall.py
		&&mPaddle1.px+mPaddle1.w>mBall.px
		&&mPaddle1.px<mBall.px+mBall.w
		&&mBall.vx<0)mBall.vx*=-1;

	if (mPaddle2.py<mBall.py + mBall.h
		&& mPaddle2.py + mPaddle2.h>mBall.py
		&& mPaddle2.px + mPaddle2.w > mBall.px
		&& mPaddle2.px < mBall.px + mBall.w
		&& mBall.vx > 0)mBall.vx *= -1;

	if (mAccelerate1.px < mBall.px + mBall.w
		&&mAccelerate1.py<mBall.py+mBall.h
		&&mAccelerate1.px+mAccelerate1.w>mBall.px
		&&mAccelerate1.py+mAccelerate1.h>mBall.py)mBall.vx *= 1.1;
	if (mAccelerate1.px < mBall.px + mBall.w
		&& mAccelerate1.py<mBall.py + mBall.h
		&& mAccelerate1.px + mAccelerate1.w>mBall.px
		&& mAccelerate1.py + mAccelerate1.h>mBall.py)mBall.vy *= 1.1;
	if (mAccelerate2.px < mBall.px + mBall.w
		&& mAccelerate2.py<mBall.py + mBall.h
		&& mAccelerate2.px + mAccelerate2.w>mBall.px
		&& mAccelerate2.py + mAccelerate2.h>mBall.py)mBall.vx *= 1.1;
	if (mAccelerate2.px < mBall.px + mBall.w
		&& mAccelerate2.py<mBall.py + mBall.h
		&& mAccelerate2.px + mAccelerate2.w>mBall.px
		&& mAccelerate2.py + mAccelerate2.h>mBall.py)mBall.vy *= 1.1;

	if (mDeceleration.px < mBall.px + mBall.w
		&& mDeceleration.py<mBall.py + mBall.h
		&& mDeceleration.px + mDeceleration.w>mBall.px
		&& mDeceleration.py + mDeceleration.h>mBall.py)mBall.vx *= 0.9;
	if (mDeceleration.px < mBall.px + mBall.w
		&& mDeceleration.py<mBall.py + mBall.h
		&& mDeceleration.px + mDeceleration.w>mBall.px
		&& mDeceleration.py + mDeceleration.h>mBall.py)mBall.vy *= 0.9;
	
	if (mDeceleration2.px < mBall.px + mBall.w
		&& mDeceleration2.py<mBall.py + mBall.h
		&& mDeceleration2.px + mDeceleration2.w>mBall.px
		&& mDeceleration2.py + mDeceleration2.h>mBall.py)mBall.vx *= 0.9;
	if (mDeceleration2.px < mBall.px + mBall.w
		&& mDeceleration2.py<mBall.py + mBall.h
		&& mDeceleration2.px + mDeceleration2.w>mBall.px
		&& mDeceleration2.py + mDeceleration2.h>mBall.py)mBall.vy *= 0.9;

	if (mFlip.px < mBall.px + mBall.w
		&& mFlip.py<mBall.py + mBall.h
		&& mFlip.px + mFlip.w>mBall.px
		&& mFlip.py + mFlip.h>mBall.py)mBall.vx *= 1;
	if (mFlip.px < mBall.px + mBall.w
		&& mFlip.py<mBall.py + mBall.h
		&& mFlip.px + mFlip.w>mBall.px
		&& mFlip.py + mFlip.h>mBall.py)mBall.vy *= -1;
	if (mFlip2.px < mBall.px + mBall.w
		&& mFlip2.py<mBall.py + mBall.h
		&& mFlip2.px + mFlip2.w>mBall.px
		&& mFlip2.py + mFlip2.h>mBall.py)mBall.vx *= 1;
	if (mFlip2.px < mBall.px + mBall.w
		&& mFlip2.py<mBall.py + mBall.h
		&& mFlip2.px + mFlip2.w>mBall.px
		&& mFlip2.py + mFlip2.h>mBall.py)mBall.vy *= -1;

}

void Game::GenerateOutput()
{
	clear(150, 150, 150);
    rect(mBall.px, mBall.py, mBall.w, mBall.h,0.785);
	/*rect(mAccelerate1.px, mAccelerate1.py, mAccelerate1.w, mAccelerate1.h);
	rect(mAccelerate2.px, mAccelerate2.py, mAccelerate2.w, mAccelerate2.h);
	rect(mDeceleration.px, mDeceleration.py, mDeceleration.w, mDeceleration.h);
	rect(mDeceleration2.px, mDeceleration2.py, mDeceleration2.w, mDeceleration2.h);
	rect(mFlip.px, mFlip.py, mFlip.w, mFlip.h);
	rect(mFlip2.px, mFlip2.py, mFlip2.w, mFlip2.h);
	*/


	rect(mPaddle1.px, mPaddle1.py, mPaddle1.w, mPaddle1.h);
	rect(mPaddle2.px, mPaddle2.py, mPaddle2.w, mPaddle2.h);
}





