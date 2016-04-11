#pragma once

#include "ofMain.h"

#define BARCELONA_HEIGHT_MM (2000)
#define BARCELONA_WIDTH_MM (2000)
#define TARGET_DISTANCE_Z (2000)
#define CAMERA_HORIZONTAL_DEGREES (45)
#define SCALE (140.f/BARCELONA_HEIGHT_MM)

const ofVec3f xAxis(1,0,0);

class SceneCalibration {
public:
	static ofVec3f kinectToSceneCoordinates(ofVec3f kinectPoint){
		ofVec3f scenePoint;
		scenePoint.x = kinectPoint.x - 320;
		scenePoint.y = -(kinectPoint.y - 240);
		scenePoint.z = kinectPoint.z - TARGET_DISTANCE_Z + BARCELONA_WIDTH_MM;//80; // hardcoded.
		scenePoint = scenePoint.getRotated(-CAMERA_HORIZONTAL_DEGREES, xAxis);
		scenePoint.z *= SCALE;
		return scenePoint;
	}
};