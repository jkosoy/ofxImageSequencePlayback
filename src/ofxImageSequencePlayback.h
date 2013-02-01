/**
 *  ofxImageSequencePlayback.h
 *
 * Created by Jamie Kosoy, http://jkosoy.com
 * Special thanks to Red Paper Heart. http://redpaperheart.com
 * Heavily inspired by TextureSequence by Red Paper Heart. https://github.com/redpaperheart/rph-TextureSequence
 *
 *
 * Dependant on ofxImageSequence library
 * Created by James George, http://www.jamesgeorge.org
 * in collaboration with FlightPhase http://www.flightphase.com
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * ----------------------
 *
 *  ofxImageSequencePlayback is a class to allow one to easily control an ofxImageSequence.
 *  Features include:
 *      Looping a sequence infinitely.
 *      Ping Ponging (play forward until the last frame, then play backward)
 *      Play sequences forward or backward.
 *      An isComplete() check to detect when your sequence has finished playing.
            Caveat :: This will always be false if ping ponging or looping.

 *  This class makes use of it's own timing mechanism, leveraging ofxImageSequence for loading and managing frame indexes only.
 *
 */

#pragma once

#include "ofMain.h"
#include "ofxImageSequence.h"

class ofxImageSequencePlayback {
  public:
    void update();
    void draw();
    
	ofxImageSequencePlayback();
	~ofxImageSequencePlayback();
    
    void play();
    void playInReverse();
    void pause();
    void stop();
    
    void reverse();
    
    bool isComplete() { return bComplete; }
    bool isReversed() { return bReversed; }
    bool isPingPong() { return bPingPong; }
    bool isPlaying()  { return bPlaying; }
    
    int  getCurrentFrameIndex();
    void setCurrentFrameIndex(int index);
    void setCurrentFramePercentage(float p);
    int getTotalFrames();
    
    void setSequence(const ofxImageSequence &sequence);
    void setSequence(const ofxImageSequence &sequence,float fps);
    void loadSequence(string pathToDir);
    void loadSequence(string pathToDir,float fps);
	void loadSequence(string prefix, string filetype, int startIndex, int endIndex,float fps);
	void loadSequence(string prefix, string filetype, int startIndex, int endIndex, int numDigits,float fps);
	void loadSequence(string prefix, string filetype, int startIndex, int endIndex);
	void loadSequence(string prefix, string filetype, int startIndex, int endIndex, int numDigits);
    
    void setFPS(const float fps) { mFPS = fps; }

    void setShouldLoop(bool shouldLoop);
    void setShouldPingPong(bool shouldPingPong);

    int getFrameIncrement() { return mFrameIncrement; }
    void setFrameIncrement(int frames) { mFrameIncrement = frames; }
    
    ofEvent<ofEventArgs> sequenceCompleted;

protected:
    void newSequenceSetup();
    void dispatchCompleteNotification();

    bool bPlaying;
    bool bPaused;
    bool bReversed;
    bool bPingPong;
    bool bComplete;
    bool bLooping;
    
    bool bPingPongForwardComplete;
    
    int mFrameIncrement;
    
    float mFPS;
    float mLastUpdateTime;
    
    ofxImageSequence mSequence;
    
};



