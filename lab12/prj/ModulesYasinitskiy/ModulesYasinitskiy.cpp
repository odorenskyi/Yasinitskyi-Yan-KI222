#include <cmath>
#include "ModulesYasinitskiy.h"

ClassLab12_Yasinitskiy::ClassLab12_Yasinitskiy(float heightToSet, float radiusToSet) {
    height = heightToSet;
    radius = radiusToSet;
}

float ClassLab12_Yasinitskiy::getHeight() {
    return height;
}

float ClassLab12_Yasinitskiy::getRadius() {
    return radius;
}

float ClassLab12_Yasinitskiy::getVolume() {
    return (1/3.0)*M_PI*pow(radius, 2)*height;
}

bool ClassLab12_Yasinitskiy::setHeight(float heightToSet) {
    if (heightToSet > 0) {
        height = heightToSet;
        return true;
    } else {
        return false;
    }
}

bool ClassLab12_Yasinitskiy::setRadius(float radiusToSet) {
    if (radiusToSet > 0) {
        radius = radiusToSet;
        return true;
    } else {
        return false;
    }
}
