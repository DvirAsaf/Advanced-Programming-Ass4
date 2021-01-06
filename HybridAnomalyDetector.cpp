
#include "HybridAnomalyDetector.h"

HybridAnomalyDetector::HybridAnomalyDetector() {
    threshold = 0.9;
}

HybridAnomalyDetector::~HybridAnomalyDetector() {
    // TODO Auto-generated destructor stub
}

void HybridAnomalyDetector::learnHelper(float pearson, correlatedFeatures ct, Point **ps, int size, string s1, string s2){
    if (pearson >= 0.9){
        SimpleAnomalyDetector::learnHelper(pearson, ct, ps, size, s1, s2);
    }
    else if (0.5 < pearson && pearson < 0.9){
        Circle c = findMinCircle(ps, size);
        ct.feature1 = s1;
        ct.feature2 = s2;
        ct.radius = c.radius;
        ct.center = c.center;
        ct.corrlation = pearson;
        ct.threshold = ct.radius * 1.1;
        cf.push_back(ct);
    }
}

bool HybridAnomalyDetector::isAnomalous(correlatedFeatures c, float x, float y) {
    if (c.threshold >= 0.9){
        return (SimpleAnomalyDetector::isAnomalous(c, x, y));
    }
    else if(0.5 < c.threshold && c.threshold < 0.9){
        return is_in_circle(Circle(c.center, c.radius), Point(x, y));
    }
}