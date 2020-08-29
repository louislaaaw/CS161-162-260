/**
  @brief Assignment 7
  @author (Louis)YunHo Law
  */
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void getData(int heights[], int size){
    cout << "Enter elevations: " ;
    for(int i = 0; i < size; i ++){
    cin >> heights[i];
    }
}
int getHighestPointBetween(const int heights[], int startMile, int endMile){
    int highest = 0 ;
    for (int i = startMile; i < endMile; i ++){
        if (highest < heights[i]){
            highest = heights[i];
        }
    }
    return highest;
}
double getAverage(const int heights[], int size){
    int sum = 0;
    double average;
    for (int i = 0; i < size; i ++){
        sum += heights[i] ;
    }
    average = sum * 1.0 / size ;
    return average ;
}
int getNumPeaks(const int heights[], int size){
    int numberOfPeak = 0;
    for (int i = 1; i < size - 1 ; i ++){
        if ((heights[i] > heights [i + 1]) && (heights[i] > heights[i - 1])){
            numberOfPeak += 1;
        }
    }
    return numberOfPeak;
}
int getNumSteepSegments(const int heights[], int size){
    int numberOfSS = 0;
    for (int i = 0; i < size - 1; i ++){
        if( abs(heights[i + 1] - heights[i]) > 1000){
            numberOfSS += 1 ;
        }
    }
    return numberOfSS;
}
int getTotalChange(const int heights[], int startMile, int endMile){
    int change;
    int total = 0;
    for (int i = startMile; i < endMile; i ++){
        change = abs(heights[i + 1] - heights[i]);
        total += change;
    }
    return total;
}

int main()
{
    const int HIKE_LENGTH = 9;
    int elevation[HIKE_LENGTH];
    getData(elevation, HIKE_LENGTH);
    cout << "Highest points:" << endl;
    cout << setw(3) << "First Half: " << getHighestPointBetween(elevation, 0, 4) << endl;
    cout << setw(3) << "Second Half: " << getHighestPointBetween(elevation, 4, 8) << endl;
    cout << setw(3) << "Overall: " << getHighestPointBetween(elevation, 0, 8) << endl;
    cout << "Average elevation: " << getAverage(elevation, HIKE_LENGTH) << endl;
    cout << "Peaks: " << getNumPeaks(elevation, HIKE_LENGTH) << endl;
    cout << "Difficult segments: " << getNumSteepSegments(elevation, HIKE_LENGTH) << endl;
    cout << "Elevation Change: " << getTotalChange(elevation, 0, 8) << endl;

    return 0;
}
