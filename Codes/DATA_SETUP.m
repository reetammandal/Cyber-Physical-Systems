clc
clear all
load('Normalplusnoise.mat');
D1=Va.signals.values(5001:15000);
I1=Ia.signals.values(5001:15000);
T1=Va.time(5001:15000)-0.5;
T2=T1+1;
T3=T2+1;
load('slowchangeandnormal.mat');
D2=Va.signals.values(5001:15000);
I2=Ia.signals.values(5001:15000);
load('changeinreferenceandnormal.mat');
D3=Va.signals.values(5001:15000);
I3=Ia.signals.values(5001:15000);
D4=Va.signals.values(5001:10000);
I4=Ia.signals.values(5001:10000);
load('changeincontrollerki.mat');
D5=Va.signals.values(5001:10000);
I5=Ia.signals.values(5001:10000);
T4=T3+1;
T=[T1;T2;T3;T4];
D=[D1;D2;D3;D4;D5];
I=[I1;I2;I3;I4;5*I5];
Power=D.*I;
% subplot(3,1,1)
% plot(T,D)
% subplot(3,1,2)
% plot(T,I)
% subplot(3,1,3)
% plot(T,Power)


% subplot(2,1,1)
% plot(T1,D1)
% subplot(2,1,2)
% plot(T2,D2)