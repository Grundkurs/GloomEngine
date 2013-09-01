#pragma once
#ifndef GLOOMENGINE_H
#define GLOOMENGINE_H

namespace gloom
	{
	class Window;
	}

using gloom::Window;

class GloomEngine
{
public:
	GloomEngine();
	virtual ~GloomEngine();

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
	GloomEngine( const GloomEngine & other );
	GloomEngine( GloomEngine && other );
	GloomEngine & operator = ( const GloomEngine & other );
	GloomEngine & operator = ( GloomEngine && other );

	double mTimeStampD;
	double mTimeDeltaD;

	float mTimeStampF;
	float mTimeDeltaF;

	int mReturnValue;
};

#endif // GLOOMENGINE_H
