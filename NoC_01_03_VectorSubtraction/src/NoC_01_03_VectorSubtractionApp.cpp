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
	void prepareSettings(Settings *settings);
    void setup();
    void mouseMove( MouseEvent event);
	void update();
	void draw();
    
    //globally declared variable
    Vec2f mMouseLoc;
};

//the * symbol is a dereference of a pointer and refers to the value stored at the location 'settings'
void NoC_01_03_VectorSubtractionApp::prepareSettings
(Settings *settings){
    settings->setWindowSize(500, 500);
}

void NoC_01_03_VectorSubtractionApp::setup()
{
    //this is where mMouseLoc is initialized
    mMouseLoc = getWindowCenter();
}

//this function runs only if the mouse is moving
void NoC_01_03_VectorSubtractionApp::mouseMove(MouseEvent event){
    //retrieves the mouse location as a Vec2f
    mMouseLoc = (Vec2f)event.getPos();
}

void NoC_01_03_VectorSubtractionApp::update()
{
}

void NoC_01_03_VectorSubtractionApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
    //the vector mouse is being created from the mouseMove function so that when the mouse isn't moving, the position drawn on screen is maintained
    Vec2f mouse = mMouseLoc;
    Vec2f center = getWindowCenter();
    
    mouse -= center;
    
    gl::pushMatrices();
    gl::translate(getWindowCenter());
    gl::lineWidth(2.0);
    //draws a line from the center of the screen to mMouseLoc
    gl::drawLine(Vec2f::zero(), mouse);
    gl::popMatrices();
}

CINDER_APP_NATIVE( NoC_01_03_VectorSubtractionApp, RendererGl )
