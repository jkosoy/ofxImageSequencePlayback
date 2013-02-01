# ofxImageSequencePlayback

An openFrameworks library for managing sequences of ofImages in a more robust way. ofxImageSequencePlayback is dependant on the awesome [ofxImageSequence](https://github.com/Flightphase/ofxImageSequence) addon by [Flightphase](https://github.com/Flightphase).

It is also heavily informed by the great work done by [Red Paper Heart](http://redpaperheart.com) on their Cinder Block, [rph-textureSequence](https://github.com/redpaperheart/rph-TextureSequence). This addon is as much a port of their Cinder Block as anything.

## Features

* Play sequences in reverse.
* Loop the infinitely.
* Ping pong the sequences (forward->reverse->forward->reverse...)
* Notifications when a sequence completes and is not looping.
* Pausing, Stopping, changing FPS of a sequence.

## Simple Example

Assuming you have a folder in your data directory named "sequence" filled with PNGs...

In your .h file:

	ofxImageSequencePlayback mySequence;
	void onSequenceCompleted(ofEventArgs &evt);

In your .cpp file:

	void testApp::setup() {
		mySequence.loadSequence("sequence",24.0f); // 24 FPS

		ofAddListener(mySequence.sequenceCompleted,this,&testApp::onSequenceCompleted);

		mySequence.play();
	}

	void testApp::onSequenceCompleted(ofEventArgs &evt) {
	    mySequence.stop();
	    ofLog(OF_LOG_VERBOSE,"The sequence is complete.");
	}

	void testApp::update() {
		mySequence.update();
	}

	void testApp::draw() {
		mySequence.draw();
	}