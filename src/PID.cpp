#include "PID.h"
#include <numeric>
#include <math.h>
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {

}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

 is_prev_cte_inited = false;

  this->Kp = Kp; // P item
  this->Ki = Ki; // I item
  this->Kd = Kd; // D item

  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
  prev_cte = 0.0;

}

void PID::UpdateError(double cte) {

 if (!is_prev_cte_inited) {
    prev_cte = cte;
    is_prev_cte_inited = true;
  }

  p_error = cte;
  i_error += cte;
  d_error = cte - prev_cte;

  prev_cte = cte;
}

double PID::TotalError() {



    double steer = -Kp * p_error -Kd * d_error - Ki * i_error;



    /*  if (fabs(steer)>1.0){
        if (steer> 0){
          steer -= 0.25;
        } else {
          steer += 0.25;
        }
      }*/

	return steer;

}

