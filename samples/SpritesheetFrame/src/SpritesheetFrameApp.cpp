#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "poSpritesheet.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class SpritesheetFrameApp : public App {
  public:
	void setup();
	void mouseDown( MouseEvent event );
	void mouseMove(MouseEvent event);
	void update();
	void draw();
	
	po::SpritesheetRef mSpritesheet;
	int mCurrentFrame;
};

void SpritesheetFrameApp::setup()
{
	setWindowSize(1024, 768);
	
	gl::TextureRef texture = gl::Texture::create(loadImage(loadAsset("goblin0.png")));
	JsonTree json = JsonTree(loadAsset("goblin0.json"));
	
	mSpritesheet = po::Spritesheet::create(texture, json);
}

void SpritesheetFrameApp::mouseDown( MouseEvent event )
{
}

void SpritesheetFrameApp::mouseMove(cinder::app::MouseEvent event)
{
	console() << event.getPos() << std::endl;
}

void SpritesheetFrameApp::update()
{
}

void SpritesheetFrameApp::draw()
{
	gl::clear(Color::gray(0.2));
	gl::pushModelView();
	gl::translate(getWindowWidth()/2 - mSpritesheet->getOriginalBounds().getWidth()/2, getWindowHeight()/2 - mSpritesheet->getOriginalBounds().getHeight()/2);
	mSpritesheet->drawFrame(31);
	gl::popModelView();
}

CINDER_APP( SpritesheetFrameApp, RendererGl )
