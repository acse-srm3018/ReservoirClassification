clc
clear all
close all
load ANN_Model
load PSin
load PSout
load InPutSummary
Min=PSin.xmin;
Max=PSin.xmax;

D_Set=input('Enter the number of reservoir model that you desired to check (1 to 6):');

switch D_Set
    case 1
      load('DS1')
        Data_Set=DS1;
        disp('The results of all patterns for the 1st reservoir model will be displayed');
        slct=input('Its only for your information, Hit Enter Key', 's');
Intrenal_Code
    case 2
        load('DS2')
        Data_Set=DS2;
      disp('The results of all patterns for the 2nd reservoir model will be displayed');
      slct=input('Its only for your information, Hit Enter Key', 's');
Intrenal_Code
    case 3
        load('DS3')
        Data_Set=DS3;
       disp('The results of all patterns for the 3rd reservoir model will be displayed');
       slct=input('Its only for your information, Hit Enter Key', 's');
Intrenal_Code
    case 4
        load('DS4')
        
        Data_Set=DS4;
        disp('The results of all patterns for the 4th reservoir model will be displayed');
        slct=input('Its only for your information, Hit Enter Key', 's');
Intrenal_Code
    case 5
        load('DS5')
        Data_Set=DS5;
        disp('The results of all patterns for the 5th reservoir model will be displayed');
        slct=input('Its only for your information, Hit Enter Key', 's');
Intrenal_Code
    case 6
        load('DS6')
        Data_Set=DS6;
        disp('The results of all patterns for the 6th reservoir model will be displayed');
        slct=input('Its only for your information, Hit Enter Key', 's');
Intrenal_Code
 otherwise
        disp('Please Enetr 1, 2, 3, 4, 5, or six ');
end
