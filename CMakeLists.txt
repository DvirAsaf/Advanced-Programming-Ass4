cmake_minimum_required(VERSION 3.16)
project(Ex4_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Ex4_1 MainTrain.cpp anomaly_detection_util.cpp anomaly_detection_util.h SimpleAnomalyDetector.cpp SimpleAnomalyDetector.h timeseries.cpp timeseries.h AnomalyDetector.h minCircle.cpp minCircle.h HybridAnomalyDetector.cpp HybridAnomalyDetector.h)