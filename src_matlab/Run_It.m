clc
clear all
close all

load data
per=input('Fraction of trainig data set '); %0.85
varIn=input('Number of Independent Variables '); %46
neuron=input('Number of hidden neurons '); % between one and a maximum value may be cahnged
            Norm1=input('Minimum number of Normalization '); %[0 0]
Norm2=input('Maximum number of Normalization ');%[1 1]
err=input('Value of desired error (MSE) ');%1e-7
MaxEpoch=input('Maximum number of Epoch ');%2000
Traintype = input('Training Algorithm ', 's');%it may be changed (eg. trainlm)

[NORMin,PSin] = mapminmax(data(1:varIn,:),Norm1(1),Norm2(1));
[NORMout,PSout] = mapminmax(data(varIn+1:end,:),Norm1(2),Norm2(2));

%% Random Selection of Train Data

R=randperm(length(NORMout));
r_trn=R(1:round(per*length(NORMout)));
r_tst=R(round(per*length(NORMout))+1:length(NORMout));

for i=1:length(r_trn)
 P(:,i)=NORMin(:,r_trn(i));
T(:,i)=NORMout(:,r_trn(i));
end

%% Artificial Neural Network Model Design

ANN_Model=newff(minmax(P),[neuron 6],{'tansig','logsig'},Traintype);
ANN_Model.trainParam.epochs = MaxEpoch;
ANN_Model.trainParam.goal = err;
ANN_Model.trainparam.show=100;
ANN_Model.trainParam.min_grad=1e-10;
% ANN_Model.trainParam.mu_max=1e100;


tic
[ANN_Model,tr]=train(ANN_Model,P,T);
toc

 %% TRN Normalized
 net_output_trn=sim(ANN_Model,P);
 
%% TRN Actual
    AX = mapminmax('reverse', net_output_trn,PSout);
    BX = mapminmax('reverse', T,PSout);
%% TST  Normalized
for j=1:length(r_tst)
    Tst_data(:,j)=NORMin(:,r_tst(j));
     Tar_Tst(:,j)=NORMout(:,r_tst(j));
end

net_output=sim(ANN_Model,Tst_data);

%% TST Actual

      AXX = mapminmax('reverse', net_output,PSout);
    BXX = mapminmax('reverse', Tar_Tst,PSout);
     %% OVERAL   
          Prediction=[AX AXX];
     Actual=[BX BXX];
   %% STATISTICAL ANALYSIS
   
    fd_TRN=abs(round(AX)-BX);   % Number of False Detection
FD_TRN=mean(mean(fd_TRN));% Average of False Detection

 fd_TST=abs(round(AXX)-BXX);
FD_TST=mean(mean(fd_TST));
 
fd_TTL=abs(round(Prediction)-Actual);
FD_TTL=mean(mean(fd_TTL));

False_Detection_Percent=[FD_TRN FD_TST FD_TTL]*100