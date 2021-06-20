function [] = analysis4()
%Alternation
a1=[2.490615e-001,5.896221e+000,1.426220e+001,3.152437e+001,6.616013e+001,1.354315e+002,2.739742e+002,5.510597e+002];
a2=[2.490386e-001,5.895450e+000,1.426004e+001,3.151928e+001,6.614918e+001,1.354089e+002,2.739282e+002,5.509668e+002];
a3=[2.488099e-001,5.887746e+000,1.423848e+001,3.146844e+001,6.603985e+001,1.351826e+002,2.734681e+002,5.500392e+002];
a4=[2.465261e-001,5.811541e+000,1.402589e+001,3.096721e+001,6.496165e+001,1.329511e+002,2.689299e+002,5.408876e+002];
a5=[2.240806e-001,5.125133e+000,1.216412e+001,2.660245e+001,5.556544e+001,1.134937e+002,2.293503e+002,4.610634e+002];
alternation=[a1;a2;a3;a4;a5];

%PistoiaFirst
a1=[3.262227e-001,5.998930e+000,1.446529e+001,3.104183e+001,6.435369e+001,1.309836e+002,2.642433e+002,5.307628e+002];
a2=[3.261938e-001,5.998076e+000,1.446311e+001,3.103688e+001,6.434315e+001,1.309619e+002,2.641993e+002,5.306740e+002];
a3=[3.259052e-001,5.989539e+000,1.444127e+001,3.098746e+001,6.423791e+001,1.307451e+002,2.637594e+002,5.297879e+002];
a4=[3.230244e-001,5.905166e+000,1.422586e+001,3.050007e+001,6.319962e+001,1.286059e+002,2.594184e+002,5.210435e+002];
a5=[2.946940e-001,5.151684e+000,1.233093e+001,2.623488e+001,5.411223e+001,1.098771e+002,2.214067e+002,4.444659e+002];
pistoiaFirst=[a1;a2;a3;a4;a5];

%LuccaFirst
a1=[3.608326e-001,6.477348e+000,1.463681e+001,3.094571e+001,6.383870e+001,1.295808e+002,2.610676e+002,5.240414e+002];
a2=[3.608007e-001,6.476468e+000,1.463464e+001,3.094104e+001,6.382913e+001,1.295614e+002,2.610287e+002,5.239632e+002];
a3=[3.604822e-001,6.467675e+000,1.461296e+001,3.089438e+001,6.373352e+001,1.293678e+002,2.606393e+002,5.231821e+002];
a4=[3.573027e-001,6.380741e+000,1.439907e+001,3.043373e+001,6.278927e+001,1.274562e+002,2.567929e+002,5.154662e+002];
a5=[3.260131e-001,5.601682e+000,1.251700e+001,2.637254e+001,5.443128e+001,1.105130e+002,2.226782e+002,4.470085e+002];
luccaFirst=[a1;a2;a3;a4;a5];
tempo=[1,6,12,24,48,96,192,384];
guasto=[0.00001,0.0001,0.001,0.01,0.1];

tiledlayout(3,1)
nexttile
surf(alternation);
xlabel( 'Tempo' );
ylabel( 'Guasto' );
zlabel( 'Treni che terminano la corsa' );
colorbar
title('Analisi 4 per la politica Alternation')

nexttile
surf(pistoiaFirst);
xlabel( 'Tempo' );
ylabel( 'Guasto' );
zlabel( 'Treni che terminano la corsa' );
colorbar
title('Analisi 4 per la politica PistoiaFirst')

nexttile
surf(luccaFirst);
xlabel( 'Tempo' );
ylabel( 'Guasto' );
zlabel( 'Treni che terminano la corsa' );
colorbar
title('Analisi 4 per la politica LuccaFirst')


end

