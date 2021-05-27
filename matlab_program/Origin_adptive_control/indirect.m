%S-function for continuous state equation
 function [sys,x0,str,ts]=indirect(t,x,u,flag,gama1,gama2,kd)

switch flag,
%Initialization
  case 0,
    [sys,x0,str,ts]=mdlInitializeSizes;
case 1,
    sys=mdlDerivatives(t,x,u,gama1,gama2);
%Outputs
  case 3,
    sys=mdlOutputs(t,x,u,kd);
%Unhandled flags
  case {2, 4, 9 }
    sys = [];
%Unexpected flags
  otherwise
    error(['Unhandled flag = ',num2str(flag)]);
end

%mdlInitializeSizes
function [sys,x0,str,ts]=mdlInitializeSizes
sizes = simsizes;
sizes.NumContStates  = 2;      
sizes.NumDiscStates  = 0;       
sizes.NumOutputs     = 1;
sizes.NumInputs      = 3;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 1;
sys=simsizes(sizes);
x0=[3005 -0.1];          
str=[];
ts=[0 0];

%输入是fm & xm, 输出是ke & xe.
function sys=mdlDerivatives(t,x,u,gama1,gama2)
fm = u(1);
xm = u(2);
ke_ = x(1);
xe_ = x(2);
%把bd算出来

f_=ke_*(xm-xe_);
sys(1)=-gama1*xm*(f_-fm);
sys(2)=(gama1*xm*xe_+gama2)*(f_-fm)/ke_;


function sys=mdlOutputs(t,x,u,kd)
xe_= x(2);  
ke_ = x(1);
keq = kd*ke_/(kd+ke_);
fr = u(3);

xr = xe_+fr/keq;
sys(1)=xr;

