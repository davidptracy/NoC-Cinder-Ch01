#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NoC_01_02_BouncingBallVectorApp : public AppBasic{
public:
	void setup();
    void prepareSettings(Settings *settings);
	void update();
	void draw();
    
    Vec2f mLocation;
    Vec2f mVelocity;
    
    int radius = 30;
    
};

void NoC_01_02_BouncingBallVectorApp::setup()
{
    gl::clear( Color( 1, 1, 1 ) );
    mLocation = Vec2f(Rand::randFloat(0.0f, getWindowWidth()),
                      Rand::randFloat(0.0f, getWindowHeight()));
    mVelocity = Vec2f(Rand::randFloat(1.0f, 5.0f), Rand::randFloat(1.0f, 5.0f));
}

void NoC_01_02_BouncingBallVectorApp::prepareSettings(Settings *settings){
    settings->setWindowSize( 640, 360 );
    settings->setFrameRate(60.0f);
}

void NoC_01_02_BouncingBallVectorApp::update()
{
    mLocation += mVelocity;
    
    if (mLocation.x > getWindowWidth() - radius || mLocation.x < radius)
        mVelocity.x = mVelocity.x * -1;
    if (mLocation.y > getWindowHeight() - radius || mLocation.y < radius)
        mVelocity.y = mVelocity.y * -1;
}

void NoC_01_02_BouncingBallVectorApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    
    gl::color(0, 0, 0);
    gl::drawSolidCircle(mLocation, radius);
    
    gl::color(0, 0, 0);
    gl::drawStrokedCircle(mLocation, radius);
}

CINDER_APP_BASIC( NoC_01_02_BouncingBallVectorApp, RendererGl )
