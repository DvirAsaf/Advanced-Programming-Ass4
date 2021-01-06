

#ifndef HYBRIDANOMALYDETECTOR_H_
#define HYBRIDANOMALYDETECTOR_H_

#include "SimpleAnomalyDetector.h"
#include "minCircle.h"

class HybridAnomalyDetector:public SimpleAnomalyDetector {
public:
    HybridAnomalyDetector();
    virtual ~HybridAnomalyDetector();
    virtual void learnHelper(float pearson, correlatedFeatures ct, Point **ps, int size, string s1, string s2);
    virtual bool isAnomalous(correlatedFeatures c, float x, float y);
};

#endif /* HYBRIDANOMALYDETECTOR_H_ */
