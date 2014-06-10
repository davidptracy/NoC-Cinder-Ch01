#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NoC_01_1_BouncingBallNoVectorApp : public AppBasic{
public:
	void setup();
    void prepareSettings(Settings *settings);
	void update();
	void draw();
    
    float mX = 100;
    float mY = 100;
    float mXSpeed = Rand::randFloat(5);
    float mYSpeed = Rand::randFloat(5);
    int radius = 15;
};

void NoC_01_1_BouncingBallNoVectorApp::setup()
{
    gl::clear( Color( 1, 1, 1 ) );
}

void NoC_01_1_BouncingBallNoVectorApp::prepareSettings(Settings *settings){
    settings->setWindowSize( 640, 360 );
    settings->setFrameRate(60.0f);
}

void NoC_01_1_BouncingBallNoVectorApp::update()
{
    mX = mX + mXSpeed;
    mY = mY + mYSpeed;
    if (mX > getWindowWidth() || mX < 0)
        mXSpeed = mXSpeed * -1;
    if (mY > getWindowHeight() || mY < 0)
        mYSpeed = mYSpeed * -1;
}

void NoC_01_1_BouncingBallNoVectorApp::draw()
{
    Vec2f loc = Vec2f(mX, mY);
    //the Vec2f is required because cinder requires a vector as an argument for the drawSolidCircle method
    
	gl::clear( Color( 1, 1, 1 ) );
    
    gl::color(0.69f, 0.69f, 0.69f);
    gl::drawSolidCircle(loc, radius);
    
    gl::color(0, 0, 0);
    gl::drawStrokedCircle(loc, radius);
}

CINDER_APP_BASIC( NoC_01_1_BouncingBallNoVectorApp, RendererGl )
