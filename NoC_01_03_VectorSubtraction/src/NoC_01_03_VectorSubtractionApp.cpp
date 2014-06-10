//Ported from Daniel Shiffman's Nature of Code
//www.natureofcode.com

//David Tracy
//www.davidptracy.com

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NoC_01_03_VectorSubtractionApp : public AppNative {
  public:
	void setup();
    void prepareSettings(Settings *settings);
	void mouseMove( MouseEvent event);
	void update();
	void draw();
    
    //globally declared variable
    Vec2f mMouseLoc;
};

void NoC_01_03_VectorSubtractionApp::setup()
{
    //this is where mMouseLoc is initialized
    mMouseLoc = getWindowCenter();
}

//the * symbol is a dereference of a pointer and refers to the value stored at the location 'settings'
void NoC_01_03_VectorSubtractionApp::prepareSettings
(Settings *settings){
    settings->setWindowSize(500, 500);
}

//this function runs only if the mouse is moving
void NoC_01_03_VectorSubtractionApp::mouseMove(MouseEvent event){
    //retrieves the mouse location as a Vec2f
    mMouseLoc = (Vec2f)event.getPos();
}

void NoC_01_03_VectorSubtractionApp::update()
{
    //vector subtraction
    mMouseLoc = mMouseLoc - getWindowCenter();
}

void NoC_01_03_VectorSubtractionApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
    gl::pushMatrices();
    gl::translate(getWindowCenter());
    //draws a line from the center of the screen to mMouseLoc
    gl::drawLine(Vec2f::zero(), mMouseLoc);
    gl::popMatrices();
}

CINDER_APP_NATIVE( NoC_01_03_VectorSubtractionApp, RendererGl )
