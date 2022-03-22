clc
clear all
load('DATASETUP.mat');
for i=1:1:80
TrainData(i,1:500)=Power(((i-1)*500)+1:i*500);
TrainData(i,501:1000)=Power(((i-1)*500)+1:i*500);
end
TrainData(:,501)=zeros(80,1);%Label
TrainData(11:15,501)=TrainData(11:15,501)+1;
TrainData(31:40,501)=TrainData(31:40,501)+2;
TrainData(51:60,501)=TrainData(51:60,501)+3;
TrainData(71:80,501)=TrainData(71:80,501)+4;

%TrainData(71:80,1:500)=TrainData(71:80,1:500)*10;


% YY=ones(80,500);
% 
% for i=1:1:80
% b(((i-1)*500)+1:i*500)=Power(1:500,1);
% end
% for i=1:1:80
% c(((i-1)*500)+1:i*500)=YY(i,1:500).*yfit(i);
% end
% figure()
% subplot(3,1,1)
% plot(T,D)
% subplot(3,1,2)
% plot(T,I)
% subplot(3,1,3)
% bar(T,c)