#ifndef TEMPERATURE_ALERTER_H
#define TEMPERATURE_ALERTER_H
#include "typewise-alert.h"

class ITemperatureBreachClassifier{
public:
    virtual BreachType checkTempBreachType(double ) = 0;
    BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
        if(value < lowerLimit) {
            return TOO_LOW;
        }
        if(value > upperLimit) {
            return TOO_HIGH;
        }
        return NORMAL;
    }
};

class PassiveCooling: public ITemperatureBreachClassifier{
public:
    BreachType checkTempBreachType(double temperatureInC){
        int lowerLimit = 0;
        int upperLimit = 35;
        return inferBreach(temperatureInC, lowerLimit, upperLimit);
    }
};

class HiActiveCooling: public ITemperatureBreachClassifier{
public:
    BreachType checkTempBreachType(double temperatureInC){
        int lowerLimit = 0;
        int upperLimit = 45;
        return inferBreach(temperatureInC, lowerLimit, upperLimit);
    }
};

class MedActiveCooling: public ITemperatureBreachClassifier{
public:
    BreachType checkTempBreachType(double temperatureInC){
        int lowerLimit = 0;
        int upperLimit = 40;
        return inferBreach(temperatureInC, lowerLimit, upperLimit);
    }
};

class TemperatureBreachClassifier{
    ITemperatureBreachClassifier *classifier;
public:
    TemperatureBreachClassifier(ITemperatureBreachClassifier *breachClassifier): classifier(breachClassifier){}
    ~TemperatureBreachClassifier(){
        delete classifier;
    }

    BreachType classifyBreach(double temperatureInC){
        return classifier->checkTempBreachType(temperatureInC);
    }
};

#endif //TEMPERATURE_ALERTER_H