clc
clear all
close all
f =0.5e3; %change
sim_time = 3;%total time change
fs = 1/4e-4;% change
Ts=0.0004;

Aux = [18.053;240;230;f;0.75;25;3000];
Param=[10e-03,0.0010000000000000,10.0000000000000e-4,0.0010000000000000,0.010000000000000];

Param = Param';
L = Param(1,1);
R_L = Param(2,1);
C = Param(3,1);
R_C = Param(4,1);
R_DS_ON = Param(5,1);

P = Aux(1,1);
V_IN = Aux(2,1);
V_OUT = Aux(3,1);
f = Aux(4,1);
V_f = Aux(5,1);
n_f = Aux(6,1);%Total samples per fundamental cycle
N_sim = Aux(7,1);%total fundamental cycles
Ts=0.0004

load('matlabtrial.mat');

f_iL_ON = @(iL_c,vc_c,R) (-(R_DS_ON+R_L+(R_C*R/(R_C+R)))/L)*iL_c + (-(R)/(L*(R_C+R)))*vc_c + V_IN/L;
f_iL_OFF = @(iL_c,vc_c,R) (-(R_L+(R_C*R/(R_C+R)))/L)*iL_c + (-(R)/(L*(R_C+R)))*vc_c - V_f/L;

f_vc = @(iL_c,vc_c,R)((R)/(C*(R_C+R)))*iL_c+((-1)/(C*(R_C+R)))*vc_c;


%Initial Conditions

 iL_IC = 0;
 vc_IC = 0;
  vo_IC = 0;

j = 1; %iteration cound for simulation cycle
k = 1; %iteration count for switching cycle

vc_c(1,1) = vc_IC;
iL_c(1,1) = iL_IC;
vo_c(1,1) = vo_IC;
V=Va.signals.values;
I=Ia2.signals.values;
D=PWM.signals.values;
H=V./I;

 for j=1:1:length(D) %multiple fundamental cycle
if D(j)==1
    k = k+1; 
    ka1 = f_iL_ON(iL_c(k-1,1),vc_c(k-1,1),H(k-1,1));
    kb1 = f_vc(iL_c(k-1,1),vc_c(k-1,1),H(k-1,1));
    
    ka2 = f_iL_ON(iL_c(k-1,1)+0.5*Ts*ka1,vc_c(k-1,1)+0.5*Ts*kb1,H(k-1,1));
    kb2 = f_vc(iL_c(k-1,1)+0.5*Ts*ka1,vc_c(k-1,1)+0.5*Ts*kb1,H(k-1,1));
    
    ka3 = f_iL_ON(iL_c(k-1,1)+0.5*Ts*ka2,vc_c(k-1,1)+0.5*Ts*kb2,H(k-1,1));
    kb3 = f_vc(iL_c(k-1,1)+0.5*Ts*ka2,vc_c(k-1,1)+0.5*Ts*kb2,H(k-1,1));
    
    ka4 = f_iL_ON(iL_c(k-1,1) + Ts*ka3, vc_c(k-1,1) + Ts*kb3,H(k-1,1));
    kb4 = f_vc(iL_c(k-1,1) + Ts*ka3,vc_c(k-1,1) + Ts*kb3,H(k-1,1));
   
   iL_c(k,1) = iL_c(k-1,1) + (Ts/6)*(ka1+2*ka2+2*ka3+ka4);
   vc_c(k,1) = vc_c(k-1,1) + (Ts/6)*(kb1+2*kb2+2*kb3+kb4);
      
   vo_c(k,1) = iL_c(k,1)*(R_C*H(k-1,1))/(R_C+H(k-1,1)) + vc_c(k,1)*H(k-1,1)/(R_C+H(k-1,1));
else

    k = k+1; 
    ka1 = f_iL_OFF(iL_c(k-1,1),vc_c(k-1,1),H(k-1,1));
    kb1 = f_vc(iL_c(k-1,1),vc_c(k-1,1),H(k-1,1));
    
    ka2 = f_iL_OFF(iL_c(k-1,1)+0.5*Ts*ka1,vc_c(k-1,1)+0.5*Ts*kb1,H(k-1,1));
    kb2 = f_vc(iL_c(k-1,1)+0.5*Ts*ka1,vc_c(k-1,1)+0.5*Ts*kb1,H(k-1,1));
    
    ka3 = f_iL_OFF(iL_c(k-1,1)+0.5*Ts*ka2,vc_c(k-1,1)+0.5*Ts*kb2,H(k-1,1));
    kb3 = f_vc(iL_c(k-1,1)+0.5*Ts*ka2,vc_c(k-1,1)+0.5*Ts*kb2,H(k-1,1));
    
    ka4 = f_iL_OFF(iL_c(k-1,1) + Ts*ka3, vc_c(k-1,1) + Ts*kb3,H(k-1,1));
    kb4 = f_vc(iL_c(k-1,1) + Ts*ka3,vc_c(k-1,1) + Ts*kb3,H(k-1,1));
   
   iL_c(k,1) = iL_c(k-1,1) + (Ts/6)*(ka1+2*ka2+2*ka3+ka4);
   vc_c(k,1) = vc_c(k-1,1) + (Ts/6)*(kb1+2*kb2+2*kb3+kb4);
      
vo_c(k,1) = iL_c(k,1)*(R_C*H(k-1,1))/(R_C+H(k-1,1)) + vc_c(k,1)*H(k-1,1)/(R_C+H(k-1,1));


end
end
 vo = vo_c;
 iL = iL_c;
 figure
 subplot(2,1,1)
plot(vo*5)
subplot(2,1,2)
plot(V)
figure
subplot(2,2,1)
plot(iL)
subplot(2,1,2)
plot(I)