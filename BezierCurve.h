#pragma once

#include <glm/vec3.hpp>
#include <vector>
#include <GL/gl.h>

using namespace std;
using namespace glm;

class BezierCurve {
public:
    BezierCurve(vector<vec3> controlPoints, int iterations);

    void update();
    void draw();
    void drawPoints(GLenum mode);

    void setPicked(int i, vec3 picked);

    virtual ~BezierCurve() = default;

    const int iterations;
private:
    void plotBezier(const vector<vec3> &currPoints, int k);
    pair<vector<vec3>, vector<vec3>> deCasteljau(const vector<vec3> &currPoints);

    void drawPolygon();
    void drawCurve();

    vector<vec3> controlPoints;
    vector<vec3> curvePoints;
};