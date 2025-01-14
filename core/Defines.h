// MIT License

// Copyright (c) 2022 jiwenchen(cjwbeyond@hotmail.com)

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once
#include <iostream>
#include <cstring>
#include "Point.h"
#include "Direction.h"

using namespace std;

namespace MonkeyGL{

    #define PI 3.141592654
    #define MAXOBJECTCOUNT 64

    struct RGB
    {
        float red;
        float green;
        float blue;

        RGB(){
            red = 0.0f;
            green = 0.0f;
            blue = 0.0f;
        }
        RGB(float r, float g, float b){
            red = r;
            green = g;
            blue = b;
        }
        void Print(){
            cout << "red: " << red << endl; 
            cout << "green: " << green << endl; 
            cout << "blue: " << blue << endl;
        }
    };

    struct RGBA
    {
        float red;
        float green;
        float blue;
        float alpha;

        RGBA(){
            red = 0.0f;
            green = 0.0f;
            blue = 0.0f;
            alpha = 0.0f;
        }
        RGBA(float r, float g, float b, float a){
            red = r;
            green = g;
            blue = b;
            alpha = a;
        }
        void Print(){
            cout << "red: " << red << endl; 
            cout << "green: " << green << endl; 
            cout << "blue: " << blue << endl; 
            cout << "alpha: " << alpha << endl; 
        }
    };

    struct VOI{
        int left;
        int right;
        int posterior;
        int anterior;
        int head;
        int foot;

        VOI() {
            left = -1;
            right = -1;
            posterior = -1;
            anterior = -1;
            head = -1;
            foot = -1;
        }
    };

    struct Lightparams{
        float ka;
        float ks;
        float kd;
        float lightColor[4];
        float globalAmbient[4];
    };

    struct AlphaAndWWWL{
        float alpha;
        float ww;
        float wl;

        AlphaAndWWWL(){
            alpha = 0.0f;
            ww = 0.0f;
            wl = 0.0f;
        }
        AlphaAndWWWL(float a, float w, float l){
            alpha = a;
            ww = w;
            wl = l;
        }
    };

    enum Orientation
    {
        OrientationNotDefined = -1,
        OrientationAnterior,
        OrientationPosterior,
        OrientationLeft,
        OrientationRight,
        OrientationHead,
        OrientationFoot
    };
    
    enum PlaneType
    {
        PlaneNotDefined = -1,
        PlaneAxial,
        PlaneSagittal,
        PlaneCoronal,
        PlaneAxialOblique,
        PlaneSagittalOblique,
        PlaneCoronalOblique,
        PlaneVR,
        PlaneStretchedCPR,
        PlaneStraightenedCPR
    };

    static std::string PlaneTypeName(PlaneType planeType){
        std::string strName;
        switch (planeType)
        {
        case PlaneNotDefined:
            strName = "PlaneNotDefined";
            break;
        case PlaneAxial:
            strName = "PlaneAxial";
            break;
        case PlaneSagittal:
            strName = "PlaneSagittal";
            break;
        case PlaneCoronal:
            strName = "PlaneCoronal";
            break;
        case PlaneAxialOblique:
            strName = "PlaneAxialOblique";
            break;
        case PlaneSagittalOblique:
            strName = "PlaneSagittalOblique";
            break;
        case PlaneCoronalOblique:
            strName = "PlaneCoronalOblique";
            break;
        case PlaneVR:
            strName = "PlaneVR";
            break;
        case PlaneStretchedCPR:
            strName = "PlaneStretchedCPR";
            break;
        case PlaneStraightenedCPR:
            strName = "PlaneStraightenedCPR";
            break;
        default:
            break;
        }
        return strName;
    }

	enum MPRType
	{
		MPRTypeNotDefined = -1,
		MPRTypeAverage,
		MPRTypeMIP,
		MPRTypeMinIP
	};

    enum LogLevel
    {
        LogLevelNotDefined = -1,
        LogLevelInfo,
        LogLevelWarn,
        LogLevelError
    };
}