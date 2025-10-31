#ifndef MOISTURE_H
#define MOISTURE_H

#include <Arduino.h>

class Moisture {
public:
    Moisture(int initialDryValue, int initialWetValue) {
        dryValue = initialDryValue;
        wetValue = initialWetValue;
        rawValue = 0;
        percentage = 0;
    }

    /**
     * @brief Updates the sensor reading and recalculates the percentage.
     * @param newRawValue The latest analog reading from the sensor pin.
     */
    void update(int newRawValue) {
        rawValue = newRawValue;

        int moisturePercentage = map(rawValue, dryValue, wetValue, 0, 100);
        moisturePercentage = constrain(moisturePercentage, 0, 100);

        percentage = moisturePercentage;
    }

    int getPercentage() const {
        return percentage;
    }

    int getRawValue() const {
        return rawValue;
    }

    int getDryValue() const {
        return dryValue;
    }
    
    int getWetValue() const {
        return wetValue;
    }

private:
    int rawValue;     
    int dryValue;     
    int wetValue;   
    int percentage;
};

#endif