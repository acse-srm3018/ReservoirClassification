clc
% clear all
close all
load ANN_Model
load PSin
load PSout
load InPutSummary

Min=PSin.xmin;
Max=PSin.xmax;


Derivative_Pressure=[

-105.843023111557
-139.329922853879
-182.951725912832
-239.289081439617
-310.841981967557
-400.671367468183
-511.360160526395
-644.247664557197
-798.021798378770
-967.614326583719
-1142.09067090169
-1303.00809691669
-1425.80909566458
-1483.47892063393
-1454.23377297990
-1332.27988533193
-1135.06518362475
-900.724503769873
-674.951549312396
-492.995407314039
-367.922755479661
-292.718183076505
-251.813917270589
-229.734458782482
-215.816142729613
-205.569054789890
-197.381468674966
-190.372881438460
-184.265439620441
-179.732145210142
-173.991108926376
-165.673162080367
-156.588129225481
-145.779560187272
-131.492990139062
-113.807346105716
-91.7885979663355
-65.4611917979230
-39.9324856906041
-20.0597552535855
-7.90354330524984
-2.51358946881882
-0.680344132793057
-0.00741738984859432
0.0816233436999515
0.0149029022846250
0.000528954855651382
3.60651030644750e-05
];

Fornorm=[Derivative_Pressure Min Max];
NoRm=mapminmax(Fornorm,InPutSummary(2),InPutSummary(4));
InPut=NoRm(:,1);

net_output=sim(ANN_Model,InPut);

OutPut=mapminmax('reverse', net_output,PSout);

disp (' Detectected reservoir model is ');
disp(100*OutPut);
bar(100*OutPut)
xlabel('Reservoir model')
ylabel('Probability of reservoir model')
