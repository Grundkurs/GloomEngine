#pragma once
#ifndef GLOWENGINE_H
#define GLOWENGINE_H

namespace gloom
	{
	class Window;
	}

using gloom::Window;

class GlowEngine
{
public:
	GlowEngine();
	virtual ~GlowEngine();

	bool init();

	int run();

	Window * getWindow();

	// timer getters
	double getTimeStampD() const;
	double getTimeDeltaD() const;
	float getTimeStampF() const;
	float getTimeDeltaF() const;

	void setReturnValue(int returnValue);

	// these must be overridden in a inherited class for game implementation
	virtual void gameUpdate() = 0;
	virtual void gameDraw() = 0;

protected:

	Window * mpWindow;

private:
	GlowEngine( const GlowEngine & other );
	GlowEngine( GlowEngine && other );

	double mTimeStampD;
	double mTimeDeltaD;

	float mTimeStampF;
	float mTimeDeltaF;

	int mReturnValue;
};

#endif // GLOWENGINE_H
