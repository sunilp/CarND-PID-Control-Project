#include "PID.h"
#include <numeric>
#include <math.h>
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

  this->Kp = Kp; // P item
  this->Ki = Ki; // I item
  this->Kd = Kd; // D item

}

void PID::UpdateError(double cte) {

  p_error = cte;
  d_error = cte - p_error;
  i_error += cte;

}

double PID::TotalError() {



    double steer = -Kp * p_error -Kd * d_error - Ki * i_error;



      if (fabs(steer)>1.0){
        if (steer> 0){
          steer -= 0.25;
        } else {
          steer += 0.25;
        }
      }

	return steer;

}

