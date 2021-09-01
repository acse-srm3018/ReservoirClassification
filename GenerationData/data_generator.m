%{
___________________________________________________________________________
                            Data generator
___________________________________________________________________________
%}
%__________________________________________________________________________
skin =                    linspace( -2     ,23     ,10 );

vertical_permeability =   linspace( 0.5    ,100    ,5  );

well_length =             linspace( 200    ,1500   ,12 );

radial_permeability = linspace( 20     ,400    ,8  );

omega =                   linspace( 1E-04  ,0.1    ,3  );

lambda =                   linspace( 1E-08  ,1E-05  ,3  );
%__________________________________________________________________________

single_porosity =  combvec(radial_permeability,...
    vertical_permeability,skin,well_length);
dual_porosity   =  combvec(single_porosity,omega,lambda);

single_porosity=single_porosity';
dual_porosity=dual_porosity';
fprintf(fopen('single_porosity.txt','w'),'%5g\t%5g\t%5g\t%5g\r\n',single_porosity);
fprintf(fopen('dual_porosity.txt','w'),'%5g\t%5g\t%5g\t%5g\t%5g\t%5g\r\n',dual_porosity);
save('single_porosity.txt','single_porosity','-ascii','-tabs') 
save('dual_porosity.txt','dual_porosity','-ascii','-tabs')