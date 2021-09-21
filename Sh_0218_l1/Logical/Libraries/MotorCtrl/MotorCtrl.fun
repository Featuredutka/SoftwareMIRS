
{REDUND_ERROR} FUNCTION_BLOCK FB_Integrator (*Integrator block for motor realization*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		in : {REDUND_UNREPLICABLE} REAL; (*Integrator input*)
	END_VAR
	VAR_OUTPUT
		out : REAL; (*Integrator output*)
	END_VAR
	VAR
		dt : REAL; (*Step*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK FB_Motor (*Functional block defining a motor*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		u : {REDUND_UNREPLICABLE} REAL; (*Input voltage*)
	END_VAR
	VAR_OUTPUT
		w : REAL; (*Rotation frequency*)
		phi : REAL; (*Position*)
	END_VAR
	VAR
		Tm : REAL; (*Electromech constant*)
		dt : REAL; (*Step*)
		ke : REAL; (*Motor EMF *)
		first_integrator : FB_Integrator; (*Integrator*)
		second_integrator : FB_Integrator;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK FB_Regulator (*PID Regulator realization*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		e : {REDUND_UNREPLICABLE} REAL; (*Difference between signal and motor rotation speed*)
	END_VAR
	VAR_OUTPUT
		u : REAL; (*Voltage going to drive input*)
	END_VAR
	VAR
		k_p : REAL; (*Proportial modifier*)
		k_i : REAL; (*Integral modifier*)
		integrator : FB_Integrator; (*Integrator*)
		iyOld : REAL; (*Previous data*)
		max_abs_value : REAL; (*Maximum edge block value*)
		dt : REAL; (*Step*)
	END_VAR
END_FUNCTION_BLOCK
