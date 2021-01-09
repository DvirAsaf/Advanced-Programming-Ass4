#include "HybridAnomalyDetector.h"

HybridAnomalyDetector::HybridAnomalyDetector() {
//    threshold = 0.9;
}

HybridAnomalyDetector::~HybridAnomalyDetector() {
    // TODO Auto-generated destructor stub
}

void HybridAnomalyDetector::learnHelper(float pearson, Point **ps, int size, string s1, string s2, correlatedFeatures ct){
    if (pearson >= 0.9){
        SimpleAnomalyDetector::learnHelper(pearson, ps, size, s1, s2, ct);
    }
    else if (0.5 < pearson && pearson < 0.9 && ct.corrlation < pearson){
        Circle c = findMinCircle(ps, size);
//        correlatedFeatures ct;
        ct.feature1 = s1;
        ct.feature2 = s2;
        ct.radius = c.radius;
        ct.center = c.center;
        ct.corrlation = pearson;
        if (ct.threshold < ct.radius) {
            ct.threshold =  ct.radius * 1.1;
        }
        cf.push_back(ct);
    }
    return;
}

bool HybridAnomalyDetector::pearsonResult(float pearson, float min) {
    if(0.5 < pearson && pearson < 0.9){
        return true;
    }
    else if(pearson >= 0.9) {
        return SimpleAnomalyDetector::pearsonResult(pearson, min);
    }
    return false;
}

bool HybridAnomalyDetector::isAnomalous(correlatedFeatures c, float x, float y) {
    if (c.corrlation >= 0.9) {
        return SimpleAnomalyDetector::isAnomalous(c, x, y);
    }
    else if(0.5 < c.corrlation ) {
        Circle circle (c.center, c.radius);
        Point point (x, y);
        return (is_in_circle(circle, point));
    }
    return false;
}