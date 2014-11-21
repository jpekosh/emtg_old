// Dormand-Prince (DOPRI) 8th(7th) order 13 step algorithm
// DOPRI constants are from Numerical Recipies
// Jacob Englander 9/10/2012

#include "missionoptions.h"
#include "universe.h"

#ifndef _RK8713M
#define _RK8713M

namespace EMTG { namespace integration
{

class rk8713M
{
	//fields
	int ns;
	double * x_left;
	
	std::vector <double> f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, 
						 df1dTOF, df2dTOF, df3dTOF, df4dTOF, df5dTOF, df6dTOF, df7dTOF, df8dTOF, df9dTOF, df10dTOF, df11dTOF, df12dTOF, df13dTOF,
						 y, dydTOF,
		                 dX_leftdTOF,
		                 dX_rightdTOF;

	//double *f1, *f2, *f3, *f4, *f5, *f6, *f7, *f8, *f9, *f10, *f11, *f12, *f13, *y, *x_left;

	//constructor
public:
	rk8713M();
	rk8713M(int ns_in);

	//destructor
	~rk8713M();

	//methods
	void rk8713M_step (double *x_left, double *x_right, double *u, double *f1, const double& t_left, const double& t_0, double & h, double * error, 
		                                        
												void(*EOM)(double * x,
												double * dx_dTOF,
												const double & t_left_step,
												const double & dt_left_stepdTOF,
												const double & c2,
												const double & h,
												const double & dhdTOF,
												const double & t0,
												double * u,
												double * f,
												double * dfdTOF,
												double * thrust,
												double * mdot,
												double * Isp,
												double * power,
												double * active_power,
												int * number_of_active_engines,
												int & STMrows,
												int & STMcolumns,
												void * optionsvoidpointer,
												void * Universepointer,
												void * ControllerPointer),
		
												double* thrust,
												double* mdot,
												double* Isp,
												double* power,
												double* active_power,
												int* number_of_active_engines,
												int &STMrows,
												int &STMcolumns,
												void* optionspointer, void* Universepointer, void* ControllerPointer);

	void adaptive_step_int(double *x_left_in, double *x_right, double *uleft, const double& t_left, const double& t_0, double const & local_step, double * resumeH, double * resumeError, double const & PRECISION_TARGET, 
		                                        void (*EOM)(double* x,
												const double& t,
												const double& t0,
												double* u,
												double* f,
												double* thrust,
												double* mdot,
												double* Isp,
												double* power,
												double* active_power,
												int* number_of_active_engines,
												int &STMrows,
												int &STMcolumns,
												void* optionsvoidpointer, 
												void* Universepointer, 
												void* ControllerPointer),
												double* thrust,
												double* mdot,
												double* Isp,
												double* power,
												double* active_power,
												int* number_of_active_engines,
												int &STMrows,
												int &STMcolumns,
												void* optionspointer, void* Universepointer, void* ControllerPointer);
};
	
}} //namespace EMTG::integration

#endif //_RK8713M