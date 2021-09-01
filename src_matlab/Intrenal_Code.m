for i=1:length(Data_Set)
    Derivative_Pressure=Data_Set(:,i);

Fornorm=[Derivative_Pressure Min Max];
NoRm=mapminmax(Fornorm,InPutSummary(2),InPutSummary(4));
InPut=NoRm(:,1);

net_output=sim(ANN_Model,InPut);

OutPut=mapminmax('reverse', net_output,PSout);

disp (' Detectected reservoir model is ');
disp(100*OutPut);
bar(100*OutPut)
xlabel('Reservoir model')
ylabel('Probability of reservoir model (%)')
 
disp('Result for dataset of ');disp(i);

chk=input('For check the result of next dataset Hit Enter Key', 's');
 
close all

end